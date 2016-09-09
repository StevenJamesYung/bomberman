/*
** server_functions.c for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:16:30 2016 YUNG Steven
** Last update Fri Sep  9 02:02:53 2016 TRAORE Abdoulaye Karim
*/

#include	<netdb.h>
#include	<sys/select.h>
#include	"command_functions.h"
#include	"server_functions.h"
#include	<unistd.h>

char		*get_map_str(t_map *map)
{
  int		x;
  int		y;
  char		*map_str;
  char		current_value;
  int		p;

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

int		broadcast_map(t_map *map, fd_set *active_fds, int server_socket)
{
  int		s;
  char		*map_str;
  int		sent;

  sent = 0;
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
  free(map_str);
  printf("end broadcast");
  return (0);
}

int			exec_cmd(char *cmd, t_map *map, int player, fd_set *active_fds)
{
  t_command_funct	*tab;

  tab = init_funct_tab();
  printf("is disconnect: %d\n\n", strncmp(cmd, "111", 3) == 0);
  if (strncmp(cmd, "111", 3) == 0)
  {
    disconnect_player(map, player);
    FD_CLR(player, active_fds);
  }
  else if (strncmp(cmd, "000", 3) == 0)
  {
    user_connect(cmd, map, player);
  }
  else
  {
    call_cmd(cmd, tab, player, map);
  }
  free(tab);
  return (0);
}

int			server_loop(fd_set active_fds,
					fd_set read_fds,
					int s,
					t_map *map)
{
  int			i;

  while (1)
    {
      read_fds = active_fds;
      if (select(10, &read_fds, NULL, NULL, NULL) < 0)
        return (-1);
      for (i = 0; i < 10; i++)
        {
          if (FD_ISSET(i, &read_fds))
            {
              if (handle_connection_server(i, s, &active_fds, map) == -1)
                return (-1);
            }
        }
    }
}
