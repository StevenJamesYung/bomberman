#ifndef __COMMANDS_H__
# define __COMMANDS_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"

void up(t_map *map, int player);
void down(t_map *map, int player);
void right(t_map *map, int player);
void left(t_map *map, int player);
void drop(t_map *map, int player);

#endif
