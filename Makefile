all : Dictionnaire

Dictionnaire.o : Dictionnaire.h Dictionnaire.c
	gcc -g -c Dictionnaire.c

Dictionnaire : Dictionnaire.o
	gcc Dictionnaire.o -o Dictionnaire

clean :
	rm -f *.o Dictionnaire
