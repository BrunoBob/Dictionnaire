#include <stdio.h>
#include <stdlib.h>
#include "Dictionary.h"

/* ASCII TABLE
 * 
 *  * (end of word) = 42
 * 
 *	a = 97
 * 	...
 * 	z = 122
 * 
 * 	A = 65
 * 	...
 * 	Z = 90 */


Dictionary Create_Dictionary(void){
	Dictionary D ;
	D = (Dictionary) malloc(sizeof(*D)) ;
	return D ;
}


Boolean Empty_Dictionary(Dictionary D){
	return (D->FSL == NULL) ;
}

Boolean Exist_Word(Dictionary D, char* word){
	
}



