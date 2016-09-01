#ifndef __CLIENT_H__
# define __CLIENT_H__
# define _GNU_SOURCE

# include "../bomberman.h"
# include "keyboard.h"
# include <netinet/in.h>
# include <arpa/inet.h>

void reset_terminal_mode();
void set_conio_terminal_mode();
int kbhit();
int getch();

#endif
