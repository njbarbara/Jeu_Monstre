#include "sae.h"

//TEST SCORE

void testInsertionEnTete(void){
    ListeScore l;

    l=creerListeVide();

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

    l=creerListeVide();

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

    l=creerListeVide();

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

    l=creerListeVide();

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
    int tlog, tmax =100;
    Joueur * tabJoueur[tmax];

    tlog = chargementJoueurs(tabJoueur, tmax);

    affichListeJoueursScores(tabJoueur, tlog);

}

void testSauvegarde(void){
    int tlog, tmax =100;
    Joueur * tabJoueur[tmax];

    tlog = chargementJoueurs(tabJoueur, tmax);

    sauvegardeJoueur(tabJoueur, tlog);

}

void testTriEchangeMeilleurScore(void){
    int tlog, tmax =100;
    Joueur * tabJoueur[tmax];

    tlog = chargementJoueurs(tabJoueur, tmax);

    affichListeJoueursScores(tabJoueur, tlog);

    affichJoueurMeilleursScores(tabJoueur,tlog);//cette fonction utilise la fonction de tri échange
}

void testRechNormalJoueur(void){
    int tlog, tmax =100, pos;
    Joueur * tabJoueur[tmax];
    char nom[30];

    tlog = chargementJoueurs(tabJoueur, tmax);

    affichListeJoueursScores(tabJoueur, tlog);

    printf("Saisir le nom du joueur : ");
    fgets(nom,30,stdin);
    nom[strlen(nom)-1]='\0';

    pos = rechercheNomJoueur(nom, tabJoueur, tlog);
    
    printf("Pos = %d \n",pos);
}

void testRechDicoJoueur(void){
    int tlog, tmax =100, pos, trouve;
    Joueur * tabJoueur[tmax];
    char nom[30];

    tlog = chargementJoueurs(tabJoueur, tmax);

    affichListeJoueursScores(tabJoueur, tlog);

    printf("Saisir le nom du joueur : ");
    fgets(nom,30,stdin);
    nom[strlen(nom)-1]='\0';

    pos = rechercheDico(tabJoueur,tlog , nom, &trouve);

    printf("Pos = %d \n",pos);
} 

void testAjoutJoueur(void){
    int tlog, tmax =100, trouve, pos;
    Joueur * tabJoueur[tmax];
    char nom[30];

    printf("Saisir le nom du joueur : ");
    fgets(nom,30,stdin);
    nom[strlen(nom)-1]='\0';

    tlog = chargementJoueurs(tabJoueur, tmax);

    printf("Avant ajout : \n");
    affichListeJoueursScores(tabJoueur, tlog);

    pos = rechercheDico(tabJoueur,tlog , nom, &trouve);
    printf("pos : %d", pos);

    if(trouve == 0){
        tlog = ajouterJoueur(tabJoueur,  nom, tlog, pos);
        printf("\nAprès ajout : \n\n");
        affichListeJoueursScores(tabJoueur, tlog);
    }
    else printf("Joueur déjà existant \n"); 

}

//TEST MONSTRE

//TEST PILE MONSTRE
void testPileMonstre(void){
    PileM pM;
    int h, i;
    Monstre testMonstre, autreMonstre;
    pM = CreerPileVide();
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

//TEST FILE MONSTRE

void testAdjQ(void){
    File fM;
    Monstre m;

    fM = CreerfileVideMonstre();

    m = saisirMonstre();
    fM = adjQ(fM, m);
    m = saisirMonstre();
    fM = adjQ(fM, m);

    affichageFileMonstres(fM);
}

void testSupT(void){
    File fM;
    Monstre m;

    fM = CreerfileVideMonstre();

    m = saisirMonstre();
    fM = adjQ(fM, m);
    m = saisirMonstre();
    fM = adjQ(fM, m);

    printf("Avant suppression : \n");
    affichageFileMonstres(fM);
    fM = supT(fM);
    printf("Après suppression : \n");
    affichageFileMonstres(fM);
}

//TEST GENERATION ALÉATOIRE D'UNE PARTIE

void testChargementMonstresEtRandomMonstre(void){
    Monstre * tab, testm;
    int tlog;
    tab = chargementMonstres(&tlog);
    afficheTabMonstre(tab, tlog);
    testm = randomMonstre(tab, tlog);
    printf("Monstre choisi : ");
    affichageMonstre(testm);
    printf("Tableau de monstres après random : \n");
    afficheTabMonstre(tab, tlog);
}


void testPremierGroupe(void){
    Monstre * tab;
    int tlog;
    PileM pM;
    tab = chargementMonstres(&tlog);
    pM = premierGroupe(tab, tlog);
    affichagePileMonstre(pM);
}


void testDeuxiemeGroupe(void){
    Monstre * tab;
    int tlog;
    File fM;
    tab = chargementMonstres(&tlog);
    fM = deuxiemeGroupe(tab, tlog);
    affichageFileMonstres(fM);
}

// TEST ATTAQUE

void testChoixArmeJoueur(void){
    Arme a;
    a = choixArmeJoueur();
    printf("Arme choisi %c \n", a);
}

void testGagneAttaqueJoueur(void){
    int a;
    a = gagneAttaqueJoueur('P', 'F');
    if(a == 2) printf("Rejouer");
    if(a == 1) printf("Le joueur a gagné l'attaque");
    if(a == 0) printf("Le monstre remporte l'attaque");
    printf("\n");
}

void testAttRandom(void){
    char a; 
    Monstre m;

    m = saisirMonstre();
    a = RandomAttaqueMonstre(m);

    printf("Attaque random du monstre : %c \n",a);
}

void testCombat(void){
    int nbPoints=0, resCombat;
    Joueur j;
    Monstre m;

    printf("Saisir votre nom de joueur : ");
    fgets(j.pseudo,30,stdin);
    j.pseudo[strlen(j.pseudo)-1]='\0';

    j = initialiserUnJoueur(j);

    m = saisirMonstre();

    resCombat = combat( &j,  &m, &nbPoints);

    printf("Nb points : %d \nResCombat : %d\n", nbPoints, resCombat);
}

//TEST PARTIE 

void testChargementPartie(void){
    File fM;
    PileM pM;
    int res;


    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    res = chargePartie("essai.txt", &fM, &pM);
    if(res ==-1)return;
    affichPartie(fM, pM);
}

void testSauvegardePartie(void){
    File fM;
    PileM pM;
    int res;

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    res = chargePartie("essai.txt", &fM, &pM);
    if(res ==-1)return;

    printf("Avant chargement : \n");

    affichPartie(fM, pM);

    sauvegardePartie("essai2.txt", fM, pM);

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    res = chargePartie("essai.txt", &fM, &pM);
    if(res ==-1)return;
    printf("Après chargement : \n");
    affichPartie(fM, pM);
}

void testGenerePartieAleatoire(void){
    char nomFich[30];
    File fM;
    PileM pM;
    int res;

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();


    generePartieAleatoire();

    printf("Saisir le fichier où vous avez enregistré la partie : ");
    scanf("%s", nomFich);
    res = chargePartie("essai.txt", &fM, &pM);
    if(res ==-1)return;}

void testCreePartie(void){
    File fM;
    PileM pM;
    char nomFich[30];
    int res;

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    creerPartie();
    printf("Saisir le fichier où vous avez enregistré la partie : ");
    scanf("%s", nomFich);
    res = chargePartie("essai.txt", &fM, &pM);
    if(res ==-1)return;

    affichPartie(fM, pM);
}

void testPartie(void){
    int tlog, tmax =100;
    Joueur * tabJoueur[tmax];

    tlog = chargementJoueurs(tabJoueur, tmax);

    tlog = Partie(tabJoueur, tlog);
}

int main(void){//fonction principale
    //TEST SCORE
    //testInsertionEnTete();
    //testInsertion();
    //testSuppressionEnTete();
    //testSuppression();
    

    //TEST JOUEUR
    //testChargement();
    //testSauvegarde();
    //testTriEchangeMeilleurScore();
    //testRechNormalJoueur();
    //testRechDicoJoueur();
    //testAjoutJoueur();
    

    //TEST MONSTRE
    //testPileMonstre();
    //testAdjQ();
    //testSupT();
    //testChargementMonstresEtRandomMonstre();
    //testPremierGroupe();
    //testDeuxiemeGroupe();
    //testChoixArmeJoueur();

    //TEST ATTAQUE 
    //testChoixArmeJoueur();
    //testGagneAttaqueJoueur();
    //testAttRandom();
    //testCombat();

    //TEST PARTIE 
    //testChargementPartie();
    //testSauvegardePartie();
    //testGenerePartieAleatoire();
    //testCreePartie();
    //testPartie();

    global();

    return 0;
}
