#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct pessoa {
    char* nome;
};

Pessoa* criaPessoa(char* nome) {
    Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    pessoa->nome = strdup(nome);
    return pessoa;
}

void destroiPessoa(Pessoa* pessoa) {
    free(pessoa->nome);
    free(pessoa);   
}

char* retornaNome(Pessoa* pessoa) {
    return pessoa->nome;
}