#include <stdio.h>
#include <stdlib.h>
/**
	@utor: Carlos Jorge
	versao: 2
	
	observações importantes:
	* A biblioteca foi feita para ser uma pilha de numeros inteiros, entretanto podem ser feitas adaptações nas funções para englobar outros 
	  tipos primitivos e tipos estruturas
	
*/
typedef struct celulaPilha{
	int elemento;
	struct celulaPilha *prox;
}CelulaPilha;

typedef struct pilha{
	CelulaPilha *aux;
	CelulaPilha *topo;
	int tamanho;
}Pilha;

Pilha iniciaPilha(Pilha pilha)
{
	pilha.topo = (CelulaPilha *)malloc(sizeof(CelulaPilha));
	pilha.topo->prox = NULL;
	return pilha;
}

Pilha incereElementoPilha(Pilha pilha,int elemento)
{
	pilha.aux = (CelulaPilha *)malloc(sizeof(CelulaPilha));
	pilha.aux->prox = pilha.topo;
	pilha.topo = pilha.aux;
	pilha.topo->elemento = elemento;
	return pilha;
}

Pilha retiraElemento(Pilha pilha)
{
	pilha.aux = pilha.topo;
	pilha.topo = pilha.topo->prox;
	free(pilha.aux);
	return pilha;
}

void mostrePilha(Pilha pilha)
{
	pilha.aux = pilha.topo;
	while(pilha.topo->prox != NULL)
	{
		printf("%d ",pilha.topo->elemento);
		pilha.topo = pilha.topo->prox;
	}
	printf("\n");
	pilha.topo = pilha.aux;
}
