all : Dictionary

main.o : Dictionary.h main.c
	gcc -c -Wall main.c
	
Dictionary.o : Dictionary.h Dictionary.c 
	gcc -c -Wall Dictionary.c
	
Dictionary : main.o Dictionary.o
	gcc main.o Dictionary.o -o Dictionary
	
clean : 
	rm *.o Dictionary
