#include "global.h"

t_global *init_global() {
  t_global *global;

  if ((global = malloc(sizeof(t_global))) == NULL)
    return (NULL);
  global->map = init_map();
  return (global);
}
