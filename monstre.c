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
    maillonAEnfiler.m = monstre;
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
        exti(1);
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
    printf("Nom : %s \t PV : %d \t Dégat : %d \t Nb Armes : %d\n", fM.t->m.nom, fM.t->m.PV, fM.t->m.degat, fM.t->m.nbArmes);
}


void affichageFileMonstres(File fM){
    while(fM.t != NULL){
        affichageMonstre(fM.t->m);
    }
    pritnf("\n");
}


/*Fonctions des monstres*/

Monstre lireMonstre(FILE *flot){
    Monstre m;
    fgets(m.nom, 30, flot);
    m.nom[strlen(m.nom)-1] = '\0';
    fscanf("%d%d", &m.PV, &m.degat);
    return m;
}



File chargementMonstres(void){
    FILE *flot;
    File fM;
    Monstre monstreAEnfiler;
    fM = fileVideMonstre();
    flot = fopen("monstres.txt", "r");
    if(flot == NULL){
        printf("Probléme de chargement !");
        exit(1);
    }
    monstreAEnfiler = lireMonstre(flot);
    while(!feof(flot)){
        fM = enfilerMonstre(fM, monstreAEnfiler);
        monstreAEnfiler = lireMonstre(flot);
    }
    return fM;
}

Monstre randomMonstre(File *fM){
    int rep, i;
    Monstre monstreTour;
    rep = 5/*FAIRE LE CALCUL RANDOM*/;
    for(i=1;i<=rep;i++){
        monstreTour = tete(*fM);
        *fM = defilerMonstre(*fM);
        if(i == rep) return monstreTour;
        *fM = enfilerMonstre(*fM, monstreTour);
    }
}


Pile premierGroupe(File *fM){

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