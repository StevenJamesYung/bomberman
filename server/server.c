#include "server_functions.h"
#include "server.h"

void main_loop(int s)
{
  fd_set active_fds;
  fd_set read_fds;
  t_map *map;

  map = init_map();
  FD_ZERO(&active_fds);
  FD_SET(s, &active_fds);
  server_loop(active_fds, read_fds, s, map);
}

int main()
{
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

  return (0);
}
