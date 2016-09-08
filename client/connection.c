/*
** client.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:11:34 2016 YUNG Steven
** Last update Tue Sep  6 22:11:36 2016 YUNG Steven
*/

#include "connection.h"

int ask_connection(int s, char *login)
{
  char *cmd;
  char *final_cmd;
  size_t size;
  int ret;

  cmd = "000";
  size = sizeof(cmd) + sizeof(login) + 1;
  if ((final_cmd = malloc(size)) == NULL)
    return (-3);
  strcpy(final_cmd, cmd);
  strcat(final_cmd, login);
  ret = send(s, final_cmd, size, 0);
  // free(final_cmd);
  if (ret == -1)
    return (-4);
  return (0);
}

// -1 socket failed
// -2 connect failed
int setup_connection(int argc, char **argv)
{
  int s;
  struct sockaddr_in sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  sin.sin_family = AF_INET;
  if (argc >= 3)
    sin.sin_port = htons((uint16_t)atoi(argv[2]));
  else
    sin.sin_port = htons(PORT);
  if (argc >= 2)
    sin.sin_addr.s_addr = inet_addr(argv[1]);
  else
    sin.sin_addr.s_addr = inet_addr(IP);
  if (connect(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) == -1)
    return (-2);
  return (s);
}
