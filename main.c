#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

void main()
{
	Lista lista = iniciaLista(lista);
	lista = incereElementoLista(lista,40);		
	lista = incereElementoLista(lista,20);
	lista = incereElementoLista(lista,30);
		lista = incereElementoLista(lista,30);

	lista = incereElementoLista(lista,300);

	lista = incereElementoLista(lista,320);

	lista = incereElementoLista(lista,130);

	lista = bubleSort(lista);
	mostreLista(lista);

	
}
