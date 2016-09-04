#ifndef __COMMANDS_FUNCTIONS_H__
# define __COMMANDS_FUNCTIONS_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"
#include "command_functions.h"

char *get_map_str(t_map *map);
void broadcast_map(t_map *map, fd_set *active_fds, int server_socket);
void exec_cmd(char *cmd, t_map *map, int player);
void handleNewConnection(int s, fd_set *active_fds, t_map *map);
void server_loop(fd_set active_fds,
                 fd_set read_fds,
                 int s,
                 t_map *map);


#endif
