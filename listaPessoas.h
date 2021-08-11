#ifndef LISTAPESSOAS_H_
#define LISTAPESSOAS_H_

#include "amizade.h"
#include "playlist.h"

typedef struct listaP ListaP;

typedef struct celulaP CelulaP;

/* Inicializa a lista de pessoas
 * Input: Nenhum
 * Output: Ponteiro para sentinela de pessoas
 * Pre-condição: Nenhum
 * Pos-condição: A memória foi corretamente alocada
 */
ListaP* inicListaP();

/* Insere uma pessoa em uma lista de pessoas
 * Input: Ponteiro para sentinela de lista de pessoas e um ponteiro para struct de pessoa
 * Output: Nenhum
 * Pre-condição: A lista e a pessoa existem e estão corretamente alocadas
 * Pos-condição: A pessoa é inserida no final da lista e a lista não é quebrada
 */
void insereListaP(ListaP* lista, Pessoa* pessoa);

/* Retorna lista de amigos de uma pessoa
 * Input: Ponteiro para sentinela de lista de pessoas e o nome da pessoa
 * Output: Ponteiro para sentinela de lista de amigos da pessoa
 * Pre-condição: A lista existe e está corretamente alocada, e o nome da pessoa existe e está na lista
 * Pos-condição: A lista permanece inalterada
 */
ListaA* retornaListaA(ListaP* lista, char* pessoa);

//Função temporária
void imprime(ListaP* lista);

/* Retorna struct de pessoa
 * Input: Lista de pessoas e o nome da pessoa
 * Output: Ponteiro para struct da pessoa
 * Pre-condição: A lista existe e está corretamente alocada, e o nome da pessoa existe e está na lista
 * Pos-condição: A lista permanece inalterada
 */
Pessoa* retornaPessoaP(ListaP* lista, char* pessoa);

/* Retorna lista de playlists de uma pessoa
 * Input: Lista de pessoas e o nome da pessoa
 * Output: Lista de playlists da pessoa
 * Pre-condição: A lista de pessoas existe e está corretamente alocada, e o nome da pessoas existe e está na lista
 * Pos-condição: A lista permanece inalterada
 */
ListaPlaylist* retornaPlaylistsP(ListaP* lista, char* pessoa);

/* Retorna primeira pessoa de uma lista
 * Input: Lista de pessoas
 * Output: Ponteiro para celula da primeira pessoa da lista
 * Pre-condição: A lista existe e está corretamente alocada
 * Pos-condição: A lista permanece inalterada
*/ 
CelulaP* retornaPrimPessoa(ListaP* lista);

/* Retorna a proxima pessoa de uma celula
 * Input: Celula de uma pessoa
 * Output: Ponteiro para celula da proxima pessoa da celula
 * Pre-condição: A celula existe e está corretamente alocada
 * Pos-condição: A celula permance inalterada
*/
CelulaP* retornaProxPessoa(CelulaP* pessoa);

CelulaP* retornaUltPessoa(ListaP* lista);

//Função em construção
void liberaListaP(ListaP* lista);

/* Retorna a lista de playlists de uma celula de pessoa
 * Input: Celula de uma pessoa
 * Output: Ponteiro para lista de playlists da pessoa
 * Pre-condição: A celula existe e está corretamente alocada
 * Pos-condição: A celula permance inalterada
*/
ListaPlaylist* retornaListaPlaylistsP(CelulaP* pessoa);

/* Retorna o nome de uma pessoa a partir de sua celula
 * Input: Celula de pessoa
 * Output: Nome da pessoa
 * Pre-condição: A celula existe e está corretamente alocada
 * Pos-condição: A celula permanece inalterada
*/
char* retornaNomeCelulaP(CelulaP* pessoa);

void alteraPlaylist(ListaPlaylist* playlist, CelulaP* pessoa);

int verificaAmizade(CelulaP* pessoa1, CelulaP* amigo);

ListaA* retornaListaAmigos(CelulaP* pessoa);

#endif