#include "sae.h"

//TEST SCORE

void testInsertionEnTete(void){
    ListeScore l;

    l=ensemble();

    l= ajouterEntete( l, 10);
    l= ajouterEntete( l, 5);
    l= ajouterEntete( l, 30);

    afficherScore(l);    
    
    printf("Insertion d'un nouveau du score 40 en tete de file : \n");

    l= ajouterEntete( l, 40);

    afficherScore(l);    

    printf("\n");
}

void testInsertion(void){
    ListeScore l;

    l=ensemble();

    l= ajouter( l, 10);
    l= ajouter( l, 5);
    l= ajouter( l, 30);
    l= ajouter( l, 40);

    afficherScore(l);

    printf("Insertion du nouveau score 15 : \n");
    l= ajouter( l, 15);

    afficherScore(l);


    printf("\n");
}

void testSuppressionEnTete(void){
    ListeScore l;

    l=ensemble();

    l= ajouter( l, 10);
    l= ajouter( l, 5);
    l= ajouter( l, 30);
    l= ajouter( l, 40);

    printf("Avant suppression : \n");    
    afficherScore(l);

    l= supprimerEntete(l);

    printf("\n");
    printf("Après suppression : \n");
    afficherScore(l);
    printf("\n");
}

void testSuppression(void){
    ListeScore l;

    l=ensemble();

    l= ajouter( l, 10);
    l= ajouter( l, 5);
    l= ajouter( l, 30);
    l= ajouter( l, 40);

    printf("Avant suppression \n");    
    afficherScore(l);

    l=supprimer(l,30);

    printf("\n");
    printf("Après suppression : \n");
    afficherScore(l);
    printf("\n");

}

void testMenu(void){
    int choix;
    choix = menu();
    printf("Le choix est %d", choix);
    printf("\n");
}

//TEST JOUEUR

void testChargement(void){
    int tmax =20, tlog;
    Joueur * tabJoueur[tmax];

    tlog = chargement(tabJoueur, "fichierSauvegarde/Scores.txt", tmax);

    affichListeJoueursScores(tabJoueur, tlog);

    for (int i = 0; i < tlog; i++) free(tabJoueur[i]);
}

void testSauvegarde(void){
    int tmax=20, tlog;
    Joueur * tabJoueur[tmax];

    tlog = chargement(tabJoueur, "fichierSauvegarde/Scores.txt", tmax);

    sauvegardeScoreJoueur(tabJoueur, "fichierSauvegarde/Scores.txt", tlog);

    for (int i = 0; i < tlog; i++) free(tabJoueur[i]);

}

void testTriEchangeScore(void){
    int tmax=20, tlog;
    Joueur * tabJoueur[tmax];

    tlog = chargement(tabJoueur, "fichierSauvegarde/Scores.txt", tmax);

    triEnchangeMeilleurScore(tabJoueur, tlog);

    affichListeJoueursScores(tabJoueur, tlog);

    for (int i = 0; i < tlog; i++) free(tabJoueur[i]);
}



int main(void){//fonction principale
    //TEST SCORE
    /*
    testInsertionEnTete();
    testInsertion();
    testSuppressionEnTete();
    testSuppression();
    */

    //TEST JOUEUR
    /*
    testChargement();
    testSauvegarde();
    */
    testTriEchangeScore();

    return 0;
}
