#ifndef __SERVER_H__
# define __SERVER_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include "player.h"
# include "map.h"
# include "server.h"
# include "commands.h"
# include "global.h"

t_global *init_global();
t_command_funct **init_funct_tab();

#endif