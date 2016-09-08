/*
** signal.c for bomberman in
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Fri Sep  9 00:30:31 2016 YUNG Steven
** Last update Fri Sep  9 00:30:43 2016 YUNG Steven
*/

#include "signal.h"

void		convert_signal_to_cmd(int ch, char** cmd)
{
  int		tmp;
  char		tmp_char;

  tmp = ch - 63 + '0';
  tmp_char = (char)tmp;
  strncpy(*cmd, &tmp_char, 1);
}

