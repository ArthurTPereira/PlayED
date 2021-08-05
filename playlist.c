#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playlist.h"

struct playlist {
    char* nome;
    ListaM* musicas;
    Playlist* prox;
};

struct listaPlaylist {
    Playlist* prim;
    Playlist* ult;
};

ListaPlaylist* inicListaPlaylists() {
    ListaPlaylist* lista = (ListaPlaylist*) malloc(sizeof(ListaPlaylist));
    if (lista == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

Playlist* criaCelulaPlaylist() {
    Playlist* play = (Playlist*) malloc(sizeof(Playlist));

    if (play == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }

    play->musicas = inicListaM(); // Nao foi liberado

    return play;
}

void insereListaPlaylist(ListaPlaylist* lista, char* playlist) {
    Playlist* play = criaCelulaPlaylist();
    play->nome = strdup(playlist);
    if (play->nome == NULL) {
        printf("Falha na alocação.\n");
        return;
    }


    play->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = play;

    } else {
        lista->ult->prox = play;
    }
    
    lista->ult = play;

}

void imprimeplaylists(ListaPlaylist* lista) {
    Playlist* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        printf("Playlist: %s\n",p->nome);
    }
}

//Retorna lista de musicas de uma playlist com base no nome
ListaM* retornaListaM(ListaPlaylist* lista, char* playlist) {
    Playlist* p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        if (strcmp(p->nome,playlist) == 0) {
            return p->musicas;
        }
    }

    return NULL;    
}

Playlist* retornaPrimPlaylist(ListaPlaylist* lista) {
    return lista->prim;
}

Playlist* retornaProxPlaylist(Playlist* playlist) {
    return playlist->prox;
}

char* retornaNomePlaylist(Playlist* playlist) {
    return playlist->nome;
}