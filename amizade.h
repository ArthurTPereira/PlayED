#ifndef AMIZADE_H_
#define AMIZADE_H_

typedef struct celulaA CelulaA;

typedef struct listaA ListaA;

/* Inicializa a lista de amigos
 * Input: Nenhum
 * Output: Ponteiro para lista de amigos
 * Pre-condição: Nenhum
 * Pos-condição: A memória foi corretamente alocada
 */
ListaA* inicListaA();

/* Inicializa a celula de um amigo
 * Input: Nenhum
 * Output: Ponteiro para celula de amigo
 * Pre-condição: Nenhum
 * Pos-condição: A memória foi corretamente alocada
 */
CelulaA* alocaCelulaA();

/* Insere um amigo na lista de amigos
 * Input: Lista de amigos e ponteiro para a pessoa a ser adicionada
 * Output: Nenhum
 * Pre-condição: A lista e o amigo existem e estão corretamente alocados
 * Pos-condição: O amigo é adicionado no final da lista e a lista não é quebrada
 */
void insereListaA(ListaA* lista, Pessoa* amigo);

void liberaListaA(ListaA* lista);

/* Retorna primeira celula da lista de amigos
 * Input: Lista de amigos
 * Output: Ponteiro para primeira celula da lista de amigos
 * Pre-condição: A lista existe e está corretamente alocada
 * Pos-condição: a lista permanece inalterada
 */
CelulaA* retornaPrim(ListaA* lista);

/* Retorna proxima celula de uma celula de amigo
 * Input: Celula de amigo
 * Output: Ponteiro para proxima celula do input
 * Pre-condição: A célula existe e está corretamente alocada
 * Pos-condição: A célula permanece inalterada
 */
CelulaA* retornaProx(CelulaA* cel);

/* Retorna o nome de um amigo
 * Input: Celula de um amigo
 * Output: Nome do amigo
 * Pre-condição: A célula existe e está corretamente alocada
 * Pos-condição: A célula permanece inalterada
 */
char* retornaNomeAmigo(CelulaA* cel);

#endif