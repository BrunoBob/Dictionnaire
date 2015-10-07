#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef enum {Faux, Vrai} Boolean;

typedef struct noeud {
	char car;
	struct noeud *PFG, *PFD;
}*Dictionnaire;

Dictionnaire Creer_Dictionnaire(void);
Dictionnaire Ajouter_Mot(Dictionnaire D, char* mot);
Dictionnaire Supprimer_Mot(Dictionnaire D, char* mot); 
Boolean Existe_Mot(Dictionnaire D, char* mot);
Boolean Dictionnaire_Vide(Dictionnaire D);
