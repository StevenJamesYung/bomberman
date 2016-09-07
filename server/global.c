/*
** global.c for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:14:32 2016 YUNG Steven
** Last update Tue Sep  6 22:14:34 2016 YUNG Steven
*/

#include "global.h"

t_global *init_global() {
  t_global *global;

  if ((global = malloc(sizeof(t_global))) == NULL)
    return (NULL);
  global->map = init_map();
  return (global);
}
