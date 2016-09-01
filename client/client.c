#include "client.h"

void main_loop(int s) {
  int ch;
  int test;

  set_conio_terminal_mode();
  for(ch = getch(); ; ch = getch()) {
    // Special Character
    if(ch == 27) {
      test = getch();
      //ARROW
      if(test == 91) {
        test = getch();
        if(test == 65) {
          send(s, "2", sizeof("2"), 0);
        }
        else if(test == 66) {
          send(s, "3", sizeof("3"), 0);
        }
        else if(test == 67) {
          send(s, "4", sizeof("4"), 0);
        }
        else if(test == 68) {
          send(s, "5", sizeof("5"), 0);
        }
      }
      else if(test == 27) {
        printf("ESC");
        exit(0);
      }
    }
  }
}

void msg_loop(int s) {
  char *msg;

  while(strcmp(msg, "EXIT") != 0) {
    printf("Enter a message:\n");
    scanf("%s", msg);

    send(s, msg, sizeof(msg), 0);
  }
}

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

  //msg_loop(s);
  main_loop(s);

  return 0;
}
