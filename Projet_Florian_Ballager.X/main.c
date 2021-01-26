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
    // Configuration des entr�es sorties
    /****************************************************************************************************/
    InitIO();

    InitPWM();
    
    PWMSetSpeed(50);

    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    while(1){
        
    } // fin main
}
