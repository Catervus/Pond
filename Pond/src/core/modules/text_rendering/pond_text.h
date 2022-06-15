#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"
#include "../../pond_basic_structs.h"
#include "../../sdl/pond_sdl.h"
#include <math.h>
#include <memory.h>

#define POND_FONT_MAX_GLYPHS 128

#define FONT_TEXTURE_SIZE 512

#define POND_ROTATION_ANCHOR_ZERO Pond_Vector2Int stuff = { 0,0 } 


typedef struct Pond_Font
{
	TTF_Font* p_fontData;
	SDL_Texture* p_textureData;
	SDL_Rect glyphs[POND_FONT_MAX_GLYPHS];

} Pond_Font;

int InitFontSystem(void);
int ShutFontSystem(void);

/// <summary>
/// Loads the passed font file, allocates memory for a Pond_Fond variable and returns pointer to it.
/// Free Pond_Fond pointer with Pond_DeleteFont.
/// </summary>
/// <param name="_filename">- filepath of the font file to load</param>
/// <returns> pointer to a Pond_Font variable</returns>
POND_API Pond_Font* Pond_LoadFont(char* _filepath);

/// <summary>
/// Frees a Pond_Font from memory.
/// Afterwards pointer pointing to that memory can be nulled.
/// This function should to be used over using free() manually in order to free all allocated memory properly.
/// </summary>
/// <param name="_p_font"></param>
/// <returns> returns 1 if successful</returns>
POND_API int Pond_DeleteFont(Pond_Font* _p_font);


/// <summary>
/// Draws passed text with passed settings and with passed font.
/// For more options use Pond_DrawTextAdvanced.
/// </summary>
/// <param name="_p_text">- text to draw</param>
/// <param name="_x">- x-position to draw text at</param>
/// <param name="_y">- y-position to draw text at</param>
/// <param name="_colour">- colour to draw text with</param>
/// <param name="_xscale">- x-scale to draw text with</param>
/// <param name="_yscale">- y-scale to draw text with</param>
/// <param name="_p_font">- font to draw text with</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_DrawText(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font);

/// <summary>
/// Draws passed text with passed advanced settings and with passed font.
/// For less options use Pond_DrawText.
/// </summary>
/// <param name="_p_text">- text to draw</param>
/// <param name="_x">- x-position to draw text at</param>
/// <param name="_y">- y-position to draw text at</param>
/// <param name="_colour">- colour to draw text with</param>
/// <param name="_xscale">- x-scale to draw text with</param>
/// <param name="_yscale">- y-scale to draw text with</param>
/// <param name="_p_font">- font to draw text with</param>
/// <param name="_rotationangle">- angle at which to draw text</param>
/// <param name="_rotationanchor">- anchor of the rotation, 0|0 is top left of the text</param>
/// <returns> returns 1 if successful</returns>
POND_API int Pond_DrawTextAdvanced(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font, int _rotationangle, Pond_Vector2Int _rotationanchor);

/// <summary>
/// Draws passed text with passed font and each character with corresponding angle around anchor.
/// </summary>
/// <param name="_p_text">- text to draw</param>
/// <param name="_x">- x-position to draw text at</param>
/// <param name="_y">- y-position to draw text at</param>
/// <param name="_colour">- colour to draw text with</param>
/// <param name="_xscale">- x-scale to draw text with</param>
/// <param name="_yscale">- y-scale to draw text with</param>
/// <param name="_p_font">- font to draw text with</param>
/// <param name="_rotationangles">- angles at which to draw each character</param>
/// <param name="_rotationanchors">- anchor at which to rotate each character</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_DrawTextSpecial(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font, int _rotationangles[], Pond_Vector2Int _rotationanchors[]);

/// <summary>
/// Gets dimensions of passed text with passed font as Pond_Vector2Int.
/// </summary>
/// <param name="_p_text">- the text of which to get the dimensions from</param>
/// <param name="_p_font">- the font of the text of which to get the dimensions from</param>
/// <returns> dimensions of passed text with font</returns>
POND_API Pond_Vector2Int Pond_GetTextDimensions(char* _p_text, Pond_Font* _p_font);


// TODO: Should go somewhere else
SDL_Texture* SurfaceToTexture(SDL_Surface* _p_surface, int _destroysurface);
