/*
** commands.h for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:14:17 2016 YUNG Steven
** Last update Thu Sep  8 22:23:15 2016 YUNG Steven
*/

#ifndef __COMMANDS_H__
# define __COMMANDS_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"
#include "map_functions.h"

int	up(t_map *map, int player);
int	down(t_map *map, int player);
int	right(t_map *map, int player);
int	left(t_map *map, int player);
int	drop(t_map *map, int player);

#endif
