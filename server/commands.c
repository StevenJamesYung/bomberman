#include "commands.h"

void up(t_global *global, int player) {

    printf("UP\n", global->players[player]->username);
}
void down(t_global *global, int player) {
    printf("DOWN\n", global->players[player]->username);
}
void right(t_global *global, int player) {
    printf("RIGHT\n", global->players[player]->username);
}
void left(t_global *global, int player) {
    printf("LEFT\n", global->players[player]->username);
}
void drop(t_global *global, int player) {
    printf("DROP\n", global->players[player]->username);
}