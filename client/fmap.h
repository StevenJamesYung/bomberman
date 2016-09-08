#include <SDL/SDL.h>

typedef struct
{
  SDL_Rect R;
  int mur;
} TileProp;

typedef struct
{
  int LARGEUR_TILE,HAUTEUR_TILE;
  int nbtilesX,nbtilesY;
  SDL_Surface* tileset;
  TileProp* props;
  Uint16** schema;
  int nbtiles_largeur_monde,nbtiles_hauteur_monde;
} Map;

Map* ChargerMap(const char* fic);
int AfficherMap(Map* m,SDL_Surface* screen);
int LibererMap(Map* m);
void UpdateMap(char* str_map, Map* m);
