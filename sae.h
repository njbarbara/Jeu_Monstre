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
#include <string.h>

// !!!! 
// corridor = pile/file mais plus file
// !!!!

typedef enum{
    FALSE,
    TRUE
}Booleen;

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

typedef struct maillonM{
    Monstre m;
    struct maillonM * suiv;
}MaillonM, *PileM;

typedef struct{
    MaillonM *t;
    MaillonM *q;
}File;

int menu(void);

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

int longueur(ListeScore l);

void sauvegardeListeScore(FILE *flot, ListeScore l);

/*PARTIE JOUEUR */

Joueur lireJoueurScores(FILE *flot);

int chargement(Joueur * tabJoueur[], char *nomFich, int tmax);

void sauvegardeScoreJoueur(Joueur * tabJoueur[], char *nomFich, int tlog);

void affichListeJoueursScores(Joueur * tabJoueur[], int tlog);
void affichJoueurMeilleurs(Joueur * tabJoueur [], int tlog);


int plusGrandScore(Joueur * tabJoueur[], int tlog);

void echange(Joueur * tabJoueur[], int i, int j);

void triEnchangeMeilleurScore(Joueur * tabJoueur[], int tlog);


/*PARTIE MONSTRES*/

//File

File fileVideMonstre(void);

File enfilerMonstre(File fM, Monstre monstre);

File defilerMonstre(File fM);

int estVide(File fM);

Monstre tete(File fM);

int longueurFileMonstres(File fM);

void affichageMonstre(Monstre monstreAafficher);

void affichageFileMonstres(File fM);

//Pile 
int hauteur(PileM p);

Booleen EstPilevide(PileM p);

PileM empiler(PileM p, Monstre val);

PileM depiler(PileM p);

Monstre sommet(PileM p);

int hauteur(PileM p);

//tableau

void afficheTabMonstre(Monstre **tab, int tlog);

int decalageAGauche(Monstre **tab, int indice, int tlog);


Monstre* lireMonstre(FILE *flot);

int chargementMonstres(Monstre **tabMonstres);

Monstre randomMonstre(File *fM);

File deuxiemeGroupe(File fM);




//int recherche(Joueur * tabJoueur[], int tlog, char * nom, int * trouve);
