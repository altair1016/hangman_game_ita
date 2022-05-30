#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impiccato.h"
// Ricorda che l'ultima parola dell'array è \n quindi è len(dizionario-2) la fine
char** importaDizionario(){
	char **dizionario;
	char stringaProvvisoria[50]=""; 
	char* stringaDef;// stringa in cui salvare provvisoriamente la parola
	FILE* file;
	int i =0;
	file = fopen("Dizionario.txt", "r");
	if (file == NULL){
		fprintf(stderr, "Il file non è stato aperto correttamente!\n");
		exit(1);
	}
	dizionario = malloc(sizeof(char *)*(contaParole(file)));// creazione dizionario
	if (dizionario == NULL)
		fprintf(stderr, "Il dizionario non è stato creato correttamente!\n");
	file = fopen("Dizionario.txt", "r");
	while(!feof(file)) 
	{
		fscanf(file, "%s", stringaProvvisoria);
		stringaDef= malloc(sizeof(char)*(strlen(stringaProvvisoria)-1));
		strcpy(stringaDef, stringaProvvisoria);
		dizionario[i]= stringaDef;
		i++;
	}

	fclose(file);
	free(stringaDef);
	return dizionario;
		
}

int contaParole(FILE* ptrFile){
	char carattere;
	int linee = 0;
	while ((carattere = getc(ptrFile))!= EOF)
		if (carattere == '\n')
			linee++;
	fclose(ptrFile);
	return linee;
		
}

int validitaLettera(char *parolaNascosta, char *asterischi, char carattereUtente){
	int i=0;
	int indovinato = 0, contaUguaglianze=0;
	for (i =0; i < strlen(parolaNascosta); i++){
		if (toupper(parolaNascosta[i]) == toupper(carattereUtente)){
			asterischi[i] = parolaNascosta[i];
			contaUguaglianze++;
		}
	}
	if (contaUguaglianze > 0)
		indovinato = 1;
	
	return indovinato;
}

int controllo_asterischi(char* asterischi){
	int i=0, controllo=0;
	for (i=0; i < strlen(asterischi); i++){
		if (asterischi[i]=='*')
			controllo = 1;
	}
	return controllo;
}
	