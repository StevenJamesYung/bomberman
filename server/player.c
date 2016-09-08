/*
** player.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:15:42 2016 YUNG Steven
** Last update Thu Sep  8 21:57:37 2016 YUNG Steven
*/

#include "player.h"

t_player *init_player(int x, int y, int s) {
  t_player *player;

  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->x = x;
  player->y = y;
  player->username = "okko";
  player->socket = s;
  return (player);
}

int search_player_by_socket(t_player **players, int nb_players, int s)
{
  int i;

  for (i = 0; i < nb_players; i++)
    {
      if (players[i]->socket == s)
	return (i);
    }
  return (-1);
}
