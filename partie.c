#include "sae.h"

Pile pileVide(void){
    return NULL;
}

//Faire une recherche dicho à la place
void chargePartie(Joueur * tabJoueur[],  char *nomFich, File fM, Pile pM, int tlog){
    FILE *flot;

    flot = fopen("fichierSauvegarde/", "r");



    while(!feof(flot)){
        for(int i = 0; i < tlog; i++){

        }
        
    }
}

void sauvegardePartie(){

}