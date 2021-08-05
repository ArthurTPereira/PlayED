#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "pessoa.h"
#include "listaPessoas.h"

int main() {

    mkdir("Saida",0777);

    FILE *amizade = fopen("Entrada/amizade.txt","r");

    ListaP* pessoas = inicListaP(); //Unico ponteiro acessivel, liberar tudo no final (?)
    
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
        insereListaA(retornaListaA(pessoas,amigo1),retornaPessoaP(pessoas,amigo2));
        insereListaA(retornaListaA(pessoas,amigo2),retornaPessoaP(pessoas,amigo1));
    }

    fclose(amizade);
    imprime(pessoas);
   
    FILE* playlists = fopen("Entrada/playlists.txt", "r");
    
    char playlist[100];
    char user[100];
    int n;

    char* pt2;
    char param[] = "Entrada/";
    char InputPath[30];
    FILE* play;
    char musica[100];

    while(!feof(playlists)) {
        fscanf(playlists," %[^;];%d;",user,&n);
        fscanf(playlists," %[^\n]\n",playlist);
        pt2 = strtok(playlist,";");
       
       
            
            printf("Usuario: %s\n",user);

        while (pt2 != NULL) {
            insereListaPlaylist(retornaPlaylistsP(pessoas,user),pt2);

            strcpy(InputPath,param);
            strcat(InputPath,pt2);
            play = fopen(InputPath,"r");

            while (!feof(play)) {
                fscanf(play," %[^\n]\n",musica);
                insereListaM(retornaListaM(retornaPlaylistsP(pessoas,user),pt2),musica);
            }
            printf("-----------------------------------\n");
            imprimeMusicas(retornaListaM(retornaPlaylistsP(pessoas,user),pt2));
            pt2 = strtok(NULL,";");
        }
        fclose(play);
    }


    fclose(playlists);

    return 0;
}