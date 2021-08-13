#include <stdio.h>
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
        //Verifica se o nome da playlist é igual ao nome da playlist atual
        if (strcmp(retornaNomePlaylist(p),playlist) == 0) {
            return 1;
        }
        p = retornaProxPlaylist(p);       
    }
    
    return 0;
}

/* Faz o trim de uma string
 * Input: Ponteiro para uma string
 * Output: Ponteiro para a string inicial sem espaços no final
 * Pre-condição: A string existe
 * Pos-condição: A string foi corretamente alterada
 */
char* trim(char *s) {
    char *ptr;
    if (s == NULL) {
        return NULL;
    }
    if (!*s) {
        return s;
    }

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

    //Faz a varredura para as playlists da lista
    for (p = retornaPrimPlaylist(lista); p != NULL; p = retornaProxPlaylist(p)) {
        //Faz a varredura para as musicas da playlist atual
        for (m = retornaPrimMusica(retornaListaMusicas(p)); m != NULL; m = retornaProxMusica(m)) {
            //Extrai o nome do artista/banda
            strcpy(musica,retornaNomeMusica(m));
            sscanf(musica," %[^-]",temp);
            strcpy(artista,trim(temp));

            //Verifica se a lista nova está vazia
            if (retornaPrimPlaylist(nova) == NULL) {
                insereListaPlaylist(nova,artista);
            } else {
                //Verifica se a playlist do artista/banda ja existe
                if (buscaPlaylist(nova,artista) == 0) {
                    insereListaPlaylist(nova,artista);
                }
            }

            //Faz a varredura nas playlists e insere as musicas correspondentes
            for (q = retornaPrimPlaylist(nova); q != NULL; q = retornaProxPlaylist(q)) {
                if (strcmp(retornaNomePlaylist(q),artista) == 0) {
                    insereListaM(retornaListaMusicas(q),musica);
                }
            }
        }
    }

    //Libera as musicas e a lista de playlists antiga
    for (p = retornaPrimPlaylist(lista); p != NULL; p = retornaProxPlaylist(p)) {
        liberaListaMusicas(retornaListaMusicas(p));
    }
    liberaListaPlaylists(lista);
        
    return nova;
}

int verificaMusicasIguais(ListaPlaylist* lista1, ListaPlaylist* lista2) {
    int qtd = 0;

    Playlist* p;
    Playlist* q;
    Musica* r;
    Musica* s;

    //Faz a varredura para a primeira lista de playlists
    for (p = retornaPrimPlaylist(lista1); p != NULL; p = retornaProxPlaylist(p)) {
        //Faz a varredura para a segunda lista de playlists
        for (q = retornaPrimPlaylist(lista2); q != NULL; q = retornaProxPlaylist(q)) {
            //Verifica se as playlists possuem nomes iguais
            if (strcmp(retornaNomePlaylist(p),retornaNomePlaylist(q)) == 0) {
                //Faz a varredura para as musicas da playlist da lista 1
                for (r = retornaPrimMusica(retornaListaMusicas(p)); r != NULL; r = retornaProxMusica(r)) {
                    //Faz a varredura para as musicas da playlist da lista 2
                    for (s = retornaPrimMusica(retornaListaMusicas(q)); s != NULL; s = retornaProxMusica(s)) {
                        //Verifica se os nomes das musicas sao iguais
                        if (strcmp(retornaNomeMusica(r),retornaNomeMusica(s)) == 0) {
                            qtd++;
                        }
                    }
                }
            }
        }
    }

    return qtd;
}