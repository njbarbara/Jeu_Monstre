#include "sae.h"


/*void ascciMonstre(char nom){

}*/

File fileVideMonstre(void){
    File fM;
    fM.t = NULL;
    fM.q = NULL
    return fM
}

File enfilerMonstre(File fM, Monstre monstre){
    MaillonM *maillon;
    maillon = (MaillonM*)malloc(sizeof(MaillonM));
    if(maillon == NULL){
        printf("Problème malloc !");
        exit(1);
    }
    maillon.m = monstre;
    maillon->suiv = NULL;
    if(estVide(fM)){
        fM.t = maillon;
        fM.q = maillon
        return fM;
    }
    f.q->suiv = maillon;
    f.q = maillon;
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
        return fileVide();
    }
    aux = fM.t;
    fM.t = fM.t->suiv;
    free(aux);
    return fM;
}

Booleen estVide(File fM){
    return fM.t == NULL && fM.q == NULL;
}

Monstre tete(File fM){
    if(estVide(fM)){
        printf("Opération interdite, la file est vide !!");
        exit(1);
    }
    return fM.t->m;
}

int longueur(File fM){
    int l=0;
    while(fM.t != NULL){
        l += 1;
        fM.t = fM.t->suiv;
    }
    return fM;
}

void affichageFileMonstres(File fM){
    while(fM.t != NULL){
        printf("%d", fM.t->m);
    }
    pritnf("\n");
}