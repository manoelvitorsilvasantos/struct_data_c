/*

	Docente:
	Lais Farias Alves
	
	Discentes:
	Gustavo Dourado Batista
	Lucas Rodrigues Ribeiro
	Manoel Vitor Pau Ferro Silva Santos

	Disciplina: Estrutura de Dados
	Algoritmo sobre arquivos

*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//data
struct Data{
	int dia, mes, ano;
};

//dados de endereco
struct Endereco{
	char log[30], complemento[15], bairro[30], cep[15];
	char cidade[30], estado[2];
	int num;
};

//dados gerais
typedef struct Dados{
	
	char nome[50];
	char tel[15], cel[15];
	char email[30];
	struct Data data;
	struct Endereco end;
}dados;

//procedimentos e funcoes
void pause(void); // dar pausa
void limpar(void);
void mostrar(const char* msg);
void cadastrar(void);
void listar(void);
void bl(void);
void line(void);

void menu(void);


int main(){
	
	FILE* arq;
	
	arq = fopen("dados.bin", "rb");
		
	if(arq == NULL){
		menu();
	}
	else{
		limpar();
		listar();
		mostrar("Aperte [ENTER] para entra no MENU PRINCIPAL!");
		pause();
		menu();	
	}
	
	menu();
	return(0);	
}

//menu

void menu(void){
	
	int alt;
	int opc;
	FILE *arq;
	
	while(1){
		
		
		limpar();
		bl();
		
		limpar();
		mostrar("[1] - CADASTRAR");
		mostrar("[2] - LISTAR");
		mostrar("[0] - SAIR");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 0:
				exit(1);
			break;
			
			case 1:
				
				alt = 1;
				
				limpar();
				
				do{
					cadastrar();
					
					mostrar("Voce deseja cadastrar outro cliente ?\n");
					mostrar("[0] NAO - [1] SIM - [2] - VOLTAR AO MENU ");
					scanf("%d", &alt);
					
					if(alt == 0){
						exit(1);
					}
					else if(alt == 2){
						menu();
					}
					
						
				} while(alt != 0);
				
				pause();
			break;
			
			case 2:
				arq = fopen("dados.bin", "rb");
				if(arq == NULL){
					limpar();
					mostrar("arquivo vazio!");
					pause();
					main();
				}
				else{
					limpar();
					listar();
					pause();
				}
			break;
			
			case 3:
				limpar();
				mostrar("Opcao invalida!");
				pause();
			break;
			
		}
		
	}
}


//procedimento de cadastro de pessoa

void cadastrar(void){
	
	FILE *arq;
	
	dados d;
	
	//abre o arquivo como modo append [Anexado]
	
	arq = fopen("dados.bin", "ab+");
	
	//verifica se o arquivo esta vazio
	
	if(arq == NULL){
		//mostrar um alerta e finaliza o programa
		mostrar("ERRO, AO ABRIR ARQUIVO!\n");
		exit(1);
	}
	
	
	//nome
	mostrar(">> Digite o nome completo: ");
	fflush(stdin);
	gets(d.nome);

	
	//data 
	mostrar(">> Digite o data de nascimento: ");
	mostrar("Dia >>");
	scanf("%d", &d.data.dia);
	mostrar("Mes >>");
	scanf("%d", &d.data.mes);
	mostrar("Ano >>");
	scanf("%d", &d.data.ano);

	
	//contatos
	mostrar(">> Digite os seus contatos: ");
	mostrar("Telefone >> ");
	fflush(stdin);
	gets(d.tel);
	mostrar("Celular >> ");
	fflush(stdin);
	gets(d.cel);
	mostrar("E-mail >> ");
	fflush(stdin);
	gets(d.email);

	
	//dados de localizacao
	mostrar(">> Endereco: ");
	mostrar("Logradouro >> ");
	fflush(stdin);
	gets(d.end.log);
	mostrar("Complemento >>");
	fflush(stdin);
	gets(d.end.complemento);
	mostrar("Bairro >> ");
	fflush(stdin);
	gets(d.end.bairro);
	mostrar("Cidade >>");
	fflush(stdin);
	gets(d.end.cidade);
	mostrar("Estado [Digite a abreviacao] >>");
	fflush(stdin);
	gets(d.end.estado);
	mostrar("CEP >>");
	fflush(stdin);
	gets(d.end.cep);
	mostrar("Numero >> ");
	scanf("%d", &d.end.num);
	
	fwrite(&d, sizeof(Dados), 1, arq);
	fclose(arq);
		
}


//procedimento que lista os clientes!

void listar(void){
	
	
	
	FILE* arq;	
	dados d;
	
	//abre o arquivo no modo binary read [Leitura de arquivo binario]
	arq = fopen("dados.bin", "rb");
	
	
	//verifica se o arquivo se encontra vazio
	if(arq == NULL){
		mostrar("ERRO na abertura!");
		pause();
		exit(1);
	}
	
	else{
		
		bl();
		mostrar("**** LISTA DE PESSOAS CADASTRADAS ******");
		line();
		bl();
		//enquanto o arquivo retorna false ele continua a repetir o ciclo
		
		while(fread(&d, sizeof(dados),1, arq) == 1){
			
			//mostra todas informacoes
			
			printf("NOME: %s \n", d.nome);
			printf("DN: %d/%d/%d \n", d.data.dia, d.data.mes, d.data.ano);
			printf("EMAIL: %s \n", d.email);
			printf("TEL: %s \n", d.tel);
			printf("CEL: %s \n", d.cel);
			
			
			printf("ENDERECO: %s \n", d.end.log);
			printf("BAIRRO: %s \n", d.end.bairro);
			printf("CIDADE: %s \n", d.end.cidade);
			printf("ESTADO: %s \n", d.end.estado);
			printf("COMPLEMENTO: %s \n", d.end.complemento);
			printf("CEP: %s \n", d.end.cep);
			printf("NUMERO: %d \n", d.end.num);
			line();
			bl();
		
		}
	}
	
	//fecha o arquivo
	fclose(arq);
}

//linha
void line(void){
	printf("==============================================\n");
}

//quebra linha
void bl(void){
	printf("\n");
}

//dar uma pausa
void pause(void){
	getch();
}

//limpar tela do prompt
void limpar(void){
	system("cls");
}

// o mesmo que o printf so que costumizavel
void mostrar(const char* msg){
	printf("%s \n", msg);
}

