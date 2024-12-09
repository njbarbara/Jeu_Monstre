#include "sae.h"


ListeScore ensemble(void){
    return NULL;
}

void afficherScore(ListeScore l){
    if(l == NULL) return;
    printf("La score est : %d \n", l->score);
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
    return tmp;
}



ListeScore supprimer(ListeScore l, int s){
    if(l == NULL) return NULL;
    if(s > l->score) return l;
    if(l->score == s)return supprimerEntete(l);

    l->suiv = supprimer(l->suiv,s);

    return l;
}
