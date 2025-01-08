#include "sae.h"

/*FICHIER DES FONCTIONNALITÉS DES JOUEURS*/

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

Joueur * chargementJoueurs(int *tlog, char *nomFich){
    FILE * flot;
    Joueur * tabJoueur;
    int i;

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
    for(i=0; i<*tlog;i++)tabJoueur[i]=lireJoueurScores(flot);

    fclose(flot);
    return tabJoueur;
}

void sauvegardeJoueur(Joueur * tabJoueur, char *nomFich, int tlog){
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
    free(tabJoueur);
}

//Fonctions de trie

int plusGrandScore(Joueur * tabJoueur, int tlog){
    int i, pg=0;

    for(i=0; i < tlog; i++)if(tabJoueur[i].l->score > tabJoueur[pg].l->score) pg = i;

    return pg;
}

int * triEnchangeMeilleurScore(Joueur * tabJoueur, int tlog){
    int pos, *tabJoueurPos, i=0;

    tabJoueurPos = (Joueur *)malloc(sizeof(Joueur)*tlog);

    while(tlog > 1){
        pos = plusGrandScore(tabJoueur, tlog);
        tabJoueurPos[i]= pos;
        tlog--;
        i++;
    }
}

void copier(Joueur * tabJoueur, int i, int j, Joueur * R){
    int k = 0;

    while(i<j){
        R[k]=T[i];
        i++;
        k++;
    }
}

void fusion(Joueur * R, int n, Joueur * S, int m, Joueur * tabJoueur){
    int i = 0, j=0, k =0;

    while(i<n && j <m){
        if(strcmp(R[i].nom, S[j].nom)<0){
            tabJoueur[k]=R[i];
            i+=1;
            k+=1;
        }
        else{
            tabJoueur[k]=S[j];
            j+=1;
            k+=1;
        }
    }
}

void triDicho(Joueur * tabJoueur, int tlog){
    Joueur * R, *S;

    R = (Joueur *)malloc((tlog/2));
    S = (Joueur *)malloc((tlog - (tlog / 2)));

    if(R==NULL || S == NULL){
        printf("Pb malloc \n");
        return;
    }

    copier(tabJoueur,0,tlog/2, R);
    copier(tabJoueur,tlog/2,tlog, S);

    triDicho(R,  tlog/2);
    triDicho(S, (tlog - tlog/2));

    fusion(R,  tlog/2, S, (tlog - tlog/2), T);

    free(R);
    free(S);
}

Joueur initialiserUnJoueur(Joueur j){
    j.nbArmes=3;

    if(!estListeVide(j.l)){//système de niveau du joueur
        if(j.l->score >=50 && j.l->score<100){
            j.PV+=30;
            j.degat+=2;
        }
        else if(j.l->score>=100 && j.l->score<150 ){
            j.PV+=40;
            j.degat+=3;
        }
        else if(j.l->score>=150){
            j.PV+=50;
            j.degat+=4;
        }
    }
    else{
        j.PV=20;
        j.degat = 1;
    }
    return j;
}

Joueur * ajouterJoueur(Joueur * tabJoueur, char nom[], int * tlog){
    Joueur nouvJ;
    Joueur * tabJoueur2;

    strcpy(nouvJ.pseudo, nom);

    tabJoueur2 = (Joueur *)realloc(tabJoueur, (*tlog+1)*sizeof(Joueur));
    if(tabJoueur2==NULL)return NULL;
    else tabJoueur = tabJoueur2;
    tabJoueur[*tlog]=nouvJ;

    (*tlog)++;

    return tabJoueur; 
}

int rechercheNomJoueur(char nom[], Joueur * tabJoueur, int tlog){
    int i;
    for(i=0; i< tlog; i++ ) if(strcmp(nom, tabJoueur[i].pseudo)==0) return i;
    return -1;
}


int rechercheDico(Joueur * tabJoueur, int tlog, char nom[], int * trouve){
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


