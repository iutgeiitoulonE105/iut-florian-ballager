#ifndef MAIN_H
#define	MAIN_H

    #define speed 30
    #define detecDistance 27

    unsigned char last_spin=0;
    #define FWD robotState.vitesseDroiteConsigne=speed;robotState.vitesseGaucheConsigne=speed;
    #define UL robotState.vitesseDroiteConsigne=-speed/1.7;robotState.vitesseGaucheConsigne=speed/1.7;last_spin=0;
    #define UR robotState.vitesseDroiteConsigne=speed/1.7;robotState.vitesseGaucheConsigne=-speed/1.7;last_spin=1;
    #define L robotState.vitesseDroiteConsigne=speed/3;robotState.vitesseGaucheConsigne=speed;
    #define R robotState.vitesseDroiteConsigne=speed;robotState.vitesseGaucheConsigne=speed/3;
    #define LL robotState.vitesseDroiteConsigne=0;robotState.vitesseGaucheConsigne=speed;
    #define RR robotState.vitesseDroiteConsigne=speed;robotState.vitesseGaucheConsigne=0;
    #define U if(last_spin){UR}else{UL};


#endif	/* MAIN_H */

