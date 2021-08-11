/* Trabalho I - Estrutura de Dados 
 * Universidade Federal do Espírito Santo 
 * 2021/1 - Patricia Dockhorn Costa
 * Arthur Tartaglia Pereira e Karla Sancio
 * Github: ArthurTPereira || KarlaSancio
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "listaPessoas.h"
#include "operacoes.h"

int main() {

    mkdir("Saida",0777);

    FILE *amizade = fopen("Entrada/amizade.txt","r");

    ListaP* pessoas = inicListaP();
    
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
   
    FILE* playlists = fopen("Entrada/playlists.txt", "r");
    
    char playlist[100];
    char user[100];
    int n;

    char* pt2;
    char param[] = "Entrada/";
    char InputPath[30];
    FILE* musicasPlaylist;
    char musica[100];

    while(!feof(playlists)) {
        fscanf(playlists," %[^;];%d;",user,&n);
        fscanf(playlists," %[^\n]\n",playlist);

        pt2 = strtok(playlist,";");
        while (pt2 != NULL) {
            insereListaPlaylist(retornaPlaylistsP(pessoas,user),pt2);

            strcpy(InputPath,param);
            strcat(InputPath,pt2);
            musicasPlaylist = fopen(InputPath,"r");

            while (!feof(musicasPlaylist)) {
                fscanf(musicasPlaylist," %[^\n]\n",musica);
                insereListaM(retornaListaM(retornaPlaylistsP(pessoas,user),pt2),musica);
            }
            pt2 = strtok(NULL,";");
        }
        fclose(musicasPlaylist);
    }

    fclose(playlists);

    CelulaP* p;
    ListaPlaylist* ls;
    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        ls = retornaListaPlaylistsP(p);
        ls = recriaPlaylists(retornaListaPlaylistsP(p));
        alteraPlaylist(ls,p);
    }

    int count;
    char destino[100];
    char nome[30];
    char nomePlaylist[30];
    Playlist* play;
    Musica* nomeMusica;
    FILE* novaPlaylist;
    FILE* playedRefatorada = fopen("Saida/played-refatorada.txt","w");
    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        count = 0;
        strcpy(destino,"Saida/");
        strcpy(nome,retornaNomeCelulaP(p));
        strcat(destino,nome);
        strcat(destino,"/");
        mkdir(destino,0777);

        for (play = retornaPrimPlaylist(retornaListaPlaylistsP(p)); play != NULL; play = retornaProxPlaylist(play)) {
            count++;
            strcpy(destino,"Saida/");
            strcat(destino,nome);
            strcat(destino,"/");
            
            strcat(destino,retornaNomePlaylist(play));
            strcat(destino,".txt");
            novaPlaylist = fopen(destino,"w");
            for (nomeMusica = retornaPrimMusica(retornaListaMusicas(play)); nomeMusica != NULL; nomeMusica = retornaProxMusica(nomeMusica)) {
                fprintf(novaPlaylist,"%s\n",retornaNomeMusica(nomeMusica));
            }
        }
        fclose(novaPlaylist);
        
        fprintf(playedRefatorada,"%s;%d",nome,count);
        for (play = retornaPrimPlaylist(retornaListaPlaylistsP(p)); play != NULL; play = retornaProxPlaylist(play)) {
            strcpy(nomePlaylist,retornaNomePlaylist(play));
            strcat(nomePlaylist,".txt");
            fprintf(playedRefatorada,";%s",nomePlaylist);
        }
        fprintf(playedRefatorada,"\n");
    }
    fclose(playedRefatorada);
    

    FILE* similaridades = fopen("Saida/similaridades.txt","w");
    CelulaP* amigo;

    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        for (amigo = retornaPrimPessoa(pessoas); amigo != NULL; amigo = retornaProxPessoa(amigo)) {
            if (verificaAmizade(p,amigo) == 1) {
                fprintf(similaridades,"%s;%s;%d\n",retornaNomeCelulaP(p),retornaNomeCelulaP(amigo),verificaMusicasIguais(retornaListaPlaylistsP(p),retornaListaPlaylistsP(amigo)));
            }
        }
    }

    fclose(similaridades);

    return 0;
}