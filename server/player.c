#include "player.h"

t_player *init_player(int x, int y) {
  t_player *player;
  player = malloc(sizeof(t_player));

  player->x = x;
  player->y = y;
  player->username = "okko";

  return player;
}
