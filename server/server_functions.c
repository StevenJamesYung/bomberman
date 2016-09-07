/*
** server_functions.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:16:30 2016 YUNG Steven
** Last update Tue Sep  6 22:16:31 2016 YUNG Steven
*/

#include <netdb.h>
#include <sys/select.h>
#include "command_functions.h"
#include "server_functions.h"
#include <unistd.h>

char *get_map_str(t_map *map)
{
  int x;
  int y;
  char *map_str;
  char current_value;
  int p;

  if ((map_str = malloc((sizeof(char) * (WIDTH + 1) * HEIGHT) + 10)) == NULL)
    return (NULL);
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      if ((p = is_player_position(map, x, y)) > 0)
      {
        current_value = p + '0';
      }
      else
      {
        current_value = map->value[x][y] + '0';
      }
      strncat(map_str, &current_value, 1);
    }
  }
  return (map_str);
}

int broadcast_map(t_map *map, fd_set *active_fds, int server_socket)
{
  int s;
  char *map_str;
  int sent = 0;

  if ((map_str = get_map_str(map)) == NULL)
    return (-1);
  printf("get_map_str() res : \n%s\n", map_str);
  for (s = 0; s < 10; s++)
  {
    if (FD_ISSET(s, active_fds) && s != server_socket)
    {
      int map_size = strlen(map_str);
      do
      {
        sent += send(s, map_str, map_size, 0);
        printf("send to %d / %d \n", sent, map_size);
      } while (sent < map_size);
      sent = 0;
    }
  }
  printf("end broadcast");
  return (0);
}

int exec_cmd(char *cmd, t_map *map, int player)
{
  int i;
  char *username;
  t_command_funct *tab;
  int src_player;

  tab = init_funct_tab();
  if (strncmp(cmd, "000", 3) == 0)
  {
    username = strtok(cmd, "000");
    src_player = search_player_by_socket(map->players, map->nb_players, player);
    if (src_player > 0)
    {
      map->players[src_player]->username = username;
      printf("%s joined the game\n", map->players[src_player]->username);
    }
  }
  else
  {
    for (i = 0; i < 5; i++)
    {
      if ((strncmp(cmd, tab[i].key, 1) == 0))
      {
        if (tab[i].function(map, player) == -1)
          return (-1);
      }
    }
  }
  return (0);
}

int handleNewConnection(int s, fd_set *active_fds, t_map *map)
{
  struct sockaddr_in peer_addr;
  socklen_t peer_addr_size;
  int cfd;
  char *msg;

  peer_addr_size = sizeof(struct sockaddr_in);
  cfd = accept(s, (struct sockaddr *)&peer_addr, &peer_addr_size);
  if (cfd < 0)
    return (-1);
  printf("Server: connect from %d\n", cfd);
  if (map->nb_players >= MAX_PLAYERS)
  {
    msg = "full";
    send(cfd, msg, strlen(msg), 0); // [TODO MY_SEND]
    close(cfd);
  }
  else
  {
    if ((add_player(map, cfd)) == -1)
      return (-1);
    FD_SET(cfd, active_fds);
  }
  debug_map(map);
  return (0);
}

int server_loop(fd_set active_fds,
                 fd_set read_fds,
                 int s,
                 t_map *map)
{
  char buf[1024];
  int nread;
  int i;

    while (1)
    {
        read_fds = active_fds;
        if (select(10, &read_fds, NULL, NULL, NULL) < 0)
            return (-1);
        for (i = 0; i < 10; i++)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == s)
                {
                  if (handleNewConnection(s, &active_fds, map) == -1)
                    return (-1);
                }
                else
                {
                    nread = recv(i, buf, 1024, 0);
                    if (nread != 0)
                    {
                      if ((exec_cmd(buf, map, i)) == -1)
                        return (-1);
                    }
                    if (broadcast_map(map, &active_fds, s) == -1)
                      return (-1);
                }
            }
        }
    }
}
