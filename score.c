#include "sae.h"

/*FICHIER DES FONCTIONS LIÉES À LA GESTION DES SCORES DU JOUEUR*/

/**
    \brief Crée une liste vide pour stocker les scores.
    \return Une liste vide de scores.
*/
ListeScore creerListeVide(void){
    return NULL;
}

/**
    \brief Vérifie si la liste de scores est vide.
    \param l La liste de scores à vérifier.
    \return Un entier indiquant 1 si la liste est vide, 0 sinon.
*/
int estListeVide(ListeScore l){
    return l == NULL;
}

/**
    \brief Affiche les scores de la liste fournie.
    \param l La liste de scores à afficher.
*/
void afficherScore(ListeScore l){
    if(l == NULL) return;
    printf("- %d \n", l->score);
    afficherScore(l->suiv);
}


/**
    \brief Ajoute un score à l'entête de la liste.
    \param l La liste de scores à modifier.
    \param s Le score à ajouter.
    \return La liste mise à jour avec le nouveau score en tête.
*/
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


/**
    \brief Ajoute un score à la liste.
    \param l La liste de scores à modifier.
    \param s Le score à ajouter.
    \return La liste mise à jour avec le nouveau score.
*/
ListeScore ajouter(ListeScore l, int s){
    if(l == NULL) return ajouterEntete(l,s);
    if(s > l->score) return ajouterEntete(l,s);

    if(s==l->score) return l;

    l->suiv = ajouter(l->suiv,s);

    return l;
}


/**
    \brief Supprime le score en tête de la liste.
    \param l La liste de scores à modifier.
    \return La liste mise à jour sans le score en tête.
*/
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

/**
    \brief Supprime un score spécifique de la liste.
    \param l La liste de scores à modifier.
    \param s Le score à supprimer.
    \return La liste mise à jour sans le score passé en paramettre.
*/
ListeScore supprimer(ListeScore l, int s){
    if(l == NULL) return NULL;
    if(s > l->score) return l;
    if(l->score == s)return supprimerEntete(l);

    l->suiv = supprimer(l->suiv,s);

    return l;
}

/**
    \brief Calcule la longueur de la liste de scores.
    \param l La liste de scores à évaluer.
    \return Le nombre d'éléments dans la liste.
*/
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