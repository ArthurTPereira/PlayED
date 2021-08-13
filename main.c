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

    //Cria a pasta de saída
    mkdir("Saida",0777);

    //Abre o arquivo amizade.txt
    FILE *amizade = fopen("Entrada/amizade.txt","r");

    //Inicia a lista de pessoas
    ListaP* pessoas = inicListaP();

    char linha[1000];

    //Faz o scan da linha de nomes, depois separa os nomes e insere na lista de pessoas
    fscanf(amizade," %[^\n]\n",linha);
    char* pt = strtok(linha,";");
    while (pt != NULL) {
        Pessoa* pessoa = criaPessoa(pt);
        insereListaP(pessoas,pessoa);    
        pt = strtok(NULL, ";");
    }

    char amigo1[100];
    char amigo2[100];

    //Faz a inserção das amizades na lista de amigos de cada pessoa
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

    //Faz a leitura dos nomes das playlists e insere na lista de playlists de cada usuário
    while(!feof(playlists)) {
        fscanf(playlists," %[^;];%d;",user,&n);
        fscanf(playlists," %[^\n]\n",playlist);

        pt2 = strtok(playlist,";");
        while (pt2 != NULL) {
            insereListaPlaylist(retornaPlaylistsP(pessoas,user),pt2);

            strcpy(InputPath,param);
            strcat(InputPath,pt2);
            musicasPlaylist = fopen(InputPath,"r");

            //Faz a leitura dos nomes das músicas e insere na lista de músicas da playlist atual
            while (!feof(musicasPlaylist)) {
                fscanf(musicasPlaylist," %[^\n]\n",musica);
                insereListaM(retornaListaM(retornaPlaylistsP(pessoas,user),pt2),musica);
            }
            pt2 = strtok(NULL,";");
            fclose(musicasPlaylist);
        }
    }

    fclose(playlists);

    CelulaP* p;
    ListaPlaylist* ls;

    //Recria as playlists dos usuários, separando por artista/banda
    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        ls = recriaPlaylists(retornaListaPlaylistsP(p));
        alteraPlaylist(ls,p);
    }

    int count;
    char destino[100];
    char nomePlaylist[30];
    Playlist* play;
    Musica* nomeMusica;
    FILE* novaPlaylist;
    FILE* playedRefatorada = fopen("Saida/played-refatorada.txt","w");

    //Imprime as playlists nos arquivos de destino
    //Faz a varredura para cada usuario
    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        count = 0;
        strcpy(destino,"Saida/");
        strcpy(user,retornaNomeCelulaP(p));
        strcat(destino,user);
        strcat(destino,"/");
        mkdir(destino,0777);

        //Faz a varredura para cada playlist do usuario
        for (play = retornaPrimPlaylist(retornaListaPlaylistsP(p)); play != NULL; play = retornaProxPlaylist(play)) {
            count++;
            strcpy(destino,"Saida/");
            strcat(destino,user);
            strcat(destino,"/");
            
            strcat(destino,retornaNomePlaylist(play));
            strcat(destino,".txt");
            novaPlaylist = fopen(destino,"w");

            //Faz a varredura para cada música da playlist
            for (nomeMusica = retornaPrimMusica(retornaListaMusicas(play)); nomeMusica != NULL; nomeMusica = retornaProxMusica(nomeMusica)) {
                fprintf(novaPlaylist,"%s\n",retornaNomeMusica(nomeMusica));
            }
            fclose(novaPlaylist);
        }

        //Imprime as playlists refatoradas
        fprintf(playedRefatorada,"%s;%d",user,count);
        for (play = retornaPrimPlaylist(retornaListaPlaylistsP(p)); play != NULL; play = retornaProxPlaylist(play)) {
            strcpy(nomePlaylist,retornaNomePlaylist(play));
            strcat(nomePlaylist,".txt");
            fprintf(playedRefatorada,";%s",nomePlaylist);
        }
        fprintf(playedRefatorada,"\n");
    }
    fclose(playedRefatorada);
    

    FILE* similaridades = fopen("Saida/similaridades.txt","w");
    CelulaP* q;

    //Imprime as amizades e a quantidade de músicas similares
    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        for (q = retornaProxPessoa(p); q != NULL; q = retornaProxPessoa(q)) {
            if (verificaAmizade(p,q) == 1) {
                fprintf(similaridades,"%s;%s;%d\n",retornaNomeCelulaP(p),retornaNomeCelulaP(q),verificaMusicasIguais(retornaListaPlaylistsP(p),retornaListaPlaylistsP(q)));
            }
        }
    }
    fclose(similaridades);

    //Libera a memória alocada para todas as listas
    for (p = retornaPrimPessoa(pessoas); p != NULL; p = retornaProxPessoa(p)) {
        for (play = retornaPrimPlaylist(retornaListaPlaylistsP(p)); play != NULL; play = retornaProxPlaylist(play)) {
            liberaListaMusicas(retornaListaMusicas(play));
        }
        liberaListaPlaylists(retornaListaPlaylistsP(p));
        liberaListaAmigos(retornaListaAmigos(p));
    }
    liberaListaP(pessoas);
    
    return 0;
}