#include "sae.h"

Pile pileVide(void){
    return NULL;
}

//Faire une recherche dicho à la place
void chargePartie(Joueur * tabJoueur[],  char *nomFich, File fM, PileM pM, int tlog){
    FILE *flot;
    Joueur j;
    int nbPile=0, nbFile;

    flot = fopen("fichierSauvegarde/", "r");

    int recherche(tabJoueur, tlog, nom, trouve);

    fscanf(flot, "%s%d%d%d", j.nom);

    while(!feof(flot)){
        for(int i = 0; i < tlog; i++) enfilerMonstre(fM, lireMonstre(flot));
        
    }
}



void sauvegardePartie(){

}
*/