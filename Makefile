exosae: sae.o Testsae.o
	gcc sae.o Testsae.o -o exosae

sae.o : sae.c sae.h
	gcc -Wall -c sae.c

Testsae.o : Testsae.c sae.h
	gcc -Wall -c Testsae.c

clean :
	rm *.o exosae
