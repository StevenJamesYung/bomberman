#include "map.h"

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
  /*
  printf("init_map map value: %p\n", map);
  newMap = {
    (int[WIDTH]){5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    (int[WIDTH]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
  printf("%p\n", &newMap);
  map = &newMap;
  */
  int **m;
  int i;
  int y;
  t_map *map;
  ///t_player *players;

  //players = malloc(MAX_PLAYERS * sizeof(t_player));

  map = malloc(sizeof(t_map));
  m = (int**)malloc(HEIGHT * sizeof(int*));

  for(i = 0; i < HEIGHT; i++) {
    m[i] = (int*)malloc(WIDTH * sizeof(int));

    for(y = 0; y < WIDTH; y++) {
      m[i][y] = 0;
    }
  }

  //map->players = players;
  map->value = m;

  return map;
}

void add_player(t_map *map) {
  int maxY = WIDTH - 1;
  int maxX = HEIGHT -1;

  if(map->value[0][0] == 0) {
    map->value[0][0] = 1;
  }
  else if(map->value[0][maxY] == 0) {
    map->value[0][maxY] = 1;
  }
  else if(map->value[maxX][0] == 0) {
    map->value[maxX][0] = 1;
  }
  else if(map->value[maxX][maxY] == 0) {
    map->value[maxX][maxY] = 1;
  }
}
