#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "main.h"
#include "ChipConfig.h"
#include "IO.h"
#include "PWM.h"
#include "Timer.h"
#include "Robot.h"
#include "adc.h"

int main(void) {
    /***************************************************************************************************/
    //Initialisation de l'oscillateur
    /****************************************************************************************************/
    InitOscillator();

    /****************************************************************************************************/
    // Configuration des entrées sorties
    /****************************************************************************************************/
    InitIO();
    InitPWM();
    InitTimer1();
    InitADC1();

    robotState.taskEnCours = 0;
    robotState.vitesseDroiteCommandeCourante = 0;
    robotState.vitesseDroiteConsigne = 0;
    robotState.vitesseGaucheCommandeCourante = 0;
    robotState.vitesseGaucheConsigne = 0;

    unsigned char obstacles = 0;
    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    while (1) {

        ADC1StartConversionSequence();
        if (ADCIsConversionFinished()) {
            ADCClearConversionFinishedFlag();
            unsigned int* distances = ADCGetResult();
            obstacles = (distances[0] < detecDistance) | ((distances[1] < detecDistance) << 1) | ((distances[2] < detecDistance) << 2) | ((distances[3] < detecDistance) << 3) | ((distances[4] < detecDistance) << 4); // | () | ();
        }

        if((obstacles == 0) || (obstacles == 1) || (obstacles == 10) || (obstacles == 16) || (obstacles == 17)){FWD}
        else{if((obstacles == 2) || (obstacles == 3) || (obstacles == 5) || (obstacles == 18) || (obstacles == 19)){R}
        else{if((obstacles == 8) || (obstacles == 9) || (obstacles == 20) || (obstacles == 24) || (obstacles == 25)){L}
        else{if((obstacles == 4) || (obstacles == 21) || (obstacles == 27) || (obstacles == 31)){U}
        else{if((obstacles == 6) || (obstacles == 7) || (obstacles == 11)){RR}
        else{if((obstacles == 12) || (obstacles == 26) || (obstacles == 28)){LL}
        else{if((obstacles == 13) || (obstacles == 15) || (obstacles == 23)){UR}
        else{if((obstacles == 22) || (obstacles == 29) || (obstacles == 30)){UL}
        }}}}}}}
        
        if(IntFlags&0x01){
            PWMUpdateSpeed();
        }

    } // fin main
}
