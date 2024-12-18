#include "sae.h"


/*void ascciMonstre(char nom){

}*/

/*Fonctions du File de monstres*/

File fileVideMonstre(void){
    File fM;
    fM.t = NULL;
    fM.q = NULL;
    return fM;
}

File enfilerMonstre(File fM, Monstre monstre){
    MaillonM *maillonAEnfiler;
    maillonAEnfiler = (MaillonM*)malloc(sizeof(MaillonM));
    if(maillonAEnfiler == NULL){
        printf("Problème malloc !");
        exit(1);
    }
    maillonAEnfiler->m = monstre;
    maillonAEnfiler->suiv = NULL;
    if(estVide(fM)){
        fM.t = maillonAEnfiler;
        fM.q = maillonAEnfiler;
        return fM;
    }
    fM.q->suiv = maillonAEnfiler;
    fM.q = maillonAEnfiler;
    return fM;
}

File defilerMonstre(File fM){
    MaillonM * aux;
    if(fM.t == NULL){
        printf("Opération interdite, la file est vide !!");
        exit(1);
    }
    if(fM.t == fM.q){
        free(fM.t);
        return fileVideMonstre();
    }
    aux = fM.t;
    fM.t = fM.t->suiv;
    free(aux);
    return fM;
}

int estVide(File fM){
    return fM.t == NULL && fM.q == NULL;
}

Monstre tete(File fM){
    if(estVide(fM)){
        printf("Opération interdite, la file est vide !!");
        exit(1);
    }
    return fM.t->m;
}

int longueurFileMonstres(File fM){
    int l=0;
    while(fM.t != NULL){
        l += 1;
        fM.t = fM.t->suiv;
    }
    return l;
}


void affichageMonstre(Monstre monstreAafficher){
    printf("Nom : %s \t PV : %d \t Dégat : %d \t Nb Armes : %d\n", monstreAafficher.nom, monstreAafficher.PV, monstreAafficher.degat, monstreAafficher.nbArmes);
}


void affichageFileMonstres(File fM){
    while(fM.t != NULL){
        affichageMonstre(fM.t->m);
        fM.t = fM.t->suiv;
    }
}

/*Pile Monstre*/

Booleen EstPilevide(PileM p){
    if(p == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }

}

PileM pileVide(void){   
    return NULL;
}

PileM empiler(PileM p, Monstre val){
    MaillonM *Mt;
    Mt =(MaillonM *)malloc(sizeof(MaillonM));
    if(Mt == NULL){
        printf("Pb allocation mémoire");
        exit(1);
    }
    Mt->m=val;
    Mt->suiv=p;//Insertion en tête
    return Mt;
}

PileM depiler(PileM p){ 
    MaillonM *Mt;

    if(EstPilevide(p)){
        printf("Opération interdite");
        exit(1);        
    }
    Mt = p;
    p=p->suiv;
    free(Mt);
    return p;
}

Monstre sommet(PileM p){
    return p->m;
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
    int k=0;
    FILE *flot;
    Monstre monstreAAjouter;
    flot = fopen("fichierSauvegarde/monstres.txt", "r");
    if(flot == NULL){
        printf("Probléme de chargement !");
        exit(1);
    }
    
    monstreAAjouter = lireMonstre(flot);
    while(!feof(flot)){
        
        tabMonstres[k] = (Monstre*)malloc(sizeof(Monstre));
        if(tabMonstres[k] == NULL){
            printf("Probléme malloc !");
            exit(1);
        }
        *tabMonstres[k] = monstreAAjouter;
        monstreAAjouter = lireMonstre(flot);
        k += 1;
    }
    return k;
}

Monstre randomMonstre(Monstre **tabMonstres, int *tlog){
    int indice;
    time_t seconds;
    Monstre monstreChoisi;
    seconds = time(NULL);
    indice = (rand()+seconds)%(*tlog);
    monstreChoisi = *tabMonstres[indice];
    decalageAGauche(tabMonstres, indice, *tlog);
    *tlog -= 1;
    return monstreChoisi;
}

PileM premierGroupe(Monstre **tabMonstres, int *tlog){
    int i;
    Monstre monstrePartie;
    PileM pG2;
    pG2 = pileVide();
    for(i=5;i>=3;i--){
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
        fG2 = enfilerMonstre(fG2, monstrePartie);
    }
    return fG2;
}