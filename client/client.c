#include "client.h"

void main_loop(int s) {
  int ch;
  int test;
  int i;
  fd_set read_fds;
  fd_set active_fds;
  int nread;
  char buf[1024];

  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  FD_SET(STDIN_FILENO, &active_fds);

  set_conio_terminal_mode();
  while(1) {
    read_fds = active_fds;
    select(s + 1, &read_fds, NULL, NULL, 0);
    for(i = 0; i < (s + 1); i++) {
      if(i == STDIN_FILENO) {
        ch = getch();
        // Special Character
        if(ch == 27) {
          test = getch();
          //ARROW
          if(test == 91) {
            test = getch();
            if(test == 65)
              send(s, "2", sizeof("2"), 0);
            else if(test == 66)
              send(s, "3", sizeof("3"), 0);
            else if(test == 67)
              send(s, "4", sizeof("4"), 0);
            else if(test == 68)
              send(s, "5", sizeof("5"), 0);
          }
          else if(test == 27) {
            exit(0);
          }
        }
        else if(ch == 32) {
          send(s, "6", sizeof("6"), 0);
          i = 3;
        }
      } else {
          nread = recv(i, buf, 1024, 0);
          if(nread != 0)
            printf("%s\n", buf);
      }
    }
  }
}

/*
void msg_loop(int s) {
  char *msg;

  while(strcmp(msg, "EXIT") != 0) {
    printf("Enter a message:\n");
    scanf("%s", msg);

    send(s, msg, sizeof(msg), 0);
  }
}
*/

void ask_connection(int s, char *login) {
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

int main(int argc, char **argv) {
  int s;
  struct sockaddr_in sin;
  ssize_t nwrite;

  s = socket(PF_INET, SOCK_STREAM, 0);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(4242);
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(s, (struct sockaddr *) &sin, sizeof(struct sockaddr_in));

  ask_connection(s, "steven");

  main_loop(s);

  return 0;
}
