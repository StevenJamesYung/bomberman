/*
** map.h for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:15:32 2016 YUNG Steven
** Last update Thu Sep  8 22:26:44 2016 YUNG Steven
*/

#ifndef __MAP_H__
# define __MAP_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "player.h"
#include "map_functions.h"
#define WIDTH 10
#define HEIGHT 10

typedef struct	s_map t_map;
struct		s_map {
  int		**value;
  t_player	**players;
  int		nb_players;
};

t_map		*init_map();
int		add_player(t_map *map, int s);
void		debug_map(t_map *map);
int		is_player_position(t_map *map, int x, int y);
int		free_map(t_map *map);
int		disconnect_player(t_map *map, int s);

#endif
