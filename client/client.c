/*
** client.c for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:11:34 2016 YUNG Steven
** Last update Thu Sep  8 22:08:27 2016 YUNG Steven
*/

#include "gui/gui.h"
#include <unistd.h>
#include "client.h"
#include "signal.h"

int		handle_user_input(int s)
{
  int		ch;
  char		*cmd;

  if ((cmd = malloc((sizeof(char) * 3) + 1)) == NULL)
    return (-1);
  ch = getch();
  if (ch == 27)
    {
      ch = getch();
      if (ch == 91)
        convert_signal_to_cmd(getch(), &cmd);
      else if (ch == 27)
      {
        ask_disconnection(s);
        return (1);
      }
    }
  else if (ch == 32)
    cmd ="6";

  if (send(s, cmd, strlen(cmd), 0) == -1)
    return (-1);
  return (0);
}

int		handle_file_desc(int s, fd_set read_fds, char **new_buff)
{
  int		ret;
  int		i;

  for (i = 0; i < (s + 1); i++)
    {
      if (FD_ISSET(i, &read_fds))
      {
        if (i == STDIN_FILENO)
        {
          if ((ret = handle_user_input(s)) == -1)
            printf("Input couldn't be sent\n");
          else if (ret == 1)
            return (ret);
        }
        else if (i == s)
          if ((ret = my_recv(i, new_buff)) > 0)
            return (2);
      }
    }
  return (0);
}

int setup_loop(Map *m, SDL_Surface *screen, fd_set *active_fds, int s)
{
  show_map(m, screen);
  SDL_Flip(screen);
  FD_ZERO(active_fds);
  FD_SET(s, active_fds);
  FD_SET(STDIN_FILENO, active_fds);
  printf("\nsetup loop\n\n");
  if (set_conio_terminal_mode() == -1)
    return (-5);
  return (0);
}

int		main_loop(int s, SDL_Surface* screen, Map* m)
{
  fd_set	read_fds;
  fd_set	active_fds;
  int		ret;
  char		*new_buf;

  ret = 0;
  if (setup_loop(m, screen, &active_fds, s) == -5)
    return (-5);
  new_buf = malloc(1024 * sizeof(char));
  while (ret == 0)
  {
    read_fds = active_fds;
    if(select(s + 1, &read_fds, NULL, NULL, 0) == -1)
      ret = -6;
    if (ret == 0 && (ret = handle_file_desc(s, read_fds, &new_buf)) == 1)
      ret = 1;
    if (ret == 0 && new_buf != NULL)
    {
      printf("newbuff : %s\n", new_buf);
      update_map(new_buf, m);
      show_map(m, screen);
      SDL_Flip(screen);
    }
  }
  free(new_buf);
  return (ret);
}

int		main(int argc, char **argv)
{
  int		ret;
  int		s;
  SDL_Surface	*screen;
  Map		*m;

  ret = 0;
  s = setup_connection(argc, argv);
  ret = s;
  if (ret >= 0)
    (argc >= 4) ? (ret = ask_connection(s, argv[3])) : (ret = ask_connection(s, USERNAME));
  if (ret >= 0)
  {
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(280, 280, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    m = load_map("level.txt");
    ret = main_loop(s, screen, m);
    free_map(m);
  }
  if (ret < 0 || ret == 2)
    handle_error(ret);
  else
    printf("\nSee you later!\n\n");
  return (ret);
}
