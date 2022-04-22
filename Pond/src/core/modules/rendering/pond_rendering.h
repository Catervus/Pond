#pragma once

#include <SDL.h>
#include "../../pond_sdl.h"
#include "../../pond_core.h"

POND_API typedef struct Pond_Point
{
	int x;
	int y;

} Pond_Point;

POND_API typedef struct Pond_Colour
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;

} Pond_Colour;

POND_API typedef struct Pond_Sprite
{
	SDL_Texture* p_texture;
	Pond_Colour* col;
	Uint32 width;
	Uint32 height;

} Pond_Sprite;



void RenderScene();

POND_API void Pond_DrawPixel(int x, int y, SDL_Color _col);
POND_API void Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, SDL_Color _col);
POND_API void Pond_DrawPolygon(Pond_Point _points[], int _arraysize, SDL_Color _col);


POND_API void Pond_DrawSprite(Pond_Sprite* _sprite, int _x, int _y, int _alpha);
static SDL_Texture* LoadTexture(char* _filename);
POND_API Pond_Sprite* Pond_LoadSprite(char* _filename, float _w, float _h, SDL_Color _col);

extern App app;


