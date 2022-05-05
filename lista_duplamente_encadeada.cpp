#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

typedef struct Node{
	int info;
	struct Node *anterior, *proximo;
}node;

node *head;

void menu(node *no);
void criar(node *no);
void inserir(node *no);
void inserirInicio(node *no);
void inserirFim(node *no);
void remover(node *no);
void removerInicio(node *no);
void removerFim(node *no);
void removerLista(node *no);
void mostrar(node *no);
void mostrarIn(node *no);
node* aloca();
bool vazio(node *no);
int tam;

int main(void){
	int i;
	node *no = (node*)malloc(sizeof(node));
	if(!no){
		printf("SEM MEMORIA PARA ALOCAR!\n");
		exit(0);	
	}
	criar(no);
	/*for(i = 0; i < 10; i++)
		inserir(no);
	*/
	menu(no);
	
	return 0;
}

void menu(node *no){
	int op;
	while(op){
		system("cls");
		printf("1.Inserir\n");
		printf("2.Remover\n");
		printf("3.Apagar Lista\n");
		printf("4.Mostra Normal\n");
		printf("5.Mostra Invertido\n");
		printf("0.Sair\n");
		scanf("%d", &op);
		switch(op){
			case 0://sair
				free(no);
				exit(0);
			break;
			
			case 1: //inserir
				system("cls");
				inserir(no);
			break;
			
			case 2://remover um no
				system("cls");
				if(!vazio(no)){
					remover(no);
					getch();
				}
				else{
					printf("Lista vazia!\n");
					getch();
				}
			break;
			
			case 3: //apagar lista
				system("cls");
				if(!vazio(no)){
					removerLista(no);
				}
				else{
					printf("Lista vazia!\n");
					getch();
				}
			break;
			
			case 4: //nostrar normal
				system("cls");
				if(!vazio(no)){
					mostrar(no);
					getch();
				}
				else{
					printf("Lista vazia!\n");
					getch();
				}
			break;
			
			case 5: // mostrar invertido
				system("cls");
				if(!vazio(no)){
					mostrarIn(no);
					getch();
				}
				else{
					printf("Lista vazia!\n");
					getch();
				}
			break;
			
			default: //opcao invalida
				system("cls");
				printf("OPCAO INVALIDA! \n");
				getch();
			break;
		}
	}
}

void criar(node *no){
	no->proximo = NULL;
	no->anterior = NULL;
	tam = 0;	
}

void inserir(node *no){
	
	node *novo;
	novo = aloca();
	novo->proximo = NULL;
	novo->anterior = NULL;
	
	if(no == NULL)
	{
		no = novo;
		return;
	}
	else{
		
		while(no->proximo!=NULL){
			no = no->proximo;
		}
		no->proximo= novo;
		novo->anterior= no;
		tam++;
	}
	
}


void inserirInicio(node *no){
	node *novo = aloca();
	if(vazio(no)){
		no->proximo = novo;
		novo->anterior = no;
	}
	else{
		node* tmp = no->proximo;
		no->proximo = novo;
		tmp->anterior = novo;
		novo->anterior = no;
		novo->proximo = tmp;
	}
	tam++;
}

void inserirFim(node *no){
	
	node* tmp = no, *novo;
	novo = aloca();
	novo->proximo = NULL;
	novo->anterior = NULL;
	if(tmp == NULL)
	{
		tmp = novo;
		novo->anterior = tmp;
		tam++;
		return;
	}
	else{
		while(tmp->proximo!=NULL){
			tmp = tmp->proximo;
		}
		tmp->proximo= novo;
		novo->anterior= tmp;
		tam++;
	}
}

void remover(node *no){
	node *anterior = no;
	node *atual = no->proximo;
	while(atual->proximo!=NULL){
		anterior = atual;
		atual = atual->proximo;
	}
	printf("Valor removido foir = %d", atual->info);
	anterior->proximo = NULL;
	anterior->anterior = NULL;
	tam--;
}

void removerFim(node *no){
	
	node *anterior = no;
	node *atual = no->proximo;
	while(atual->proximo->proximo!=NULL){
		anterior = atual;
		atual = atual->proximo;
	}
	anterior->proximo = NULL;
	anterior->anterior = NULL;
}

void removerLista(node *no){
	if(!vazio(no)){
		removerLista(no->proximo); //remover do inicio da lista
		node* tmp = no->proximo;
		no->proximo = tmp->proximo;
		no->anterior = NULL;
	}
	else{
		printf("Lista apagada com sucesso!\n");
		getch();
	}
	tam = 0;
}

void mostrar(node *no){
	node* tmp = no->proximo;
	printf("\n");
	while(tmp!=NULL){
		printf("[%d]", tmp->info);
		tmp = tmp->proximo;
	}
	printf("\n");
}

void mostrarIn(node *no){
	node* tmp = no;
	while(tmp->proximo!=NULL){
		tmp = tmp->proximo;
	}
	node *aux;
	aux = tmp;
	do{
		printf("[%d]", aux->info);
		aux = aux->anterior;
	}while(aux!=NULL);
}

void removerInicio(node* no){
	node *tmp = no->proximo;
	no->proximo = tmp->proximo;
	no->anterior = NULL;
	tam--;
}

node* aloca(){
	node *novo = (node*)malloc(sizeof(node));
	
	if(novo == NULL){
		printf("Sem espaco na memoria! \n");
		exit(0);
	}	
	else{
		printf("Digite o valor: \n");
		scanf("%d", &novo->info);
		novo->anterior = NULL;
		novo->proximo = NULL;
	}
	return novo;
}
bool vazio(node *no){
	if(no->proximo == NULL)
		return true;
	else
		return false;
}
