#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 100

void pause(void);

void mostrar(int vetor[TAM]);
void mostrarInvertido(int vetor[TAM]);
void limpar(void);
void mergeSort(int vetor[], int comeco, int fim);
void mergeSortInvertido(int vetor[], int comeco, int fim);
void merge(int vetor[], int comeco, int meio, int fim);


int main(){
	
	int vetor[TAM], i;
	
	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%TAM+1;
	}
	
	
	
	printf("Algoritmo de Ordenação -> Merge Sort\n");
	printf("\n\n\n");
	printf("=========   Lista Desordenada  ================\n");
	mostrar(vetor);
	printf("\n===============================================\n");
	mergeSort(vetor, 0, 99);
	printf("\n\n\n\n\n");
	printf("=========   Lista Ordenada CRESCENTE ==========\n");
	mostrar(vetor);
	printf("\n===============================================\n");

	printf("\n\n\n\n\n");
	printf("=========   Lista Ordenada DECRESCENTE ========\n");
	mostrarInvertido(vetor);
	
	printf("\n===============================================\n");
	printf("\n\n");
	printf("	EQUIPE	\n");
	printf("\n");
	pause();
	return 0;
}
void pause(void){
	getch();
}

void limpar(void){
	system("cls");
}


void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;

    int *vetAux;

    vetAux = (int*)malloc(tam * sizeof(int));


    while(com1 <= meio && com2 <= fim){

        if(vetor[com1] < vetor[com2]) {

            vetAux[comAux] = vetor[com1];

            com1++;

        } else {

            vetAux[comAux] = vetor[com2];

            com2++;

        }

        comAux++;

    }


    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade

        vetAux[comAux] = vetor[com1];

        comAux++;

        com1++;

    }


    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade

        vetAux[comAux] = vetor[com2];

        comAux++;

        com2++;

    }


    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original

        vetor[comAux] = vetAux[comAux-comeco];

    }

    

    free(vetAux);

}


void mergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim) {

       

        int meio = (fim+comeco)/2;


        mergeSort(vetor, comeco, meio);

        mergeSort(vetor, meio+1, fim);

        merge(vetor, comeco, meio, fim);

    }

}



void mostrar(int vetor[TAM]){
	int i, tam;
	
	tam  = sizeof(vetor);
	
	printf("Valor 	|\b");
	for(i = 0; i < TAM; i++)
		printf("[%dn] \b", vetor[i]);
	printf("\n");
	printf("-----------------------------------------------\n");
	printf("Posicao |\b");
	for(i = 0; i < TAM; i++)
		printf("[%d] \b", i);
}

void mostrarInvertido(int vetor[TAM]){
	int i, tam;
	tam  = sizeof(vetor);
	
	printf("Valor 	|\b");
	for(i = TAM-1; i >= 0; i--)
		printf("[%dn] \b", vetor[i]);
	printf("\n");
	printf("-----------------------------------------------\n");
	printf("Posicao |\b");
	for(i = 0; i < TAM; i++)
		printf("[%d] \b", i);
}



