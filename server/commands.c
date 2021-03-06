/*
** commands.c for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:14:07 2016 YUNG Steven
** Last update Thu Sep  8 22:22:56 2016 YUNG Steven
*/

#include "commands.h"
#include "map_functions.h"

int	up(t_map *map, int player)
{
  int	i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (i == -1)
    return (-1);
  if (map->players[i]->y - 1 >= 0)
    {
      map->players[i]->y -= 1;
    }
  printf("-------------\n");
  debug_map(map);
  return (0);
}

int	down(t_map *map, int player)
{
  int	i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (i == -1)
    return (-1);
  if (map->players[i]->y + 1 < HEIGHT)
    {
      map->players[i]->y += 1;
    }
  printf("-------------\n");
  debug_map(map);
  return (0);
}

int	right(t_map *map, int player)
{
  int	i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (i == -1)
    return (-1);
  if (map->players[i]->x + 1 < WIDTH)
    {
      map->players[i]->x += 1;
    }
  printf("-------------\n");
  debug_map(map);
  return (0);
}

int	left(t_map *map, int player)
{
  int	i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (i == -1)
    return (-1);
  if (map->players[i]->x - 1 >= 0)
    {
      map->players[i]->x -= 1;
    }
  printf("-------------\n");
  debug_map(map);
  return (0);
}

int	drop(t_map *map, int player)
{
  int	i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (i == -1)
    return (-1);
  printf("DROP %d\n", player);
  printf("DROP %s\n", map->players[i]->username);
  debug_map(map);
  return (0);
}
