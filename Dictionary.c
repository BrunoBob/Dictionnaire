#include "Dictionary.h"

#define __DEBUG

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

Dictionary Add_Word(Dictionary D, char* word) {

	if(!Is_Empty_Dictionary(D)){
		if(Exist_Word(D,word) == True) {
			return D;
		}
	}

	size_t length = strlen(word);
	int i ;

	Dictionary current = D ;
	Dictionary next = D->FSL ;

	for(i = 0 ; i < length ; i++){
		if(next == NULL){ // If fisrt son is null then break and create the rest of the word
			break ;
		}
		while((next != NULL) && (next->car < word[i])){ //Search the good caracter while node is not null
			current = next;
			next = next->FBR ;
		}
		if(next == NULL || (next->car != word[i])){ // If the current caracter doesnt exist we create it
			if(current->FSL == next){ //If the node to create is the first brother
				next = Create_Dictionary() ;
				next->car = word[i] ;
				next->FBR =current->FSL ;
				current->FSL = next ;
			}
			else{
				next = Create_Dictionary() ;
				next->car = word[i] ;
				next->FBR = current->FBR ;
				current->FBR = next ;
			}
		}
		current = next ;
		next = next->FSL ;
	}
	for( ; i < length ; i++){ // Add the rest of the word wich doesnt exist yet
		next = Create_Dictionary();
		next->car = word[i] ;
		current->FSL = next ;
		current = next ;
		next = next->FSL ;
	}
	next = Create_Dictionary(); //Add the end of the word caracter *
	next->car = '*' ;
	current->FSL = next ;

	return D ;


		/*int ascii1, ascii2;

	// E is current, while F is next. D is the root. N is a new node.
	Dictionary E = Create_Dictionary();
	Dictionary F = Create_Dictionary();
	Dictionary N = Create_Dictionary();
	Boolean finish = False;
	E = D;
	F = D;
	if(F->FSL != NULL) {
		F = F->FSL;

		//We check for each character if it exists already.
		while((i < length) && (finish == False)) {

			ascii1 = word[i];
			ascii2 = F->car;

			//If it exists, we go to the next level and check the next character.
			if(word[i] == F->car) {
				if (F->FSL != NULL) {
					E = F;
					F = F->FSL;
				}
				else {
					finish = True;
				}
				i++;
			}//If we are not sure, we check the next character.
			else if(ascii1 < ascii2) {
				if(F->FBR != NULL) {
					E = F;
					F = F->FBR;
				}
				else {
					N->car = ascii1;
					F->FBR = N;
					E = F;
					F = N->FBR;
					finish = True;
					i++;
				}
			}//If the letter did not exist, we create it and finish the word.
			else if(ascii1 > ascii2) {
				N->car = ascii1;
				N->FBR = F;
				if(E->FSL == F) {
					E->FSL = N;
				}
				else {
					E->FBR = N;
				}
				finish = True;
				i++;
			}
		}
	}
	else {
		N->car = word[i];
		F = N->FBR;
		E->FSL = N;
		finish = True;
		i++;
	}

	if(finish == True) {
		for(; i < length; i++) {
			Dictionary R = Create_Dictionary();
			R->car = word[i];
			N->FSL = R;
			N = R;
		}
		Dictionary R = Create_Dictionary();
		R->car = 42;
		N->FSL = R;
	}

	return D;*/

}

Dictionary Empty_Dictionary(Dictionary D) {
	if(Is_Empty_Dictionary(D) == False) {
		Empty_Dictionary(D->FSL);
	}
	if(D->FBR != NULL) {
		Empty_Dictionary(D->FBR);
	}
	if(D->car != 0){
		free(D);
	}
	else{
		D->FSL = NULL;
	}
	return D;
}

Dictionary Load_Dictionary(char* filename) {
	Dictionary D = Create_Dictionary();
	FILE* file;
	char* word = malloc(25*sizeof(char));
	ssiez_t line;
	size_t word_length = 25;

	file = fopen(filename, "r");
	if(file == NULL) {
		printf("The file does not exist.\n")
		return NULL;
	}
	while((line = gets(word, word_length, file)) != NULL) {
		Add_Word(D, word);
	}

	printf("The Dictionary has been loaded successfully.");
	return D;
}

Boolean Is_Empty_Dictionary(Dictionary D){
	if(D->FSL == NULL) {
		return True;
	}
	return False;
}

Boolean Exist_Word(Dictionary D, char* word){ //Require a non empty dictionary

	if(strlen(word) == 0 && D->FSL->car == 42){ // If end of the word return true
		return True;
	}
	D = D->FSL ;
	while(*word > D->car){
		if(D->FBR == NULL ){
			break;
		}
		D = D->FBR;
	}
	if(D->car == *word){
		return Exist_Word(D,word+1);
	}
	return False;
}

void Display_Dictionary(Dictionary D) {
	//TODO
}

void Save_Dictionary(Dictionary D, char* filename) {
	//TODO
}
