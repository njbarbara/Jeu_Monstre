#include "sae.h"


Joueur lireJoueur(File *flot){
    Joueur j;
    ListeScore l;
    int nb,i;

    l= ensemble();

    fgets(j.pseudo, sizeof(j.pseudo), flot);
    fscanf(flot, "%d", nb);

    for(i=0; i<nb;i++) fscanf();

    return j;
}

ListeScore chargement(char *nomFich){
    FILE * flot;
    int valScore;

    flot = feof();
    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }

    fscanf(flot,"%d",);

    while(!feof(flot)){

    }
    fclose(flot);
    return l;

}

