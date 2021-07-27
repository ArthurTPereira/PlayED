#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "listaPessoas.h"
#include "amizade.h"

struct celulaP {
    Pessoa* pessoa;
    CelulaP* prox;
    ListaA* amigos;
};

struct listaP {
    CelulaP* prim;
    CelulaP* ult;
};

ListaP* inicListaP() {
    ListaP* lista = (ListaP*) malloc(sizeof(ListaP));
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

void insereListaP(ListaP* lista, Pessoa* pessoa) {
    CelulaP* celula = (CelulaP*) malloc(sizeof(CelulaP));
    celula->pessoa = pessoa;

    celula->prox = lista->prim;
    lista->prim = celula;

    if (lista->ult == NULL) {
        lista->ult = celula;
    }
}

void liberaListaP(ListaP* lista) {
    CelulaP* p = lista->prim;
    CelulaP* t;

    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}

ListaA* retornaListaA(ListaP* lista, Pessoa* pessoa) {
    CelulaP* p = lista->prim;

    for (p = lista->prim; p != NULL; p = p->prox) {
        if (p->pessoa == pessoa) {
            return p->amigos;
        }
    }
}