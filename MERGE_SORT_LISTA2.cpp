#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 26
void pause(void);

void mostrar(int vetor[TAM]);
void limpar(void);
void mergeSort(int vetor[], int comeco, int fim);
void merge(int vetor[], int comeco, int meio, int fim);


int main(){
	
	int i;
	int vetor[TAM];
	char letras[TAM];
	//char alephBeth[26] = { 'v', 'w','x', 'a', 'g', 'f', 'c', 'm', 'y', 'z', 'o', 'j', 'i', 'h', 'b', 'r', 'n', 'q', 's', 'p', 'k', 'd', 'l', 'e'  , 'u', 't' };
	
	printf("Letras do Alfabeto Desorganizada: \n");
	for(i = 0; i < 26; i++){
		printf(">> Digite uma letra aleatoriamente: \n");
		scanf("%c", &letras[i]);
		fflush(stdin);
	}
	printf("\n");
	
	for(i = 0; i < 26; i++){
		vetor[i] = (int) letras[i];
	}
	system("color 0E");
	printf("\n");
	printf("Letras do Alfabeto Organizado: \n");
	mergeSort(vetor, 0, 26);
	for(i = 0; i < 26; i++)
		printf("[%c]", vetor[i]);
	/*
	
	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%TAM+1;
	}
	
	*/
	/*
	printf("Algoritmo de Ordenação -> Merge Sort\n");
	printf("\n\n\n");
	printf("=========   Lista Desordenada  ================\n");
	mostrar(vetor);
	printf("\n===============================================\n");
	mergeSort(vetor, 0, TAM-1);
	printf("\n\n\n\n\n");
	printf("=========   Lista Ordenada  ===================\n");
	mostrar(vetor);
	printf("\n===============================================\n");
	printf("\n\n");
	printf("	EQUIPE	\n");
	printf("\n");
	pause();
	
	*/
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
		printf("[%d] \b", vetor[i]);
	printf("\n");
	printf("-----------------------------------------------\n");
	printf("Posicao |\b");
	for(i = 0; i < TAM; i++)
		printf("[%d] \b", i);
}
