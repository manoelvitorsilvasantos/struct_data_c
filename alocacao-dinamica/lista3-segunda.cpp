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

void escrever(int vector[], const char* texto, int tam);
int once(int vector[], int valor,  int tam);

int main(){
	
	int* vector, N, vezes;
	
	printf(">> Digite o valor para 'N' : \n");
	scanf("%d", &N);
	
	vector = (int*) calloc(N, sizeof(int));
	escrever(vector, "Digite o valor do vector na posicao", N);
	mostrar(vector, "Lista do vector", N);
	
	limpar();
	fprintf(stdout, ">> Digite o valor para identificarmos \n");
	fprintf(stdout, ">> Quantas vezes ele aparece: \n");
	scanf("%d", &vezes);
	
	limpar();
	printf("O valor %d aparece exatamente [%d] vezes", vezes,  once(vector, vezes, N));
	bl();
	printf("Veja para conferir!\n");
	bl();
	mostrar(vector, "Lista", N);
	line();
	free(vector);
	
	return 0;
}

int once(int vector[], int valor, int tam){
	int i, cont;
	
	cont = 0;
	
	for(i = 0; i < tam; i++){
		if(vector[i] == valor ){
			cont++;	
		}
	}
	
	return cont;
}

void escrever(int vector[], const char* texto, int tam){
	
	int i;
	
	fprintf(stdout, "%s\n", texto);
	line();
	for(i = 0; i < tam; i++){
		limpar();
		printf("%s [%d]\n", texto, i);
		scanf("%d", &vector[i]);
	}
	
	
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
