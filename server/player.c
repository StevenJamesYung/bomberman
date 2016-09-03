#include "player.h"

t_player *init_player(int x, int y, int s) {
  t_player *player;
  player = malloc(sizeof(t_player));

  player->x = x;
  player->y = y;
  player->username = "okko";
  player->socket = s;

  return player;
}
