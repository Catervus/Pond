#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"
#include "../../pond_basic_structs.h"
#include "../../sdl/pond_sdl.h"

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


// TODO: Should go somewhere else
SDL_Texture* SurfaceToTexture(SDL_Surface* _p_surface, int _destroysurface);
