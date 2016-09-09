/*
** map.c for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:15:17 2016 YUNG Steven
** Last update Thu Sep  8 22:25:37 2016 YUNG Steven
*/

#include "map.h"

int		is_player_position(t_map *map, int x, int y)
{
  int		i;

  for (i = 0; i < MAX_PLAYERS; i++)
  {
    if (map->players[i] && map->players[i]->x == x && map->players[i]->y == y)
    {
      return (i + 1);
    }
  }
  return (0);
}

void		debug_map(t_map *map)
{
  int		x;
  int		y;
  int		p;

  for (y = 0; y < HEIGHT; y++)
    {
      for (x = 0; x < WIDTH; x++)
      {
        if ((p = is_player_position(map, x, y)) > 0)
        {
          printf("%d ", p);
        }
        else
        {
          printf("%d ", map->value[x][y]);
        }
      }
      printf("\n");
    }
}

t_map		*init_map()
{
  int		**m;
  int		i;
  int		y;
  t_map		*map;
  t_player	**players;

  if ((players = (t_player **)malloc(MAX_PLAYERS * sizeof(t_player))) == NULL)
    return (NULL);
  if ((map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  if ((m = (int **)malloc(HEIGHT * sizeof(int *))) == NULL)
    return (NULL);
  for (i = 0; i < HEIGHT; i++)
  {
    if ((m[i] = (int *)malloc(WIDTH * sizeof(int))) == NULL)
      return (NULL);
    for (y = 0; y < WIDTH; y++)
      m[i][y] = 0;
  }
  map->players = players;
  for (i = 0; i < MAX_PLAYERS; i++)
    map->players[i] = NULL;
  map->value = m;
  map->nb_players = 0;
  return (map);
}

int		free_map(t_map *map)
{
  int		i;

  for (i = 0; i < HEIGHT; i++)
    free(map->value[i]);
  free(map->value);
  for (i = 0; i < map->nb_players; i++)
    free(map->players[i]);
  free(map->players);
  free(map);

  return (0);
}

int		disconnect_player(t_map *map, int s)
{
  int		i;

  i = search_player_by_socket(map->players, map->nb_players, s);
  printf("iiiiiii: %d\n", i);
  if (i < 0)
    return (-1);
  free(map->players[i]);
  map->players[i] = NULL;
  map->nb_players--;
  return (0);
}
