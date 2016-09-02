#ifndef __SERVER_H__
# define __SERVER_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include <netdb.h>
# include <sys/select.h>
# include "map.h"
# include "shared.h"
# include "commands.h"

typedef struct s_global t_global;
struct s_global {
    t_map *map;
    t_player **players;
    int nb_players;
};

# define MAX_CONNECTIONS 4
# define PORT 4242

#endif
