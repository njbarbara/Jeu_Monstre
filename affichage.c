#include "sae.h"


//AFFICHAGE PRINCIPAL 

int menu(void){
    int choix;
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*\t                                                          \t*\n");
    printf("*\t    Veuiller choisir en tapant le numéro correspondant    \t*\n");
    printf("*\t                                                          \t*\n");
    printf("*\t 1. jouer une partie prédéfinie                           \t*\n");
    printf("*\t 2. créer une nouvelle partie                             \t*\n");
    printf("*\t 3. afficher la liste des joueurs triée par nom           \t*\n");
    printf("*\t 4. afficher la liste des joueurs triée par meilleur score\t*\n");
    printf("*\t 5. afficher les statistiques d'un joueur                 \t*\n");
    printf("*\t 9. Quitter                                               \t*\n");
    printf("*\t                                                          \t*\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    scanf("%d", &choix);

    while((choix != 1) && (choix != 2) && (choix != 3) && (choix != 3) && (choix != 4) && (choix != 5) && (choix != 9)){
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*\t                                                          \t*\n");
        printf("*\t                      CHOIX INVALIDE                      \t*\n");
        printf("*\t                                                          \t*\n");
        printf("*\t    Veuiller choisir en tapant le numéro correspondant    \t*\n");
        printf("*\t                                                          \t*\n");
        printf("*\t 1. jouer une partie prédéfinie                           \t*\n");
        printf("*\t 2. créer une nouvelle partie                             \t*\n");
        printf("*\t 3. afficher la liste des joueurs triée par nom           \t*\n");
        printf("*\t 4. afficher la liste des joueurs triée par meilleur score\t*\n");
        printf("*\t 5. afficher les statistiques d'un joueur                 \t*\n");
        printf("*\t 9. Quitter                                               \t*\n");
        printf("*\t                                                          \t*\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        scanf("%d", &choix);
    }
    return choix;
}



//AFFICHAGE JOUEUR 
void affichListeJoueursScores(Joueur * tabJoueur[], int tlog){
    int i;

    for(i =0; i<tlog; i++){
        printf("Nom du joueur : %s\n",tabJoueur[i]->pseudo);
        printf("scores associés : \n");
        afficherScore(tabJoueur[i]->l);
    }
}

void affichJoueurMeilleurs(Joueur * tabJoueur [], int tlog){
    int i;

    triEnchangeMeilleurScore(tabJoueur, tlog);

    for(i=0; i<tlog; i++) printf("Nom du joueur : %s \t Son meilleur score : %d",tabJoueur[i]->pseudo, tabJoueur[i]->l->score);

}

// AFFICHAGE PARTIE

//fct utilisé pour tester le chargement et la sauvegarde de partie
void affichPartie(File fM, PileM pM, int tlog){

}

void clear(void){
    for(int i =0; i < 33; i++)printf("\n");
}

void affichArriveeNouvMonstre(Joueur j, Monstre m, int nbPoints){
    printf("Le monstre %s(%dptV, %dAtt) s'avance pour vous attaquer %s(%dptV, %dAtt)\n", m.nom, m.PV, m.degat, j.pseudo, j.PV, j.degat);
    printf("%s (%dpts), ", j.pseudo, nbPoints);
}

void affichNouvMonstrePlaine(Joueur j, Monstre m, int nbPoints){
    printf("Le monstre %s(%dptV, %dAtt) s'avance pour vous attaquer %s(%dptV, %dAtt)\n", m.nom, m.PV, m.degat, j.pseudo, j.PV, j.degat);
    printf("%s (%dpts), ", j.pseudo, nbPoints);
}