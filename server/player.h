#ifndef __PLAYER_H__
# define __PLAYER_H__
# define _GNU_SOURCE

#include "../bomberman.h"

typedef struct s_player t_player;
struct s_player {
  int x;
  int y;
  char *username;
  int socket;
};

t_player *init_player(int x, int y, int s);
int search_player_by_socket(t_player **players, int nb_players, int s);

#endif
