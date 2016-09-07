/*
** command_functions.h for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:13:55 2016 YUNG Steven
** Last update Tue Sep  6 22:13:59 2016 YUNG Steven
*/

#ifndef __COMMANDS_FUNCTIONS_H__
# define __COMMANDS_FUNCTIONS_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"

typedef int (*t_func)(t_map *map, int player);

typedef struct	s_command_funct t_command_funct;
struct	s_command_funct
{
  char		*key;
  t_func	function;
};

t_command_funct *init_funct_tab();


#endif
