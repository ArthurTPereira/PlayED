#include <stdio.h>
#include "pessoa.h"
#include "listaPessoas.h"
#include "amizade.h"

int main() {

    Pessoa* joao = criaPessoa("Joao");
    Pessoa* caio = criaPessoa("Caio");
    
    ListaP* pessoas = inicListaP();

    insereListaP(pessoas,joao);
    insereListaP(pessoas,caio);

    inicListaA(retornaListaA(pessoas,joao));
    insereListaA(retornaListaA(pessoas,joao),caio);

    
    liberaListaP(pessoas);
    destroiPessoa(joao);
    destroiPessoa(caio);

    return 0;
}