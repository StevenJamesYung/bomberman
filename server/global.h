#ifndef __GLOBAL_H__
# define __GLOBAL_H__
# define _GNU_SOURCE

# include "map.h"

typedef struct s_global t_global;
struct s_global {
    t_map *map;
    t_player **players;
    int nb_players;
};

#endif
