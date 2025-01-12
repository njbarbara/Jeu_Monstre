#include "sae.h"

/*FICHIER DES FONCTIONNALITÉS DES JOUEURS*/
Joueur lireJoueurScores(FILE *flot){
    Joueur j;
    int nb, i, scoresJ;

    j.l= creerListeVide();

    fgets(j.pseudo,30,flot);
    j.pseudo[strlen(j.pseudo)-1]='\0';

    fscanf(flot, "%d%*c",&nb);

    for(i=0; i<nb;i++){
        fscanf(flot,"%d%*c", &scoresJ);
        j.l = ajouter(j.l,scoresJ);
    } 

    return j;
}

void decalageADroite(Joueur ** tabJoueur, int tlog, int pos){
    int i;

    for(i=tlog; i>pos; i--)tabJoueur[i]=tabJoueur[i-1];
}

int chargementJoueurs(Joueur * tabJoueur[], int tmax){
    FILE * flot;
    Joueur j;
    int tlog=0, pos, trouve;

    flot = fopen("fichierSauvegarde/Joueurs.txt", "r");

    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }

    j = lireJoueurScores(flot);

    while(!feof(flot)){
        if(tlog == tmax){
            printf("Tableau plein \n");
            fclose(flot);
            return tlog;
        }

        tabJoueur[tlog] = (Joueur *)malloc(sizeof(Joueur));

        if(tabJoueur[tlog]==NULL){
            printf("Pb malloc \n");
            exit(1);
        }
        
        pos = rechercheDico(tabJoueur, tlog, j.pseudo, &trouve);

        if(trouve == 0) {
            decalageADroite(tabJoueur, tlog, pos);
            tabJoueur[pos] = malloc(sizeof(Joueur));
            if (tabJoueur[pos] == NULL) {
                printf("Pb malloc \n");
                exit(1);
            }
            *tabJoueur[pos] = j;
            tlog++;
        } else{
            printf("Erreur, Joueur déjà présent : %s\n", j.pseudo);
        }

        j = lireJoueurScores(flot);
    }
    fclose(flot);
    return tlog;
}

void libereTabJoueur(Joueur ** tabJoueur, int tlog){
    int i;

    for(i=0; i<tlog; i++)free(tabJoueur[i]);
}

void sauvegardeJoueur(Joueur ** tabJoueur, int tlog){
    FILE * flot;
    int i;

    flot = fopen("fichierSauvegarde/Joueurs.txt", "w");

    if(flot==NULL){
        printf("Pb ouverture de fichier \n");
        exit(1);
    }

    for(i=0; i<tlog; i++){
        fprintf(flot, "%s\n%d\n",tabJoueur[i]->pseudo, longueur(tabJoueur[i]->l));
        sauvegardeListeScore(flot, tabJoueur[i]->l);
    }
    fclose(flot);

}

//Fonctions de trie

int plusGrandScore(Joueur * tabJoueur, int tlog){
    int i, pg=0;

    for(i=0; i < tlog; i++)if(tabJoueur[i].l->score < tabJoueur[pg].l->score) pg = i;

    return pg;
}

void echange(Joueur * tabJoueur, int I, int i){
    Joueur j;

    j=tabJoueur[i];
    tabJoueur[i]=tabJoueur[I];
    tabJoueur[I]=j;
}

void triEnchangeMeilleurScore(Joueur * tabJoueur, int tlog){
    int pos;

    while(tlog > 1){
        pos = plusGrandScore(tabJoueur, tlog);
        echange(tabJoueur, pos, tlog-1);
        tlog--;
    }
}

/*
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
*/

Joueur initialiserUnJoueur(Joueur j){
    j.nbArmes=3;

    if(!estListeVide(j.l)){//système de niveau du joueur
        if(j.l->score >=50 && j.l->score<100){
            j.PV=30;
            j.degat=2;
        }
        else if(j.l->score>=100 && j.l->score<300 ){
            j.PV=40;
            j.degat=3;
        }
        else if(j.l->score>=300){
            j.PV=50;
            j.degat=4;
        }
    }
    else{
        j.PV=20;
        j.degat = 1;
    }


    return j;
}


int ajouterJoueur(Joueur **tabJoueur, char nom[], int tlog, int pos) {
    Joueur *nouvJ;
    nouvJ = (Joueur *)malloc(sizeof(Joueur));
    if (nouvJ == NULL) {
        printf("Pb malloc \n");
        exit(1);
    }

    strcpy(nouvJ->pseudo, nom);
    nouvJ->l = creerListeVide();

    decalageADroite(tabJoueur, tlog, pos);

    tabJoueur[pos] = nouvJ;

    tlog++;
    return tlog;
}

int rechercheNomJoueur(char nom[], Joueur ** tabJoueur, int tlog){
    int i;
    for(i=0; i< tlog; i++ ){
        if(strcmp(nom, tabJoueur[i]->pseudo)==0) return i;
        else if(strcmp(nom, tabJoueur[i]->pseudo)<0)return -1;
    } 
    return -1;
}


int rechercheDico(Joueur ** tabJoueur, int tlog, char nom[], int * trouve){
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


