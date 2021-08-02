#ifndef AMIZADE_H_
#define AMIZADE_H_

typedef struct celulaA CelulaA;

typedef struct listaA ListaA;

ListaA* inicListaA();

void insereListaA(ListaA* lista, Pessoa* amigo);

void liberaListaA(ListaA* lista);

CelulaA* retornaProx(CelulaA* cel);

char* retornaNomeAmigo(CelulaA* cel);

#endif