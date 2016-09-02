#ifndef __COMMANDS_H__
# define __COMMANDS_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include "global.h"

typedef void (*t_func)(t_global *global, int player);

typedef struct	s_command_funct t_command_funct;
struct	s_command_funct
{
  char		*key;
  t_func	function;
};

void up(t_global *global, int player);
void down(t_global *global, int player);
void right(t_global *global, int player);
void left(t_global *global, int player);
void drop(t_global *global, int player);
t_command_funct *init_funct_tab();

#endif
