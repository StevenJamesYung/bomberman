/*
** second_server_functions.c for bomberman in /media/sf_bomberman/server
**
** Made by TRAORE Abdoulaye Karim
** Login   <traore_a@etna-alternance.net>
**
** Started on  Fri Sep  9 00:29:05 2016 TRAORE Abdoulaye Karim
** Last update Fri Sep  9 02:06:00 2016 TRAORE Abdoulaye Karim
*/

#include		"second_server_functions.h"

int			handle_new_connection(int s, fd_set *fds, t_map *map)
{
  struct sockaddr_in	peer_addr;
  socklen_t		peer_addr_size;
  int			cfd;
  char			*msg;

  peer_addr_size = sizeof(struct sockaddr_in);
  cfd = accept(s, (struct sockaddr *)&peer_addr, &peer_addr_size);
  if (cfd < 0)
    return (-1);
  printf("Server: connect from %d\n", cfd);
  if (map->nb_players >= MAX_PLAYERS)
    {
      msg = "full";
      send(cfd, msg, strlen(msg), 0);
      close(cfd);
    }
  else
    {
      if ((add_player(map, cfd)) == -1)
        return (-1);
      FD_SET(cfd, fds);
    }
  debug_map(map);
  return (0);
}

int			handle_connection_server(int i, int s, fd_set *fds, t_map *map)
{
  char			buf[1024];
  int			nread;

  if (i == s)
  {
      if (handle_new_connection(s, fds, map) == -1)
          return (-1);
  }
  else
  {
      nread = recv(i, buf, 1024, 0);
      if (nread != 0)
      {
          if ((exec_cmd(buf, map, i, fds)) == -1)
              return (-1);
      }
      if (broadcast_map(map, fds, s) == -1)
          return (-1);
  }
  return (0);
}

int			user_connect(char *cmd, t_map *map, int player )
{
  int			src_player;
  char			*username;

  username = strtok(cmd, "000");
  src_player = search_player_by_socket(map->players, map->nb_players, player);
  if (src_player >= 0)
  {
      map->players[src_player]->username = username;
      printf("%s joined the game\n", map->players[src_player]->username);
  }
  return (0);
}

int			call_cmd(char *cmd, t_command_funct *tab, int player, t_map *map)
{
  int			i;

  for (i = 0; i < 5; i++)
  {
      if ((strncmp(cmd, tab[i].key, 1) == 0))
      {
          if (tab[i].function(map, player) == -1)
          {
              free(tab);
              return (-1);
          }
      }
  }
  return (0);
}
