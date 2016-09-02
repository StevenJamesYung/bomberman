#include "map.h"

int is_player_position(t_map *map, int x, int y) {
  int i;

  for(i = 0; i < MAX_PLAYERS; i++) {
    if(map->players[i] && map->players[i]->x == x && map->players[i]->y == y) {
      // TRUE
      return 1;
    }
  }
  // FALSE
  return 0;
}

void debug_map(t_map *map) {
  int x;
  int y;

  for(x = 0; x < HEIGHT; x++) {
    for(y = 0; y < WIDTH; y++) {
      printf("%d ", map->value[x][y]);
    }
    printf("\n");
  }
}

t_map *init_map() {
  int **m;
  int i;
  int y;
  t_map *map;
  t_player **players;

  players = (t_player **)malloc(MAX_PLAYERS * sizeof(t_player));

  map = malloc(sizeof(t_map));
  m = (int**)malloc(HEIGHT * sizeof(int*));

  for(i = 0; i < HEIGHT; i++) {
    m[i] = (int*)malloc(WIDTH * sizeof(int));

    for(y = 0; y < WIDTH; y++) {
      m[i][y] = 0;
    }
  }

  map->players = players;
  map->value = m;
  map->nb_players = 0;

  return map;
}

void add_player(t_map *map) {
  t_player *new_player;

  new_player = init_player(0, 0);
  map->players[map->nb_players++] = new_player;
}
