#include "commands.h"

void up(t_map *map, int player)
{
  int i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (map->players[i]->y - 1 >= 0) 
  {
    map->players[i]->y -= 1;
  }
  printf("-------------\n");
  debug_map(map);
}

void down(t_map *map, int player)
{
  int i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (map->players[i]->y + 1 < HEIGHT) 
  {
    map->players[i]->y += 1;
  }
  printf("-------------\n");
  debug_map(map);
}

void right(t_map *map, int player)
{
  int i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (map->players[i]->x + 1 < WIDTH) 
  {
    map->players[i]->x += 1;
  }
  printf("-------------\n");
  debug_map(map);
}

void left(t_map *map, int player)
{
  int i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  if (map->players[i]->x - 1 >= 0) 
  {
    map->players[i]->x -= 1;
  }
  printf("-------------\n");
  debug_map(map);
}

void drop(t_map *map, int player)
{
  int i;

  i = search_player_by_socket(map->players, map->nb_players, player);
  printf("DROP %d\n", player);
  printf("DROP %s\n", map->players[i]->username);
  debug_map(map);
}
