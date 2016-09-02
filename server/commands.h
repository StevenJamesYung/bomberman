#ifndef __COMMANDS_H__
# define __COMMANDS_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include "map.h"
# include "player.h"

typedef void (*t_func)();

typedef struct	s_command_funct
{
  char		key;
  t_func	function;
}		t_command_funct;

void up();
void down();
void right();
void left();
void drop();

#endif