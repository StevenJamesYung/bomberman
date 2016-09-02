#include "map.h"
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
