/*
** free_gui.c for bomberman in
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Fri Sep  9 03:12:04 2016 YUNG Steven
** Last update Fri Sep  9 03:12:11 2016 YUNG Steven
*/

#include "free_gui.h"

int		free_map(Map* m)
{
  int		i;

  SDL_FreeSurface(m->tileset);
  for (i = 0; i < m->nbtiles_height_world; i++)
    free(m->schema[i]);
  free(m->schema);
  free(m->props);
  free(m);
  return (0);
}
