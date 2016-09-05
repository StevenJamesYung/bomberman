#include "client.h"

void handle_user_input(int s)
{
  int ch;

  ch = getch();
  if (ch == 27)
  {
    ch = getch();
    if (ch == 91)
    {
      ch = getch();
      if (ch == 65)
        send(s, "2", sizeof("2"), 0);
      else if (ch == 66)
        send(s, "3", sizeof("3"), 0);
      else if (ch == 67)
        send(s, "4", sizeof("4"), 0);
      else if (ch == 68)
        send(s, "5", sizeof("5"), 0);
    }
    else if (ch == 27)
      exit(0);
  }
  else if (ch == 32)
    send(s, "6", sizeof("6"), 0);
}

void handle_file_desc(int s, fd_set read_fds)
{
  int i;
  int nread;
  char buf[1024];

  for (i = 0; i < (s + 1); i++)
  {
    if (FD_ISSET(i, &read_fds))
    {
      if (i == STDIN_FILENO)
        handle_user_input(s);
      else if (i == s)
      {
        do
        {
          nread = recv(i, buf, 1024, 0);
          if (nread > 0)
          {
            if (strcmp(buf, "full") == 0)
            {
              printf("The server is full.\n");
              exit(0);
            }
            printf("%s\n", buf);
          }
        } while (nread == 0);
      }
    }
  }
}

void main_loop(int s)
{
  fd_set read_fds;
  fd_set active_fds;

  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  FD_SET(STDIN_FILENO, &active_fds);
  set_conio_terminal_mode();
  while (1)
  {
    read_fds = active_fds;
    select(s + 1, &read_fds, NULL, NULL, 0);
    handle_file_desc(s, read_fds);
  }
}

int ask_connection(int s, char *login)
{
  char *cmd;
  char *final_cmd;
  size_t size;

  cmd = "000";
  size = sizeof(cmd) + sizeof(login) + 1;
  if ((final_cmd = malloc(size)) == NULL)
    return (-1);
  strcpy(final_cmd, cmd);
  strcat(final_cmd, login);
  send(s, final_cmd, size, 0);
  return (0);
}

int main(int argc, char **argv)
{
  int s;
  struct sockaddr_in sin;

  s = socket(PF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  if (argc >= 3)
    sin.sin_port = htons((uint16_t)atoi(argv[2]));
  else
    sin.sin_port = htons(PORT);
  if (argc >= 2)
    sin.sin_addr.s_addr = inet_addr(argv[1]);
  else
    sin.sin_addr.s_addr = inet_addr(IP);
  connect(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in));
  if (argc >= 4)
    ask_connection(s, argv[3]);
  else
    ask_connection(s, USERNAME);
  main_loop(s);
  return (0);
}
