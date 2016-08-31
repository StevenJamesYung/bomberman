#include "server.h"

void exec_cmd(char *cmd) {
  char *username;

  if(strncmp(cmd, "000", 3) == 0) {
    username = strtok(cmd, "000");
    printf("%s joined the game\n", username);
  }
  else {
    printf("message receive which is not a command: %s\n", cmd);
  }
}

void handleNewConnection(int s, fd_set *active_fds) {
  struct sockaddr_in peer_addr;
  socklen_t peer_addr_size;
  int cfd;

  peer_addr_size = sizeof(struct sockaddr_in);
  cfd = accept(s, (struct sockaddr *) &peer_addr, &peer_addr_size);

  if(cfd < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  printf("Server: connect from %d\n", cfd);

  FD_SET(cfd, active_fds);
}

void main_loop(int s) {
  fd_set active_fds;
  fd_set read_fds;
  int i;
  int nread;
  char buf[1024];

  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  while(1) {
    read_fds = active_fds;
    if(select(10, &read_fds, NULL, NULL, NULL) < 0) {
      perror("select");
      exit(EXIT_FAILURE);
    }
    for(i = 0; i < 10; i++) {
      if(FD_ISSET(i, &read_fds)) {
        if(i == s)
          handleNewConnection(s, &active_fds);
        else {
          nread = recv(i, buf, 1024, 0);
          if(nread != 0)
            exec_cmd(buf);
        }
      }
    }
  }
}

int main(int argc, char **argv) {
  int s;
  struct protoent *pe;
  struct sockaddr_in sin;

  pe = getprotobyname("tcp");
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
  sin.sin_addr.s_addr = INADDR_ANY;

  bind(s, (struct sockaddr*) &sin,  sizeof(sin));

  listen(s, 4);

  main_loop(s);

  return 0;
}
