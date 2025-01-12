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


/**
    \brief Affiche le menu principal du jeu.
    \return Le choix de l'utilisateur.
*/
int menu(void);

/**
    \brief Affiche le logo  du jeu.
*/
void logo(void);

/**
    \brief Fonction principale qui gère le déroulement global du jeu.
*/
void global(void);

/*PARTIE SCORE*/

/**
    \brief Crée une liste vide pour stocker les scores.
    \return Une liste vide de scores.
*/
ListeScore creerListeVide(void);

/**
    \brief Affiche les scores de la liste fournie.
    \param l La liste de scores à afficher.
*/
void afficherScore(ListeScore l);

/**
    \brief Ajoute un score à l'entête de la liste.
    \param l La liste de scores à modifier.
    \param s Le score à ajouter.
    \return La liste mise à jour avec le nouveau score en tête.
*/
ListeScore ajouterEntete(ListeScore l, int s);

/**
    \brief Ajoute un score à la liste.
    \param l La liste de scores à modifier.
    \param s Le score à ajouter.
    \return La liste mise à jour avec le nouveau score.
*/
ListeScore ajouter(ListeScore l, int s);

/**
    \brief Supprime le score en tête de la liste.
    \param l La liste de scores à modifier.
    \return La liste mise à jour sans le score en tête.
*/
ListeScore supprimerEntete(ListeScore l);

/**
    \brief Supprime un score spécifique de la liste.
    \param l La liste de scores à modifier.
    \param s Le score à supprimer.
    \return La liste mise à jour sans le score passé en paramettre.
*/
ListeScore supprimer(ListeScore l, int s);

/**
    \brief Vérifie si la liste de scores est vide.
    \param l La liste de scores à vérifier.
    \return Un entier indiquant 1 si la liste est vide, 0 sinon.
*/
int estListeVide(ListeScore l);

/**
    \brief Calcule la longueur de la liste de scores.
    \param l La liste de scores à évaluer.
    \return Un entier représentant le nombre d'éléments dans la liste.
*/
int longueur(ListeScore l);

/**
    \brief Sauvegarde la liste de scores dans un fichier.
    \param flot Le fichier dans lequel on sauvegarde la liste.
    \param l La liste de scores à sauvegarder.
*/
void sauvegardeListeScore(FILE *flot, ListeScore l);


/*PARTIE JOUEUR */

/**
    \brief Lit les informations d'un joueur à partir d'un fichier.
    \param flot Pointeur vers le fichier d'entrée contenant les données du joueur.
    \return Un Joueur contenant les informations lues depuis le fichier.
*/
Joueur lireJoueurScores(FILE *flot);

/**
    \brief Charge les joueurs depuis un fichier et les stocke dans un tableau.
    \param tabJoueur Tableau de pointeurs vers les joueurs à remplir.
    \param tmax Taille maximale du tableau de joueurs.
    \return Le nombre de joueurs chargés.
*/
int chargementJoueurs(Joueur *tabJoueur[], int tmax);

/**
    \brief Sauvegarde les joueurs dans un fichier.
    \param tabJoueur Tableau de pointeurs vers les joueurs à sauvegarder.
    \param tlog Nombre de joueurs.
*/
void sauvegardeJoueur(Joueur **tabJoueur, int tlog);

/**
    \brief Affiche la liste des joueurs et de leurs scores associés.
    \param tabJoueur Tableau de pointeurs vers les joueurs à afficher.
    \param tlog Nombre de joueurs.
*/
void affichListeJoueursScores(Joueur **tabJoueur, int tlog);

/**
    \brief Affiche les joueurs ayant les meilleurs scores.
    \param tabJoueur Tableau de pointeurs vers les joueurs à afficher.
    \param tlog Nombre de joueurs.
*/
void affichJoueurMeilleursScores(Joueur **tabJoueur, int tlog);

/**
    \brief Affiche un joueur par son nom.
    \param tabJoueur Tableau de pointeurs vers les joueurs à afficher.
    \param tlog Nombre de joueurs.
*/
void affichJoueurParNom(Joueur **tabJoueur, int tlog);


/**
    \brief Libère la mémoire allouée pour le tableau de joueurs.
    \param tabJoueur Tableau de pointeurs vers les joueurs à libérer.
    \param tlog Nombre de joueurs.
*/
void libereTabJoueur(Joueur **tabJoueur, int tlog);

/**
    \brief Affiche les stat d'un joueur en question.
    \param tabJoueur Tableau de pointeurs vers les joueurs.
    \param tlog Nombre actuel de joueurs dans le tableau.
*/
void affichStatJoueur(Joueur **tabJoueur, int tlog);

/**
    \brief Recherche dichotomique d' un joueur dans le tableau en utilisant son nom.
    \param tabJoueur Tableau de pointeurs vers les joueurs.
    \param tlog Nombre actuel de joueurs.
    \param nom Nom du joueur à rechercher.
    \param trouve Pointeur pour indiquer si le joueur a été trouvé.
    \return Index du joueur dans le tableau ou pos d'insertion si pas trouvé.
*/
int rechercheDico(Joueur **tabJoueur, int tlog, char nom[], int *trouve);

/**
    \brief Vérifie si un joueur avec un nom donné existe dans le tableau.
    \param nom Nom du joueur à rechercher.
    \param tabJoueur Tableau de pointeurs vers les joueurs.
    \param tlog Nombre actuel de joueurs dans le tableau.
    \return Indice du joueur ou -1 si le joueur n'est pas trouvé.
*/
int rechercheNomJoueur(char nom[], Joueur **tabJoueur, int tlog);

/**
    \brief Ajoute un joueur au tableau à une position donnée.
    \param tabJoueur Tableau de pointeurs vers les joueurs.
    \param nom Nom du joueur à ajouter.
    \param tlog Nombre  joueurs.
    \param pos Position où ajouter le joueur.
    \return la taille logique.
*/
int ajouterJoueur(Joueur **tabJoueur, char nom[], int tlog, int pos);

/**
    \brief Initialise un joueur slon son meilleur score (si il en a un).
    \param j Joueur à initialiser.
    \return Joueur initialisé.
*/
Joueur initialiserUnJoueur(Joueur j);

/**
    \brief Trouve le plus grand score parmi les joueurs.
    \param tabJoueur Tableau de joueurs à analyser.
    \param tlog Nombre de joueurs dans le tableau.
    \return la pos du plus grand score trouvé.
*/
int plusGrandScore(Joueur *tabJoueur, int tlog);

/**
    \brief Échange deux joueurs dans le tableau.
    \param tabJoueur Tableau de joueurs.
    \param i Index du premier joueur à échanger.
    \param j Index du deuxième joueur à échanger.
*/
void echange(Joueur *tabJoueur, int i, int j);

/**
    \brief Trie les joueurs par leur meilleur score en utilisant l'algorithme d'échange.
    \param tabJoueur Tableau de joueurs à trier.
    \param tlog Nombre actuel de joueurs dans le tableau.
*/
void triEnchangeMeilleurScore(Joueur *tabJoueur, int tlog);


/*PARTIE MONSTRES*/

//File

/**
    \brief Crée une file vide de monstre.
*/
File CreerfileVideMonstre(void);


/**
    \brief  Vérifie si la file est vide
*/
int estFileVide(File fM);


/**
    \brief Récupère le monstre en tete de file.
    \param fM La file de monstres.
    \return Le monstre en tete de  file.
*/
Monstre teteFile(File fM);

/**
    \brief Calcule la longueur de la file de monstres.
    \param fM La file à analyser.
    \return Le nombre de monstres dans la file.
*/
int longueurFileMonstres(File fM);

/**
    \brief Affiche les détails d'un monstre.
    \param monstreAafficher Le monstre à afficher.
*/
void affichageMonstre(Monstre monstreAafficher);

/**
    \brief Affiche tous les monstres présents dans la file.
    \param fM La file contenant les monstres à afficher.
*/
void affichageFileMonstres(File fM);


/**
    \brief Ajoute un monstre à la fin de la file.
    \param fM La file de monstres.
    \param x Le monstre à ajouter.
    \return La file mise à jour contenant le nouveau monstre.
*/
File adjQ(File fM, Monstre x);

/**
    \brief Supprime le monstre en tête de la file.
    \param fM La file de monstres.
    \return La file mise à jour après la suppression du premier monstre.
*/
File supT(File fM);


//Pile 

/**
    \brief Fonction qui renvoit la hauteur de la pile de monstre.
*/
int hauteur(PileM p);

/**
    \brief Fonction pour savoir si la pile est vide
*/
int estPileVide(PileM p);

/**
    \brief Crée une pile vide de monstres.
    \return Une pile vide.
*/
PileM CreerPileVide(void);

/**
    \brief Ajoute un monstre au sommet de la pile.
    \param p La pile de monstres.
    \param val Le monstre à ajouter.
    \return La pile mise à jour avec le nouveau monstre au sommet.
*/
PileM empiler(PileM p, Monstre val);

/**
    \brief Supprime le monstre au sommet de la pile.
    \param p La pile de monstres.
    \return La pile mise à jour après la suppression du sommet.
*/
PileM depiler(PileM p);

/**
    \brief Récupère le monstre au sommet de la pile.
    \param p La pile de monstres.
    \return Le monstre situé au sommet de la pile.
*/
Monstre sommet(PileM p);

/**
    \brief Affiche les monstres présents dans la pile.
    \param p La pile de monstres à afficher.
*/
void affichagePileMonstre(PileM p);


//tableau de monstres

/**
    \brief Affiche les  monstres présents dans le tableau.
    \param tab Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
*/
void afficheTabMonstre(Monstre *tab, int tlog);

/**
    \brief Lit les données d'un monstre depuis un fichier.
    \param flot Fichier contenant les données du monstre.
    \return Le monstre lu depuis le fichier.
*/
Monstre lireMonstre(FILE *flot);

/**
    \brief Charge un tableau de monstres depuis un fichier.
    \param tlog Pointeur vels  le nombre de monstres chargés.
    \return Un tableau de monstres chargé depuis le fichier.
*/
Monstre * chargementMonstres(int *tlog);

/**
    \brief Sélectionne aléatoirement un monstre dans un tableau.
    \param tabMonstres Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
    \return Un monstre sélectionné aléatoirement.
*/
Monstre randomMonstre(Monstre *tabMonstres, int tlog);

/**
    \brief Crée un premier groupe de monstres.
    \param tabMonstres Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
    \return Une pile contenant le premier groupe de monstres.
*/
PileM premierGroupe(Monstre *tabMonstres, int tlog);

/**
    \brief Crée un second groupe de monstres.
    \param tabMonstres Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
    \return Une file contenant le second groupe de monstres.
*/
File deuxiemeGroupe(Monstre *tabMonstres, int tlog);

/**
    \brief Modifie les statistiques d'un monstre en fonction de son niveau.
    \param m Monstre à modifier.
    \param niveau Niveau du monstre.
    \return Le monstre avec ses statistiques en fct du nivea.
*/
Monstre convertisseurNiveauEnStat(Monstre m, int niveau);



/*PARTIE DÉROULEMENT DU JEU */

void affichPartie(File fM, PileM pM);
void affichScenario1erGrpe(void);
void affichScenario2ndGrpe(void);
void clear(void);

/**
    \brief Permet de saisir manuellement les données d'un monstre (nivrau et nom).
    \return Le monstre saisi par l'utilisateur.
*/
Monstre saisirMonstre(void);

/**
    \brief cette fonction permet de charger une partie à partir d'un nom fichier passer en paramètre
    \param nomFich nom du fichier à utiliser
    \param fM pointeur sur la file de monstre à charger
    \param pM pointeur sur la pile de monstre à charger 
*/
int chargePartie(char *nomFich, File *fM, PileM *pM);

/**
    \brief Cette fonction permet de sauvegarder une partie à l'intérieur d'un fichier 
    \param nomFich Nom du fichier à utiliser
    \param fM File de monstre à sauvegarder
    \param pM Pile de monstre à sauvegarder 
*/
void sauvegardePartie(char *nomFich, File fM, PileM pM);

/**
    \brief Cette fonction permet d'initialiser une parti et d'appeler la fonction deroulement partie pour la charger. 
    \param tabJoueur Tableau des joueurs.
    \param tlog Nombre de joueurs dans le tableau.
    \return La taille logique du tab. 
*/
int Partie(Joueur ** tabJoueur, int tlog);

/**
    \brief Crée une nouvelle partie définis par l'utilisateur.
*/
void creerPartie(void);

/**
    \brief Génère une partie aléatoire avec des monstres aléatoires tirés au sort dans un fichier.
*/
void generePartieAleatoire(void);

/**
    \brief Gère le déroulement complet d'une partie, incluant les combats.
    \param j Le joueur.
    \param pM Pile contenant le premier groupe de monstres.
    \param fM File contenant le second groupe de monstres.
    \return Le score total du joueur à la fin de la partie.
*/
int deroulementPartie(Joueur j, PileM pM, File fM);

void affichNouvMonstrePlaine(Joueur j, Monstre m, int nbPoints);

void affichArriveeNouvMonstre(Joueur j, Monstre m, int nbPoints);



/*ATTAQUE*/

/**
    \brief Permet au joueur de choisir une arme pour attaquer.
    \return L'arme choisie par le joueur.
*/
Arme choixArmeJoueur(void);

/**
    \brief Détermine le résultat des 2 attques du joueur et un monstre.
    \param attaqueJ L'arme utilisée par le joueur.
    \param attaqueM L'arme utilisée par le monstre.
    \return Un nombre représentant le résultat de la comparaison des 2 attaque :
            - 0 si le joueur perd le duel
            - 1 si l'attaque gangne le duel re,
            - 2 si les attaques sont identiques.
*/
int gagneAttaqueJoueur(Arme attaqueJ, Arme attaqueM);

/**
    \brief Gère le combat entre un joueur et un monstre.
    \param j Pointeur vers le joueur participant au combat.
    \param m Pointeur vers le monstre avec lequel le joueur combat.
    \param points Pointeur vers le compteur de points du joueur.
    \return Un nombre indiquant le résultat du combat :
            - 1 si le monstre est vaincu,
            - -1 si le joueur est mort,
            - 0 si le combat continue.
*/
int combat(Joueur *j, Monstre *m, int *points);

/**
    \brief Génére une attaque aléatoire pour le monstre.
    \param m Le monstre qui effectue l'attaque.
    \return L'arme utilisée par le monstre pour attaquer.
*/
Arme RandomAttaqueMonstre(Monstre m);

