#include "sae.h"

/*FONCTIONS LIÉES AUX MONSTRE*/

/*void ascciMonstre(char nom []){

}*/

/*Fonctions du File de monstres*/


File fileVideMonstre(void){
    return NULL;
}

int estFileVide(File fM){
    return fM == NULL;
}

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

File supT(File fM){
    MaillonM * tmp;

    if(fM == NULL){
        printf("Opération interdite \n");
        return NULL;
    }
    if(fM->suiv==fM){
        free(fM);
        return fileVideMonstre();
    }

    tmp = fM->suiv;
    fM->suiv = fM->suiv->suiv;
    free(tmp);
    return fM;
}

Monstre teteFile(File fM){
    if(estFileVide(fM)){
        printf("Opération interdite, la file est vide \n");
        exit(1);
    }
    return fM->suiv->val;
}

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


void affichageMonstre(Monstre monstreAafficher){
    printf("Nom : %s \t PV : %d \t Dégat : %d \t Nb Armes : %d\n", monstreAafficher.nom, monstreAafficher.PV, monstreAafficher.degat, monstreAafficher.nbArmes);
}


void affichageFileMonstres(File fM){
    MaillonM * tmp;
    if(estFileVide(fM))return;
    tmp = fM->suiv;
    while(tmp != fM){
        affichageMonstre(fM->val);
        tmp = tmp->suiv;
    }
    affichageMonstre(fM->val);
}

/*Pile Monstre*/

int estPileVide(PileM p){
    return p == NULL;
}


PileM pileVide(void){   
    return NULL;
}

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

Monstre sommet(PileM p){
    if(p==NULL){
        printf("Opération impossible \n");
        exit(1);
    }
    return p->val;
}

int hauteur(PileM p){
    int cpt=0;
    MaillonM * ptm = p;
    while (ptm != NULL){
        cpt++;
        ptm = ptm->suiv;
    } 
    return cpt;
}

void affichagePileMonstre(PileM p){
    MaillonM * ptm = p;
    while (ptm != NULL){
        affichageMonstre(sommet(ptm));
        ptm = ptm->suiv;
    } 
}


/*Fonctions des monstres*/

void decalageAGauche(Monstre **tab, int indice, int tlog){
    int i;
    for(i=indice;i<tlog-1;i++)
        tab[i] = tab[i+1];
}

void afficheTabMonstre(Monstre **tab, int tlog){
    int i;
    for(i=0;i<tlog;i++)
        affichageMonstre(*tab[i]);
}


Monstre lireMonstre(FILE *flot){
    Monstre m;
    fgets(m.nom, 30, flot);
    m.nom[strlen(m.nom)-1] = '\0';
    fscanf(flot, "%d%d%*c", &m.PV, &m.degat);
    m.nbArmes = 0;
    return m;
}

int chargementMonstres(Monstre **tabMonstres){
    int tlog=0;
    FILE *flot;
    Monstre monstreAAjouter;
    flot = fopen("fichierSauvegarde/monstres.txt", "r");
    if(flot == NULL){
        printf("Probléme de chargement !");
        exit(1);
    }
    
    monstreAAjouter = lireMonstre(flot);
    while(!feof(flot)){
        tabMonstres[tlog] = (Monstre*)malloc(sizeof(Monstre));
        if(tabMonstres[tlog] == NULL){
            printf("Probléme malloc !");
            exit(1);
        }
        *tabMonstres[tlog] = monstreAAjouter;
        monstreAAjouter = lireMonstre(flot);
        tlog += 1;
    }   
    return tlog;
}

Monstre randomMonstre(Monstre **tabMonstres, int tlog){
    int indice;
    time_t seconds;
    Monstre monstreChoisi;

    seconds = time(NULL);
    indice = (rand()+seconds)%(tlog);
    monstreChoisi = *tabMonstres[indice];

    return monstreChoisi;
}

PileM premierGroupe(Monstre **tabMonstres, int *tlog){
    int i;
    Monstre monstrePartie;
    PileM pG2;
    pG2 = pileVide();
    for(i=4;i>=3;i--){
        monstrePartie = randomMonstre(tabMonstres, tlog);
        monstrePartie.nbArmes = i;
        pG2 = empiler(pG2, monstrePartie);
    }
    return pG2;
}


File deuxiemeGroupe(Monstre **tabMonstres, int *tlog){
    int i;
    Monstre monstrePartie;
    File fG2;
    fG2 = fileVideMonstre();
    for(i=3;i<=5;i++){
        monstrePartie = randomMonstre(tabMonstres, tlog);
        monstrePartie.nbArmes = i;
        fG2 = adjQ(fG2, monstrePartie);
    }
    return fG2;
}

///CREER UNE FONCTION QUI TRI LES MONSTRES PAR ORDRE ALPHABÉTIQUE

