/*
** map_functions.c for bomberman in /media/sf_bomberman/server
**
** Made by TRAORE Abdoulaye Karim
** Login   <traore_a@etna-alternance.net>
**
** Started on  Thu Sep  8 22:57:40 2016 TRAORE Abdoulaye Karim
** Last update Fri Sep  9 00:05:46 2016 TRAORE Abdoulaye Karim
*/

#include	"map.h"

int		add_player(t_map *map, int s)
{
  int		i;
  int		x;
  int		y;

  for (i = 0; i < MAX_PLAYERS; i++)
    if (map->players[i] == NULL)
    {
      if (i <= 1)
      {
        x = 0;
        (i == 0) ? (y = 0) : (y = WIDTH - 1);
      }
      else if (i >= 2)
      {
        x = HEIGHT - 1;
        (i == 2) ? (y = 0) : (y = WIDTH - 1);
      }
      map->players[i] = init_player(x, y, s);
      map->nb_players++;
      i = MAX_PLAYERS;
    }
  return (0);
}
