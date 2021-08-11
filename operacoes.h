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

int verificaMusicasIguais(ListaPlaylist* lista1, ListaPlaylist* lista2);

#endif