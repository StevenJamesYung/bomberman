/*
** client.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:11:34 2016 YUNG Steven
** Last update Tue Sep  6 22:11:36 2016 YUNG Steven
*/

#include "client.h"

void convert_signal_to_cmd(int ch, char** cmd)
{
  int tmp;
  char tmp_char;

  tmp = ch - 63 + '0';
  tmp_char = (char)tmp;
  *cmd = &tmp_char;
}
int handle_user_input(int s)
{
  int ch;
  char *cmd;

  ch = getch();
  if (ch == 27)
  {
    ch = getch();
    if (ch == 91)
      convert_signal_to_cmd(getch(), &cmd);
    else if (ch == 27)
      return (1);
  }
  else if (ch == 32)
    cmd ="6";

  if (send(s, cmd, strlen(cmd), 0) == -1)
    return (-1);
  return (0);
}

int my_recv(int s)
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
  return (0);
}

int handle_file_desc(int s, fd_set read_fds)
{
  int ret;
  int i;

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
        if ((ret = my_recv(i)) > 0)
          return (2);
    }
  }
  return (0);
}

int main_loop(int s)
{
  fd_set read_fds;
  fd_set active_fds;
  int ret;

  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  FD_SET(STDIN_FILENO, &active_fds);
  if (set_conio_terminal_mode() == -1)
    return (-5);
  while (1)
  {
    read_fds = active_fds;
    if((ret = select(s + 1, &read_fds, NULL, NULL, 0)) == -1)
      return (-6);
    if ((ret = handle_file_desc(s, read_fds)) == 1)
      return (ret);
    else if (ret == 2)
      return (ret);
  }
}

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
  if ((ret = send(s, final_cmd, size, 0)) == -1)
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

int main(int argc, char **argv)
{
  int ret;
  int s;

  ret = 0;
  s = setup_connection(argc, argv);
  ret = s;
  if (ret == -1)
    printf("Failed to create socket");
  else if (ret == -2)
    printf("Failed to connect to the server");
  if (ret >= 0)
  {
    if (argc >= 4)
      ret = ask_connection(s, argv[3]);
    else
      ret = ask_connection(s, USERNAME);
    if (ret == -3)
      printf("Failed to malloc in ask_connection");
    else if (ret == -2)
      printf("Failed to send the connection request");
    else if (ret < 0)
      return (-4);
  }
  if (ret >= 0)
  {
    if((ret = main_loop(s)) == -6)
      printf("select failed");
    else if (ret == 2)
      printf("The server is full");
    else if (ret == -5)
      printf("set_conio_terminal_mode failed, program will close now.");
  }

  if (ret != 0)
    printf(", program will close now.\n\n");
  else
    printf("\nSee you later!\n\n");
  return (ret);
}
