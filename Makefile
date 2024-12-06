exosae: sae.o Testsae.o affichage.o
	gcc sae.o Testsae.o affichage.o -o exosae

sae.o : sae.c sae.h
	gcc -Wall -c sae.c

Testsae.o : Testsae.c sae.h
	gcc -Wall -c Testsae.c

affichage.o : affichage.c sae.h
	gcc -Wall -c affichage.c

clean :
	rm *.o exosae
