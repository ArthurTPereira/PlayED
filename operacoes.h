#ifndef OPERACOES_H_
#define OPERACOES_H_


/* Recria a playlist de músicas, separando por artista/banda, e destroi as playlists antigas
 * Input: Lista de playlists
 * Output: Lista de playlists com novas playlists
 * Pre-condição: A lista de playlists existe e está corretamente alocada
 * Pos-condição: A lista de playlists foi corretamente alocada, está dividida por artistas e contém as músicas dos artistas,
 * e as playlists antigas foram destruídas
*/
ListaPlaylist* recriaPlaylists(ListaPlaylist* lista);

/* Verifica e retorna a quantidade de músicas iguais entre duas listas de playlists
 * Input: Duas listas de playlists
 * Output: Número de músicas iguais entre as duas listas de playlists
 * Pre-condição: As duas listas existem e estão corretamente alocadas
 * Pos-condição: As listas permanecem inalteradas
 */
int verificaMusicasIguais(ListaPlaylist* lista1, ListaPlaylist* lista2);

#endif