#ifndef __KEYBOARD_H__
# define __KEYBOARD_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stdio.h>

void reset_terminal_mode();
int set_conio_terminal_mode();
int kbhit();
int getch();

#endif
