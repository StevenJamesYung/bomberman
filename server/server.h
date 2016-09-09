/*
** server.h for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:16:20 2016 YUNG Steven
** Last update Thu Sep  8 22:29:01 2016 YUNG Steven
*/

#ifndef __SERVER_H__
# define __SERVER_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "map.h"
#include <netdb.h>
#include <sys/select.h>
#include "commands.h"
#include "command_functions.h"

int	main_loop(int s);
int	main();

#define MAX_CONNECTIONS 4
#define PORT 4242

#endif
