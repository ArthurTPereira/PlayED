#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "listaPessoas.h"

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

ListaP* inicListaP() {
    ListaP* lista = (ListaP*) malloc(sizeof(ListaP));
    if (lista == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }
    
    
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

CelulaP* criaCelulaP() {
    CelulaP* celula = (CelulaP*) malloc(sizeof(CelulaP));
    if (celula == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }
    
    return celula;
}

void insereListaP(ListaP* lista, Pessoa* pessoa) {
    CelulaP* celula = criaCelulaP();
    celula->pessoa = pessoa;
    celula->prox = NULL;
    
    celula->amigos = inicListaA();
    celula->playlists = inicListaPlaylists();

    if (lista->ult == NULL) {
        lista->prim = celula;
    } else {
        lista->ult->prox = celula;
    }
    
    lista->ult = celula;
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

        CelulaA* t = retornaPrimAmigo(p->amigos);
        if (t == NULL) {
            printf("Nenhum\n");
        } else {
            for ( t; t != NULL ; t = retornaProxAmigo(t)) {
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

ListaPlaylist* retornaPlaylistsP(ListaP* lista, char* pessoa) {
    CelulaP* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        if (strcmp(retornaNome(p->pessoa),pessoa) == 0) {
            return p->playlists;
        }
    }
    
    return NULL;
}

CelulaP* retornaPrimPessoa(ListaP* lista) {
    return lista->prim;
}

CelulaP* retornaProxPessoa(CelulaP* pessoa) {
    return pessoa->prox;
}

CelulaP* retornaUltPessoa(ListaP* lista) {
    return lista->ult;
}

ListaPlaylist* retornaListaPlaylistsP(CelulaP* pessoa) {
    return pessoa->playlists;
}

char* retornaNomeCelulaP(CelulaP* pessoa) {
    return retornaNome(pessoa->pessoa);
}

void alteraPlaylist(ListaPlaylist* playlist, CelulaP* pessoa) {
    pessoa->playlists = playlist;
}

int verificaAmizade(CelulaP* pessoa1, CelulaP* amigo) {
    CelulaA* p;
    for (p = retornaPrimAmigo(pessoa1->amigos); p != NULL; p = retornaProxAmigo(p)) {
        if (strcmp(retornaNomeAmigo(p),retornaNomeCelulaP(amigo)) == 0) {
            return 1;
        }
    }

    return 0;
}

ListaA* retornaListaAmigos(CelulaP* pessoa) {
    return pessoa->amigos;
}