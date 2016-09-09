/*
** display.c for bomberman in
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Fri Sep  9 02:45:01 2016 YUNG Steven
** Last update Fri Sep  9 02:45:08 2016 YUNG Steven
*/

#include "display.h"

int		show_map(Map* m,SDL_Surface* screen)
{
  int		i;
  int		j;
  SDL_Rect	Rect_dest;
  int		numero_tile;

  for (i = 0; i < m->nbtiles_width_world; i++)
  {
    for (j = 0; j < m->nbtiles_height_world; j++)
    {
      Rect_dest.x = i * m->TILE_WIDTH;
      Rect_dest.y = j * m->TILE_HEIGHT;
      numero_tile = m->schema[i][j];
      SDL_BlitSurface(m->tileset, &(m->props[numero_tile].R), screen, &Rect_dest);
    }
  }
  return (0);
}
