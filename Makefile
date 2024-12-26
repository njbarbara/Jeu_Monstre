sae: sae.o Testsae.o affichage.o score.o joueur.o monstre.o partie.o attaque.o
	gcc sae.o Testsae.o affichage.o score.o joueur.o monstre.o partie.o attaque.o -o sae

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

attaque.o : attaque.c sae.h
	gcc -Wall -c attaque.c 

partie.o : partie.c sae.h
	gcc -Wall -c partie.c 

clean :
	rm *.o sae
