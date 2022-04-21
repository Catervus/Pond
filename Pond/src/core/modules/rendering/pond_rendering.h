#pragma once

#include <SDL.h>
#include "../../pond_init_sdl.h"
#include "../../pond_core.h"

POND_API typedef struct Pond_Point
{
	int x;
	int y;

} Pond_Point;

POND_API void Pond_DrawPixel(int x, int y, SDL_Color _col);
POND_API void Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, SDL_Color _col);
POND_API void Pond_DrawPolygon(Pond_Point _points[], int _arraysize, SDL_Color _col);


extern App app;
