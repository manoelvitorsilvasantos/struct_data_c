/*
	Lucas
	Manoel Vitor
	Reginaldo


*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(){
	
	long *vetor;
	int contador, estado , valor, i;
	
	vetor = (long*) malloc(sizeof(long));
	
	estado = 0;
	contador = 0;
	
	while(estado == 0){
		
		printf(">> Digite o valor na posicao [%i]: \n", contador);
		scanf("%li", &vetor[contador]);
		
		if( vetor[contador] ==  0 ){
			estado = 1;
			break;
		}
		
		contador++;
		vetor = (long*) realloc(vetor, sizeof(long));		
	} 
	
	
	
	
	printf("\n\n Sua lista -> .....\n");
	printf("\n");
	
	for(i = 0; i < contador; i++){
		printf("[%li] \b", vetor[i]);
	}

	
	//libera o espaco
	free(vetor);
	return 0;
}

