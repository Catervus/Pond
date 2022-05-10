#pragma once

#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_basic_structs.h"
#include <memory.h>

POND_API typedef struct Pond_Texture
{
	SDL_Texture* p_textureData;

} Pond_Texture;

POND_API typedef struct Pond_Rect
{
	int x;
	int y;
	int w;
	int h;

} Pond_Rect;

POND_API typedef struct Pond_Sprite
{
	Pond_Texture* p_texture;
	
	Pond_Rect spriteRect;

	Pond_Colour colour;

	double rotationAngle;
	Pond_Vector2Int rotationAnchor;
	bool flipX;
	bool flipY;


} Pond_Sprite;


static Pond_Colour renderClearColour = { 0,0,0,255 };

int RenderScene(void);
int PrepareScene(void);

typedef enum POND_TEXTURE_BLEND_MODE
{
	POND_TEXTURE_BLEND_MODE_NO_BLENDING = 0,
	POND_TEXTURE_BLEND_MODE_BLENDING,

} POND_TEXTURE_BLEND_MODE;


POND_API int Pond_SetRenderClearColour(Pond_Colour _col);
POND_API Pond_Colour Pond_GetColour(int _r, int _g, int _b, int _a);
POND_API int Pond_DrawPixel(int x, int y, Pond_Colour _col);
POND_API int Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col);
POND_API int Pond_DrawPolygon(Pond_Vector2Int _points[], int _arraysize, Pond_Colour _col);
POND_API int Pond_DrawRect(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col, bool _fill);
POND_API int Pond_DrawRectByDimensions(int _x, int _y, int _w, int _h, Pond_Colour _col, bool _fill);
POND_API int Pond_DrawCircle(int _x, int _y, int _radius, Pond_Colour _col, bool _fill);
static int DrawCircleAlgorithm(int _x, int _y, int _radius);

POND_API int Pond_DrawTexture(Pond_Texture* _tex, int _x, int _y, float _xscale, float _yscale, int _alpha);
POND_API int Pond_DrawTexturePortion(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, int _alpha);
POND_API int Pond_DrawTextureAdvanced(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, Pond_Colour _colour, int _rotationangle, Pond_Vector2Int _rotation);


static SDL_Texture* LoadTexture(char* _filename, POND_TEXTURE_BLEND_MODE _quality);
POND_API Pond_Texture* Pond_LoadTexture(char* _filename, POND_TEXTURE_BLEND_MODE _quality);
POND_API int Pond_FreeTexture(Pond_Texture* _p_texture);

POND_API int Pond_SetTextureScaleQuality(int _rendermode);
static int SetTextureBlendMode(POND_TEXTURE_BLEND_MODE _quality);

POND_API Pond_Sprite* Pond_InitSprite(Pond_Texture* _p_texture);
// POND_API Pond_Sprite* Pond_InitSprite(char* _filename, E_ImportQuality _quality);
POND_API int Pond_FreeSprite(Pond_Sprite* _p_sprite);
POND_API int Pond_DrawSprite(Pond_Sprite* _tex, int _x, int _y, float _xscale, float _yscale);
POND_API int Pond_SetSpriteValues(Pond_Rect _spriterect, Pond_Colour _colour, double _rotationangle, SDL_Point _rotationanchor, bool _flipx, bool _flipy);
POND_API int Pond_SetSpriteTexture(Pond_Sprite* _p_sprite, Pond_Texture* _p_texture);
POND_API int Pond_SetSpriteRect(Pond_Sprite* _p_sprite, int _x, int _y, int _w, int _h);
POND_API int Pond_SetSpriteColour(Pond_Sprite* _p_sprite, int _r, int _g, int _b, int _a);
POND_API int Pond_SetSpriteRotationAnchor(Pond_Sprite* _p_sprite, int _x, int _y);


POND_API Pond_Vector2Int Pond_GetTextureSize(Pond_Texture* _p_texture);

extern App app;

