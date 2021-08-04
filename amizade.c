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

//Inicializa a lista de amigos
ListaA* inicListaA() {
    ListaA* lista = (ListaA*) malloc(sizeof(ListaA));
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

//Aloca uma celula de amigo e verifica alocacao
CelulaA* alocaCelulaA() {
    CelulaA* celula = (CelulaA*) malloc(sizeof(CelulaA));
    if (celula == NULL) {
        printf("falhou o maloc");
        exit(1);
    }
    return celula;
}

//Insere uma pessoa na lista de amigos (Recebe a lista de amigos da pessoa e recebe a pessoa a ser adicionada)
void insereListaA(ListaA* lista, Pessoa* amigo) {
    CelulaA* celula = alocaCelulaA();
    celula->amigo = amigo;

    celula->prox = lista->prim;
    lista->prim = celula;

    if (lista->ult == NULL) {
        lista->ult = celula;
    }
}

//Retorna o primeiro amigo da lista
CelulaA* retornaPrim(ListaA* lista) {
    return lista->prim;
}

//Retorna a proxima celula 
CelulaA* retornaProx(CelulaA* cel) {
    return cel->prox;
}

//Retorna o nome do amigo da celula
char* retornaNomeAmigo(CelulaA* cel) {
    return retornaNome(cel->amigo);
}

