#include "client.h"

void ask_connection(int s, char *login) {
  char *cmd;
  char *final_cmd;
  size_t size;

  cmd = "CONNECT";
  send(s, cmd, size, 0);
  /*
  size = sizeof(cmd) + sizeof(login) + 1;
  final_cmd = malloc(size);

  strcpy(final_cmd, cmd);
  strcat(final_cmd, " ");
  strcat(final_cmd, login);

  send(s, final_cmd, size, 0);
  */
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

  return 0;
}
