#ifndef __COMMANDS_H__
# define __COMMANDS_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include "map.h"
# include "player.h"
# include "server.h"

typedef void (*t_func)();

typedef struct	s_command_funct t_command_funct;
struct	s_command_funct
{
  char		key;
  t_func	function;
};

void up(t_global *global, int player);
void down(t_global *global, int player);
void right(t_global *global, int player);
void left(t_global *global, int player);
void drop(t_global *global, int player);

#endif