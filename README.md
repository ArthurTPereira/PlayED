# PlayED

PlayED! é um programa que modela uma rede de amizades que podem compartilhar músicas entre si. Cada usuário possui sua lista de amigos e sua lista de playlists, em que cada playlist possui uma lista de músicas, e esse sistema é implementado por meio de listas de listas encadeadas, assim como TAD's de cada tipo utilizado no programa.

## Padrão dos arquivos

O arquivo amizade.txt possui o nome de todos os usuários na primeira linha, seguido dos nomes de dois usuários que são amigos. Além disso, o arquivo playlists.txt possui o nome do usuário, seguido da quantidade de playlists que este usuário possui, e o nome de suas playlists.

Cada arquivo .txt restante possui o nome de uma playlist, e dentro do arquivo existem as músicas que estão dentro dessa playlist. O padrão do nome das músicas é dado por:
```
Nome do artista/banda - Nome da música
```
Essa padronização é necessária por ser utilizado como base o site https://www.tunemymusic.com/pt/.

## Utilização

Rode o programa com os seguintes comandos:
```makefile
#Compila todos os arquivos
make
```
```makefile
#Roda o programa
make run
```
Caso seja necessário uma recompilação, utilize o comando
```makefile
#Remove todos os arquivos compilados
make clean
```
E repita o primeiro passo.

## Licença
[MIT](https://choosealicense.com/licenses/mit/)
