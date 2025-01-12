#include "sae.h"

/*FONCTIONS LIÉES AUX MONSTRE*/

/*void ascciMonstre(char nom []){

}*/

/*File de monstres*/

/**
    \brief Crée une file vide de monstre.
*/
File CreerfileVideMonstre(void){
    return NULL;
}


/**
    \brief  Vérifie si la file est vide
*/
int estFileVide(File fM){
    return fM == NULL;
}

/**
    \brief Ajoute un monstre à la fin de la file.
    \param fM La file de monstres.
    \param x Le monstre à ajouter.
    \return La file mise à jour contenant le nouveau monstre.
*/
File adjQ(File fM, Monstre x){
    MaillonM * m;

    m = (MaillonM *)malloc(sizeof(MaillonM));

    if(m==NULL){
        printf("Pb malloc \n");
        exit(1);
    }
    m->val = x;
    if(estFileVide(fM)){
        m->suiv = m;
        return m;
    }

    m->suiv = fM->suiv;
    fM->suiv = m;
    fM=m;

    return fM;
}


/**
    \brief Supprime le monstre en tête de la file.
    \param fM La file de monstres.
    \return La file mise à jour après la suppression du premier monstre.
*/
File supT(File fM){
    MaillonM * tmp;

    if(fM == NULL){
        printf("Opération interdite \n");
        return NULL;
    }
    if(fM->suiv==fM){
        free(fM);
        return CreerfileVideMonstre();
    }

    tmp = fM->suiv;
    fM->suiv = fM->suiv->suiv;
    free(tmp);
    return fM;
}

/**
    \brief Récupère le monstre en tete de file.
    \param fM La file de monstres.
    \return Le monstre en tete de  file.
*/
Monstre teteFile(File fM){
    if(estFileVide(fM)){
        printf("Opération interdite, la file est vide \n");
        exit(1);
    }
    return fM->suiv->val;
}


/**
    \brief Calcule la longueur de la file de monstres.
    \param fM La file à analyser.
    \return Le nombre de monstres dans la file.
*/
int longueurFileMonstres(File fM){
    int l=1;
    MaillonM * tmp;

    if(estFileVide(fM))return 0;

    tmp = fM->suiv;

    while(tmp != fM){
        l += 1;
        tmp = tmp->suiv;
    }
    return l;
}

/**
    \brief Affiche les détails d'un monstre.
    \param monstreAafficher Le monstre à afficher.
*/
void affichageMonstre(Monstre monstreAafficher){
    printf("Nom : %s \t PV : %d \t Dégat : %d \t Nb Armes : %d\n", monstreAafficher.nom, monstreAafficher.PV, monstreAafficher.degat, monstreAafficher.nbArmes);
}

/**
    \brief Affiche tous les monstres présents dans la file.
    \param fM La file contenant les monstres à afficher.
*/
void affichageFileMonstres(File fM){
    MaillonM * tmp;
    if(estFileVide(fM))return;
    tmp = fM->suiv;
    while(tmp != fM){
        affichageMonstre(tmp->val);
        tmp = tmp->suiv;
    }
    affichageMonstre(fM->val);
}

/*Pile Monstre*/

/**
    \brief Fonction pour savoir si la pile est vide
*/
int estPileVide(PileM p){
    return p == NULL;
}


PileM CreerPileVide(void){   
    return NULL;
}

/**
    \brief Ajoute un monstre au sommet de la pile.
    \param p La pile de monstres.
    \param val Le monstre à ajouter.
    \return La pile mise à jour avec le nouveau monstre au sommet.
*/
PileM empiler(PileM p, Monstre m){
    MaillonM *Mt;
    Mt =(MaillonM *)malloc(sizeof(MaillonM));
    if(estPileVide(Mt)){
        printf("Pb malloc \n");
        exit(1);
    }
    Mt->val=m;
    Mt->suiv=p;//Insertion en tête
    return Mt;
}


/**
    \brief Supprime le monstre au sommet de la pile.
    \param p La pile de monstres.
    \return La pile mise à jour après la suppression du sommet.
*/
PileM depiler(PileM p){ 
    MaillonM *Mt;

    if(estPileVide(p)){
        printf("Opération interdite");
        exit(1);        
    }
    Mt = p;
    p=p->suiv;
    free(Mt);
    return p;
}

/**
    \brief Récupère le monstre au sommet de la pile.
    \param p La pile de monstres.
    \return Le monstre situé au sommet de la pile.
*/
Monstre sommet(PileM p){
    if(p==NULL){
        printf("Opération impossible \n");
        exit(1);
    }
    return p->val;
}

/**
    \brief Fonction qui renvoit la hauteur de la pile de monstre.
*/
int hauteur(PileM p){
    int cpt=0;
    MaillonM * ptm = p;
    while (ptm != NULL){
        cpt++;
        ptm = ptm->suiv;
    } 
    return cpt;
}


/**
    \brief Affiche les monstres présents dans la pile.
    \param p La pile de monstres à afficher.
*/
void affichagePileMonstre(PileM p){
    MaillonM * ptm = p;

    if(estPileVide(p)) return;
    while (ptm != NULL){
        affichageMonstre(sommet(ptm));
        ptm = ptm->suiv;
    } 
}


/*Fonctions des monstres*/

/**
    \brief Modifie les statistiques d'un monstre en fonction de son niveau.
    \param m Monstre à modifier.
    \param niveau Niveau du monstre.
    \return Le monstre avec ses statistiques en fct du nivea.
*/
Monstre convertisseurNiveauEnStat(Monstre m, int niveau){
    if(niveau == 3){
        m.PV=4;
        m.degat=2;
        m.nbArmes=5;
    }
    else if(niveau == 2){
        m.PV=6;
        m.degat=1;
        m.nbArmes=3;
    }
    else{
        m.PV=4;
        m.degat=1;
        m.nbArmes=4;
    }
    return m;
}
/*
int ajouterMonstre(Monstre **tab, int tlog, int tmax){
    Monstre m;
    int niveau;

    if(tlog == tmax){
        printf("Tableau plein \n");
        return tlog;
    }

    printf("Saisir le nom du monstre : ");
    fgets(m.nom,30,stdin);

    m.nom[strlen(m.nom)-1]='\0';

    printf("Saisir son niveau (entre 1 et 3) : ");
    scanf("%d", &niveau);

    while(niveau <1 || niveau > 3 ){
        printf("Niveau incorrect \n");
        printf("Saisir son niveau (entre 1 et 3) : ");
        scanf("%d", &niveau);
    }

    m = convertisseurNiveauEnStat(m, niveau);

    tab[tlog] = (Monstre *)malloc(sizeof(Monstre));
    *tab[tlog] = m;

    tlog++;
    return tlog;  
} 

*/


/**
    \brief Affiche les  monstres présents dans le tableau.
    \param tab Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
*/
void afficheTabMonstre(Monstre *tab, int tlog){
    int i;
    for(i=0;i<tlog;i++)
        affichageMonstre(tab[i]);
}

/**
    \brief Lit les données d'un monstre depuis un fichier.
    \param flot Fichier contenant les données du monstre.
    \return Le monstre lu depuis le fichier.
*/
Monstre lireMonstre(FILE *flot){
    Monstre m;
    fgets(m.nom, 30, flot);
    m.nom[strlen(m.nom)-1] = '\0';
    fscanf(flot, "%d%d%d%*c", &m.PV, &m.degat, &m.nbArmes);
    return m;
}

/**
    \brief Charge un tableau de monstres depuis un fichier de monstre.
    \param tlog Pointeur vels  le nombre de monstres chargés.
    \return Un tableau de monstres chargé depuis le fichier de monstre.
*/
Monstre *chargementMonstres(int *tlog){
    int i;
    FILE *flot;
    Monstre * tabMonstres;

    flot = fopen("fichierSauvegarde/monstres.txt", "r");
    if(flot == NULL){
        printf("Problème de chargement !");
        exit(1);
    }
    
    fscanf(flot,"%d%*c", tlog);
    tabMonstres = (Monstre *)malloc(*tlog*sizeof(Monstre));

    for(i=0; i<*tlog; i++)tabMonstres[i]=lireMonstre(flot);
   
    fclose(flot);
    return tabMonstres;
}

/**
    \brief Sélectionne aléatoirement un monstre dans un tableau.
    \param tabMonstres Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
    \return Un monstre sélectionné aléatoirement.
*/
Monstre randomMonstre(Monstre *tabMonstres, int tlog){
    int indice;
    time_t seconds;
    Monstre monstreChoisi;

    seconds = time(NULL);
    indice = (rand()+seconds)%(tlog);
    monstreChoisi = tabMonstres[indice];

    return monstreChoisi;
}

/**
    \brief Crée un premier groupe de monstres.
    \param tabMonstres Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
    \return Une pile contenant le premier groupe de monstres.
*/
PileM premierGroupe(Monstre *tabMonstres, int tlog){
    int i;
    Monstre monstrePartie;
    PileM pG2;
    pG2 = CreerPileVide();
    for(i=4;i>=3;i--){
        monstrePartie = randomMonstre(tabMonstres, tlog);
        pG2 = empiler(pG2, monstrePartie);
    }
    return pG2;
}

/**
    \brief Crée un second groupe de monstres.
    \param tabMonstres Tableau de monstres.
    \param tlog Nombre de monstres dans le tableau.
    \return Une file contenant le second groupe de monstres.
*/
File deuxiemeGroupe(Monstre *tabMonstres, int tlog){
    int i;
    Monstre monstrePartie;
    File fG2;
    fG2 = CreerfileVideMonstre();
    for(i=3;i<=5;i++){
        monstrePartie = randomMonstre(tabMonstres, tlog);
        fG2 = adjQ(fG2, monstrePartie);
    }
    return fG2;
}