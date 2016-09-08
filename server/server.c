/*
** server.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:16:12 2016 YUNG Steven
** Last update Tue Sep  6 22:16:13 2016 YUNG Steven
*/

#include "server_functions.h"
#include "server.h"

int main_loop(int s)
{
  fd_set active_fds;
  fd_set read_fds;
  t_map *map;

  if ((map = init_map()) == NULL)
    return (-1);
  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  if (server_loop(active_fds, read_fds, s, map) == -1)
  {
    free(map);
    return (-1);
  }
  free(map);
  return (0);
}

int main()
{
  int s;
  struct protoent *pe;
  struct sockaddr_in sin;

  pe = getprotobyname("tcp");
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
  sin.sin_addr.s_addr = INADDR_ANY;

  bind(s, (struct sockaddr*) &sin,  sizeof(sin));

  listen(s, 4);

  main_loop(s);

  return (0);
}
