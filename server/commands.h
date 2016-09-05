#ifndef __COMMANDS_H__
# define __COMMANDS_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"

int up(t_map *map, int player);
int down(t_map *map, int player);
int right(t_map *map, int player);
int left(t_map *map, int player);
int drop(t_map *map, int player);

#endif
