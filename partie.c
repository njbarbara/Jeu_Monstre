#include "sae.h"

/*FICHIER DES FONCTIONS LIÉES AUX FONCTIONNEMENTS DU JEU */


/**
    \brief cette fonction permet de charger une partie à partir d'un nom fichier passer en paramètre
    \param nomFich nom du fichier à utiliser
    \param fM file de monstre à charger
    \param pM pile de monstre à charger 
*/
void chargePartie(char *nomFich, File *fM, PileM *pM){
    FILE *flot;
    int nbPile, nbFile, i;
    char chemin[60] = "fichierSauvegarde/";
    Monstre m;

    strcat(chemin,nomFich);

    flot = fopen(chemin, "r");

    if(flot==NULL){
        printf("Pb ouverture fichier \n");
        return;
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
}

/**
    \brief cette fonction permet de sauvegarder une partie à l'intérieur d'un fichier 
    \param nomFich nom du fichier à utiliser
    \param fM file de monstre à sauvegarder
    \param pM pile de monstre à sauvegarder 
*/
void sauvegardePartie(char *nomFich, File *fM, PileM *pM){
    FILE *flot;
    int nbPile = hauteur(*pM), nbFile = longueurFileMonstres(*fM), i,j;

    char chemin[60] = "fichierSauvegarde/";

    strcat(chemin,nomFich);

    flot = fopen(chemin, "w+");

    if(flot == NULL){
        printf("Pb ouverture fichier \n");
        return;
    }

    fprintf(flot, "%d\n", nbPile);
    for(i=0; i<nbPile; i++){
        fprintf(flot, "%s\n%d %d %d\n", sommet(*pM).nom, sommet(*pM).PV, sommet(*pM).degat, sommet(*pM).nbArmes);
        depiler(*pM);
    }

    fprintf(flot,"%d\n",nbFile);
    for(j = 0; j< nbFile; j++){
        fprintf(flot, "%s\n%d %d %d\n", teteFile(*fM).nom, teteFile(*fM).PV, teteFile(*fM).degat, teteFile(*fM).nbArmes);
        supT(*fM);
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
void generePartieAleatoire(void){
    File fM; 
    PileM pM;
    char nomFich[30];
    int tlog;
    Monstre *tabMonstres[6];

    tlog = chargementMonstres(tabMonstres);

    printf("Monstre qui vont être tirés aux sorts : \n");
    afficheTabMonstre(tabMonstres, tlog);

    pM = premierGroupe(tabMonstres, tlog);
    fM = deuxiemeGroupe(tabMonstres, tlog);

    affichPartie(fM, pM);

    printf("Saisir le nom de fichier où les sauvegarder : ");
    scanf("%s", nomFich);

    sauvegardePartie(nomFich, &fM, &pM);
}

void saisiePartie(int *nbPile, int *nbFile){
    printf("Saisir le nombre de monstre du premier groupe (entre 1 et 10): \n");     
    scanf("%d", nbPile);    
    while(*nbPile < 1 && *nbPile>10){
        printf("Saisie incorrect \n");
        printf("Saisir le nombre de monstre du premier groupe (entre 1 et 10): \n");     
        scanf("%d", nbPile);    
    }

    printf("Saisir le nombre de monstre du second groupe (entre 1 et 10): \n"); 
    scanf("%d", nbFile); 
    while(*nbFile < 1 && *nbFile>10){
        printf("Saisie incorrect \n");
        printf("Saisir le nombre de monstre du premier groupe (entre 1 et 10): \n");     
        scanf("%d", nbFile);    
    }   
}

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

void creerPartie(void){
    File fM;
    PileM pM;
    int i, nbPile, nbFile;
    Monstre m;
    char nomFich[15];

    saisiePartie(&nbPile, &nbFile);

    for(i=0; i<nbPile; i++){
        m = saisirMonstre();
        pM =empiler(pM, m);
    }
    for(i=0; i<nbFile; i++){
        m = saisirMonstre();
        fM = adjQ(fM, m);
    }

    printf("Saisir le nom du fichier où les sauvegarder : ");
    scanf("%s%*c", nomFich);

    sauvegardePartie(nomFich, &fM, &pM);
}

/**
    \brief 
    \param
    \param 
*/
int Partie(Joueur ** tabJoueur, int tlog){
    char nomJoueur[30], nomPartie[30];
    File fM;
    PileM pM;
    int pos, nbPoints, trouve;

    fM = CreerfileVideMonstre();
    pM = CreerPileVide();

    printf("Saisir le nom d'une partie : ");
    scanf("%s%*c",nomPartie);

    printf("Saisir votre nom de joueur : ");
    fgets(nomJoueur,30,stdin);

    nomJoueur[strlen(nomJoueur)-1]='\0';

    pos = rechercheDico(tabJoueur,  tlog,  nomJoueur, &trouve);

    if(trouve==0)tlog = ajouterJoueur(tabJoueur, nomJoueur, tlog, pos);
    *tabJoueur[pos]=initialiserUnJoueur(*tabJoueur[pos]);

    chargePartie(nomPartie, &fM, &pM);

    nbPoints = deroulementPartie(*tabJoueur[pos],pM, fM);

    tabJoueur[pos]->l = ajouter(tabJoueur[pos]->l, nbPoints);

    return tlog;
}

int deroulementPartie(Joueur j, PileM pM, File fM){
    int resCombat, nbPoints=0;
    
    if(estPileVide(pM))return 0;

    affichScenario1erGrpe();

    while(!estPileVide(pM)){
        affichArriveeNouvMonstre( j, sommet(pM), nbPoints);
        resCombat = combat(j, sommet(pM), &nbPoints);

        while(resCombat != 1){
            if(resCombat == -1)return nbPoints;//le joueur est mort
            resCombat = combat(j, sommet(pM), &nbPoints);
        } 
        depiler(pM);
    }

    if(estFileVide(fM))return nbPoints;

    affichScenario2ndGrpe();
    
    while(!estFileVide(fM)){
        affichNouvMonstrePlaine(j, teteFile(fM), nbPoints);
        resCombat = combat(j, teteFile(pM), &nbPoints);
        if(resCombat==1) supT(fM);
        else if(resCombat == -1)return nbPoints;//le joueur est mort
        pM = pM->suiv;
    }
    printf("BIEN JOUÉ...\n");
    return nbPoints;
}