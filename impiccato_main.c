#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impiccato.h"
#include <time.h>

int main (int argc, char *argv[]){
	char** dizionario;
	char* parolaNascosta;
	char* asterischi;
	char carattereUtente;
	char* caratteriUtilizzati[26];
	int numeroParole = 0, numero = 0, i = 0, tentativi = 10, indovinato = 0, vittoria=0;
	FILE* file;
	srand(time(NULL));
	file = fopen("Dizionario.txt", "r");
	numeroParole = contaParole(file);
	dizionario = importaDizionario();
	fclose(file);
	numero = rand()%(numeroParole+1);
	parolaNascosta = malloc(strlen(*(dizionario+numero)));
	parolaNascosta = *(dizionario+numero);
	asterischi = malloc(sizeof(char)*strlen(parolaNascosta));
	for (i=0; i < strlen(parolaNascosta); i++)
		asterischi[i]=asterischi[i]+'*';
	while(!vittoria && (tentativi>0) && (controllo_asterischi(asterischi)==1)){
		printf("\nDa Indovinare:\t%s\n", asterischi);
		printf("Numero di tentativi rimanenti: %d\n", tentativi);
		printf("Inserire una lettera: ");
		scanf("%c", &carattereUtente);
		while(getchar()!='\n');
		indovinato = validitaLettera(parolaNascosta, asterischi, carattereUtente);
		if ( indovinato == 0){
			tentativi--;
		}
	}
	if ((controllo_asterischi(asterischi)==0) && tentativi > 0)
		vittoria =1;
	printf("La parola é........ %s\n", parolaNascosta);
	if (vittoria==1)
		printf("Complimentiii!! Hai vinto....");
	else
		printf("HAI PERSO!!!!");
		
	free(asterischi);
	free(parolaNascosta);
	free(dizionario);
	return 0;
}
