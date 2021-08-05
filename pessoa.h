#ifndef PESSOA_H_
#define PESSOA_H_

typedef struct pessoa Pessoa;

/* Inicializa uma struct Pessoa
 * Input: Nome de uma pessoa
 * Output: Ponteiro para a pessoa inicializada
 * Pre-condição: Ponteiro para char possui um nome
 * Pos-condição: Ponteiro para pessoa aponta para uma memoria corretamente alocada // Verificar isso com a Karla
 */
Pessoa* criaPessoa(char* nome);

/* Libera memoria de um struct pessoa
 * Input: Ponteiro para struct de uma pessoa
 * Output: Nenhum
 * Pre-condição: Ponteiro para pessoa existe e a memória está alocada
 * Pos-condição: Toda a memoria do struct foi corretamente liberada
 */
void destroiPessoa(Pessoa* pessoa);

/* Retorna nome de uma pessoa
 * Input: Ponteiro de uma struct pessoa
 * Output: Nome da pessoa
 * Pre-condição: Ponteiro para pessoa existe e a memória está alocada
 * Pos-condição: O nome da pessoa permanece inalterado
 */
char* retornaNome(Pessoa* pessoa);

#endif