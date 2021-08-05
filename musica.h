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

void imprimeMusicas(ListaM* lista);



#endif