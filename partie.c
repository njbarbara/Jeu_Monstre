#include "sae.h"

/*FICHIER DES FONCTIONS LIÉES AUX FONCTIONNEMENTS DU JEU */



/**
    \brief cette fonction permet de charger une partie à partir d'un nom fichier passer en paramètre
    \param nomFich nom du fichier à utiliser
    \param fM file de monstre à charger
    \param pM pile de monstre à charger 
*/
void chargePartie(char *nomFich, File * fM, PileM * pM){
    FILE *flot;
    int nbPile, nbFile, i;
    char chemin[60] = "fichierSauvegarde/";

    strcat(chemin,nomFich);

    flot = fopen(chemin, "r");
    
    fscanf(flot,"%d",&nbPile);
    for( i = 0; i < nbPile; i++) empiler(*pM, lireMonstre(flot));
    fscanf(flot, "%d", &nbFile);
    for( i = 0; i < nbFile; i++) adjQ(*fM, lireMonstre(flot)); 
}


/**
    \brief cette fonction permet de sauvegarder une partie à l'intérieur d'un fichier 
    \param nomFich nom du fichier à utiliser
    \param fM file de monstre à sauvegarder
    \param pM pile de monstre à sauvegarder 
*/
void sauvegardePartie(char *nomFich, File fM, PileM pM){
    FILE *flot;
    int nbPile = hauteur(pM), nbFile = longueurFileMonstres(fM), i;

    char chemin[60] = "fichierSauvegarde/";

    strcat(chemin,nomFich);

    flot = fopen(chemin, "w+");

    if(flot == NULL){
        printf("Pb ouverture fichier \n");
        return ;
    }

    fprintf(flot, "%d\n", nbPile);

    for(i=0; i<nbPile; i++){
        fprintf(flot, "%s%d%d%d", pM->val.nom, pM->val.PV, pM->val.degat, pM->val.nbArmes);
        depiler(pM);
    }

    fprintf(flot,"%d\n",nbFile);

    for(i = 0; i< nbFile; i++){
        fprintf(flot, "%s%d%d%d", fM->suiv->val.nom, fM->suiv->val.PV, fM->suiv->val.degat, fM->suiv->val.nbArmes);
        supT(fM);
    } 
}

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

void generePartieAleatoire(Monstre **tabMonstres, int tlog){
    int choix;
    File fM; 
    Pile pM;
    char nomFich[30];

    pM = premierGroupe( tabMonstres, tlog);
    fM = deuxiemeGroupe( tabMonstres, tlog);

    printf("Saisir le nom de fichier où les sauvegarder : ");
    scanf("%s", nomFich);

    SauvegardePartie(nomFich, fM, pM);
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
    char nom[30];
    Monstre m;
    int niv;

    printf("Saisir le nom du monstre : ");
    fgets(m.nom,30,stdin);
    m.nom[strlen(m.nom)-1]='\0';

    printf("Saisir le niveau du monstre (entre 1 et 3) : ");
    scanf("%d", &niv);

    while(niv < 1 && niv > 3){
        printf("Niveau incorrect \n");
        printf("Saisir le niveau du monstre (entre 1 et 3) : ");
        scanf("%d", &niv);
    }

    m = convertisseurNiveauEnStat(m, niv);

    return m;
}

void creerPartie(void){
    File fM;
    Pile pM;
    int i, nbPile, nbFile;
    Monstre m;
    char nomFich[15];

    saisiePartie(&nbPile, &nbFile);

    for(i=0; i<nbPile; i++){
        m = saisirMonstre(tabMonstres, tlog);
        pM =empiler(pM, m);
    }
    for(i=0; i<nbFile; i++){
        m = saisirMonstre(tabMonstres, tlog);
        fM = adjQ(fM, m);
    }

    printf("Saisir le nom du fichier où les sauvegarder : ");
    scanf("%s", nomFich);

    sauvegardePartie(nomFich, fM, pM);
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
    int pos, nbPoints;

    printf("Saisir votre nom de joueur : \n");
    fgets(nomJoueur,30,stdin);

    printf("Saisir une partie : ");
    fgets(nomPartie,30,stdin);

    nomJoueur[strlen(nomJoueur)-1]='\0';
    nomPartie[strlen(nomPartie)-1]='\0';

    pos = rechercheDico(tabJoueur,  tlog,  nom, &trouve)


    if(trouve==0){
        pos = tlog;
        tabJoueur = ajouterJoueur(tabJoueur, nomJoueur, &tlog);
    } 
    tabJoueur[pos]=initialiserUnJoueur(tabJoueur[pos]);

    chargePartie(nomPartie, &fM, &pM);

    nbPoints = deroulementPartie(tabJoueur[pos], pM, fM);

    tabJoueur[pos].l = ajouter(tabJoueur[pos].l, nbPoints);

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