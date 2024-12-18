#include "sae.h"

Pile pileVide(void){
    return NULL;
}

//Faire une recherche dicho à la place
void chargePartie(Joueur * tabJoueur[],  char *nomFich, File fM, PileM pM, int tlog){
    FILE *flot;
    Joueur j;
    int nbPile, nbFile;

    flot = fopen(nomFich, "r");

    recherche(tabJoueur, tlog, j.nom, trouve);

    fscanf(flot, "%s%d%d%d%d", j.nom);

    pos = recherche(tabJoueur, tlog, j.nom, trouve);

    
    while(!feof(flot)){
        for(int i = 0; i < nbPile; i++) enfilerMonstre(fM, lireMonstre(flot));
        fscanf(flot, "%d", &nbFile);
        for(int i = 0; i < nbFile; i++) empilerMonstre(pM, lireMonstre(flot));
    }
}



void sauvegardePartie(){

}
