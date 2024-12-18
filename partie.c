#include "sae.h"


//Faire une recherche dicho à la place
void chargePartie(Joueur * tabJoueur[],  char *nomFich, File fM, PileM pM, int tlog){
    FILE *flot;
    Joueur j;
    int nbPile, nbFile, trouve, pos;

    flot = fopen(nomFich, "r");

    fscanf(flot, "%s%d%d%d%d", j.pseudo, &j.PV, &j.degat, &j.nbParties, &nbPile);

    pos = rechercheDico(tabJoueur, tlog, j.pseudo, &trouve);

    if(trouve == 0){
        printf("Joueur Inconnu(e) \n");
        return;
    }

    *tabJoueur[pos] = j;

    for(int i = 0; i < nbPile; i++) enfilerMonstre(fM, lireMonstre(flot));
    fscanf(flot, "%d", &nbFile);
    for(int i = 0; i < nbFile; i++) empiler(pM, lireMonstre(flot));
}

void sauvegardePartie(Joueur * tabJoueur[],  char *nomFich, File fM, PileM pM, int tlog){

}
