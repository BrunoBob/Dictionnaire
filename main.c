#include "Dictionary.h"

char* getParameter() {
	char* parameter;
	parameter = malloc(25*sizeof(char));
	scanf("%s", parameter);
	return parameter;
}

int main(int argc, char *argv[]) {

	system("clear");

	int choice = 0;
	Dictionary D = Create_Dictionary();

	while(choice != 8) {

		printf("This program is to be used as a dictionary.\n");
		printf("Several options are possible.\n");
		printf("Write the caracter before ':' to call the related function.\n");
		printf("--------------------------------\n");
		printf("1: Add a word in the dictionary.\n");
		printf("2: Delete a word of the dictionary.\n");
		printf("3: Display dictionary.\n");
		printf("4: Verify if a word is in the dictionary.\n");
		printf("5: Empty dictionary.\n");
		printf("6: Save Dictionary in a file.\n");
		printf("7: Load a Dictionary from a file.\n");
		printf("8: Quit.\n");

		printf("Select which action to make: ");
		scanf("%d", &choice);
		system("clear");
		char* parameter;

		switch(choice) {
			case 1 :
				printf("Word to add: \n");
				parameter = getParameter();
				if(Is_Empty_Dictionary(D) == False) {
					if(Exist_Word(D,parameter) == True) {
						printf("Error : The word '%s' already in the dictionary.\n", parameter);
						break;
					}
				}
				D = Add_Word(D, parameter);
				printf("The word '%s' has been added.\n", parameter);
				free(parameter);
				break;
			case 2 :
				printf("Word to delete: \n");
				parameter = getParameter();
				if(Is_Empty_Dictionary(D) == True) {
					printf("Error : Can't delete because the dictionary is empty.\n");
				}
				else if(!Exist_Word(D,parameter) == True) {
					printf("Error : The word '%s' is not in the dictionary.\n", parameter);
				}
				else {
					D = Delete_Word(D, parameter);
					printf("The word '%s' has been deleted.\n", parameter);
				}
				free(parameter);
				break;
			case 3 :
				if(Is_Empty_Dictionary(D) == True) {
					printf("Error : The dictionary is empty and can't be displayed.\n");
				}
				else {
					Display_Dictionary(D->FSL, "", 0);
				}
				break;
			case 4 :
				printf("Word to verify: \n");
				parameter = getParameter();
				if(Is_Empty_Dictionary(D) == True) {
					printf("Error : The dictionary is empty.\n");
					break;
				}
				if(Exist_Word(D, parameter) == True) {
					printf("The word '%s' is in the dictionary.\n", parameter);
				}
				else{
					printf("The word '%s' is not in the dictionary.\n", parameter);
				}
				free(parameter);
				break;
			case 5 :
				D = Empty_Dictionary(D);
				if(Is_Empty_Dictionary(D) == True) {
					printf("The dictionary is now empty.\n");
				}
				break;
			case 6 :
				if(Is_Empty_Dictionary(D) == True) {
					printf("Error : The dictionary is empty.\n");
				}
				else {
					printf("Name of the file in which you want to save: \n");
					parameter = getParameter();
					Save_Dictionary(D, parameter);
					free(parameter);
				}
				break;
			case 7 :
				printf("Name of the file to load: \n");
				parameter = getParameter();
				D = Load_Dictionary(parameter, D);
				free(parameter);
				break;
		}
	}
	return 0;
}
