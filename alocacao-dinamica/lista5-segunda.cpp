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
void zerar(int vector[], int tam);
int veracidade(int vector[], int tam);

int main(void){
	
	int *vector, *aux;
	int tam = 1500, i, v;
	int j, cont = 0, par = 0, zero = 0, s= 0;
	char sp = ' ';
	vector = (int*) calloc(tam, sizeof(int));
	aux = (int*) calloc(tam, sizeof(int));
	cont = 9;
	
	for(i = 0; i < tam; i++){
		
		vector[i] = rand()%9;	
	}
	
	bl();
	

	printf(" Realmente o vector tem o tamanho de exatamente %d posicoes \n", veracidade(vector, tam));
	printf("\n");
	bl();
	printf(" Lista do 10 primeiros vetores \n");
	bl();
	printf(" VALORES \0");
	cont = 9;
	for(i = 0; i < 10; i++){
		printf("[%d] \b", vector[i]);
		if(i == cont){
			printf("\n");
			for(j = 0; j < 10; j++){
				
				if(j == 0){
					printf(" INDICES \0");
				}
				printf("[%i] \b", j);
				zero++;
			}
			
			cont+= 10;	
		}
	}
	printf("\n");
	bl();
	s = tam-10;
	printf(" Lista do 10 ultimos vetores \n");
	bl();
	printf(" VALORES \0");
	
	for(i = s; i < 1500; i++){
		
		printf("[%d] %c%c ", vector[i], sp, sp);

	
	}
	printf("\n");
	printf(" INDICES \0");
	for(j = s; j < tam; j++){

		printf("[%i] \0", j);

	}
	
	
	
}

int veracidade(int vector[], int tam){
	int cont, i;
	cont  = 0;
	
	for(i = 0; i < tam; i++){
		cont++;
	}
	
	return cont;
}

void zerar(int vector[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		vector[i] = 0;
	}
}

void mostrar(int vetor[], const char* titulo, int tam){
	int i,j, cont, par, zero = 0;
	fprintf(stdout, "%s\n", titulo);
	line();
	cont = 9;
	
	
	printf("\n");
	printf("	Lista do vector\n");
	printf("----------------------------------------------\n");
	par = 10;
	zero = 0;
	printf(" LIN -> \0");
	for(i = 0; i < tam; i++){
		printf("[%i] \b", vetor[i]);
		if(i == cont){
			printf("\n");
			printf(" POS -> \0");
			
			if(zero == par ){
				par+= 10;
			}
			
			for(j = zero; j < par; j++){
				printf("[%i] \b", zero);
				zero++;
			}
			
			printf("\n");
			printf(" LIN -> \0");
			cont += 10;

		}		
	}
	printf("\n----------------------------------------------\n");
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
	printf("\n----------------------------------------------\n");
}
