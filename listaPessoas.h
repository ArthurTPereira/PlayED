#ifndef LISTAPESSOAS_H_
#define LISTAPESSOAS_H_

#include "amizade.h"

typedef struct celulaP CelulaP;

typedef struct listaP ListaP;

ListaP* inicListaP();

void insereListaP(ListaP* lista, Pessoa* pessoa);

void liberaListaP(ListaP* lista);

ListaA* retornaListaA(ListaP* lista, Pessoa* pessoa);

#endif