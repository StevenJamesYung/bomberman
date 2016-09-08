/*
** client.c for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:11:34 2016 YUNG Steven
** Last update Thu Sep  8 22:08:27 2016 YUNG Steven
*/

#include "fmap.h"
#include <unistd.h>
#include "client.h"

void		convert_signal_to_cmd(int ch, char** cmd)
{
  int		tmp;
  char		tmp_char;

  tmp = ch - 63 + '0';
  tmp_char = (char)tmp;
  strcpy(*cmd, &tmp_char);
}

int		handle_user_input(int s)
{
  int		ch;
  char		*cmd;

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

int		main_loop(int s, SDL_Surface* screen, Map* m)
{
  fd_set	read_fds;
  fd_set	active_fds;
  int		ret;
  char		*new_buf;

  ShowMap(m,screen);
  SDL_Flip(screen);

  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  FD_SET(STDIN_FILENO, &active_fds);
  if (set_conio_terminal_mode() == -1)
    return (-5);
  new_buf = malloc(1024 * sizeof(char));
  while (1)
    {
      read_fds = active_fds;
      if((ret = select(s + 1, &read_fds, NULL, NULL, 0)) == -1)
	{
	  free(new_buf);
	  return (-6);
	}
      if ((ret = handle_file_desc(s, read_fds, &new_buf)) == 1)
	{
	  free(new_buf);
	  return (ret);
	}
      else if (ret == 2)
	{
	  free(new_buf);
	  return (ret);
	}
      if (new_buf != NULL) {
	UpdateMap(new_buf, m);
	ShowMap(m, screen);
	SDL_Flip(screen);
      }
    }
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
    {
      if (argc >= 4)
	ret = ask_connection(s, argv[3]);
      else
	ret = ask_connection(s, USERNAME);
    }
  if (ret >= 0)
    {
      SDL_Init(SDL_INIT_VIDEO);
      screen = SDL_SetVideoMode(280, 280, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
      m = LoadMap("level.txt");
      ret = main_loop(s, screen, m);
      FreeMap(m);
    }
  if (ret < 0 || ret == 2)
    handle_error(ret);
  else
    printf("\nSee you later!\n\n");
  return (ret);
}
