#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "amizade.h"
#include "listaPessoas.h"

struct celulaA {
    CelulaP* amigo;
    CelulaA* prox;
};

struct listaA {
    CelulaA* prim;
    CelulaA* ult;
};

ListaA* inicListaA() {
    ListaA* lista = (ListaA*) malloc(sizeof(ListaA));
    if (lista == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

CelulaA* alocaCelulaA() {
    CelulaA* celula = (CelulaA*) malloc(sizeof(CelulaA));
    if (celula == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }
    return celula;
}

void insereListaA(ListaA* lista, CelulaP* amigo) {
    CelulaA* celula = alocaCelulaA();
    celula->amigo = amigo;
    celula->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = celula;
    } else {
        lista->ult->prox = celula;
    }
    
    lista->ult = celula;
}

CelulaA* retornaPrimAmigo(ListaA* lista) {
    return lista->prim;
}

CelulaA* retornaProxAmigo(CelulaA* cel) {
    return cel->prox;
}

char* retornaNomeAmigo(CelulaA* cel) {
    return retornaNomeCelulaP(cel->amigo);
}

CelulaP* retornaCelulaPAmigo(CelulaA* amigo) {
    return amigo->amigo;
}