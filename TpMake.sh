#!/usr/bin/env bash 

echo -n 'Nom du tp : '
read nomTp

mkdir -p $nomTp

echo 'exo'$nomTp': '$nomTp'.o Test'$nomTp'.o
	gcc '$nomTp'.o Test'$nomTp'.o -o exo'$nomTp'

'$nomTp'.o : '$nomTp'.c '$nomTp'.h
	gcc -Wall -c '$nomTp'.c

Test'$nomTp'.o : Test'$nomTp'.c '$nomTp'.h
	gcc -Wall -c Test'$nomTp'.c

clean :
	rm *.o exo'$nomTp'' > $nomTp/'Makefile'

echo '#include "'$nomTp'.h"
int main(void){//fonction principale
    global();
    return 0;
}' > $nomTp/'Test'$nomTp'.c'


echo '/**
    \file '$nomTp'.h
    \author najib
    \date 
    \brief 
*/ 
/**
    \brief fonction global qui appelle toutes les autres fonctions du tp
*/
void global(void);' > $nomTp/$nomTp'.h'

echo '#include <stdio.h>
#include "'$nomTp'.h"

void global(void){
    printf("Hello global\n");
}' > $nomTp/$nomTp'.c'

cd ./$nomTp
make 
