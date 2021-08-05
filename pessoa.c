#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct pessoa {
    char* nome;
};

Pessoa* criaPessoa(char* nome) {
    Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if (pessoa == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }

    pessoa->nome = strdup(nome);
    if (pessoa->nome == NULL) {
        printf("Falha na alocação.\n");
        return NULL;
    }
    return pessoa;
}

void destroiPessoa(Pessoa* pessoa) {
    free(pessoa->nome);
    pessoa->nome = NULL;
    free(pessoa);
    pessoa = NULL;
}

char* retornaNome(Pessoa* pessoa) {
    return pessoa->nome;
}