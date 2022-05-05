/*
	----------------------------------------------

	-----------------------------------------------
	
	Lesson First - About Dinamic allocatation
	
	2) Write your full name on allocate dinamic in vetor.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <conio.h>

void limpar(void){
	system("cls");
}

int main(){
	int i;

	char *nome;
	char *sobrenome;
	
	nome = (char*) calloc(26, sizeof(char));
	
	printf("\n");
	printf("Write your first name: \n");
	fflush(stdin);
	gets(nome);
	printf("\n");
	strcat(nome, " ");
	
	sobrenome = (char*) calloc(50, sizeof(char));
	
	printf("\n");
	printf("Write your last name: \n");
	fflush(stdin);
	gets(sobrenome);
	printf("\n");
	nome = (char*) realloc(nome, 55*sizeof(char));
	strcat(nome, sobrenome);
	
	limpar();
	printf("\n");
	printf("Your full name: \n");
	printf("%s \n", nome);
	printf("\n");
	
	free(nome);
	free(sobrenome);
	
	return 0;
}
