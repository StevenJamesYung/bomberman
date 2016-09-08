#include "signal.h"

void		convert_signal_to_cmd(int ch, char** cmd)
{
  int		tmp;
  char		tmp_char;

  tmp = ch - 63 + '0';
  tmp_char = (char)tmp;
  strncpy(*cmd, &tmp_char, 1);
}

