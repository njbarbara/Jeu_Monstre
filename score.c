#include "sae.h"

/*FICHIER DES FONCTIONS LIÉES À LA GESTION DES SCORES*/

ListeScore creerListeVide(void){
    return NULL;
}

int estListeVide(ListeScore l){
    return l == NULL;
}

void afficherScore(ListeScore l){
    if(l == NULL) return;
    printf("- %d \n", l->score);
    afficherScore(l->suiv);
}

ListeScore ajouterEntete(ListeScore l, int s){
    Maillon * m;

    m = (Maillon *)malloc(sizeof(Maillon));

    if(m==NULL){
        printf("Pb malloc");
        exit(1);
    }

    m->score = s;
    m->suiv = l;

    return m;

}

ListeScore ajouter(ListeScore l, int s){
    if(l == NULL) return ajouterEntete(l,s);
    if(s > l->score) return ajouterEntete(l,s);

    if(s==l->score) return l;

    l->suiv = ajouter(l->suiv,s);

    return l;
}

ListeScore supprimerEntete(ListeScore l){
    Maillon * tmp;

    if(l==NULL){
        printf("Opération interdite \n");
        exit(1);
    }

    tmp = l->suiv;

    free(l);
    l = tmp;
    
    return l;
}

ListeScore supprimer(ListeScore l, int s){
    if(l == NULL) return NULL;
    if(s > l->score) return l;
    if(l->score == s)return supprimerEntete(l);

    l->suiv = supprimer(l->suiv,s);

    return l;
}

int longueur(ListeScore l){
    if(l==NULL) return 0;
    return longueur(l->suiv)+1;
}

void sauvegardeListeScore(FILE *flot, ListeScore l){
    if(l == NULL) return;
    fprintf(flot,"%d\n", l->score);
    l = supprimerEntete(l);
    sauvegardeListeScore(flot, l);
}