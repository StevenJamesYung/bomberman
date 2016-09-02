#include "commands.h"

void up(t_global *global, int player) {
    printf("UP %d\n", player);
    printf("UP %d\n", global->nb_players);    
}
void down(t_global *global, int player) {
    printf("DOWN %d\n", player);
    // printf("DOWN %s\n", global->players[player]->username);    
}
void right(t_global *global, int player) {
    printf("RIGHT %d\n", player);
    // printf("RIGHT %s\n", global->players[player]->username);    
}
void left(t_global *global, int player) {
    printf("LEFT %d\n", player);
    // printf("LEFT %s\n", global->players[player]->username);    
}
void drop(t_global *global, int player) {
    printf("DROP %d\n", player);
    // printf("DROP %s\n", global->players[player]->username);    
}

t_global *init_global() {
    t_global *global;
    t_player **players;

    global = malloc(sizeof(t_global));
    players = (t_player **)malloc(MAX_PLAYERS * sizeof(t_player));

    global->players = players;
    global->map = init_map();
    global->nb_players = 0;

    return (global); 
}

t_command_funct *init_funct_tab() {
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