#ifndef LISTAPESSOAS_H_
#define LISTAPESSOAS_H_

#include "amizade.h"


typedef struct listaP ListaP;

typedef struct celulaP CelulaP;

ListaP* inicListaP();

void insereListaP(ListaP* lista, Pessoa* pessoa);

void liberaListaP(ListaP* lista);

ListaA* retornaListaA(ListaP* lista, char* pessoa);

void imprime(ListaP* lista);

Pessoa* retornaPessoaP(ListaP* lista, char* pessoa);

#endif