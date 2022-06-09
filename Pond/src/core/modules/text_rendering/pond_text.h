#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"
#include "../../pond_basic_structs.h"
#include "../../sdl/pond_sdl.h"
#include <math.h>

#define POND_FONT_MAX_GLYPHS 128

#define FONT_TEXTURE_SIZE 512


typedef struct Pond_Font
{
	TTF_Font* p_fontData;
	SDL_Texture* p_textureData;
	SDL_Rect glyphs[POND_FONT_MAX_GLYPHS];

} Pond_Font;

int InitFontSystem(void);

POND_API Pond_Font* Pond_InitFont(char* _filename);
POND_API int Pond_DeleteFont(Pond_Font* _p_font);

POND_API int Pond_DrawText(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font);
POND_API int Pond_DrawTextAdvanced(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font, int _rotationangle, Pond_Vector2Int _rotationanchor);

// This can be used to determine where to rotate the text around
POND_API Pond_Vector2Int Pond_GetTextDimensions(char* _p_text, Pond_Font* _p_font);


// TODO: A function where every character get's a different position and rotation, to make animation easier and not a hazzle with a function call for every character


// TODO: Should go somewhere else
SDL_Texture* SurfaceToTexture(SDL_Surface* _p_surface, int _destroysurface);
