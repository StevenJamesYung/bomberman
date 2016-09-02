#include "map.h"

void debug_map(int **map) {
  int x;
  int y;

  for(x = 0; x < HEIGHT; x++) {
    for(y = 0; y < WIDTH; y++) {
      printf("%d ", map[x][y]);
    }
    printf("\n");
  }
}

int **init_map() {
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

  m = (int**)malloc(HEIGHT * sizeof(int*));

  for(i = 0; i < HEIGHT; i++) {
    m[i] = (int*)malloc(WIDTH * sizeof(int));

    for(y = 0; y < WIDTH; y++) {
      m[i][y] = 0;
    }
  }

  return m;
}

int **add_player(int **map) {
  int maxY = WIDTH - 1;
  int maxX = HEIGHT -1;

  if(map[0][0] == 0) {
    map[0][0] = 1;
  }
  else if(map[0][maxY] == 0) {
    map[0][maxY] = 1;
  }
  else if(map[maxX][0] == 0) {
    map[maxX][0] = 1;
  }
  else if(map[maxX][maxY] == 0) {
    map[maxX][maxY] = 1;
  }
  return map;
}
