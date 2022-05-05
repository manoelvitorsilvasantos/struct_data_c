#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAM 10

void pause(void);
void bl(void);
void randomico(int vetor[]);
void mostrar(const char* titulo, int vetor[]);
void merge(int vetor[], int vetorPosInicio, int vetorPosMeio, int vetorPosFinal);
void mergeSort(int vetor[], int vetorPosInicio, int vetorPosFinal);

void mergeInverse(int vetor[], int vetorPosInicio, int vetorPosMeio, int vetorPosFinal);
void mergeSortInverse(int vetor[], int vetorPosInicio, int vetorPosFinal);

int main(){
	
	int vetor[TAM];
	bl();
	randomico(vetor);
	mostrar(" Lista com valores randomicos*", vetor);
	bl();
	
	mergeSort(vetor, 0, TAM-1);
	mostrar(" Lista ordenada crescente*", vetor);
	bl();
	
	mergeSortInverse(vetor, 0, TAM-1);
	mostrar(" Lista ordenada decrescente*", vetor);
	bl();
	
	
	
	pause();
	return 0;
}

void bl(void){
	printf("\n");
}

void pause(void){
	getch();
}
void randomico(int vetor[]){
	int posicao;
	for(posicao = 0; posicao < TAM; posicao++){
		vetor[posicao] = rand()%TAM+1;
	}
}

void mostrar(const char* titulo, int vetor[]){
	int posicao;
	printf("%s\n", titulo);
	
	printf("-------------------------------\n");
	
	for(posicao = 0; posicao < TAM; posicao++){
		
		printf("[%d] \b", vetor[posicao]);

	}
	printf("\n");
	printf("_______________________________\n");
}




void merge(int vetor[], int vetorPosInicio, int vetorPosMeio,  int vetorPosFinal){
	
	int n1 = vetorPosInicio, n2 = vetorPosMeio+1, comAux = 0, tamanho = vetorPosFinal-vetorPosInicio+1;
	int* vetorAuxiliar;
	
	vetorAuxiliar = (int*) malloc(tamanho*sizeof(int));
	
	while(n1 <= vetorPosMeio && n2 <= vetorPosFinal){
		
		if(vetor[n1] < vetor[n2]){
			vetorAuxiliar[comAux] = vetor[n1];
			++n1;
		}
		else{
			vetorAuxiliar[comAux] = vetor[n2];
			++n2;
		}
		
		++comAux;
		
	}
	
	while(n1 <= vetorPosMeio){
		vetorAuxiliar[comAux] = vetor[n1];
		++comAux;
		++n1;
	}
	
	while(n2 <= vetorPosFinal){
		vetorAuxiliar[comAux] = vetor[n2];
		++comAux;
		++n2;
	}
	
	for(comAux = vetorPosInicio; comAux <= vetorPosFinal; comAux++){
		vetor[comAux] = vetorAuxiliar[comAux-vetorPosInicio];
	}
	
	//LIBERA O ESPACO ALOCADO PELO VETOR 'vetorAuxiliar';
	free(vetorAuxiliar);
	
}
	


void mergeSort(int vetor[], int vetorPosInicio, int vetorPosFinal){
	
	if(vetorPosInicio < vetorPosFinal){
		
		int vetorPosMeio = (vetorPosFinal+vetorPosInicio)/2;
		
		mergeSort(vetor, vetorPosInicio, vetorPosMeio);
		
		mergeSort(vetor, vetorPosMeio+1, vetorPosFinal);
		
		merge(vetor, vetorPosInicio, vetorPosMeio, vetorPosFinal);
		
	}
}

//**********************************************************************************************************//
/*
		MERGE SORT INVERSO

*/

void mergeInverse(int vetor[], int vetorPosInicio, int vetorPosMeio,  int vetorPosFinal){
	
	int n1 = vetorPosInicio, n2 = vetorPosMeio+1, comAux = 0, tamanho = vetorPosFinal-vetorPosInicio+1;
	int* vetorAuxiliar;
	
	vetorAuxiliar = (int*) malloc(tamanho*sizeof(int));
	
	while(n1 <= vetorPosMeio && n2 <= vetorPosFinal){
		
		if(vetor[n1] < vetor[n2]){
			vetorAuxiliar[comAux] = vetor[n2];
			++n2;
		}
		else{
			vetorAuxiliar[comAux] = vetor[n1];
			++n1;
		}
		
		++comAux;
		
	}
	
	while(n1 <= vetorPosMeio){
		vetorAuxiliar[comAux] = vetor[n1];
		++comAux;
		++n1;
	}
	
	while(n2 <= vetorPosFinal){
		vetorAuxiliar[comAux] = vetor[n2];
		++comAux;
		++n2;
	}
	
	for(comAux = vetorPosInicio; comAux <= vetorPosFinal; comAux++){
		vetor[comAux] = vetorAuxiliar[comAux-vetorPosInicio];
	}
	
	//LIBERA O ESPACO ALOCADO PELO VETOR 'vetorAuxiliar';
	free(vetorAuxiliar);
	
}
	


void mergeSortInverse(int vetor[], int vetorPosInicio, int vetorPosFinal){
	
	if(vetorPosInicio < vetorPosFinal){
		
		int vetorPosMeio = (vetorPosFinal+vetorPosInicio)/2;
		
		mergeSortInverse(vetor, vetorPosInicio, vetorPosMeio);
		
		mergeSortInverse(vetor, vetorPosMeio+1, vetorPosFinal);
		
		mergeInverse(vetor, vetorPosInicio, vetorPosMeio, vetorPosFinal);
		
	}
}


