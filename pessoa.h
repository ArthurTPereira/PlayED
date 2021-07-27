#ifndef PESSOA_H_
#define PESSOA_H_

typedef struct pessoa Pessoa;

Pessoa* criaPessoa(char* nome);

void destroiPessoa(Pessoa* pessoa);

char* retornaNome(Pessoa* pessoa);

#endif