#include "global.h"

t_global *init_global() {
  t_global *global;

  global = malloc(sizeof(t_global));

  global->map = init_map();

  return (global);
}
