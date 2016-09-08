#ifndef __FMAP_H__
# define __FMAP_H__
# define _GNU_SOURCE

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

Map* LoadMap(const char* fic);
int ShowMap(Map* m,SDL_Surface* screen);
int FreeMap(Map* m);
void UpdateMap(char* str_map, Map* m);

#endif