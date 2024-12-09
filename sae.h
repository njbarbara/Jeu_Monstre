/**
    \file sae.h
    \author najib aron agocs
    \date 
    \brief Jeu de la saé 1.02
*/ 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>

// !!!! 
// corridor = pile/file mais plus file
// !!!!

typedef struct{
    char nom[30];
    int PV;
    int degat;
    int nbArmes;
}Monstre;

typedef struct maillon{
    int score;
    struct maillon * suiv;
}Maillon, *ListeScore;

typedef struct{
    char pseudo[30];
    int PV;
    int degat;
    int nbParties;
    ListeScore l; //par ordre décroissant
}Joueur;



/*PARTIE SCORE*/

/**
    \brief 
    \param
*/
void global(void);

/**
    \brief 
    \param
    \return
*/
ListeScore ensemble(void);

/**
    \brief 
    \param
*/
void afficherScore(ListeScore l);

/**
    \brief 
    \param
    \return
*/
ListeScore ajouterEntete(ListeScore l, int s);

/**
    \brief 
    \param
    \return
*/
ListeScore ajouter(ListeScore l, int s);

/**
    \brief 
    \param
    \return
*/
ListeScore supprimerEntete(ListeScore l);

/**
    \brief 
    \param
    \return
*/
ListeScore supprimer(ListeScore l, int s);