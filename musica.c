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

/* Faz a alocação de uma célula de músicas
 * Input: Nenhum
 * Output: Ponteiro para celula de musicas alocada
 * Pre-condição: Nenhum
 * Pos-condição: A celula foi corretamente alocada
 */
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

Musica* retornaPrimMusica(ListaM* lista) {
    return lista->prim;
}

Musica* retornaProxMusica(Musica* musica) {
    return musica->prox;
}

char* retornaNomeMusica(Musica* musica) {
    return musica->musica;
}

void liberaListaMusicas(ListaM* lista) {
    Musica* p = lista->prim;
    Musica* t;

    while (p != NULL) {
        t = p->prox;
        free(p->musica);
        p->musica = NULL;
        free(p);
        p = t;
    }

    free(lista);
    lista = NULL;
}