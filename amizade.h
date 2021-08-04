#ifndef AMIZADE_H_
#define AMIZADE_H_

typedef struct celulaA CelulaA;

typedef struct listaA ListaA;

ListaA* inicListaA();

CelulaA* alocaCelulaA();

void insereListaA(ListaA* lista, Pessoa* amigo);

void liberaListaA(ListaA* lista);

CelulaA* retornaPrim(ListaA* lista);

CelulaA* retornaProx(CelulaA* cel);

char* retornaNomeAmigo(CelulaA* cel);

#endif