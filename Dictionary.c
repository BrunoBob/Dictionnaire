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
	D->FSL = D->FBR = NULL ;
	D->car = 0;
	return D ;
}


Boolean Empty_Dictionary(Dictionary D){
	return (D->FSL == NULL) ;
}

Boolean Exist_Word(Dictionary D, char* word){ //Require a non empty dictionary
	
	//DEBUG
	printf("D->car = %c : strlen = %d : word = %s\n", D->car, strlen(word), word) ;
	
	if(strlen(word) == 0 && D->FSL->car == 42){ // If end of the word return true
		return True;
	}
	
	D = D->FSL ; 
	//DEBUG
	printf("D->car = %c : strlen = %d : word = %s\n", D->car, strlen(word), word) ;
	while(*word > D->car){
		if(D->FBR == NULL ){
			break;
		}
		D = D->FBR;
	}
	
	//DEBUG
	printf("D->car = %c : strlen = %d : word = %s\n\n", D->car, strlen(word), word) ;
	
	if(D->car == *word){
		
		return Exist_Word(D,word+1);
	}
	return False;		
}



