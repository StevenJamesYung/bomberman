#include "server.h"

int main(int argc, char **argv) {
  int s;
  struct protoent *pe;
  struct sockaddr_in sin;
  int b;

  pe = getprotobyname("tcp");
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(4242);
  sin.sin_addr.s_addr = INADDR_ANY;

  b = bind(s, (struct sockaddr*) &sin,  sizeof(sin));

  printf("%d\n", b);

  return 0;
}
