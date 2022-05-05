/*
	----------------------------------------------

	-----------------------------------------------

	Lesson First - About Dinamic allocatation
	Primeira Atividade - Sobre alocação Dinâmica
	
	2) Write your full name on allocate dinamic in vetor.
	   Escreva seu nome completo on vetor  alocado dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <conio.h>

void pause(void);
void limpar(void);
void mostrar(int vetor[], const char* titulo, int tam);
void bl(void);
void line(void);


int main(){
	
	int tam, *vector, i;
	
	printf("Write size of your vector?\n");
	scanf("%d", &tam);
	
	vector = (int*) calloc(tam, sizeof(int));
	
	
	for(i = 0; i < tam; i++){
		limpar();
		printf("\n");
		printf("Write the value to vector on position[%d]: \n", i);
		scanf("%d", &vector[i]);	
	}
	
	limpar();
	line();
	mostrar(vector, "Vector List", tam);
	free(vector);
	return 0;
}


void mostrar(int vetor[], const char* titulo, int tam){
	int i;
	fprintf(stdout, "%s\n", titulo);
	line();
	for(i = 0; i < tam; i++){
		printf("[%d] \b", vetor[i]);
	}
	printf("\n");
}

void pause(void){
	getch();
}

void limpar(void){
	system("cls");
}

void bl(void){
	printf("\n");
}

void line(void){
	printf("===================================\n");
}
