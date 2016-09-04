#include "commands.h"

int search_player_by_socket(t_player **players, int nb_players, int s)
{
  int i;

  for(i = 0; i < nb_players; i++)
  {
    if(players[i]->socket == s)
      return i;
  }
  return -1;
}

void up(t_global *global, int player)
{
  int i;

  i = search_player_by_socket(global->map->players, global->map->nb_players, player);
  if (global->map->players[i]->y - 1 >= 0) {
    global->map->players[i]->y -= 1;
  }
  printf("-------------\n");
  debug_map(global->map);
}

void down(t_global *global, int player)
{
  int i;

  i = search_player_by_socket(global->map->players, global->map->nb_players, player);
  if (global->map->players[i]->y + 1 < HEIGHT) {
    global->map->players[i]->y += 1;
  }
  printf("-------------\n");
  debug_map(global->map);
}

void right(t_global *global, int player)
{
  int i;

  i = search_player_by_socket(global->map->players, global->map->nb_players, player);
  if (global->map->players[i]->x + 1 < WIDTH) {
    global->map->players[i]->x += 1;
  }
  printf("-------------\n");
  debug_map(global->map);
}

void left(t_global *global, int player)
{
  int i;

  i = search_player_by_socket(global->map->players, global->map->nb_players, player);
  if (global->map->players[i]->x - 1 >= 0) {
    global->map->players[i]->x -= 1;
  }
  printf("-------------\n");
  debug_map(global->map);
}

void drop(t_global *global, int player)
{
  int i;
  i = search_player_by_socket(global->map->players, global->map->nb_players, player);
    printf("DROP %d\n", player);
    printf("DROP %s\n", global->map->players[i]->username);
  debug_map(global->map);
}

t_command_funct *init_funct_tab()
{
    t_command_funct *tab;

    tab = malloc(sizeof(t_command_funct) * 5);

    tab[0].key = "2";
    tab[0].function = &up;
    tab[1].key = "3";
    tab[1].function = &down;
    tab[2].key = "4";
    tab[2].function = &right;
    tab[3].key = "5";
    tab[3].function = &left;
    tab[4].key = "6";
    tab[4].function = &drop;

    return (tab);
}
