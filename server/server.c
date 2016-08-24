#include "server.h"

int main(int argc, char **argv) {
  int s;
  struct protoent *pe;
  struct sockaddr_in sin;
  int cfd;
  struct sockaddr_in peer_addr;
  socklen_t peer_addr_size;

  pe = getprotobyname("tcp");
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(4242);
  sin.sin_addr.s_addr = INADDR_ANY;

  bind(s, (struct sockaddr*) &sin,  sizeof(sin));

  listen(s, 4);

  peer_addr_size = sizeof(struct sockaddr_in);
  cfd = accept(s, (struct sockaddr *) &peer_addr, &peer_addr_size);

  printf("New connection detected as socket %d\n", cfd);

  return 0;
}
