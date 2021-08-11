#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "musica.h"

typedef struct playlist Playlist;

typedef struct listaPlaylist ListaPlaylist;

/* Inicializa uma lista de playlists
 * Input: Nenhum
 * Output: Ponteiro para sentinela da lista de playlists
 * Pre-condição: Nenhum
 * Pos-condição: A memória foi corretamente alocada
 */
ListaPlaylist* inicListaPlaylists();

/* Insere uma playlist em uma lista de playlists
 * Input: Lista de playlists e o nome da playlist a ser adicionada
 * Output: Nenhum
 * Pre-condição: A lista existe e está corretamente alocada, e o nome da playlist existe e é válida
* Pos-condição: A playlist é adicionada no final da lista, e a lista não é quebrada
 */
void insereListaPlaylist(ListaPlaylist* lista, char* playlist);

//Função temporária
void imprimeplaylists(ListaPlaylist* lista);

/* Retorna ponteiro para sentinela da lista de músicas de uma playlist com base no nome
 * Input: Lista de playlists e o nome de uma playlist
 * Output: Ponteiro para sentinela de lista de músicas
 * Pre-condição: A lista existe e está corretamente alocada, e o nome da playlist está na lista
 * Pos-condição: A lista de playlists é inalterada
 */
ListaM* retornaListaM(ListaPlaylist* lista, char* playlist);

/* Retorna primeira playlist de uma lista
 * Input: Lista de playlists
 * Output: Ponteiro para a primeira playlist da lista
 * Pre-condição: A lista existe e está corretamente alocada
 * Pos-condição: A lista permanece inalterada
 */
Playlist* retornaPrimPlaylist(ListaPlaylist* lista);

/* Retorna proxima playlist
 * Input: Celula de uma playlist
 * Output: Proxima celula
 * Pre-condição: Celula da playlist existe e está corretamente alocada
 * Pos-condição: A celula permanece inalterada
 */
Playlist* retornaProxPlaylist(Playlist* playlist);

/* Retorna o nome de uma playlist
 * Input: Celula de uma playlist
 * Output: Nome da playlist da celula
 * Pre-condição: Celula da playlist existe e está corretamente alocada
 * Pos-condição: A celula permanece inalterada
 */
char* retornaNomePlaylist(Playlist* playlist);

/* Retorna a lista de musicas de uma celula de playlist
 * Input: Celula de uma playlist
 * Output: Ponteiro para lista de musicas
 * Pre-condição: A celula existe e está corretamente alocada
 * Pos-condição: A celula permanece inalterada
*/
ListaM* retornaListaMusicas(Playlist* playlist);

/* Libera a memória alocada de uma lista de playlists
 * Input: Lista de playlists
 * Output: Nenhum
 * Pre-condição: A lista existe e está corretamente alocada
 * Pos-condição: Somente a lista, a sentinela e os nomes das playlists foram liberados
*/
void liberaListaPlaylists(ListaPlaylist* lista);

#endif