#include <stdio.h>
#include <stdlib.h>

typedef struct celulaFila{
	int elemento;
	struct celulaFila *prox;
}CelulaFila;

typedef struct fila{
	CelulaFila *inicio;
	CelulaFila *fim;
	CelulaFila *aux;
}Fila;

Fila iniciaFila(Fila fila)
{
	fila.inicio = (CelulaFila *)malloc(sizeof(CelulaFila));
	fila.inicio->prox = NULL;
	fila.fim = fila.inicio;
	return fila;
}

Fila incereElementoFila(Fila fila,int elemento)
{
	fila.fim->prox = (CelulaFila *)malloc(sizeof(CelulaFila));
	fila.fim = fila.fim->prox;
	fila.fim->elemento = elemento;
	fila.fim->prox = NULL;
	return fila;
}

Fila enfileira(Fila fila, int x)
{
	// feita de acordo com os parametros da questao
	// considere fim como L
	fila.aux =(celulaFila*) malloc(sizeof(celulaFila));
	fila.aux->prox = fila.fim;
	fila.fim = fila.aux;
	fila.fim->elemento = x;
	return fila;
}

Fila desenfileiraElemento(Fila fila){
	fila.aux = fila.inicio;
	fila.inicio = fila.inicio->prox;
	free(aux);
}






