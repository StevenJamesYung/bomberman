/*
** server_functions.h for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:16:42 2016 YUNG Steven
** Last update Fri Sep  9 02:04:37 2016 TRAORE Abdoulaye Karim
*/

#ifndef __SERVER_FUNCTIONS_H__
# define __SERVER_FUNCTIONS_H__
# define _GNU_SOURCE

#include	"../bomberman.h"
#include	"map.h"
#include	"command_functions.h"
#include	"second_server_functions.h"

char		*get_map_str(t_map *map);
int		broadcast_map(t_map *map, fd_set *active_fds, int server_socket);
int		exec_cmd(char *cmd, t_map *map, int player, fd_set *active_fds);
int		server_loop(fd_set active_fds,
			    fd_set read_fds,
			    int s,
			    t_map *map);

#endif
