#pragma once

#include <SDL.h>
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_basic_structs.h"

POND_API typedef struct Pond_Sprite
{
	SDL_Texture* p_texture;

} Pond_Texture;

POND_API typedef struct Pond_Rect
{
	float x;
	float y;
	float w;
	float h;

} Pond_Rect;

static Pond_Colour renderClearColour = { 0,0,0,255 };

int RenderScene(void);
int PrepareScene(void);

enum
{
	POND_TEXTURE_SCALE_QUALITY_NO_FILTER = 0,
	POND_TEXTURE_SCALE_QUALITY_FILTER,

};

POND_API int Pond_SetTextureScaleQuality(int _rendermode);

POND_API int Pond_SetRenderClearColour(Pond_Colour _col);
POND_API int Pond_DrawPixel(int x, int y, Pond_Colour _col);
POND_API int Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col);
POND_API int Pond_DrawPolygon(Pond_Vector2Int _points[], int _arraysize, Pond_Colour _col);
POND_API int Pond_DrawRect(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col, int _fill);
POND_API int Pond_DrawCircle(int _x, int _y, int _radius, Pond_Colour _col, int _fill);
static int DrawCircleAlgorithm(int _x, int _y, int _radius);

POND_API int Pond_DrawTexture(Pond_Texture* _tex, int _x, int _y, float _xscale, float _yscale, int _alpha);
POND_API int Pond_DrawTexturePortion(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, int _alpha);
static SDL_Texture* LoadTexture(char* _filename);
POND_API Pond_Texture* Pond_LoadTexture(char* _filename, float _w, float _h, SDL_Color _col);

extern App app;


