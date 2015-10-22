#include "Dictionary.h"

char* getParameter(){
	char* parameter ;
	parameter = malloc(25*sizeof(char)) ;
	scanf("%s", parameter) ;
	return parameter ;
}

int main(int argc, char *argv[]) {	

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
		printf("6: Save Dictionary into a '.dic' file.\n");
		printf("7: Load a Dictionary from a '.dic' file.\n");
		printf("8: Quit.\n");
		
		

		printf("Select which action to make: ");
		scanf("%d", &choice);
		system("clear");
		char* parameter ;

		switch(choice) {
			case 1 :
				printf("Word to add: \n");
				parameter = getParameter();
				D = Add_Word(D, parameter) ;
				free(parameter);
				break;
			case 2 :
				printf("Word to delete: \n");
				parameter = getParameter();
				//D = Delete_Word(D, parameter);
				free(parameter);
				break;
			case 3 :
				Display_Dictionary(D);
				break;
			case 4 :
				printf("Word to verify: \n");
				parameter = getParameter();
				if(Is_Empty_Dictionary(D)){
					printf("The dictionary is empty\n") ;
					break;
				}
				if(Exist_Word(D, parameter)== True){
					printf("The word is in the dictionary\n");
				}
				else{
					printf("The word is not in the dictionary\n");
				}
				free(parameter);
				break;
			case 5 :
				D = Empty_Dictionary(D);
				if(Is_Empty_Dictionary(D)){
					printf("The dictionary is empty\n") ;
				}
				break;
			case 6 :
				printf("Name of the file in which you want to save: \n");
				parameter = getParameter();
				Save_Dictionary(D, parameter);
				free(parameter);
				break;
			case 7 :
				printf("Name of the file to load: \n");
				parameter = getParameter();
				D = Load_Dictionary(parameter);
				free(parameter);
				break;
		}
	}
	/*Dictionary a = Create_Dictionary();
	a= a->FBR ;
	if(a == NULL){
		printf("GFIENEFIOEH\n");
	}*/
	return 0;
}
