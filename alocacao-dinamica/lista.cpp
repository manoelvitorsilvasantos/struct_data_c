/*
	----------------------------------------------

	-----------------------------------------------
	
	Lesson First - About Dinamic allocatation
	
	1) Find the number major and less on vetor.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <conio.h>
#define TAM 50

void pause(void);
void limpar(void);
void randomizar(int vetor[], int tam);
void mostrar(int vetor[], const char* texto, int tam);
void major(int vetor[], const char* texto, int tam);
void bl(void);
void line(void);

int main(int argv, char* argc[]){
	
	int* vetor, *vetorM, i, maior = 0, menor = 0, tam = TAM;

	
	
	//usando calloc
	vetor = (int*) calloc(tam, sizeof(int));
	for(i = 0; i < tam; i++){
		limpar();
		printf("Vetor on position [%d]\n", i);
		fprintf(stdout, ">> Write value on this position of vector? \n");
		scanf("%d", &vetor[i]);
		
	}
	//randomizar(vetor, tam);
	
	//usando o malloc
	vetorM = (int*) malloc(tam*sizeof(int));
	for(i = 0; i < tam; i++){
		limpar();
		printf("VetorM on position [%d]\n", i);
		fprintf(stdout, ">> Write value on this position of vetorM? \n");
		scanf("%d", &vetorM[i]);	
	}
	//randomizar(vetorM, tam);

	mostrar(vetor, "calloc", tam);	
	major(vetor, "calloc", tam);
	line();
	bl();
	bl();
	mostrar(vetorM, "Malloc", tam);
	major(vetorM, "Malloc", tam);
	line();
	free(vetor);
	free(vetorM);

	return 0;
}

void bl(void){
	printf("\n");
}

void line(void){
	fprintf(stdout, "==================================\n");
	
}

void major(int vetor[], const char* texto, int tam){
	
	int i, maior, menor;
	
	maior = vetor[0];
	menor = vetor[0];
	
	for(i = 0; i < tam; i++){
		
		if(vetor[i] > maior){
			maior = vetor[i];
		}
		
		if(vetor[i] < menor){
			menor = vetor[i];
		}
	}
	
	printf("Your list %s \n", texto);
	printf("More = %d\n", maior);
	printf("Less = %d\n", menor);
	pause();
	
}

void mostrar(int vetor[], const char* texto, int tam){
	int i;
	fprintf(stdout, "==================================\n");
	fprintf(stdout, "	Your List %s\n", texto);
	fprintf(stdout, "==================================\n");
	for(i = 0; i < tam; i++){
		printf("[%d] \b", vetor[i]);
	}
	printf("\n\n");
}

void randomizar(int vetor[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		vetor[i] = rand()%tam+1;
	}
}

void pause(void){
	getch();
}
void limpar(void){
	system("cls");
}
