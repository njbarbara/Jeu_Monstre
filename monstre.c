#include "sae.h"


/*void ascciMonstre(char nom){

}*/

/*Fonctions du File de monstres*/

File fileVideMonstre(void){
    File fM;
    fM.t = NULL;
    fM.q = NULL;
    return fM;
}

File enfilerMonstre(File fM, Monstre monstre){
    MaillonM *maillonAEnfiler;
    maillonAEnfiler = (MaillonM*)malloc(sizeof(MaillonM));
    if(maillonAEnfiler == NULL){
        printf("Problème malloc !");
        exit(1);
    }
    maillonAEnfiler->m = monstre;
    maillonAEnfiler->suiv = NULL;
    if(estVide(fM)){
        fM.t = maillonAEnfiler;
        fM.q = maillonAEnfiler;
        return fM;
    }
    fM.q->suiv = maillonAEnfiler;
    fM.q = maillonAEnfiler;
    return fM;
}

File defilerMonstre(File fM){
    MaillonM * aux;
    if(fM.t == NULL){
        printf("Opération interdite, la file est vide !!");
        exit(1);
    }
    if(fM.t == fM.q){
        free(fM.t);
        return fileVideMonstre();
    }
    aux = fM.t;
    fM.t = fM.t->suiv;
    free(aux);
    return fM;
}

int estVide(File fM){
    return fM.t == NULL && fM.q == NULL;
}

Monstre tete(File fM){
    if(estVide(fM)){
        printf("Opération interdite, la file est vide !!");
        exit(1);
    }
    return fM.t->m;
}

int longueurFileMonstres(File fM){
    int l=0;
    while(fM.t != NULL){
        l += 1;
        fM.t = fM.t->suiv;
    }
    return l;
}


void affichageMonstre(Monstre monstreAafficher){
    printf("Nom : %s \t PV : %d \t Dégat : %d \t Nb Armes : %d\n", monstreAafficher.nom, monstreAafficher.PV, monstreAafficher.degat, monstreAafficher.nbArmes);
}


void affichageFileMonstres(File fM){
    while(fM.t != NULL){
        affichageMonstre(fM.t->m);
        fM.t = fM.t->suiv;
    }
    printf("\n");
}

/*Pile Monstre*/
/*
Booleen Pilevide(PileM p){
    if(p == NULL){
        return FALSE;
    }
    else{
        return TRUE;
    }

}

PileM pileVide(void){   
    return NULL;
}

PileM empiler(PileM p, Monstre val){
    MaillonM *m;
    m =(MaillonM *)malloc(sizeof(MaillonM));
    if(m == NULL){
        printf("Pb allocation mémoire");
        exit(1);
    }
    m->monstre=val;
    m->suiv=p;//Insertion en tête
    return m;
}

PileM depiler(PileM p){ 
    MaillonM *m;

    if(vide(p)){
        printf("Opération interdite");
        exit(1);        
    }
    m = p;
    p=p->suiv;
    free(m);
    return p;
}

int sommet(PileM p){
    return p->monstre;
}

int hauteur(PileM p){
    int cpt=0;
    MaillonM * ptm = p;
    while (ptm != NULL){
        cpt++;
        ptm = ptm->suiv;
    } 
    return cpt;
}
*/
/*Fonctions des monstres*/


int decalageAGauche(Monstre **tab, int indice, int tlog){
    int i;
    for(i=indice;i<tlog-1;i++)
        tab[i] = tab[i+1];
    return tlog - 1;
}

void afficheTabMonstre(Monstre **tab, int tlog){
    int i;
    for(i=0;i<tlog;i++)
        affichageMonstre(*tab[i]);
}



Monstre* lireMonstre(FILE *flot){
    Monstre *m;
    m = (Monstre*)malloc(sizeof(Monstre));
    if(m == NULL){
        printf("Probléme malloc !");
        exit(1);
    }
    fgets(m->nom, 30, flot);
    m->nom[strlen(m->nom)-1] = '\0';
    fscanf(flot, "%d%d", &m->PV, &m->degat);
    m->nbArmes = 0;
    return m;
}

int chargementMonstres(Monstre **tabMonstres){
    int k=0;
    FILE *flot;
    Monstre *monstreAAjouter;
    flot = fopen("fichierSauvegarde/monstres.txt", "r");
    if(flot == NULL){
        printf("Probléme de chargement !");
        exit(1);
    }
    monstreAAjouter = lireMonstre(flot);
    while(!feof(flot)){
        tabMonstres[k] = monstreAAjouter;
        monstreAAjouter = lireMonstre(flot);
        k += 1;
    }
    return k;
}

Monstre randomMonstre(File *fM){
    int rep, i;
    time_t seconds;
    Monstre monstreTour;
    seconds = time(NULL);
    if(estVide(*fM)){
        printf("La file est vide !");
        exit(1);
    }
    rep = (rand()+seconds)%longueurFileMonstres(*fM);
    for(i=1;i<=rep;i++){
        monstreTour = tete(*fM);
        *fM = defilerMonstre(*fM);
        if(i != rep) *fM = enfilerMonstre(*fM, monstreTour);
    }
    return monstreTour;
}

File deuxiemeGroupe(File fM){
    int i;
    Monstre monstrePartie;
    File fG2;
    fG2 = fileVideMonstre();
    for(i=3;i<=5;i++){
        monstrePartie = randomMonstre(&fM);
        monstrePartie.nbArmes = i;
        fG2 = enfilerMonstre(fM, monstrePartie);
    }
    return fG2;
}