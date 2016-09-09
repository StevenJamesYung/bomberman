/*
** fmap.c for bomberman in
**
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
**
** Started on  Fri Sep  9 02:40:24 2016 YUNG Steven
** Last update Fri Sep  9 02:40:31 2016 YUNG Steven
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include "fmap.h"

SDL_Surface	*LoadImage32(const char* image_file)
{
  SDL_Surface	*image_result;
  SDL_Surface	*image_ram;

  image_ram = SDL_LoadBMP(image_file);
  if (image_ram == NULL)
  {
    printf("Image %s introuvable !! \n", image_file);
    SDL_Quit();
    system("pause");
    return (NULL);
  }
  image_result = SDL_DisplayFormat(image_ram);
  SDL_FreeSurface(image_ram);
  return (image_result);
}

void		LoadMap_tileset(FILE* F,Map* m)
{
  int		numtile;
  int		i;
  int		j;
  char		buf[CACHE_SIZE];
  char		buf2[CACHE_SIZE];

  fscanf(F, "%s", buf);
  fscanf(F, "%s", buf);
  m->tileset = LoadImage32(buf);
  fscanf(F, "%d %d", &m->nbtilesX, &m->nbtilesY);
  m->TILE_WIDTH = m->tileset->w / m->nbtilesX;
  m->TILE_HEIGHT = m->tileset->h / m->nbtilesY;
  m->props = malloc(m->nbtilesX * m->nbtilesY * sizeof(TileProp));
  for (j = 0, numtile = 0; j < m->nbtilesY; j++)
    for (i = 0; i < m->nbtilesX; i++, numtile++)
    {
      m->props[numtile].R.w = m->TILE_WIDTH;
      m->props[numtile].R.h = m->TILE_HEIGHT;
      m->props[numtile].R.x = i * m->TILE_WIDTH;
      m->props[numtile].R.y = j * m->TILE_HEIGHT;
      fscanf(F, "%s %s", buf, buf2);
      m->props[numtile].mur = 0;
      if (strcmp(buf2, "mur") == 0)
        m->props[numtile].mur = 1;
    }
}

void		UpdateMap(char* str_map, Map* m)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  for (j = 0; j < m->nbtiles_height_world; j++)
  {
    for (i = 0; i < m->nbtiles_width_world; i++)
    {
      m->schema[i][j] = str_map[k] - 48;
      k++;
    }
  }
}

int		LoadMap_level(FILE* F,Map* m)
{
  int		i;
  int		j;
  char		buf[CACHE_SIZE];

  fscanf(F, "%s", buf);
  fscanf(F, "%d %d", &m->nbtiles_width_world, &m->nbtiles_height_world);
  m->schema = malloc(m->nbtiles_width_world * sizeof(Uint16 *));
  for (i = 0; i < m->nbtiles_width_world; i++)
    m->schema[i] = malloc(m->nbtiles_height_world * sizeof(Uint16));
  for (j = 0; j < m->nbtiles_height_world; j++)
  {
    for (i = 0; i < m->nbtiles_width_world; i++)
    {
      int tmp;
      fscanf(F, "%d", &tmp);

      if (tmp >= m->nbtilesX * m->nbtilesY)
      {
        printf("level tile hors limite\n");
        SDL_Quit();
        system("pause");
        return (-1);
      }
      m->schema[i][j] = tmp;
    }
  }
  return (0);
}

Map*		LoadMap(const char* level)
{
  FILE*		F;
  Map*		m;

  F = fopen(level,"r");
  if (!F)
  {
    printf("fichier %s introuvable !! \n",level);
    SDL_Quit();
    system("pause");
    return (NULL);
  }
  m = malloc(sizeof(Map));
  LoadMap_tileset(F,m);
  LoadMap_level(F,m);
  fclose(F);
  return (m);
}

int		FreeMap(Map* m)
{
  int		i;

  SDL_FreeSurface(m->tileset);
  for (i = 0; i < m->nbtiles_height_world; i++)
    free(m->schema[i]);
  free(m->schema);
  free(m->props);
  free(m);
  return (0);
}
