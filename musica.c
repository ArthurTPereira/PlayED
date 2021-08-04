#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"
#include "playlist.h"

struct celulaM {
    char* musica;
    Musica* prox;
};

struct listaM {
    Musica* prim;
    Musica* ult;
};

ListaM* inicListaM() {
    ListaM* lista = (ListaM*) malloc(sizeof(ListaM));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

Musica* alocaCelulaM() {
    Musica* musica = (Musica*) malloc(sizeof(Musica));
    if (musica == NULL) {
        printf("erro malocc");
        exit(1);
    }
    
    return musica;
}

void insereListaM(ListaM* lista, char* musica) {// tem q botar 2 char depois
    Musica* music = alocaCelulaM();
    music->musica = strdup(musica); // serase ta certo assim

    music->prox = lista->prim;
    lista->prim = music;

    if (lista->ult == NULL) {
        lista->ult = music;
    }
}

void imprimeMusicas(ListaM* lista) {
    Musica* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        printf("%s\n",p->musica);
    }
}