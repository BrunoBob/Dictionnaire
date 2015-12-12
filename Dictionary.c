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
			if(current->car == '*'){
				next = Create_Dictionary() ;
				next->car = word[i] ;
				next->FBR = current->FBR ;
				current->FBR = next ;
			}
			else if(current->FSL == next){ //If the node to create is the first brother
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
		//next = next->FSL ;
	}
	next = Create_Dictionary(); //Add the end of the word caracter *
	next->car = '*' ;
	next->FBR = current->FSL ;
	current->FSL = next ;

	return D ;
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

Dictionary Load_Dictionary(char* filename, Dictionary D) {

	D = Empty_Dictionary(D);
	FILE* file = NULL ;
	file = fopen(filename, "r") ;

	if(file == NULL){
		printf("ERREUR : file not found\n") ;
	}
	else{
		char* word = malloc(25 * sizeof(char)) ;

		while(fgets(word, 25, file) != NULL){

				char c = word[0];	//Remove the '\n' from the word
				int i=0;
				while(c!='\n'){
					i++;
					c = word[i];
				}
				word[i]=0;
				if(Is_Empty_Dictionary(D) == True){
					printf("word loaded : %s \n", word) ;
					D = Add_Word(D, word) ; //Add the word to the dictionary
				}
				else if((Is_Empty_Dictionary(D) == False) && (Exist_Word(D,word) == False)){
					printf("word loaded : %s \n", word) ;
					D = Add_Word(D, word) ; //Add the word to the dictionary
				}
			}


		fclose(file) ;
	}

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

void Display_Dictionary(Dictionary D, char* word, int lenght) {
	//printf("display %s\n", word);
	char* newWord =  malloc((lenght + 1)  * sizeof(char)) ;
	int i ;
	for(i = 0 ; i< lenght ; i++){
		newWord[i] = word[i] ;  //Get the start of the word with the previous word
	}

	if(D->car == '*'){
		for(i = 0 ; i< lenght ; i++){ // If end of the word print it
			printf("%c", newWord[i]) ;
		}
		printf("\n") ;
	}
	else{
		newWord[lenght] = D->car ;
		Display_Dictionary(D->FSL, newWord, lenght + 1) ;//Call the function for the son
	}

	if(D->FBR != NULL){
		Display_Dictionary(D->FBR, newWord, lenght) ;  //Call the function for the brother
	}
	free(newWord) ;
}

void Save_Dictionary(Dictionary D, char* filename) {
	FILE* file = NULL ;

	file = fopen(filename, "w") ;

	if(file == NULL){
		printf("ERREUR : impossible to create the file\n") ;
	}
	else{
		SaveWords(D->FSL, "", 0, file) ;

		fclose(file) ;
	}
}

void SaveWords(Dictionary D, char* word, int lenght, FILE* file) { //Save all the words of a dictionary recursivly in a file

	char* newWord =  malloc((lenght + 1)  * sizeof(char)) ;
	int i ;
	for(i = 0 ; i< lenght ; i++){
		newWord[i] = word[i] ;  //Get the start of the word with the previous word
	}

	if(D->FBR != NULL){
		SaveWords(D->FBR, newWord, lenght, file) ;  //Call the function for the brother
	}

	if(D->car == '*'){
		printf("word save :") ;
		for(i = 0 ; i< lenght ; i++){ // If end of the word print it
			fputc(newWord[i], file) ;
			printf("%c", newWord[i]) ;
		}
		fputc('\n', file) ;
		printf("\n") ;
	}
	else{
		newWord[lenght] = D->car ;
		SaveWords(D->FSL, newWord, lenght + 1, file) ;//Call the function for the son
	}
	free(newWord) ;
}

Dictionary Delete_Word(Dictionary D, char* word){
	size_t lenght = strlen(word) ;
	int i ;
	Dictionary current = D ;
	Dictionary next = D->FSL ;
	Dictionary previous ;

	for(i=0 ; i < lenght ; i++){
		while((next != NULL) && (next->FBR == NULL)){
			next = next->FSL ;
		}
		if(next == NULL){
			break ;
		}
		previous = current ;
		current = current->FSL ;
		while(current->car != word[i]){
			previous = current ;
			current = current->FBR ;
		}
		next = current->FSL ;
	}

	if(current->FBR != NULL){
		if(previous->FSL == current){
			previous->FSL = current->FBR ;
		}
		else if(previous->FBR == current){
			previous->FBR = current->FBR ;
		}
	}

	if(current==D){
		D=Empty_Dictionary(D);
	}
	else{
		if(previous->FBR == current){
			previous->FBR = NULL;
		}
		else if(previous->FSL == NULL){
			previous->FSL = NULL;
		}
		next = current->FSL ;
		for( ; i < lenght ; i++){
			free(current) ;
			current = next ;
			next = next->FSL ;
		}
		if(current->FBR == NULL && current->FSL->FBR==NULL){
			if(previous->FBR == current){
				previous->FBR = NULL;
			}
			else if(previous->FSL == NULL){
				previous->FSL = NULL;
			}
			free(current);
		}
		if(next->FBR != NULL){
			current->FSL = next->FBR ;
		}
		free(next) ;
	}

	return D;
}
