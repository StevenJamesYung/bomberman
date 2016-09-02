#include "commands.h"

void up(t_global *global, int player) {
    printf("UP %s\n", global->players[player]->username);
}
void down(t_global *global, int player) {
    printf("DOWN %s\n", global->players[player]->username);
}
void right(t_global *global, int player) {
    printf("RIGHT %s\n", global->players[player]->username);
}
void left(t_global *global, int player) {
    printf("LEFT %s\n", global->players[player]->username);
}
void drop(t_global *global, int player) {
    printf("DROP %s\n", global->players[player]->username);
}