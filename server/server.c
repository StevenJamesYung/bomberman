#include "server.h"

int main(int argc, char **argv) {
  int s;
  struct protoent *pe;

  pe = getprotobyname("tcp");
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);

  printf("%d\n", s);

  return 0;
}
