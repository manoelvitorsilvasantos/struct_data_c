#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define filename "data.bin"

struct Endereco{
	char cidade[25];
	char rua[20];
	char bairro[15];
	char cep[15];
	char complemento[15];
	int numero;
};

typedef struct Pessoa{
	char nome[50];
	int sexo;
	int idade;
	struct Endereco end;
}pessoa;


void mostrar(const char* msg);
void limpar(void);
void pause(void);

int tam;

int main(void){
	
	tam = -1;
	FILE* arq;
	pessoa p[10];
	
	int opc, pos = 0, res = 0, cont = 0;
	
	res = 0;
	
	while(1){
		
		
		limpar();
		mostrar("MENU PRINCIPAL");
		mostrar("[1] - CADASTRAR");
		mostrar("[2] - CONSULTAR");
		mostrar("[0] - SAIR");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 0:
				exit(1);
			break;
			
			case 1:
				
				
				limpar();
				tam++;
				mostrar("CADASTRO DE PESSOA");
				mostrar("digite as informacoes solicitadas: ");
				printf("Nome: \n");
				fflush(stdin);
				gets(p[tam].nome);
				
				printf("Sexo [1] MASCULINO [2] FEMININO \n");
				scanf("%d", &p[tam].sexo);
				
				printf("Idade: \n");
				scanf("%d", &p[tam].idade);
				
				printf("Rua: \n");
				fflush(stdin);
				gets(p[tam].end.rua);
				
				printf("Bairro\n");
				fflush(stdin);
				gets(p[tam].end.bairro);
				
				printf("Complemento\n");
				fflush(stdin);
				gets(p[tam].end.complemento);
				
				printf("Numero: \n");
				scanf("%d", &p[tam].end.numero);
				
				printf("Cidade\n");
				fflush(stdin);
				gets(p[tam].end.cidade);

				printf("Cep\n");
				fflush(stdin);
				gets(p[tam].end.cep);
				
				arq = fopen("data.bin", "ab");
				
				if(arq == NULL){
					mostrar("Erro ao abrir arquivo");
					exit(1);
				}
				
				fwrite(&p, sizeof(pessoa), tam, arq);
				cont++;
				
				
				if(ferror(arq))
					mostrar("Erro, na gravacao do arquivo!");
				else
					mostrar("Cadastro realizado com sucesso!");
				pause();
				
				tam++;
			
			break;
			
			case 2: // leitura
				
				
				if(tam == -1){
					limpar();
					mostrar(">> Arquivo vazio!");
					pause();
				}
				else{
					
					limpar();
					int i, contador;
					arq = fopen("data.bin", "rb");
					
					if(arq == NULL){
						mostrar("Erro ao abrir arquivo!");
						exit(1);
					}
					
					res = fread(&p, sizeof(pessoa), tam, arq);
					/*
					if(res != tam){
						limpar();
						printf("Erro ao abrir arquivo!\n");
						pause();
						exit(1);
					}
					*/
					
					for(i = 0; i < tam; i++){
						
						printf("Nome: %s \n", p[i].nome);
						if(p[i].sexo == 1)
							printf("Sexo: Masculino\n");
						else if(p[i].sexo == 2)
							printf("Sexo: Feminino\n");
						printf("Idade: %d \n", p[i].idade);
						printf("Rua: %s \n", p[i].end.rua);
						printf("Bairro: %s \n", p[i].end.bairro);
						printf("CEP: %s \n", p[i].end.cep);
						printf("Cidade: %s \n", p[i].end.cidade);
						printf("Complemento: %s \n", p[i].end.complemento);
						printf("Numero: %d \n", p[i].end.numero);
						printf("===================================\n");
					}
					fclose(arq);
				}
				
				pause();
			break;
			
			default:
				limpar();
				mostrar("Opcao invalida!");
				pause();
			break;
			
		}

	}
	
	free(p);
	
}

void mostrar(const char* msg){
	printf("%s \n", msg);
}

void limpar(void){
	system("cls");
}
void pause(void){
	getch();
}

