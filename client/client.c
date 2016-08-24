#include "client.h"

int main(int argc, char **argv) {
  int s;
  struct sockaddr_in sin;

  s = socket(PF_INET, SOCK_STREAM, 0);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(4242);
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");

  printf("%d\n", connect(s, (struct sockaddr *) &sin, sizeof(struct sockaddr_in)));

  return 0;
}
