#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Dictionary.h"

int main(int argc, char *argv[]) {

	printf("This program is to be used as a dictionary.\n");
	printf("Several options are possible.\n");
	printf("Write the caracter before ':' to call the related function.\n");
	printf("--------------------------------\n");
	printf("1: Add a word in the dictionary.\n");
	printf("2: Delete a word of the dictionary.\n");
	printf("3: Display dictionary.\n");
	printf("4: Verify if a word is in the dictionary.\n");
	printf("5: Empty dictionary.\n");
	printf("6: Save Dictionary into a '.dic' file.\n");
	printf("7: Load a Dictionary from a '.dic' file.\n");
	printf("8: Quit.\n");

	int choice = 0;
	Dictionary D = Create_Dictionary();

	while(choice != 8) {

		printf("Select which action to make: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1 :
				char* word = (char*) malloc(25*sizeof(char));
				printf("Word to add: \n");
				scanf("%s", &word);
				D = Add_Word(D, word);
				free(word);
				break;
			case 2 :
				char* word = (char*) malloc(25*sizeof(char));
				printf("Word to delete: \n");
				scanf("%s", &word);
				D = Delete_Word(D, word);
				free(word);
				break;
			case 3 :
				Display_Dictionary();
				break;
			case 4 :
				char* word = (char*) malloc(25*sizeof(char));
				printf("Word to delete: \n");
				scanf("%s", &word);
				D = Exist_Wor(D, word);
				free(word);
				break;
			case 5 :
				D = Empty_Dictionary(D);
				break;
			case 6 :
				Save_Dictionary(D);
				break;
			case 7 :
				char* filename = (char*) malloc(25*sizeof(char));
				printf("name of the file to load: \n");
				scanf("%s", &filename);
				D = Load_Dictionary(filename);
				free(filename);
				break;
			default :
		}
	}
	return 0;
}
