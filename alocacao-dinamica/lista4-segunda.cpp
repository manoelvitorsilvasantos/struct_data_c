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
int posicao(int estado, int tam);

int main(){
	
	int tam, choice, i, pos, cont, valor, contido;
	int* memoria;
	
	printf("\n");
	printf(">> Digite o tamanho da memoria? \n");
	scanf("%d", &tam);
	
	memoria = (int*) malloc(tam*sizeof(int));
	zerar(memoria, tam);
	
	while(1){
		
		limpar();
		printf("[1] - INSERIR VALOR \n");
		printf("[2] - CONSULTAR VALOR X \n");
		printf("[3] - MOSTRAR \n");
		printf("[0] - SAIR \n");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 0:
				exit(1);
			break;
			
			case 1:
				limpar();
				cont = 0;
				valor = 0;
				
				do{
					
					if(cont >= 1){
						limpar();
						printf("Essa posicao não foi allocada no seu vector! \n");
						pause();
					}
					limpar();
					//pega a posicao no vector
					printf(">> Digite a posicao: \n");
					scanf("%d", &pos);
					
					// --------------------
					
					cont++;
				}while(posicao(pos, tam) == 0);
				
				printf(">> Digite o valor: \n");
				scanf("%d", &valor);
				memoria[pos] = valor;
				line();
				printf("Valor %d foi inserido com sucesso....\n", valor);
				printf("Aperte [ENTER] para voltar ao MENU. \n");
				pause();
				
			break;
			
			case 2:
				
				limpar();
				
				printf("\n");
				cont = 0;
				valor = 0;
				contido = 0;
				
				do{
					
					if(cont >= 1){
						limpar();
						printf("Essa posicao não foi allocada no seu vector! \n");
						pause();
					}
					limpar();
					//pega a posicao no vector
					printf(">> Digite a posicao: \n");
					scanf("%d", &pos);
					
					// --------------------
					
					cont++;	
				}while(posicao(valor, tam) == 0);
				
				printf(">> Digite o valor: \n");
				scanf("%d", &valor);
				
				if(memoria[pos] == valor){
					limpar();
					printf("O valor = %d  foi encontrado na posicao[%d] do vector! \n", valor, pos);
					pause();
				}
				else{
					limpar();
					printf("O valor = %d  nao foi encontrado na posicao[%d] do vector! \n", valor, pos);
					pause();
				}
				
			break;
			
			case 3:
				limpar();
				mostrar(memoria, "Lista de vector", tam);
				pause();
			break;	
			
			default:
				limpar();
				printf("Opcao invalida, tente novamente \n");
				pause();
			break;
			
		}
		
	}
	
	free(memoria);
	return 0;
}

void zerar(int vector[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		vector[i] = 0;
	}
}

int posicao(int estado, int tam){
	
	if(estado >= 0 && estado < tam){
		return 1;
	}
	else if(estado < 0 || estado > tam){
		return 0;
	}
	else if(estado == tam || estado > tam){
		return 0;
	}
}

void escrever(const char* texto){
	printf("%s \n");
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
