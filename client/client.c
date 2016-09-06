#include "fmap.h"
#include "client.h"

#include <unistd.h>

void handle_user_input(int s)
{
  int ch;

  ch = getch();
  if(ch == 27)
  {
    ch = getch();
    if(ch == 91)
    {
      ch = getch();
      if(ch == 65)
        send(s, "2", sizeof("2"), 0);
      else if(ch == 66)
        send(s, "3", sizeof("3"), 0);
      else if(ch == 67)
        send(s, "4", sizeof("4"), 0);
      else if(ch == 68)
        send(s, "5", sizeof("5"), 0);
    }
    else if(ch == 27)
      exit(0);
  }
  else if(ch == 32)
    send(s, "6", sizeof("6"), 0);
}

char* handle_file_desc(int s, fd_set read_fds)
{
  int i;
  int nread;
  char buf[1024];
  char *newbuf;
  int j, k, count;

  for (i = 0; i < (s + 1); i++)
  {
    printf("FD_ISSET +> %d \n", FD_ISSET(i, &read_fds));
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
            printf("%s\n", buf);

            count = strlen(buf);
            newbuf = malloc(count * sizeof(char));
            k = 0;
            for (j = 0; j < count; j++)
            {

              if ((int)buf[j] >= 48 && (int)buf[j] <= 57)
              {
                newbuf[k] = buf[j];
                printf("bufval %d\n", newbuf[k]);
                k++;
                //newbuf[k] = 32;
                //k++;
              }
            }
          }
        } while (nread == 0);
      }
    }
  }
  return newbuf;
}

void main_loop(int s, SDL_Surface* screen, Map* m)
{
  fd_set read_fds;
  fd_set active_fds;
  char *new_buf;

  new_buf = malloc(96 * sizeof(char));
  AfficherMap(m,screen);
  SDL_Flip(screen);
  
  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  FD_SET(STDIN_FILENO, &active_fds);

  set_conio_terminal_mode();
  while(1)
  {
    read_fds = active_fds;
    select(s + 1, &read_fds, NULL, NULL, 0);
    // new_buf = NULL;
    new_buf =  handle_file_desc(s, read_fds);
    if (new_buf != NULL) {
          UpdateMap(new_buf, m);
      AfficherMap(m, screen);
      SDL_Flip(screen);
    }

  }
}

void ask_connection(int s, char *login)
{
  char *cmd;
  char *final_cmd;
  size_t size;

  cmd = "000";
  size = sizeof(cmd) + sizeof(login) + 1;
  final_cmd = malloc(size);

  strcpy(final_cmd, cmd);
  strcat(final_cmd, login);

  send(s, final_cmd, size, 0);
}

int main()
{
  int s;
  struct sockaddr_in sin;
  SDL_Surface* screen;

  Map* m;
  s = socket(PF_INET, SOCK_STREAM, 0);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(4242);
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(s, (struct sockaddr *) &sin, sizeof(struct sockaddr_in));

  ask_connection(s, "steven");
  
  SDL_Init(SDL_INIT_VIDEO);               // prepare SDL
  screen = SDL_SetVideoMode(280, 280, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  m = ChargerMap("level.txt");
  
  main_loop(s, screen, m);

  return (0);
}
