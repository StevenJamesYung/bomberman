#ifndef __MAP_H__
# define __MAP_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include "player.h"

# define WIDTH 10
# define HEIGHT 10

typedef struct s_map t_map;
struct s_map {
  int ** value;
  //t_players *players;
};

t_map *init_map();
void add_player(t_map *map);
void debug_map(t_map *map);

#endif
