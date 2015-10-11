#include <stdio.h>
#include <stdlib.h>
#include "Dictionary.h"

int main(int argc, char *argv[]) {	
	
	Dictionary D ;
	D = Create_Dictionary() ;
	
	char* test = "bonjour" ;
		
	printf("%s and %c : %c : %c : %c \n", test, *test, *(test+1), *(test+4), *(test+6)) ;
	
	free(D);
	return 0;
}
