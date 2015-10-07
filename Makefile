all : Dictionary

Dictionnaire.o : Dictionary.h Dictionary.c
	gcc -g -c Dictionary.c

Dictionnaire : Dictionary.o
	gcc Dictionary.o -o Dictionary

clean :
	rm -f *.o Dictionary
