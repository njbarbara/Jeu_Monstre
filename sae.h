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

typedef enum{P=1, F, C, O, S}Arme;

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
    int nbArmes;
    ListeScore l; //par ordre décroissant
}Joueur;

typedef struct maillonM{
    Monstre val;
    struct maillonM * suiv;
}MaillonM, *PileM, *File;



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
ListeScore creerListeVide(void);

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

int estListeVide(ListeScore l);

int longueur(ListeScore l);

void sauvegardeListeScore(FILE *flot, ListeScore l);

/*PARTIE JOUEUR */

Joueur lireJoueurScores(FILE *flot);

int chargementJoueurs(Joueur * tabJoueur[], int tmax);

void sauvegardeJoueur(Joueur ** tabJoueur, int tlog);

void affichListeJoueursScores(Joueur ** tabJoueur, int tlog);

void affichJoueurMeilleursScores(Joueur ** tabJoueur, int tlog);

void affichStatJoueur(Joueur ** tabJoueur, int tlog);

int rechercheDico(Joueur ** tabJoueur, int tlog, char nom[], int * trouve);

int rechercheNomJoueur(char nom[], Joueur ** tabJoueur, int tlog);

int ajouterJoueur(Joueur ** tabJoueur, char nom[], int tlog, int pos);

Joueur initialiserUnJoueur(Joueur j);

int plusGrandScore(Joueur * tabJoueur, int tlog);

void echange(Joueur * tabJoueur, int i, int j);

void triEnchangeMeilleurScore(Joueur * tabJoueur, int tlog);


/*PARTIE MONSTRES*/

//File

File CreerfileVideMonstre(void);

int estFileVide(File fM);

Monstre teteFile(File fM);



int longueurFileMonstres(File fM);

void affichageMonstre(Monstre monstreAafficher);

void affichageFileMonstres(File fM);

//Pile 

int hauteur(PileM p);

int estPileVide(PileM p);

File adjQ(File fM, Monstre x);

File supT(File fM);

PileM CreerPileVide(void);

PileM empiler(PileM p, Monstre val);

PileM depiler(PileM p);

Monstre sommet(PileM p);

int hauteur(PileM p);

void affichagePileMonstre(PileM p);

//tableau

void afficheTabMonstre(Monstre *tab, int tlog);

Monstre lireMonstre(FILE *flot);

Monstre * chargementMonstres(int *tlog);

Monstre randomMonstre(Monstre *tabMonstres, int tlog);

PileM premierGroupe(Monstre *tabMonstres, int tlog);

File deuxiemeGroupe(Monstre *tabMonstres, int tlog);

Monstre convertisseurNiveauEnStat(Monstre m, int niveau);

/*Parties Déroulement du jeu */

void affichPartie(File fM, PileM pM);

Monstre saisirMonstre(void);

void affichScenario1erGrpe(void);

void affichScenario2ndGrpe(void);

void chargePartie(char *nomFich, File *fM, PileM *pM);

void sauvegardePartie(char *nomFich, File *fM, PileM *pM);

int Partie(Joueur ** tabJoueur, int tlog);

void creerPartie(void);

void clear(void);

void generePartieAleatoire(void);

int deroulementPartie(Joueur j, PileM pM, File fM);

void affichNouvMonstrePlaine(Joueur j, Monstre m, int nbPoints);

void affichArriveeNouvMonstre(Joueur j, Monstre m, int nbPoints);

//int recherche(Joueur * tabJoueur[], int tlog, char * nom, int * trouve);


/*ATTAQUE*/

Arme choixArmeJoueur(void);

int gagneAttaqueJoueur(Arme attaqueJ, Arme attaqueM);

int combat(Joueur j, Monstre m, int *points);

Arme RandomAttaqueMonstre(Monstre m);
