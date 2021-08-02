#include <stdio.h>
#include <string.h>
#include "pessoa.h"
#include "listaPessoas.h"
#include "amizade.h"

int main() {

    FILE *amizade = fopen("Entrada/amizade.txt","r");

    ListaP* pessoas = inicListaP(); //Unico ponteiro acessivel, liberar tudo no final
    
    char linha[1000];
    fscanf(amizade," %[^\n]\n",linha);

    char* pt = strtok(linha,";");
    while (pt != NULL) {
        Pessoa* pessoa = criaPessoa(pt);
        insereListaP(pessoas,pessoa);    
        pt = strtok(NULL, ";");
    }

    char amigo1[100];
    char amigo2[100];
    while(!feof(amizade)) {
        fscanf(amizade," %[^;];%s",amigo1,amigo2);
        // funcao pra add amigo
        insereListaA(retornaListaA(pessoas,amigo1),retornaPessoaP(pessoas,amigo2));
        insereListaA(retornaListaA(pessoas,amigo2),retornaPessoaP(pessoas,amigo1));
    }

    fclose(amizade);
    imprime(pessoas);
    printf("\n\n\n\n");
    FILE* playlists = fopen("Entrada/playlists.txt", "r");
    
    char playlist[100];
    char user[100];
    int n;

    while(!feof(playlists)) {

    }






    fclose(playlists);



    return 0;




    Pessoa* joao = criaPessoa("Joao");
    Pessoa* caio = criaPessoa("Caio");
    
    // ListaP* pessoas = inicListaP();

    // insereListaP(pessoas,joao);
    // insereListaP(pessoas,caio);

    // inicListaA(retornaListaA(pessoas,joao));
    // insereListaA(retornaListaA(pessoas,joao),caio);
    // insereListaA(retornaListaA(pessoas,caio),joao);

    // imprime(pessoas);

    
    // liberaListaP(pessoas);
    // destroiPessoa(joao);
    // destroiPessoa(caio);

    return 0;
}