#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct listaA {
    CelulaA* prim;
    CelulaA* ult;
};

ListaP* inicListaP() {
    ListaP* lista = (ListaP*) malloc(sizeof(ListaP));
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

CelulaP* criaCelulaP() {
    CelulaP* celula = (CelulaP*) malloc(sizeof(CelulaP));
    return celula;
}

void insereListaP(ListaP* lista, Pessoa* pessoa) {
    CelulaP* celula = criaCelulaP();
    celula->pessoa = pessoa;
    
    celula->amigos = (ListaA*) malloc(sizeof(ListaA));  // Nao foi liberado isso aqui

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

ListaA* retornaListaA(ListaP* lista, char* pessoa) {
    CelulaP* p = lista->prim;

    for (p = lista->prim; p != NULL; p = p->prox) {
        if (strcmp(retornaNome(p->pessoa),pessoa) == 0) {
            return p->amigos;
        }
    }
}

void imprime(ListaP* lista) {
    CelulaP* p;
    for ( p = lista->prim; p != NULL; p = p->prox ) {
        printf("Amigos de %s:\n",retornaNome(p->pessoa));

        CelulaA* t = p->amigos->prim;
        if (t == NULL) {
            printf("Nenhum\n");
        } else {
            for ( t; t != NULL ; t = retornaProx(t)) {
                printf("%s\n",retornaNomeAmigo(t));
            }
        }
    }
}

Pessoa* retornaPessoaP(ListaP* lista, char* pessoa) {
    CelulaP* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        if (strcmp(retornaNome(p->pessoa),pessoa) == 0) {
            return p->pessoa;
        }
    }

    return NULL;
}