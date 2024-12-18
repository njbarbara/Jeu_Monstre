#include "sae.h"

Joueur lireJoueurScores(FILE *flot){
    Joueur j;
    int nb, i, scoresJ;

    j.l= ensemble();

    fscanf(flot, "%s%d", j.pseudo, &nb);

    for(i=0; i<nb;i++){
        fscanf(flot,"%d", &scoresJ);
        j.l = ajouter(j.l,scoresJ);
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

    nouvJ = lireJoueurScores(flot);

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
        nouvJ = lireJoueurScores(flot);
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
        fprintf(flot, "%s %d\n",tabJoueur[i]->pseudo, longueur(tabJoueur[i]->l));
        sauvegardeListeScore(flot, tabJoueur[i]->l);
    }
    fclose(flot);
}

int plusGrandScore(Joueur * tabJoueur[], int tlog){
    int i, pg=0;

    for(i=0; i < tlog; i++)if(tabJoueur[i]->l->score > tabJoueur[pg]->l->score) pg = i;

    return pg;
}

void echange(Joueur * tabJoueur[], int i, int j){
    Joueur * tmp;

    tmp = tabJoueur[i];
    tabJoueur[i]= tabJoueur[j];
    tabJoueur[j]=tmp;
}

void triEnchangeMeilleurScore(Joueur * tabJoueur[], int tlog){
    int I;

    while(tlog > 1){
        I = plusGrandScore(tabJoueur, tlog);
        echange(tabJoueur, tlog-1,I);
        tlog--;
    }
}
/*
int ajouterJoueur(Joueur * tabJoueur[], int tlog){
    printf("Saisir le pseudo du joueur à créer : ");

}


int recherche(char nom[], Joueur * tabJoueur[], int tlog){
    int i;
    for(i=0; i< tlog; i++ ) if(strcmp(nom, tabJoueur[i]->pseudo)==0) return i;
}
*/

int rechercheDico(Joueur * tabJoueur[], int tlog, char * nom, int * trouve){
    int m, inf =0, sup = tlog-1;

    while(inf<=sup){
        m = (inf + sup)/2;

        if(strcmp(tabJoueur[m]->pseudo, nom)>0) sup = m-1;
        else if (strcmp(tabJoueur[m]->pseudo, nom)<0) inf = m+1;
        else{
            *trouve =1;
            return m;
        }

    }
    *trouve = 0;
    return inf; 
}


// JE VAIS LA FAIRE APRÈS
void triDico(Joueur * tabJoueur[], int tlog){

}


//void ajoutNouvJoueur

