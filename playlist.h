#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "musica.h"

typedef struct playlist Playlist;

typedef struct listaPlaylist ListaPlaylist;

ListaPlaylist* inicListaPlaylists();

void insereListaPlaylist(ListaPlaylist* lista, char* playlist);

void imprimeplaylists(ListaPlaylist* lista);

ListaM* retornaListaM(ListaPlaylist* lista, char* playlist);

Playlist* retornaPrimPlaylist(ListaPlaylist* lista);

Playlist* retornaProxPlaylist(Playlist* playlist);

char* retornaNomePlaylist(Playlist* playlist);

#endif