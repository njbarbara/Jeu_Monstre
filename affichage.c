#include "sae.h"

/*FICHIER CONTENANT TOUT LES AFFICHAGES DU JEU */

//AFFICHAGE PRINCIPAL 

int menu(void){
    int choix;
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*\t                                                          \t*\n");
    printf("*\t    Veuillez choisir en tapant le numéro correspondant    \t*\n");
    printf("*\t                                                          \t*\n");
    printf("*\t 1. jouer une partie prédéfinie                           \t*\n");
    printf("*\t 2. créer une nouvelle partie                             \t*\n");
    printf("*\t 3. afficher la liste des joueurs triée par nom           \t*\n");
    printf("*\t 4. afficher la liste des joueurs triée par meilleur score\t*\n");
    printf("*\t 5. afficher les statistiques d'un joueur                 \t*\n");
    printf("*\t 6. Génerer une partie aléatoire                          \t*\n");
    printf("*\t 9. Quitter                                               \t*\n");
    printf("*\t                                                          \t*\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("Choix : ");
    scanf("%d%*c", &choix);

    while(choix != 1 && choix != 2 && choix != 3 && choix != 3 && choix != 4 && choix != 5 && choix != 6 && choix != 9){
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*\t                                                          \t*\n");
        printf("*\t                      CHOIX INVALIDE                      \t*\n");
        printf("*\t                                                          \t*\n");
        printf("*\t    Veuillez choisir en tapant le numéro correspondant    \t*\n");
        printf("*\t                                                          \t*\n");
        printf("*\t 1. jouer une partie prédéfinie                           \t*\n");
        printf("*\t 2. créer une nouvelle partie                             \t*\n");
        printf("*\t 3. afficher la liste des joueurs triée par nom           \t*\n");
        printf("*\t 4. afficher la liste des joueurs triée par meilleur score\t*\n");
        printf("*\t 5. afficher les statistiques d'un joueur                 \t*\n");
        printf("*\t 6. Génerer une partie aléatoire                          \t*\n");
        printf("*\t 9. Quitter                                               \t*\n");
        printf("*\t                                                          \t*\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("Choix : ");
        scanf("%d%*c", &choix);
    }
    return choix;
}



//AFFICHAGE JOUEUR 
void affichListeJoueursScores(Joueur ** tabJoueur, int tlog){
    int i;

    for(i =0; i<tlog; i++){
        printf("Nom du joueur : %s \n",tabJoueur[i]->pseudo);
        if(!estListeVide(tabJoueur[i]->l)){
            printf("Scores associés : \n");
            afficherScore(tabJoueur[i]->l);
        }
    }
}

void affichStatJoueur(Joueur ** tabJoueur, int tlog){
    char nom[30];
    int pos;

    printf("Saisir le nom du joueur à rechercher : ");
    fgets(nom,30,stdin);
    nom[strlen(nom)-1]='\0';

    pos = rechercheNomJoueur( nom, tabJoueur, tlog);

    if(pos == -1){
        printf("Joueur/Joueuse inconnu(e)\n");
        return;
    }
    else printf("Le joueur %s a joué  à %d parties, avec pour meilleur score : %d \n", tabJoueur[pos]->pseudo, longueur(tabJoueur[pos]->l), tabJoueur[pos]->l->score);

}

void affichJoueurMeilleursScores(Joueur ** tabJoueur, int tlog){
    int i, j, classement=0;
    Joueur * tmp;

    tmp = (Joueur *)malloc(sizeof(Joueur)*tlog);

    for(j = 0; j<tlog; j++ )tmp[j]=*tabJoueur[j];

    triEnchangeMeilleurScore(tmp, tlog);

    for(i=0; i<tlog; i++){
        classement++;
        printf("Le joueur présent en position %d est %s, avec pour meilleur meilleur score : %d \n",classement,tmp[i].pseudo, tmp[i].l->score);
    } 
    free(tmp);
}

void affichJoueurParNom(Joueur ** tabJoueur, int tlog){
    int i;

    for(i=0; i<tlog; i++)printf("Le joueur  %s, a pour meilleur meilleur score : %d \n",tabJoueur[i]->pseudo, tabJoueur[i]->l->score);
}



// AFFICHAGE PARTIE

//fct utilisé pour tester le chargement et la sauvegarde de partie
void affichPartie(File fM, PileM pM){
    printf("Premier groupe : \n");
    affichagePileMonstre(pM);
    printf("Second groupe : \n");
    affichageFileMonstres(fM);
}

void clear(void){
    for(int i =0; i < 33; i++)printf("\n");
}   

void affichScenario1erGrpe(void){
    printf("\n");
    printf("Contexte : vous arrivez dans un corridor, bordé par deux falaises des monstres arrivent les uns après les autres. \n");
}

void affichScenario2ndGrpe(void){
    printf("Tous les monstres sont morts... \nvous arrivez au bout du corridor, une plaine herbeuse apparaît. Malheureusement des monstres sortent de partout pour tous vous attaquer en même temps ou presque...");
}
void affichArriveeNouvMonstre(Joueur j, Monstre m, int nbPoints){
    printf("Le monstre %s(%dptV, %dAtt) accoure et se prépare à t'attaquer %s(%dptV, %dAtt)\n", m.nom, m.PV, m.degat, j.pseudo, j.PV, j.degat);
}

void affichNouvMonstrePlaine(Joueur j, Monstre m, int nbPoints){
    printf("Le monstre %s(%dptV, %dAtt) s'avance pour vous attaquer %s(%dptV, %dAtt)\n", m.nom, m.PV, m.degat, j.pseudo, j.PV, j.degat);
}