#include "sae.h"

/*
    - comparer les attaques + ajouter 10 points si gagné par le joueur + ajouter 50points si le monstre meurt soit tete/sommet->PV <= 0 + s'il meurt apprès l'ajoute des points il faut le defélier/dépiler
    - choix de l'attaque du joueur entre P, F, C
    - attaque aléatoire du monstre en fonction de son nombres d'armes. Si tete/sommet->nbArmes = 3, entre P, F, C
                                                                       Si tete/sommet->nbArmes = 4, entre P, F, C, O
                                                                       Si tete/sommet->nbArmes = 5, entre P, F, C, O, # soit S
    - affichage 
*/


Arme choixArmeJoueur(void){
    char choix;
    printf("choisis ton attaque parmi P, F, C : ");
    scanf("%c%*c", &choix);
    while(choix != 'P' && choix != 'F' && choix != 'C'){
        printf("choisis ton attaque parmi P, F, C : ");
        scanf("%c%*c", &choix);
    }
    return choix;
}

int gagneAttaqueJoueur(Arme attaqueJ, Arme attaqueM){
    if(attaqueJ == attaqueM) return 2;
    if(attaqueM == 'S') return 0;
    if(attaqueM == 'O') return 1;
    if(attaqueJ == 'P'){
        if(attaqueM == 'C') return 1;
        return 0;
    }
    if(attaqueJ == 'C'){
        if(attaqueM == 'F') return 1;
        return 0;
    }
    if(attaqueJ == 'F'){
        if(attaqueM == 'P') return 1;
        return 0;
    }
    return -1;
}

/*A REGARDER, REFAIRE, UTILISER AUTREMENT - TESTER*/
void combat(Joueur j, Monstre m, int *points){
    Arme armeJ, armeM;
    int compa;
    printf("Le monstre %s(%dptV, %dAtt) s'avance pour vous attaquer %s(%dptV, %dAtt)\n", m.nom, m.PV, m.degat, j.pseudo, j.PV, j.degat);
    printf("%s (%dpts), ", j.pseudo, *points);
    armeJ = choixArmeJoueur();
    armeM = 'P'/*fonction renvoyant l'arme du monstre aléatoire*/;
    printf("%s (%c) attaque %s(%c)\n", j.pseudo, armeJ, m.nom, armeM);
    compa = gagneAttaqueJoueur(armeJ, armeM);
    if(compa == 2) printf("\taucune de %s(%dptV) et %s(%dptV) ne gagne l'attaque\n", j.pseudo, j.PV, m.nom, m.PV);
    if(compa == 1){
        m.PV -= j.degat;
        printf("\t%s(%dptV) gagne l'attaque contre %s(%dptV)\t\t+ 10pts\n", j.pseudo, j.PV, m.nom, m.PV);
        *points += 10;
        if(m.PV <= 0){
            printf("%s meurt sous le coup de l'attaque\t\t\t + 50pts", m.nom);
            *points += 50;
            /*Monstre tué - que faire?*/
        }
    }
    if(compa == 0){
        j.PV -= m.degat;
        printf("\t%s(%dptV) perd l'attaque contre %s(%dptV)\n", j.pseudo, j.PV, m.nom, m.PV);
        if(j.PV <= 0){
            printf("PERDU... nombre de pts acquis : %d", *points);
        }
    }
}