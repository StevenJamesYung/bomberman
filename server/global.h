/*
** global.h for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:14:47 2016 YUNG Steven
** Last update Tue Sep  6 22:14:52 2016 YUNG Steven
*/

#ifndef __GLOBAL_H__
# define __GLOBAL_H__
# define _GNU_SOURCE

#include "map.h"

typedef struct s_global t_global;
struct s_global {
    t_map *map;
};

t_global *init_global();

#endif