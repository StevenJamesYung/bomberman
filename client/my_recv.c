/*
** client.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:11:34 2016 YUNG Steven
** Last update Tue Sep  6 22:11:36 2016 YUNG Steven
*/

#include "my_recv.h"

int my_recv(int s, char **new_buff)
{
  int nread;
  char buf[1024];

  do
  {
    if ((nread = recv(s, buf, 1024, 0)) == -1)
      printf("failed to received map\n");
    if (nread > 0)
    {
      if (strncmp(buf, "full", 4) == 0)
        return (2);
      printf("%s\n", buf);
    }
  } while (nread == 0);
  strncpy(*new_buff, buf, 1024);
  printf("buffer %s\n", *new_buff);
  return (0);
}
