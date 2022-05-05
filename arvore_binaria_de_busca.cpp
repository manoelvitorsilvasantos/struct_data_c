/*
    Arvore Binaria de busca
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

//estrutura de dados -> Informacoes do usuario;
typedef struct Dados{
	int NUM;
	char FULLNAME[80];
	char RG[12];
	char CPF[12];
	int AGE;
}DADOS;

//estrutura de dados -> arvore
typedef struct Arvore{
	DADOS dados;
	struct Arvore *esq;
	struct Arvore *dir;
}arv;

//PROTOTIPOS E FUNCOES
//funcoes do tipo arv
arv* root;
arv* iniciar();
arv* inserir(arv* a, DADOS my);
arv* remover(arv* a, DADOS my);
arv* liberarArvore(arv* a);
int buscarNumero(arv* a, int numero);
//funcao do tipo inteiro
int contarNos(arv* a);
int altura(arv* a);

//funcao do tipo booleano
bool vazio(arv* a);

//funcao do tipo chars
const char *buscarNome(arv* a, char* nome);

//procedimentos ou metodos
void mostrar(arv* a);
void mostrarARV(arv* a, int deslocamento);
void menu(arv* a);


int main(void)
{
    //criar a raiz da nossa arvmore
	arv* NO = iniciar();
	menu(NO);// o nosso lindo e maravilhoso e espetacular menu kkkkk.
}

// menu de opcoes
void menu(arv* a){
	int opc, n, valor;
	//crei essa variavel para poupar de ter que digitar todas
	//aquelas benditas variaveis da estrutura, nos achamos desnecessario.
	DADOS my; 
	while(1)
	{
		system("cls");
		printf("\n");
		printf(" %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
		"=================================================\n",
		"|           MENU DE OPCOES                      |\n",
		"=================================================\n",
		"| [1] - Inserir                                 |\n",
		"| [2] - Buscar por node - Numero                |\n",
		"| [3] - Buscar por node - Nome                  |\n",
		"| [4] - Qtd. de nodes                           |\n",
		"| [5] - Altura da arvore                        |\n",
		"| [6] - Lista informacoes                       |\n",
		"| [7] - Remover um node especifico              |\n",
		"| [8] - Destruir arvore                         |\n",
		"| [9] - Bonus -> Mostra em forma de arvore      |\n",
		"| [0] - Sair                                    |\n",
		"=================================================\n",
		"Opcao: "
		);
		scanf("%d", &opc);
		switch(opc){
			case 0:
				exit(0);
			break;
			
			case 1: //inserir
				system("cls");
				
				printf("%s", "Digite o nome completo: \n");
				fflush(stdin);
				gets(my.FULLNAME);
				strlwr(my.FULLNAME);
				
				//verifica se o nome ja consta na arvore
				if(strcmp(my.FULLNAME, buscarNome(a, my.FULLNAME))== 0)
                {
				    system("cls");
                    printf("Esse nome ja se encontra na arvore! \n");
                }
                else{ //se nao o usuario continua a digitar as informacoes
                    printf("%s", "Digite o seu CPF: \n");
				    fflush(stdin);
				    gets(my.CPF);

    				printf("%s", "Digite o seu RG: \n");
    				fflush(stdin);
    				gets(my.RG);

    				printf("%s", "Digite o numero: \n");
    				scanf("%d", &my.NUM);

    				printf("%s", "Digite a Idade: \n");
    				scanf("%d", &my.AGE);
    				a = inserir(a, my);
                }
				getch();
			break;
			
			case 2: //buscar por numero
				system("cls");
				if(!vazio(a)){
				    
				    printf(">> Digite o numero: ");
				    scanf("%d", &valor);
                    n = buscarNumero(a, valor);
                    if(n == valor){
                        printf("Existe na arvore! \n");
                    }
                    else{
                        printf("O numero nao foi encontrado! \n");
                    }
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 3: //buscar por nome
				system("cls");
				if(!vazio(a))
				{
					printf("Digite o nome: \n");
                    fflush(stdin);
                    gets(my.FULLNAME);
                    strlwr(my.FULLNAME);
                    
                    if(strcmp(my.FULLNAME, buscarNome(a, my.FULLNAME)) == 0)
                    {
                        system("cls");
                        printf("Foi encontrado %s! \n\n\n", my.FULLNAME);
                    }
                    else
                    {
                      system("cls");
                      printf("Nenhum nome foi encontrado com essa descricao! \n");
                    }
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 4: //verificar quantos no possui a arvore
				system("cls");
				if(!vazio(a))
				{
					printf("Arvore possui [%d] node. \n", contarNos(a));
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 5: //verificar altura da arvore
				system("cls");
				if(!vazio(a))
				{
					printf("Altura da arvore e [%d]", altura(a));
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 6: //lista arvore
				system("cls");
				if(!vazio(a))
				{
				    printf("%s","======================================\n");
				    printf("%s", "|            Arvore B.B             |\n");
                    printf("%s","======================================\n");
					mostrar(a);
                    printf("\n");
                    printf("%s","======================================\n");
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 7: //deletar um no da arvore
				system("cls");
				if(!vazio(a))
				{
                    
                    printf("Digite o nome: \n");
                    fflush(stdin);
                    gets(my.FULLNAME);
                    strlwr(my.FULLNAME);
                    a = remover(a, my);
                    if(!a){
                        printf("%s foi removido com sucesso! \n", my.FULLNAME);
                    }
                    else{
                        printf("Esse nome nao esta na arvore! \n");
                    }
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 8: //destruir arvore
				system("cls");
				if(!vazio(a))
				{
					a = liberarArvore(a);
					printf("%s", "Arvore destruida com suceso...\n");
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			case 9:
			    system("cls");
				if(!vazio(a))
				{
				    printf("%s","======================================\n");
				    printf("%s", "|            Arvore B.B             |\n");
                    printf("%s","======================================\n");
					//mostrar(a);
                    mostrarARV(a, 0);
                    printf("\n");
                    printf("%s","======================================\n");
				}
				else
				{
					printf("%s", "Arvore vazia! \n");
				}
				getch();
			break;
			
			default: //opcao invalida!
				system("cls");
				printf("%s", "Opcao invalida! \n");
				getch();
			break;
		}
	}
}

//criar a arvore
arv* iniciar(){
    //Aponta root para nulo
    //retorna ele para se a raiz da nossa arvore!
    root = NULL;
	return root;
}

//insere as informacoes
arv* inserir(arv* a, DADOS my)
{
	if(a == NULL)
	{
	    //aloca um espaco de bloco de bytes correspondente ao tamanho da
	    //estrutura do tipo arvore
		a = (arv*)malloc(sizeof(arv));
		//copia as variaveis do parametro para a estrutura
		strcpy(a->dados.FULLNAME, my.FULLNAME);
		strcpy(a->dados.CPF, my.CPF);
		strcpy(a->dados.RG, my.RG);
		a->dados.AGE = my.AGE;
		a->dados.NUM = my.NUM;
		a->esq = NULL;
		a->dir = NULL;
	}
	else{
	    //verifica primeiramente se o nome ja esta na arvore
		if(strcmp(a->dados.FULLNAME, my.FULLNAME) != 0){
            //se o valor do paramentro  < o valor da arvore
            //coloca a esquerda da arvore

            //senao coloca ao lado direito
            if(strcmp(my.FULLNAME, a->dados.FULLNAME) < 0){
			    a->esq = inserir(a->esq, my);

		    }
		    if(strcmp(my.FULLNAME, a->dados.FULLNAME) > 0){
			    a->dir = inserir(a->dir, my);
		    }
        }
	}
	//retorna o resultado
	return a;
}

//funcao para remover um node especifico da arvore
arv* remover(arv* a, DADOS my){

    if(a == NULL){
		return NULL;
	}else{
	    
		if(strcmp(a->dados.FULLNAME, my.FULLNAME) > 0){
			a->esq = remover(a->esq, my);
		}else{
		    
			if(strcmp(a->dados.FULLNAME, my.FULLNAME) < 0){
				a->dir = remover(a->dir, my);
			}else{//achou o node a remover
				if(a->esq == NULL && a->dir == NULL){//node sem filho
					a = NULL;
					free(a);
				}else{//node somente tem filho a  direita
				
					if(a->esq == NULL){
						arv* t = a;
						a = a->dir;
						free(t);
					}else{//node somente tem filho a esquerda
						if(a->dir == NULL){
							arv* t = a;
							a = a->esq;
							free(t);
						}else{ //node possui dois filhos
						
							//arv* t = a->esq;
							arv* t = a->esq;
							
                            while(t->dir != NULL){
								t = t->dir;
							}

                            //copia os dados para depois for remover
                            strcpy(a->dados.FULLNAME, t->dados.FULLNAME);
							strcpy(a->dados.CPF, t->dados.CPF);
                            strcpy(a->dados.RG, t->dados.RG);
                            a->dados.NUM = t->dados.NUM;
                            a->dados.AGE = t->dados.AGE;
							
							//
							strcpy(t->dados.FULLNAME, my.FULLNAME);
							strcpy(t->dados.CPF, my.CPF);
                            strcpy(t->dados.RG, my.RG);
                            t->dados.NUM = my.NUM;
                            t->dados.AGE = my.AGE;
							a->esq = remover(a->esq,my);
						}
					}
				}
			}
		}
	}
	return a;
}


//libera a arvore -> Destroi a arvore
arv* liberarArvore(arv* a){
	if(!vazio(a)){
	    //percorre do menor ao maior valor e destruindo tudo o que vem.
		liberarArvore(a->esq);
		liberarArvore(a->dir);
		free(a); //libera o espaco de memoria para S.O
	}
	return NULL;
}

//funcao para verificar se a arvore esta vazia!
bool vazio(arv* a){
    //Verifica se a raiz a esq. e dir. esta apotando para nulo
    //se sim retorna verdadeiro, senao retorna falso
	if(a==NULL){return true;} 
	else{ return false;}
}

int buscarNumero(arv* a, int numero){
    int res;
    if(a == NULL)
        return 0;
    else{
        if(a->dados.NUM > numero){
            res = buscarNumero(a->esq, numero);
        }
        else{
            if(numero > a->dados.NUM)
                res = buscarNumero(a->dir, numero);
            else
                return a->dados.NUM;
        }
    }
    return res;
}

//mostra na forma de arvore
void mostrarARV(arv* a, int deslocamento){ //mostra as informacoes de forma ordenada
    int i;
    if(!vazio(a)){
        mostrarARV(a->esq, deslocamento+2);
        for(i = 0; i < deslocamento; i++)
            printf("  ");
        printf("[%s]\n", a->dados.FULLNAME);
        mostrarARV(a->dir, deslocamento+2);
    }
}

//procedimento - mostra as informacoes em ordem na arvore
void mostrar(arv* a){
    //verifica se a arvore esta vazia!
    if(!vazio(a)){ //mostra as informacoes de forma ordenada
	    //vai primeira aos valores menores e apos isso
	    //aos valores maiores
	    //em seguinda vai imprimindo em ordem alfabetica
	    //lembrando que eu[manoel vitor] e lucas,
	    //colocamos para imprimir em ordem alfabetica,
	    //usando como referencias o nome dos usuarios!
	    mostrar(a->esq);
		printf(" Nome: [%s] \n", a->dados.FULLNAME);
		printf(" CPF: [%s] \n", a->dados.CPF);
		printf(" RG: [%s] \n", a->dados.RG);
		printf(" Numero: [%d] \n", a->dados.NUM);
		printf(" Idade: [%d] \n", a->dados.AGE);
		printf("%s","======================================\n");
		mostrar(a->dir);
	}
}

const char *buscarNome(arv* a, char* nome){
    
    //praticamente faz a mesma coisa que a funcao acima
    const char *res;
    if(a == NULL){
        return "\0";
    }
    else{
        //verifica se o elemento da arvore e maior que o valor do paramento
        if(strcmp(a->dados.FULLNAME, nome) > 0)
        {   //se ele for, ele vai para o lado esquerdo da arvore em buscar
            res = buscarNome(a->esq, nome);
        }
        else{ //se caso nao for ele tenta outro condicao *[Digo se ele for maior]
            //se for o contrario da condicao acima
            if(strcmp(a->dados.FULLNAME, nome) < 0)
            {   //se ele for, ele vai para o lado direito da arvore em buscar
                res = buscarNome(a->dir, nome);
            }
            else
            { //manda o valor para retornar
                return a->dados.FULLNAME;
            }
        }
    }
    return res; //retorna o resultado
}



int contarNos(arv* a){
    //variaveis da direita[right] e esquerda[left], isso funciona como um contador
    int left, right; 
    
    if(a == NULL){
        //se a raiz [ESQUERDA E DIREITA] estiver apontando para nulo retorna zero
        return 0; 
    }
    else{
        left  = contarNos(a->esq); //*GUARDA O RESULTADO VERDADEIRO NA VARIAVEL LEFT
        right = contarNos(a->dir); //PRATICAMENTE A MESMA COISA DO LEFT*
    }
    return (left+right+1); //RETORNA A SOMA DOS RESULTADOS ((esquerda+direita)+raiz);
}

int altura(arv* a){
    //variaveis para guarda o resultado do lado
    //esquerdo[left] e direito[right] da arvore
    
    int left, right;
    if(a == NULL){
        return 0;
    }
    else{
        //guarda os resultados
        left  = altura(a->esq);
        right = altura(a->dir);
        //verifica se o resultado do lado direito
        //e maior que o do lado esquedo
        //se for retorna ele mais a raiz
        //se nao significa que e o lado esquerdo, entao
        //retorna o resultado do lado esquerdo+raiz
        if(right > left)
            return (right+1);
        else
            return (left+1);
    }
}
