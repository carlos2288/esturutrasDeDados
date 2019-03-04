#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <limits.h>
#include <math.h>

typedef struct produto
{
    char nome[30];
    float preco;
    int distancia;
    int codigo;
}Produto;

typedef struct ramo
{
	Produto produto;
	struct ramo *esquerda;
	struct ramo *diretia;	
}Ramo;

typedef struct arvore
{
	Ramo *raiz;
	Ramo *percorreArvore;
	Ramo *aux;
	int tamanho;
}Arvore;

Arvore iniciaArvore(Arvore arvore)
{
	arvore.raiz = (Ramo *)malloc(sizeof(Ramo));
	arvore.raiz->produto.distancia = 0;
	arvore.raiz->produto.preco = 0;
	strcmp(arvore.raiz->produto.nome," ");
	arvore.raiz->diretia = NULL;
	arvore.raiz->esquerda = NULL;
	arvore.tamanho = 1;
	return arvore;
}

Produto geraProduto(char nome[],float preco,int distancia)
{
	Produto produto;
	strcpy(produto.nome,nome);
	produto.distancia = distancia;
	produto.preco = preco;
	return produto;
}

void mostreProduto(Produto produto)
{
	if(produto.preco != 0)
	{
		printf("Nome: %s\nPreco: %.2f\nCodigo %d\n",produto.nome,produto.preco,produto.codigo);
		if(produto.distancia != INT_MAX)
		{
			printf("Distancia: %d\n",produto.distancia);
		}
	}
	
	printf("\n");
}

Arvore insereProdutoPreco(Arvore arvore,Produto produto)
{
	arvore.percorreArvore = arvore.raiz;
	while(1)
	{
		if(arvore.percorreArvore->produto.preco < produto.preco)
		{
			if(arvore.percorreArvore->diretia == NULL)
			{
				arvore.percorreArvore->diretia = (Ramo *)malloc(sizeof(Ramo));
				arvore.percorreArvore = arvore.percorreArvore->diretia;
				arvore.percorreArvore->produto  = produto;
				arvore.percorreArvore->diretia  = NULL;
				arvore.percorreArvore->esquerda = NULL;
				arvore.tamanho = arvore.tamanho + 1;
				arvore.percorreArvore->produto.codigo = arvore.tamanho;
				arvore.percorreArvore->produto.distancia = INT_MAX;
				break;
				
			}
			arvore.percorreArvore = arvore.percorreArvore->diretia;	
		}
		else
		{
			if(arvore.percorreArvore->esquerda == NULL)
			{
				arvore.percorreArvore->esquerda = (Ramo *)malloc(sizeof(Ramo));
				arvore.percorreArvore = arvore.percorreArvore->esquerda;
				arvore.percorreArvore->produto  = produto;
				arvore.percorreArvore->diretia  = NULL;
				arvore.percorreArvore->esquerda = NULL;
				arvore.tamanho = arvore.tamanho + 1;
				arvore.percorreArvore->produto.codigo = arvore.tamanho;
				arvore.percorreArvore->produto.distancia = INT_MAX;
				break;
			}
			arvore.percorreArvore = arvore.percorreArvore->esquerda;	
		}	
	}
	return arvore;
}

Produto maisBarato(Arvore arvore){
	Produto elemento;
	if(arvore.raiz->esquerda != NULL){
		arvore.percorreArvore = arvore.raiz->esquerda;
	}else{
		arvore.percorreArvore = arvore.raiz->diretia;
	}
	while(arvore.percorreArvore->esquerda != NULL ){
		arvore.percorreArvore = arvore.percorreArvore->esquerda;
	}
	elemento = arvore.percorreArvore->produto;
	return elemento;
}
void mostreemordem(Ramo *ramo)
{
	if(ramo != NULL)
	{
		mostreemordem(ramo->esquerda);
		mostreProduto(ramo->produto);
		mostreemordem(ramo->diretia);	
	}	
}

void mostreEmOrdem(Arvore arvore)
{
	mostreemordem(arvore.raiz);
}

void procuraporcodigo(Ramo *ramo,int codigo,int distancia)
{
	if(ramo != NULL)
	{
		procuraporcodigo(ramo->esquerda,codigo,distancia);
		if(ramo->produto.codigo == codigo)
		{
			ramo->produto.distancia = distancia;
		}
		procuraporcodigo(ramo->diretia,codigo,distancia);	
	}	
}

void procuraPorCodigo(Arvore arvore,int codigo,int distancia)
{
	procuraporcodigo(arvore.raiz,codigo,distancia);
}

// menus

char menuPrincipal()
{
	system("cls");
	printf("1. Arvore\n");
	printf("2. Grafo\n");
	printf("0. Sair\n");
	return getch();
}

char menuPrincipalArvore()
{
	system("cls");
	printf("1. Incerir um produto\n");
	printf("2. Mostrar produto mais barato\n");
	printf("3. Mostrar produtos por ordem de preço\n");
	printf("0. Sair\n");
	return getch();
}

// funcoes principais
Arvore arvorePrincipal(Arvore arvore)
{
	setlocale(LC_ALL, "Portuguese");
	char nome[30];
	float preco; 
	int distancia;
	char menuPrincipallArvore = 'z';
	Produto produto;
	while(1)
	{
		menuPrincipallArvore = menuPrincipalArvore();
		if(menuPrincipallArvore == '0')
		{
			break;
		}
		switch(menuPrincipallArvore)
		{
			case '1':// inserir elemento
			
				while(1)
				{
					system("cls");
					printf("digite o nome do produto(0 - Sair): ");
					scanf("%s",nome);
					if(strcmp(nome,"0") == 0)
					{
						break;
					}
					printf("digite o preço do produto: ");
					scanf("%f",&preco);
					produto = geraProduto(nome,preco,distancia);
					arvore = insereProdutoPreco(arvore,produto);
				}
			
				break;
			case '2':// mostrar menor Elemento
				system("cls");
				produto = maisBarato(arvore);
				mostreProduto(produto);
				getch();
				break;
			case '3'://mostrar todos os elemento
				system("cls");
				mostreEmOrdem(arvore);
				getch();
				break;
			default:
				system("cls");
				printf("digite um valor válido");
				getch();
		}
	}
	return arvore;
}
