/*
** server_functions.h for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:16:42 2016 YUNG Steven
** Last update Tue Sep  6 22:16:43 2016 YUNG Steven
*/

#ifndef __COMMANDS_FUNCTIONS_H__
# define __COMMANDS_FUNCTIONS_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"
#include "command_functions.h"

char *get_map_str(t_map *map);
int broadcast_map(t_map *map, fd_set *active_fds, int server_socket);
int exec_cmd(char *cmd, t_map *map, int player, fd_set *active_fds);
int handleNewConnection(int s, fd_set *active_fds, t_map *map);
int server_loop(fd_set active_fds,
                 fd_set read_fds,
                 int s,
                 t_map *map);


#endif
