#ifndef __MAP_H__
# define __MAP_H__
# define _GNU_SOURCE

# include "../bomberman.h"

# define WIDTH 10
# define HEIGHT 10

int **init_map();
int **add_player(int **map);
void debug_map(int **map);

#endif
