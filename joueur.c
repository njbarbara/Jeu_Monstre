#include "sae.h"

Joueur lireJoueur(FILE *flot){
    Joueur j;
    ListeScore l;
    int nb, i, scoresJ;

    l= ensemble();

    fscanf(flot, "%s%d", j.pseudo, &nb);

    for(i=0; i<nb;i++){
        fscanf(flot,"%d", &scoresJ);
        l = ajouter(l,scoresJ);
    } 

    return j;
}

int chargement(Joueur * tabJoueur[], char *nomFich, int tmax){
    FILE * flot;
    int tlog=0;
    Joueur nouvJ;

    flot = fopen(nomFich, "r");

    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }

    nouvJ = lireJoueur(flot);

    while(!feof(flot)){
        if(tlog == tmax){
            printf("Tableau plein ");
            fclose(flot);
            return tlog;
        }

        tabJoueur[tlog] = (Joueur *)malloc(sizeof(Joueur));
        if(tabJoueur[tlog]==NULL){
            printf("Problème malloc \n");
            fclose(flot);
            return tlog;
        }
        *tabJoueur[tlog] = nouvJ;
        tlog++;
        nouvJ = lireJoueur(flot);
    }

    fclose(flot);
    return tlog;
}

void sauvegardeScoreJoueur(Joueur * tabJoueur[], char *nomFich, int tlog){
    FILE * flot;
    int i;

    flot = fopen(nomFich, "w");

    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }

    for(i=0; i<tlog; i++){
        fprintf(flot, "%s %d",tabJoueur[i]->pseudo, longueur(tabJoueur[i]->l));
        sauvegardeListeScore(flot, tabJoueur[i]->l);
    }
    fclose(flot);
    free(tabJoueur);
}

//void ajoutNouvJoueur

