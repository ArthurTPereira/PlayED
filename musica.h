#ifndef MUSICA_H_
#define MUSICA_H_

typedef struct celulaM Musica;

typedef struct listaM ListaM;

/* Inicializa uma lista de musicas
 * Input: Nenhum
 * Output: Ponteiro para sentinela da lista de músicas
 * Pre-condição: Nenhum
 * Pos-condição: A memória foi corretamente alocada
 */
ListaM* inicListaM();

/* Insere uma música em uma lista de músicas
 * Input: Lista de músicas e o nome da música a ser adicionada
 * Output: Nenhum
 * Pre-condição: A lista existe e está corretamente alocada, e o nome da música existe
 * Pos condição: A música é adicionada no final da lista, e a lista não é quebrada
 */
void insereListaM(ListaM* lista, char* musica);

//Função temporária
void imprimeMusicas(ListaM* lista);

/* Retorna primeira celula de musica de uma lista
 * Input: Lista de musicas
 * Output: Ponteiro para primeira celula da lista
 * Pre-condição: A lista existe e está corretamente alocada
 * Pos-condição: A lista permanece inalterada
 */
Musica* retornaPrimMusica(ListaM* lista);

/* Retorna proxima celula de musica de uma celula
 * Input: Celula de uma musica
 * Output: Ponteiro para próxima celula
 * Pre-condição: A celula existe e está corretamente alocada
 * Pos-condição: A celula permanece inalterada
 */
Musica* retornaProxMusica(Musica* musica);

/* Retorna nome de uma musica
 * Input: Celula de uma musica
 * Output: Ponteiro para nome de uma musica
 * Pre-condição: A celula e o nome da musica existem e estão corretamente alocados
 * Pos-condição: A celula e o nome da musica permanecem inalterados
 */
char* retornaNomeMusica(Musica* musica);

/* Libera a memória alocada de uma lista de musicas
 * Input: Lista de musicas
 * Output: Nenhum
 * Pre-condição: A lista existe e está corretamente alocada
 * Pos-condição: A lista, a sentinela e os nomes das musicas foram liberados
*/
void liberaListaMusicas(ListaM* lista);

#endif