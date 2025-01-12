#include "sae.h"

/*FICHIER DES FONCTIONS LIÉES AUX FONCTIONNEMENTS DU JEU */


/**
    \brief cette fonction permet de charger une partie à partir d'un nom fichier passer en paramètre
    \param nomFich nom du fichier à utiliser
    \param fM file de monstre à charger
    \param pM pile de monstre à charger 
*/
int chargePartie(char *nomFich, File *fM, PileM *pM){
    FILE *flot;
    int nbPile, nbFile, i;
    char chemin[60] = "fichierSauvegarde/";
    Monstre m;

    strcat(chemin,nomFich);

    flot = fopen(chemin, "r");

    if(flot==NULL){
        printf("Pb ouverture fichier \n");
        return -1;
    }
    
    fscanf(flot,"%d%*c",&nbPile);
    for(i = 0; i < nbPile; i++){
        m = lireMonstre(flot);
        *pM = empiler(*pM, m);
    } 
    fscanf(flot, "%d%*c", &nbFile);
    for( i = 0; i < nbFile; i++){
        m = lireMonstre(flot);
        *fM = adjQ(*fM, m); 
    } 
    fclose(flot);
    return 0;
}

/**
    \brief cette fonction permet de sauvegarder une partie à l'intérieur d'un fichier 
    \param nomFich nom du fichier à utiliser
    \param fM file de monstre à sauvegarder
    \param pM pile de monstre à sauvegarder 
*/
void sauvegardePartie(char *nomFich, File fM, PileM pM){
    FILE *flot;
    int nbPile = hauteur(pM), nbFile = longueurFileMonstres(fM), i,j;

    char chemin[60] = "fichierSauvegarde/";

    strcat(chemin,nomFich);

    flot = fopen(chemin, "w+");

    if(flot == NULL){
        printf("Pb ouverture fichier \n");
        return;
    }

    fprintf(flot, "%d\n", nbPile);


    for(i=0; i<nbPile; i++){
        fprintf(flot, "%s\n%d %d %d\n", sommet(pM).nom, sommet(pM).PV, sommet(pM).degat, sommet(pM).nbArmes);
        pM = pM->suiv;
    }

    fprintf(flot,"%d\n",nbFile);
    for(j = 0; j< nbFile; j++){
        fprintf(flot, "%s\n%d %d %d\n", teteFile(fM).nom, teteFile(fM).PV, teteFile(fM).degat, teteFile(fM).nbArmes);
        fM = fM->suiv;
    } 
    fclose(flot);
}

/*
int choixSauvegarde(void){
    char choix;

    printf("Voulez-vous sauvegarder votre progression (o : oui / n : non) : ");
    scanf("%c%*c",&choix);
    
    while(choix != 'o' && choix != 'O' && choix != 'n' && choix != 'N'){
        printf("Choix incorrect \n");
        printf("Voulez-vous sauvegarder (o : oui / n : non) : ");
        scanf("%c",&choix);
    }

    if(choix == 'o' || choix == 'O') return 1;
    else return 0;
}
*/

/**
    \brief Génère une partie aléatoire avec des monstres aléatoires tirés au sort dans un fichier.
*/
void generePartieAleatoire(void){
    File fM; 
    PileM pM;
    char nomFich[30];
    int tlog;
    Monstre *tabMonstres;

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    tabMonstres = chargementMonstres(&tlog);

    printf("Monstre qui vont être tirés aux sorts : \n");
    afficheTabMonstre(tabMonstres, tlog);

    pM = premierGroupe(tabMonstres, tlog);
    fM = deuxiemeGroupe(tabMonstres, tlog);

    affichPartie(fM, pM);

    printf("Saisir le nom de fichier où les sauvegarder : ");
    scanf("%s", nomFich);

    sauvegardePartie(nomFich, fM, pM);
    free(tabMonstres);

}

/**
    \brief Permet de saisir manuellement les données d'un monstre (nivrau et nom).
    \return Le monstre saisi par l'utilisateur.
*/
void saisiePartie(int *nbPile, int *nbFile){
    printf("Saisir le nombre de monstre du premier groupe (entre 1 et 10): ");     
    scanf("%d", nbPile);    
    while(*nbPile < 1 && *nbPile>10){
        printf("Saisie incorrect \n");
        printf("Saisir le nombre de monstre du premier groupe (entre 1 et 10): ");     
        scanf("%d", nbPile);    
    }

    printf("Saisir le nombre de monstre du second groupe (entre 1 et 10): "); 
    scanf("%d%*c", nbFile); 
    while(*nbFile < 1 && *nbFile>10){
        printf("Saisie incorrect \n");
        printf("Saisir le nombre de monstre du premier groupe (entre 1 et 10): ");     
        scanf("%d%*c", nbFile);    
    }   
}

/**
    \brief Permet de saisir manuellement les données d'un monstre (nivrau et nom).
    \return Le monstre saisi par l'utilisateur.
*/
Monstre saisirMonstre(void){
    Monstre m;
    int niv;

    printf("Saisir le nom du monstre : ");
    fgets(m.nom,30,stdin);
    m.nom[strlen(m.nom)-1]='\0';

    printf("Saisir le niveau du monstre (entre 1 et 3) : ");
    scanf("%d%*c", &niv);

    while(niv < 1 || niv > 3){
        printf("Niveau incorrect \n");
        printf("Saisir le niveau du monstre (entre 1 et 3) : ");
        scanf("%d%*c", &niv);
    }

    m = convertisseurNiveauEnStat(m, niv);

    return m;
}

/**
    \brief Crée une nouvelle partie définis par l'utilisateur.
*/
void creerPartie(void){
    File fM;
    PileM pM;
    int i, nbPile, nbFile;
    Monstre m;
    char nomFich[15];

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    saisiePartie(&nbPile, &nbFile);

    printf("Premier groupe : \n");
    for(i=0; i<nbPile; i++){
        m = saisirMonstre();
        pM =empiler(pM, m);
    }
    printf("Second groupe : \n");
    for(i=0; i<nbFile; i++){
        m = saisirMonstre();
        fM = adjQ(fM, m);
    }

    printf("Saisir le nom du fichier où les sauvegarder : ");
    scanf("%s%*c", nomFich);

    sauvegardePartie(nomFich, fM, pM);
}

/**
    \brief Cette fonction permet d'initialiser une parti et d'appeler la fonction deroulement partie pour la charger. 
    \param tabJoueur Tableau des joueurs.
    \param tlog Nombre de joueurs dans le tableau.
    \return La taille logique du tab. 
*/
int Partie(Joueur ** tabJoueur, int tlog){
    char nomJoueur[30], nomPartie[30];
    File fM;
    PileM pM;
    int pos, nbPoints, trouve, res;
    Joueur j;
    

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    printf("Saisir le nom d'une partie : ");
    scanf("%s%*c",nomPartie);

    res = chargePartie(nomPartie, &fM, &pM);
    if(res ==-1)return tlog;

    printf("Saisir votre nom de joueur : ");
    fgets(nomJoueur,30,stdin);

    nomJoueur[strlen(nomJoueur)-1]='\0';

    pos = rechercheDico(tabJoueur,  tlog,  nomJoueur, &trouve);

    if(trouve==0){
        printf("Le joueur %s n'a pas été trouvé, vous allez être ajouté à la liste des joueurs \n", nomJoueur);
        tlog = ajouterJoueur(tabJoueur, nomJoueur, tlog, pos);
    }
    j = *tabJoueur[pos];
    j=initialiserUnJoueur(j);


    nbPoints = deroulementPartie(j,pM, fM);

    tabJoueur[pos]->l = ajouter(tabJoueur[pos]->l, nbPoints);

    return tlog;
}


/**
    \brief Gère le déroulement complet d'une partie, incluant les combats.
    \param j Le joueur participant à la partie.
    \param pM Pile contenant le premier groupe de monstres.
    \param fM File contenant le second groupe de monstres.
    \return Le score total du joueur à la fin de la partie.
*/
int deroulementPartie(Joueur j, PileM pM, File fM) {
    int resCombat, nbPoints = 0;
    Monstre tmpMonstre;//monstre de à chaque combat

    if (estPileVide(pM)) return 0;

    affichScenario1erGrpe();

    while (!estPileVide(pM)) {
        tmpMonstre = sommet(pM);  
        affichArriveeNouvMonstre(j, tmpMonstre, nbPoints);
        resCombat = combat(&j, &tmpMonstre, &nbPoints);
        printf("\n");

        while (resCombat != 1) {
            if (resCombat == -1) return nbPoints;  // Le joueur est mort
            resCombat = combat(&j, &tmpMonstre, &nbPoints);
            printf("\n");
        }
        pM = depiler(pM);
    }

    if (estFileVide(fM)) return nbPoints;

    printf("\n");
    affichScenario2ndGrpe();

    while (!estFileVide(fM)) {
        tmpMonstre = teteFile(fM); 
        printf("\n");
        affichNouvMonstrePlaine(j, tmpMonstre, nbPoints);
        printf("\n");
        resCombat = combat(&j, &tmpMonstre, &nbPoints);
        printf("\n");

        fM->suiv->val = tmpMonstre;
        
        if (resCombat == -1)return nbPoints;  // Le joueur est mort
        else if(resCombat == 1)fM = supT(fM);
        else fM = fM->suiv;  
    }

    printf("Nombre de points acquis : %d\n", nbPoints);
    printf("\n\nBIEN JOUÉ...\n \n");

    
    return nbPoints;
}
