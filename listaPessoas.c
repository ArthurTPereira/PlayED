#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "listaPessoas.h"
#include "musica.h"
#include "playlist.h"

struct celulaP {
    Pessoa* pessoa;
    CelulaP* prox;
    ListaA* amigos;
    ListaPlaylist* playlists;
};

struct listaP {
    CelulaP* prim;
    CelulaP* ult;
};

//Inicializa a lista de pessoas e verifica alocacao
ListaP* inicListaP() {
    ListaP* lista = (ListaP*) malloc(sizeof(ListaP));
    if (lista == NULL) {
        printf("erro alloc");
        exit(1);
    }
    
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

//Cria uma celula de uma pessoa e verifica alocacao
CelulaP* criaCelulaP() {
    CelulaP* celula = (CelulaP*) malloc(sizeof(CelulaP));
    if (celula == NULL) {
        printf("erro aloc");
        exit(1);
    }
    
    return celula;
}

//Insere uma pessoa na lista de pessoas
void insereListaP(ListaP* lista, Pessoa* pessoa) {
    CelulaP* celula = criaCelulaP();
    celula->pessoa = pessoa;
    
    //Inicializa a sentinela da lista de amigos
    celula->amigos = inicListaA();  // Nao foi liberado isso aqui
    celula->playlists = inicListaPlaylists(); // Nao foi liberado

    celula->prox = lista->prim;
    lista->prim = celula;

    if (lista->ult == NULL) {
        lista->ult = celula;
    }
}

//Libera a memoria da lista de pessoas(acho q essa funçao vai ter que liberar tudo)
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

//Retorna a lista de amigos de uma pessoa
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

        CelulaA* t = retornaPrim(p->amigos);
        if (t == NULL) {
            printf("Nenhum\n");
        } else {
            for ( t; t != NULL ; t = retornaProx(t)) {
                printf("%s\n",retornaNomeAmigo(t));
            }
        }
    }
}

//Retorna struct de uma pessoa em uma lista com base no nome
Pessoa* retornaPessoaP(ListaP* lista, char* pessoa) {
    CelulaP* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        if (strcmp(retornaNome(p->pessoa),pessoa) == 0) {
            return p->pessoa;
        }
    }

    return NULL;
}

//Retorna ponteiro para sentinela de playlists de uma pessoa com base no nome
ListaPlaylist* retornaPlaylistsP(ListaP* lista, char* pessoa) {
    CelulaP* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        if (strcmp(retornaNome(p->pessoa),pessoa) == 0) {
            return p->playlists;
        }
    }
    
    return NULL;
}