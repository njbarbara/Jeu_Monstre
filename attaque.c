#include "sae.h"

Arme choixArmeJoueur(void){
    char choix;
    printf("Choisis ton attaque parmi P, F, C : ");
    scanf("%c%*c", &choix);
    while(choix != 'P' && choix != 'F' && choix != 'C'){
        printf("Choix incorrect \n");
        printf("Choisis ton attaque parmi P, F, C : ");
        scanf("%c%*c", &choix);
    }
    return choix;
}

int gagneAttaqueJoueur(Arme attaqueJ, Arme attaqueM){
    if(attaqueJ == attaqueM) return 2;
    else if(attaqueM == 'S') return 0;
    else if(attaqueM == 'O') return 1;
    else if(attaqueJ == 'P'){
        if(attaqueM == 'C') return 1;//le joueur gagne le duel
        return 0;
    }
    else if(attaqueJ == 'C'){
        if(attaqueM == 'F') return 1;
        return 0;
    }
    else {
        if(attaqueM == 'P') return 1;
        return 0;
    }
}

Arme RandomAttaqueMonstre(Monstre m){
    time_t seconds = time(NULL);
    int att = (rand()+seconds)%(m.nbArmes);
    if(att==0)return 'P';
    else if(att==1) return 'F';
    else if(att==2) return 'C';
    else if(att==3) return 'O';
    else return 'S';
}

int combat(Joueur j, Monstre m, int *points){
    Arme armeJ, armeM;
    int compa;

    armeJ = choixArmeJoueur();
    armeM = RandomAttaqueMonstre(m);

    printf("%s (%c) attaque %s(%c)\n", j.pseudo, armeJ, m.nom, armeM);

    compa = gagneAttaqueJoueur(armeJ, armeM);

    if(compa == 2)printf("Ni %s(%dptV) ni %s(%dptV) ne gagne l'attaque\n", j.pseudo, j.PV, m.nom, m.PV);
    else if(compa == 1){
        m.PV -= j.degat;
        printf("%s(%dptV) gagne l'attaque contre %s(%dptV)\t\t+ 10pts\n", j.pseudo, j.PV, m.nom, m.PV);
        *points += 10;

        if(m.PV <= 0){
            printf("%s meurt sous le coup de l'attaque\t\t\t + 50pts", m.nom);
            *points += 50;
            return 1;
        }
    }
    else {
        j.PV -= m.degat;
        printf("%s(%dptV) perd l'attaque contre %s(%dptV)\n", j.pseudo, j.PV, m.nom, m.PV);
        if(j.PV <= 0){
            printf("VOUS ÊTES MORT... nombre de points acquis : %d", *points);
            return -1;
        }
    }        
    return 0;

}