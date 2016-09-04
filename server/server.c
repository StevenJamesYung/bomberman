#include "server.h"

char *get_map_str(t_global *global) {
  int x;
  int y;
  char *map_str;
  char current_value;

  map_str = malloc((sizeof(char) * (WIDTH + 1) * HEIGHT) + 10);

  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      /*
         if (send(s, &global->map->value[x][y], sizeof(int), 0) < 0) {
         perror("send");
         exit(EXIT_FAILURE);
         }
         */
      current_value = global->map->value[x][y] + '0';
      strcat(map_str, &current_value);
    }
    strcat(map_str, "\n");
  }
  return map_str;
}

void broadcast_map(t_global *global, fd_set *active_fds, int server_socket) {
  int s;

  for (s = 0; s < 10 ;s++) {
    if (FD_ISSET(s, active_fds) && s != server_socket) {
      for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
          if (send(s, &global->map->value[x][y], sizeof(int), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
          }
        }
      }
    }
  }
}

void exec_cmd(char *cmd, t_global *global, int player) {
  int i;
  char *username;
  t_command_funct *tab;

  tab = init_funct_tab();
  if(strncmp(cmd, "000", 3) == 0) {
    username = strtok(cmd, "000");
    printf("%s joined the game\n", username);
  }
  else {
    for (i = 0; i < 5; i++)
    {
      if ((strncmp(cmd, tab[i].key, 1) == 0))
      {
        tab[i].function(global, player);
        //free(tab);
      }
    }
  }
  // else {
  //   printf("message receive which is not a command: %s\n", cmd);
  // }
}

// void handleNewConnection(int s, fd_set *active_fds, t_map *map) { [REFACTOR]
void handleNewConnection(int s, fd_set *active_fds, t_global *global) {
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
  // add_player(map, cfd); [REFACTOR]
  add_player(global->map, cfd);
  // debug_map(map); [REFACTOR]
  debug_map(global->map);

  FD_SET(cfd, active_fds);
}

void main_loop(int s) {
  fd_set active_fds;
  fd_set read_fds;
  int i;
  int nread;
  char buf[1024];
  // t_map *map; // [REFACTOR]
  t_global *global;

  printf("b4 init");
  // map = init_map(); //[REFACTOR]
  global = init_global();

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
          // handleNewConnection(s, &active_fds, map); [REFACTOR]
          handleNewConnection(s, &active_fds, global);
        else {
          nread = recv(i, buf, 1024, 0);
          if(nread != 0)
            // exec_cmd(buf); [REFACTOR]
            exec_cmd(buf, global, i);
            //broadcast_map(global, &active_fds, s);
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
