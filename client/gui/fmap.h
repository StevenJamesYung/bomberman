/*
** fmap.h for bomberman in
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Fri Sep  9 02:40:49 2016 YUNG Steven
** Last update Fri Sep  9 02:40:56 2016 YUNG Steven
*/

#ifndef __FMAP_H__
# define __FMAP_H__
# define _GNU_SOURCE

#include "gui.h"

Map	*LoadMap(const char* fic);
int	ShowMap(Map* m,SDL_Surface* screen);
int	FreeMap(Map* m);
void	UpdateMap(char* str_map, Map* m);

#endif
