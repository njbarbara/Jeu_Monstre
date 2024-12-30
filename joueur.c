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

Joueur * tabJoueur chargement(int *tlog, char *nomFich){
    FILE * flot;
    Joueur * tabJoueur;

    flot = fopen(nomFich, "r");

    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }
    fscanf(flot,"%d",tlog);

    tabJoueur = (Joueur *)malloc(*tlog*sizeof(Joueur));
    if(tabJoueur==NULL){
        printf("Pb malloc \n");
        exit(1);
    }
    for(i=0; i<*tlog;i++)tabJoueur[i]=lireJoueurScores(flot)

    fclose(flot);
    return tabJoueur;
}

void sauvegardeScoreJoueur(Joueur * tabJoueur, char *nomFich, int tlog){
    FILE * flot;
    int i;

    flot = fopen(nomFich, "w");

    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }

    fprintf(flot,"%d\n",tlog);
    for(i=0; i<tlog; i++){
        fprintf(flot, "%s %d\n",tabJoueur[i].pseudo, longueur(tabJoueur[i].l));
        sauvegardeListeScore(flot, tabJoueur[i].l);
    }
    fclose(flot);
}

int plusGrandScore(Joueur * tabJoueur, int tlog){
    int i, pg=0;

    for(i=0; i < tlog; i++)if(tabJoueur[i].l->score > tabJoueur[pg].l->score) pg = i;

    return pg;
}

void echange(Joueur * tabJoueur, int i, int j){
    Joueur tmp;

    tmp = tabJoueur[i];
    tabJoueur[i]= tabJoueur[j];
    tabJoueur[j]=tmp;
}

void triEnchangeMeilleurScore(Joueur * tabJoueur, int tlog){
    int I;

    while(tlog > 1){
        I = plusGrandScore(tabJoueur, tlog);
        echange(tabJoueur, tlog-1,I);
        tlog--;
    }
}


Joueur initialiserUnJouer(Joueur j){
    j.nbArmes=3;
    j.PV=20;
    j.degat = 1;

    if(!estListeVide(j.l)){//système de niveau du joueur
        if(j.l>=50 && j.l<100){
            j.PV+=10;
            j.degat+=1;
        }
        else if(j.l>=100 && j.l<150 ){
            j.PV+=20;
            j.degat+=2;
        }
        else if(j.l >=150){
            j.PV+=30;
            j.degat+=3;
        }
    }

    return j;
}

int ajouterJoueur(Joueur tabJoueur, Joueur j, int tlog){
    Joueur * tabJoueur2;

    tabJoueur2 = (Joueur *)realloc(tabJoueur, tlog)
    tabJoueur[tlog]=(Joueur *)
    
}

int recherche(char nom[], Joueur tabJoueur, int tlog){
    int i;
    for(i=0; i< tlog; i++ ) if(strcmp(nom, tabJoueur[i].pseudo)==0) return i;
    return -1;
}


int rechercheDico(Joueur tabJoueur, int tlog, char * nom, int * trouve){
    int m, inf =0, sup = tlog-1;

    while(inf<=sup){
        m = (inf + sup)/2;

        if(strcmp(tabJoueur[m].pseudo, nom)>0) sup = m-1;
        else if (strcmp(tabJoueur[m].pseudo, nom)<0) inf = m+1;
        else{
            *trouve =1;
            return m;
        }

    }
    *trouve = 0;
    return inf; 
}


// JE VAIS LA FAIRE APRÈS

//void ajoutNouvJoueur

