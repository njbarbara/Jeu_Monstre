#include "sae.h"

/*
    - comparer les attaques + ajouter 10 points si gagné par le joueur + ajouter 50points si le monstre meurt soit tete/sommet->PV <= 0 + s'il meurt apprès l'ajoute des points il faut le defélier/dépiler
    - choix de l'attaque du joueur entre P, F, C
    - attaque aléatoire du monstre en fonction de son nombres d'armes. Si tete/sommet->nbArmes = 3, entre P, F, C
                                                                       Si tete/sommet->nbArmes = 4, entre P, F, C, O
                                                                       Si tete/sommet->nbArmes = 5, entre P, F, C, O, # soit S
    - affichage 
*/

/*
Arme choixArmeJoueur(void){
    char choix;
    printf("choisis ton attaque parmi P, F, C : ");
    scanf("%c%*c", choix);
    while(choix != 'P' && choix != 'F' && choix != 'C'){
        printf("choisis ton attaque parmi P, F, C : ");
        scanf("%c%*c", choix);
    }
    return choix;
}
*/
