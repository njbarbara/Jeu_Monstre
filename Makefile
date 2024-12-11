exosae: sae.o Testsae.o affichage.o score.o joueur.o
	gcc sae.o Testsae.o affichage.o score.o joueur.o -o exosae

sae.o : sae.c sae.h
	gcc -Wall -c sae.c

Testsae.o : Testsae.c sae.h
	gcc -Wall -c Testsae.c

affichage.o : affichage.c sae.h
	gcc -Wall -c affichage.c

score.o : score.c sae.h
	gcc -Wall -c score.c 

monstre.o : monstre.c sae.h
	gcc -Wall -c monstre.c

joueur.o : joueur.c sae.h 
	gcc -Wall -c joueur.c

clean :
	rm *.o exosae
