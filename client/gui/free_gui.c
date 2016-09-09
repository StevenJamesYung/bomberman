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
