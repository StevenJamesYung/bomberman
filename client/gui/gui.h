/*
** gui.h for bomberman in
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Fri Sep  9 02:45:55 2016 YUNG Steven
** Last update Fri Sep  9 02:46:02 2016 YUNG Steven
*/

#ifndef __GUI_H__
# define __GUI_H__
# define _GNU_SOURCE

#include "../../bomberman.h"
#include <SDL/SDL.h>

#define CACHE_SIZE 5000

typedef struct
{
  SDL_Rect R;
  int mur;
} TileProp;

typedef struct
{
  int TILE_WIDTH,TILE_HEIGHT;
  int nbtilesX,nbtilesY;
  SDL_Surface* tileset;
  TileProp* props;
  Uint16** schema;
  int nbtiles_width_world,nbtiles_height_world;
} Map;

int		free_map(Map* m);
Map	*load_map(const char* fic);
int	show_map(Map* m,SDL_Surface* screen);
int	free_map(Map* m);
void	update_map(char* str_map, Map* m);

#endif
