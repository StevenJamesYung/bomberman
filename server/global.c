#include "global.h"

t_global *init_global() {
  t_global *global;
  //t_player **players;

  global = malloc(sizeof(t_global));
  //players = (t_player **)malloc(MAX_PLAYERS * sizeof(t_player));


  global->map = init_map();
  /*
  global->players = players;
  global->nb_players = 0;
  */

  return (global);
}
