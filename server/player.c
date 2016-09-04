#include "player.h"

t_player *init_player(int x, int y, int s) {
  t_player *player;

  player = malloc(sizeof(t_player));
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