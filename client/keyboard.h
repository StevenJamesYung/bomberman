/*
** keyboard.h for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:13:06 2016 YUNG Steven
** Last update Tue Sep  6 22:13:11 2016 YUNG Steven
*/

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
