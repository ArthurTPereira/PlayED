#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaPessoas.h"
#include "operacoes.h"


/* Busca por uma playlist em uma lista de playlists
 * Input: Lista de playlists e o nome da playlist
 * Output: Booleano: retorna 1 se a playlist está na lista, ou 0 se não está na lista
 * Pre-condição: A lista existe e está corretamente alocada, e o nome da playlist é válido
 * Pos-condição: Nenhum
*/
int buscaPlaylist(ListaPlaylist* lista,char* playlist) {
    Playlist* p = retornaPrimPlaylist(lista);
    while (p != NULL) {
        if (strcmp(retornaNomePlaylist(p),playlist) == 0) {
            return 1;
        }
        p = retornaProxPlaylist(p);       
    }
    
    return 0;
}

char* trim(char *s) {
    char *ptr;
    if (!s)
        return NULL;   // handle NULL string
    if (!*s)
        return s;      // handle empty string
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}


ListaPlaylist* recriaPlaylists(ListaPlaylist* lista) {
    ListaPlaylist* nova = inicListaPlaylists();
    
    Playlist* p;
    Playlist* q;
    Musica* m;
    char musica[100];
    char temp[30];
    char artista[30];

    for (p = retornaPrimPlaylist(lista); p != NULL; p = retornaProxPlaylist(p)) {
        for (m = retornaPrimMusica(retornaListaMusicas(p)); m != NULL; m = retornaProxMusica(m)) {
            strcpy(musica,retornaNomeMusica(m));
            sscanf(musica," %[^-]",temp);
            strcpy(artista,trim(temp));

            if (retornaPrimPlaylist(nova) == NULL) {
                insereListaPlaylist(nova,artista);
            } else {
                if (buscaPlaylist(nova,artista) == 1) {
                } else {
                    insereListaPlaylist(nova,artista);
                }
            }

            for (q = retornaPrimPlaylist(nova); q != NULL; q = retornaProxPlaylist(q)) {
                if (strcmp(retornaNomePlaylist(q),artista) == 0) {
                    insereListaM(retornaListaMusicas(q),musica);
                }
            }
        }
    }

    for (p = retornaPrimPlaylist(lista); p != NULL; p = retornaProxPlaylist(p)) {
        liberaListaMusicas(retornaListaMusicas(p));
    }
    liberaListaPlaylists(lista);
        
    return nova;
}