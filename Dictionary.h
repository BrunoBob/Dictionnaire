#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef enum {False, True} Boolean;

typedef struct node {
	char car;
	struct node *FSL, *FBR; //First Son Left and First Brother Right
}*Dictionary;

Dictionary Create_Dictionary(void);// Done
Dictionary Add_Word(Dictionary D, char* word);//Done
Dictionary Delete_Word(Dictionary D, char* word); //Done
Dictionary Empty_Dictionary(Dictionary D);//Done
Dictionary Load_Dictionary(char* filename, Dictionary D);//Done
void SaveWords(Dictionary D, char* word, int lenght, FILE* file) ;
Boolean Exist_Word(Dictionary D, char* word);//Done
Boolean Is_Empty_Dictionary(Dictionary D);//Done
void Display_Dictionary(Dictionary D, char* word, int lenght);
void Save_Dictionary(Dictionary D, char* filename); //Done
