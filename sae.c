#include "sae.h"

/**
    \brief Affiche le logo  du jeu.
*/
void logo(void){
    printf("         />_________________________________\n");
    printf("[########[]_________________________________>\n");
    printf("         \\>                                 \n");
    printf(" _   __      _       _     _       \n");
    printf("| | / /     (_)     | |   | |      \n");
    printf("| |/ / _ __  _  __ _| |__ | |_ ___ \n");
    printf("|    \\| '_ \\| |/ _` | '_ \\| __/ __|\n");
    printf("| |\\  \\ | | | | (_| | | | | |\\__ \\ \n");
    printf("\\_| \\_/|_| |_|_|\\__, |_| |_||__|___/\n");
    printf("                __/ |              \n");
    printf("               |___/               \n");
}

/**
    \brief Affiche le menu principal du jeu.
    \return Le choix de l'utilisateur.
*/
void global(void){
    int choix, tlog, tmax =100;
    Joueur * tabJoueur[tmax];

    logo();

    tlog = chargementJoueurs(tabJoueur, tmax);

    choix = menu();
    while(choix !=9){
        if(choix == 1)tlog = Partie(tabJoueur, tlog);
        else if(choix == 2)creerPartie();
        else if(choix == 3)affichJoueurParNom(tabJoueur, tlog);
        else if(choix == 4)affichJoueurMeilleursScores(tabJoueur, tlog);
        else if(choix == 5)affichStatJoueur(tabJoueur, tlog);
        else if(choix == 6)generePartieAleatoire();

        choix = menu();
    }
    printf("Merci d'avoir utilisé  l'application \n");
    sauvegardeJoueur(tabJoueur, tlog);
    libereTabJoueur(tabJoueur, tlog);
}


