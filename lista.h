#include <stdio.h>
#include <stdlib.h>
/**
	@utor: Carlos Jorge
	versao: 5
	
	observações importantes:
	*nessa biblioteca o primeiro elemento da lista tem posição igual a 1 
	*A biblioteca foi feita para ser uma lista de numeros inteiros, entretanto podem ser feitas adaptações nas funções para englobar outros tipos primitivos e tipos estruturas
	
*/
typedef struct celula{
	int elemento;
	struct celula *prox;
}Celula;

typedef struct lista{
	Celula *inicio;
	Celula *fim;
	Celula *percorreLista;
	int tamanho;
}Lista;

int ordenaCrecente(const void *q1,const void *q2)
{
	Celula *n1 =(Celula *)q1, *n2 = (Celula *)q2;
	if(n1->elemento>n2->elemento)
	{
		return 1;
	}else if(n1->elemento == n2->elemento){
		return 0;
	}else 
	return -1;
}

int ordenaDecrecente(const void *q1,const void *q2)
{
	Celula *n1 =(Celula *)q1, *n2 = (Celula *)q2;
	if(n1->elemento>n2->elemento)
	{
		return -1;
	}else if(n1->elemento == n2->elemento){
		return 0;
	}else 
	return 1;
}

Lista iniciaLista(Lista lista)
{
	// faz as configurações basicas de funcionamento de uma lista
	
	lista.inicio = (Celula *)malloc(sizeof(Celula));
	lista.inicio->prox = NULL;
	lista.fim = lista.inicio;
	lista.tamanho = 0;
	return lista;
}

Lista incereElementoLista(Lista lista,int elemento)
{
	// incere o elemento desejado na ultima posicao da lista
	
	lista.fim->prox = (Celula *)malloc(sizeof(Celula));
	lista.fim = lista.fim->prox;
	lista.fim->prox = NULL;
	lista.fim->elemento = elemento;
	lista.tamanho = lista.tamanho + 1;
	return lista;
}

void mostreLista(Lista lista)
{
	// mostra todos os elementos da lista
	
	lista.percorreLista = lista.inicio->prox;
	while(lista.percorreLista != NULL)
	{
		printf("%d ",lista.percorreLista->elemento);
		lista.percorreLista =lista.percorreLista->prox;
		
	}
	printf("\n");
}

Lista incereElementoInicio(Lista lista,int elemento)
{
	// incere um elemento na primeira posição da lista
	
	Celula *aux;
	aux = lista.inicio->prox;
	lista.inicio->prox =(Celula *)  malloc(sizeof(Celula));
	lista.inicio->prox->elemento = elemento;
	lista.inicio->prox->prox = aux;
	
	
	return lista;
}

Lista incereElementoPosicao(Lista lista,int elemento,int posicao)
{
	// incere um elemento em qualquer posição da lista
	
	int i;
	lista.percorreLista = lista.inicio->prox;
	Celula *aux;
	if (posicao == 1)
	{
		lista = incereElementoInicio(lista,elemento);
		lista.tamanho = lista.tamanho+1;
		return lista;
	}
	else{
			for(i = 1; i<posicao - 1; i++)
		{
			lista.percorreLista = lista.percorreLista->prox;
		}
		aux = lista.percorreLista->prox;
		lista.percorreLista->prox = (Celula *)malloc(sizeof(Celula));
		lista.percorreLista = lista.percorreLista->prox;
		lista.percorreLista->elemento = elemento;
		lista.percorreLista->prox = aux;
		lista.tamanho = lista.tamanho + 1;
		return lista;
	}
	
	
}
Lista removeUltimoElemento(Lista lista)
	{
		// retira o ultimo elemento da lista
		
		
		int i;
		Celula *aux;
		lista.percorreLista = lista.inicio->prox;
		while(lista.percorreLista->prox->prox != NULL)
		{
			lista.percorreLista = lista.percorreLista->prox;	
		}
		aux = lista.percorreLista->prox;
		lista.percorreLista->prox = lista.percorreLista->prox->prox;
		lista.fim = lista.percorreLista;
		lista.fim->prox = NULL;
		free(aux);
		//printf("%d",lista.percorreLista->elemento);
		return lista;
	}
	

	
Lista removeElementoPosicao(Lista lista,int posicao)
{
	//remove um elemento da lista da posição desejada
	
	int contador = 2;
	Celula *aux;
	if(posicao <= lista.tamanho)
	{
		if (posicao == 1)
		{
			lista.percorreLista = lista.inicio;
			aux = lista.percorreLista->prox;
			lista.percorreLista->prox = lista.percorreLista->prox->prox;
			free(aux);
			lista.tamanho = lista.tamanho - 1;
		}
		else{
			lista.percorreLista = lista.inicio->prox;
			while(contador < posicao)
			{
				lista.percorreLista = lista.percorreLista->prox;
				contador++;
			}
			aux = lista.percorreLista->prox;
			lista.percorreLista->prox = lista.percorreLista->prox->prox;
			free(aux);
			lista.tamanho = lista.tamanho - 1;
		}
	
	}
	else{
		printf("\n a Lista nao tem tamanho suficiente \n");
	}
	return lista;
}

Lista ordenaListaCresente(Lista lista)
{
	int i;
	Celula vetorOrdenacao[lista.tamanho];
	lista.percorreLista = lista.inicio->prox;
	for(i = 0;i<lista.tamanho;i++)
	{
		vetorOrdenacao[i].elemento = lista.percorreLista->elemento;	
		lista.percorreLista = lista.percorreLista->prox;
	}
	
	qsort(vetorOrdenacao,lista.tamanho,sizeof(Celula),ordenaCrecente);
	
	lista.percorreLista = lista.inicio->prox;
	for(i = 0;i<lista.tamanho;i++)
	{
		 lista.percorreLista->elemento = vetorOrdenacao[i].elemento; 
		 lista.percorreLista = lista.percorreLista->prox;
	}
	return lista;
}
Lista ordenaListaDecrecente(Lista lista)
{
	int i;
	Celula vetorOrdenacao[lista.tamanho];
	lista.percorreLista = lista.inicio->prox;
	for(i = 0;i<lista.tamanho;i++)
	{
		vetorOrdenacao[i].elemento = lista.percorreLista->elemento;	
		lista.percorreLista = lista.percorreLista->prox;
	}
	
	qsort(vetorOrdenacao,lista.tamanho,sizeof(Celula),ordenaDecrecente);
	
	lista.percorreLista = lista.inicio->prox;
	for(i = 0;i<lista.tamanho;i++)
	{
		 lista.percorreLista->elemento = vetorOrdenacao[i].elemento; 
		 lista.percorreLista = lista.percorreLista->prox;
	}
	return lista;
}

Lista mostreListaRecursivo(Lista lista)
{
	Lista list;
	lista.percorreLista = lista.inicio->prox;
	int n = 0;
	if(lista.tamanho)
	{
		//n++;
		printf("%d ",lista.percorreLista->elemento);
		list = removeElementoPosicao(lista,1);
		list = mostreListaRecursivo(list);
		return list;	
	}
	else{
		return list;
	}
}

Lista selectionSort(Lista lista)
{
	int i;
	int j;
	Celula listaOrdena[lista.tamanho];
	Celula aux;
	lista.percorreLista = lista.inicio->prox;
	for(i = 0;i<lista.tamanho;i++){
		listaOrdena[i].elemento = lista.percorreLista->elemento;
		lista.percorreLista = lista.percorreLista->prox;
	}
	
	//inicio selection sort
	for(i=0;i<lista.tamanho;i++){
		for(j=i+1;j<lista.tamanho;j++){
			if(listaOrdena[i].elemento > listaOrdena[j].elemento){
				aux.elemento = listaOrdena[i].elemento;
				listaOrdena[i].elemento = listaOrdena[j].elemento;
				listaOrdena[j].elemento = aux.elemento;
			}
		}
	}
	// fim selection sort
	lista.percorreLista = lista.inicio->prox;
	for(i=0;i<lista.tamanho;i++){
		lista.percorreLista->elemento = listaOrdena[i].elemento;
		lista.percorreLista = lista.percorreLista->prox;
	}
	return lista;
}

Lista bubleSort(Lista lista)
{
	int i;
	int j;
	Celula listaOrdena[lista.tamanho];
	Celula aux;
	lista.percorreLista = lista.inicio->prox;
	for(i = 0;i<lista.tamanho;i++){
		listaOrdena[i].elemento = lista.percorreLista->elemento;
		lista.percorreLista = lista.percorreLista->prox;
	}
	//
	int contador = lista.tamanho;
	for(i=0;i<lista.tamanho;i++){
		for(j=0;j<contador-1;j++){
			if(listaOrdena[j].elemento>listaOrdena[j+1].elemento){
				aux.elemento = listaOrdena[j].elemento;
				listaOrdena[j].elemento = listaOrdena[j+1].elemento;
				listaOrdena[j+1].elemento = aux.elemento;
			}
		}
		contador--;
	}
	//
	lista.percorreLista = lista.inicio->prox;
	for(i=0;i<lista.tamanho;i++){
		lista.percorreLista->elemento = listaOrdena[i].elemento;
		lista.percorreLista = lista.percorreLista->prox;
	}
	return lista;
}









