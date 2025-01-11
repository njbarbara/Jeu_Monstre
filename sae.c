#include "sae.h"


void global(void){
    int choix;

    choix = menu();
    while(choix !=9){
        if(choix==0){
            printf("A ajouter \n");
        }
        else if(choix == 1)printf("A implémenter \n");
        else if(choix == 2)printf("A implémenter \n");
        else if(choix == 3)printf("A implémenter \n");
        else if(choix == 4)printf("A implémenter \n");
        else if(choix == 5)printf("A implémenter \n");
        else printf("Merci d'avoir utilisé notre application \n");
    }
}


