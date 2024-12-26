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

//TEST MONSTRE



void testPileMonstre(void){
    PileM pM;
    int h, i;
    Monstre testMonstre, autreMonstre;
    pM = pileVide();
    strcpy(testMonstre.nom, "dragon");
    testMonstre.PV = 20;
    testMonstre.degat = 2;
    testMonstre.nbArmes = 3;
    pM = empiler(pM, testMonstre);
    autreMonstre = sommet(pM);
    affichageMonstre(autreMonstre);
    h = hauteur(pM);
    printf("Hauteur de la pile : %d\n", h);
    i = estPileVide(pM);
    printf("Pile vide ? %d\n", i);
    affichagePileMonstre(pM);
    pM = depiler(pM);
    i = estPileVide(pM);
    printf("Pile vide ? %d\n", i);
    if(i == 1){
        printf("Plus de monstre à afficher\n");
    }
    else affichagePileMonstre(pM);
}

void testChargementMonstresEtRandomMonstre(void){
    Monstre *tab[6], testm;
    int tlog;
    tlog = chargementMonstres(tab);
    afficheTabMonstre(tab, tlog);
    testm = randomMonstre(tab, &tlog);
    printf("Monstre choisi : ");
    affichageMonstre(testm);
    printf("Tableau de monstres après random : \n");
    afficheTabMonstre(tab, tlog);
}


void testPremierGroupe(void){
    Monstre *tab[6];
    int tlog;
    PileM pM;
    tlog = chargementMonstres(tab);
    pM = premierGroupe(tab, &tlog);
    affichagePileMonstre(pM);
}


void testDeuxiemeGroupe(void){
    Monstre *tab[6];
    int tlog;
    File fM;
    tlog = chargementMonstres(tab);
    fM = deuxiemeGroupe(tab, &tlog);
    affichageFileMonstres(fM);
}


// TEST ATTAQUE

void testChoixArmeJoueur(void){
    Arme a;
    a = choixArmeJoueur();
    printf("Arme choisi %c", a);
}

void testGagneAttaqueJoueur(void){
    int a;
    a = gagneAttaqueJoueur('P', 'F');
    if(a == 2) printf("Rejouer");
    if(a == 1) printf("Le joueur a gagné l'attaque");
    if(a == 0) printf("Le monstre remporte l'attaque");
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

    //TEST MONSTRE
    //testTriEchangeScore();
    //testFileMonstres();
    //testPileMonstre();
    //testChargementMonstresEtRandomMonstre();
    //testPremierGroupe();
    //testDeuxiemeGroupe();
    testChoixArmeJoueur();
    return 0;
}
