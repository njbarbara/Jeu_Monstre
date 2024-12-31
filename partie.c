#include "sae.h"


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

void creerPartie(){

}

int Partie(Joueur * tabJoueur, int tlog){
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

    pos = rechercheNomJoueur(nomJoueur, tabJoueur, tlog);

    if(pos==-1){
        pos = tlog;
        tabJoueur = ajouterJoueur(tabJoueur, nomJoueur, &tlog);
    } 
    tabJoueur[pos]=initialiserUnJoueur(tabJoueur[pos]);

    chargePartie(nomPartie, &fM, &pM);

    nbPoints = deroulementPartie(tabJoueur[pos], pM, fM);

    tabJoueur[pos].l = ajouter(tabJoueur[pos].l, nbPoints);

    return tlog;
}

//Il faut une file circulaire 
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