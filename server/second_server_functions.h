/*
** second_server_functions.h for bomberman in /media/sf_bomberman/server
**
** Made by TRAORE Abdoulaye Karim
** Login   <traore_a@etna-alternance.net>
**
** Started on  Fri Sep  9 00:29:25 2016 TRAORE Abdoulaye Karim
** Last update Fri Sep  9 02:07:04 2016 TRAORE Abdoulaye Karim
*/

#ifndef __SECOND_SERVER_FUNCTIONS_H__
# define __SECOND_SERVER_FUNCTIONS_H__
# define _GNU_SOURCE

#include	<netdb.h>
#include	<sys/select.h>
#include	<unistd.h>
#include	"../bomberman.h"
#include	"map.h"
#include	"command_functions.h"
#include	"server_functions.h"

int		handle_new_connection(int s, fd_set *active_fds, t_map *map);
int		handle_connection_server(int i, int s, fd_set *active_fds, t_map *map);
int		user_connect(char *cmd, t_map *map, int player);
int		call_cmd(char *cmd, t_command_funct *tab, int player, t_map *map);

#endif
