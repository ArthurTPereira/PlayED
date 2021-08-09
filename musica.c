#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

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
    if (lista == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

Musica* alocaCelulaM() {
    Musica* musica = (Musica*) malloc(sizeof(Musica));
    if (musica == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }
    
    return musica;
}

void insereListaM(ListaM* lista, char* musica) {
    Musica* music = alocaCelulaM();
    music->musica = strdup(musica);
    if (music->musica == NULL) {
        printf("Falha na alocação.\n");
        return;
    }
    music->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = music;
    } else {
        lista->ult->prox = music;
    }
    
    lista->ult = music;

}

void imprimeMusicas(ListaM* lista) {
    Musica* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        printf("%s\n",p->musica);
    }
}

Musica* retornaPrimMusica(ListaM* lista) {
    return lista->prim;
}

Musica* retornaProxMusica(Musica* musica) {
    return musica->prox;
}

char* retornaNomeMusica(Musica* musica) {
    return musica->musica;
}