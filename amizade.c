#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "amizade.h"

struct celulaA {
    Pessoa* amigo;
    CelulaA* prox;
};

struct listaA {
    CelulaA* prim;
    CelulaA* ult;
};

ListaA* inicListaA() {
    ListaA* lista = (ListaA*) malloc(sizeof(ListaA));
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

void insereListaA(ListaA* lista, Pessoa* amigo) {
    CelulaA* celula = (CelulaA*) malloc(sizeof(CelulaA));
    celula->amigo = amigo;

    celula->prox = lista->prim;
    lista->prim = celula;

    if (lista->ult == NULL) {
        lista->ult = celula;
    }
}

