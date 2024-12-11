#include "sae.h"

//TEST SCORE

void testInsertionEnTete(void){
    ListeScore l;

    l=ensemble();

    l= ajouterEntete( l, 10);
    l= ajouterEntete( l, 5);
    l= ajouterEntete( l, 30);

    afficherScore(l);    
    
    printf("Insertion d'un nouveau du score : \n");

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

    printf("Insertion d'un nouveau du score : \n");
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
    printf("Avant suppression : \n");
    afficherScore(l);
    printf("\n");

}

void testMenu(void){
    int choix;
    choix = menu();
    printf("Le choix est %d", choix);
    printf("\n");
}


int main(void){//fonction principale
    //Test de scores
    /**/
    testInsertionEnTete();
    testInsertion();
    testSuppressionEnTete();
    testSuppression();


    return 0;
}
