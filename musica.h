#ifndef MUSICA_H_
#define MUSICA_H_

typedef struct celulaM Musica;

typedef struct listaM ListaM;

ListaM* inicListaM();

void insereListaM(ListaM* lista, char* musica);

void imprimeMusicas(ListaM* lista);



#endif