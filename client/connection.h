/*
** client.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:11:34 2016 YUNG Steven
** Last update Tue Sep  6 22:11:36 2016 YUNG Steven
*/

#ifndef __CONNECTION_H__
# define __CONNECTION_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "keyboard.h"
#include "my_recv.h"
#include <netinet/in.h>
#include <arpa/inet.h>

int ask_connection(int s, char *login);
int setup_connection(int argc, char **argv);

#endif
