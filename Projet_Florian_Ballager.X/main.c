#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "PWM.h"
#include "Timer.h"
#include "Robot.h"

int main (void){
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
    
    robotState.taskEnCours = 0;
    robotState.vitesseDroiteCommandeCourante = 0;
    robotState.vitesseDroiteConsigne = 0;
    robotState.vitesseGaucheCommandeCourante = 0;
    robotState.vitesseGaucheConsigne = 0;

    robotState.vitesseGaucheConsigne = 100;
    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    while(1){
        if(IntFlags & 0x01){
            IntFlags &= 0xFE;
            PWMUpdateSpeed();
            if(abs(robotState.vitesseGaucheCommandeCourante) > abs(robotState.vitesseGaucheConsigne)-2) robotState.vitesseGaucheConsigne *= -1;
        }
    } // fin main
}
