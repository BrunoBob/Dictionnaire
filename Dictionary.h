#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef enum {False, True} Boolean;

typedef struct node {
	char car;
	struct node *FSL, *FBR; //First Son Left and First Brother Right
}*Dictionary;

Dictionary Create_Dictionary(void);
Dictionary Add_Word(Dictionary D, char* word);
Dictionary Delete_Word(Dictionary D, char* word);
Dictionary Empty_Dictionary(Dictionary D);
Dictionary Load_Dictionary(char* filename);
Boolean Exist_Word(Dictionary D, char* word);
Boolean Is_Empty_Dictionary(Dictionary D);
void Display_Dictionary(Dictionary D);
void Save_Dictionary(Dictionary D);
