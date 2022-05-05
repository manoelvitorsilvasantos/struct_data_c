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
#define TAM 10

void pause(void);
void limpar(void);
void mostrar(int vetor[], const char* titulo);
void bl(void);
void line(void);
void imparPar(int vetor[]);

int main(){
	
	int *vetor, i;
	
	vetor = (int*) malloc(TAM*sizeof(int));
	
	for(i = 0; i < TAM; i++){
		limpar();
		fprintf(stdout, ">> Write value of position[%d] on vetor\n", i);
		scanf("%d", &vetor[i]);
	}
	
	mostrar(vetor, "Vetor list");
	imparPar(vetor);
	free(vetor);
	
	return 0;
}

void imparPar(int vetor[]){
	int par, impar, i;
	
	par = 0;
	impar  = 0;
	
	
	for(i = 0; i < TAM; i++){
		
		if(vetor[i] % 2 == 0){
			++par;
		}
		else{
			++impar;
		}	
	}
	
	limpar();
	mostrar(vetor, "Vector list");
	line();
	printf(" You have [%d] numbers odd/Impar! \n", impar);
	printf(" You have [%d] numbers pair/Par! \n", par);
}

void mostrar(int vetor[], const char* titulo){
	int i;
	fprintf(stdout, "%s\n", titulo);
	line();
	for(i = 0; i < TAM; i++){
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
