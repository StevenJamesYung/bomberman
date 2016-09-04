#include "server.h"

char *get_map_str(t_map *map) {
  int x;
  int y;
  char *map_str;
  char current_value;
  int p;

  map_str = malloc((sizeof(char) * (WIDTH + 1) * HEIGHT) + 10);

  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      if((p = is_player_position(map, x, y)) > 0) {
        current_value = p + '0';
      }
      else {
        current_value = map->value[x][y] + '0';
      }

      strcat(map_str, &current_value);
    }
  }
  return (map_str);
}

void broadcast_map(t_map *map, fd_set *active_fds, int server_socket) {
  int s;
  char *map_str;
  int sent = 0;

  map_str = get_map_str(map);
  printf("get_map_str() res : \n%s\n", map_str);
  for (s = 0; s < 10 ;s++) {
    if (FD_ISSET(s, active_fds) && s != server_socket) {
      int map_size= strlen(map_str);
      do {
        sent += send(s, map_str, map_size, 0);
        printf("send to %d / %d \n", sent, map_size);
      } while(sent < map_size);
    }
  }
  printf("end broadcast");
}

void exec_cmd(char *cmd, t_map *map, int player) {
  int i;
  char *username;
  t_command_funct *tab;
  int src_player;

  tab = init_funct_tab();
  if(strncmp(cmd, "000", 3) == 0) {
    username = strtok(cmd, "000");
    src_player = search_player_by_socket(map->players, map->nb_players, player);
    if(src_player > 0)
    {
      map->players[src_player]->username = username;
      printf("%s joined the game\n", map->players[src_player]->username);
    }
  }
  else {
    for (i = 0; i < 5; i++)
    {
      if ((strncmp(cmd, tab[i].key, 1) == 0))
      {
        tab[i].function(map, player);
      }
    }
  }
}

void handleNewConnection(int s, fd_set *active_fds, t_map *map) {
  struct sockaddr_in peer_addr;
  socklen_t peer_addr_size;
  int cfd;
  char *msg;

  peer_addr_size = sizeof(struct sockaddr_in);
  cfd = accept(s, (struct sockaddr *) &peer_addr, &peer_addr_size);

  if(cfd < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  printf("Server: connect from %d\n", cfd);
  if(map->nb_players >= MAX_PLAYERS)
  {
    msg = "full";
    send(cfd, msg, strlen(msg), 0);
    shutdown(cfd, 2);
  }
  else {
    add_player(map, cfd);
    FD_SET(cfd, active_fds);
  }
  debug_map(map);

}

void main_loop(int s) {
  fd_set active_fds;
  fd_set read_fds;
  int i;
  int nread;
  char buf[1024];
  t_global *global;

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
          handleNewConnection(s, &active_fds, global->map);
        else {
          nread = recv(i, buf, 1024, 0);
          if(nread != 0)
            exec_cmd(buf, global->map, i);
          broadcast_map(global->map, &active_fds, s);
        }
      }
    }
  }
}

int main() {
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
