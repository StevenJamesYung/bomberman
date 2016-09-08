/*
** command_functions.c for bomberman in /Users/stevenyung/workspace/current/bomberman
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Tue Sep  6 22:13:45 2016 YUNG Steven
** Last update Thu Sep  8 22:17:32 2016 YUNG Steven
*/

#include "commands.h"
#include "command_functions.h"

t_command_funct		*init_funct_tab()
{
  t_command_funct	*tab;

  if ((tab = malloc(sizeof(t_command_funct) * 5)) == NULL)
    return (NULL);
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
