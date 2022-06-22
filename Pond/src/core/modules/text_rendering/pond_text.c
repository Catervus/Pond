#include "pond_text.h"

#pragma region System
int InitFontSystem(void)
{
	TTF_Font* p_font;

	if (TTF_Init())
	{
		printf("ERROR: Couldn't initialise SDL TTF: %s\n", SDL_GetError());
	}

	return 1;
}

int ShutFontSystem(void)
{
	TTF_Quit();

	return 1;
}
#pragma endregion


#pragma region User_Functions

/// <summary>
/// Loads the passed font file, allocates memory for a Pond_Fond variable and returns pointer to it.
/// Free Pond_Fond pointer with Pond_DeleteFont.
/// </summary>
/// <param name="_filename">- filepath of the font file to load</param>
/// <returns> pointer to a Pond_Font variable</returns>
Pond_Font* Pond_LoadFont(char* _filepath)
{
	Pond_Font* p_font;

	p_font = malloc(sizeof(Pond_Font));

	memset(&p_font->glyphs, 0, sizeof(SDL_Rect) * POND_FONT_MAX_GLYPHS);

	p_font->p_fontData = TTF_OpenFont(_filepath, 16); // FONT_SIZE: 16

	SDL_Surface* p_surface = SDL_CreateRGBSurface(0, FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE, 32, 0, 0, 0, 0xff);
	SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGBA(p_surface->format, 0, 0, 0, 0));

	SDL_Surface* p_text;

	SDL_Rect dest;
	dest.x = dest.y = 0;

	SDL_Rect* p_rect;

	char c[2];

	for (int i = ' '; i <= 'z'; i++)
	{
		c[0] = i;
		c[1] = 0;

		SDL_Color col = { 255, 255, 255, 255 };
		p_text = TTF_RenderUTF8_Blended(p_font->p_fontData, c, col);

		TTF_SizeText(p_font->p_fontData, c, &dest.w, &dest.h);

		if (dest.x + dest.w >= FONT_TEXTURE_SIZE)
		{
			dest.x = 0;
			dest.y += dest.h + 1;

			if (dest.y + dest.h >= FONT_TEXTURE_SIZE)
			{
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "ERROR: Out of glyph space in %dx%d font atlas texture map.", FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE);
				exit(1);
			}
		}

		SDL_BlitSurface(p_text, NULL, p_surface, &dest);

		p_rect = &p_font->glyphs[i];

		p_rect->x = dest.x;
		p_rect->y = dest.y;
		p_rect->w = dest.w;
		p_rect->h = dest.h;

		SDL_FreeSurface(p_text);

		dest.x += dest.w;
	}


	p_font->p_textureData = SurfaceToTexture(p_surface, 1);


	return p_font;
}

/// <summary>
/// Frees a Pond_Font from memory.
/// Afterwards pointer pointing to that memory can be nulled.
/// This function should to be used over using free() manually in order to free all allocated memory properly.
/// </summary>
/// <param name="_p_font"></param>
/// <returns> returns 1 if successful</returns>
int Pond_DeleteFont(Pond_Font* _p_font)
{
	TTF_CloseFont(_p_font->p_fontData);
	_p_font->p_fontData = NULL;


	SDL_DestroyTexture(_p_font->p_textureData);
	_p_font->p_textureData = NULL;

	// free(_p_font->glyphs);

	free(_p_font);

	return 1;
}

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
int Pond_DrawText(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font)
{
	if (_p_font == NULL || _p_text == NULL)
		return 0;

	int i = 0;
	int character = _p_text[i++];

	SDL_Rect* p_glyph;
	SDL_Rect dest;

	// int w = 1 * _xscale;
	// int h = 1 * _yscale;

	SDL_SetTextureColorMod(_p_font->p_textureData, _colour.r, _colour.g, _colour.b);

	while (character)
	{
		p_glyph = &_p_font->glyphs[character];

		dest.x = _x;
		dest.y = _y;
		dest.w = p_glyph->w * _xscale;
		dest.h = p_glyph->h * _yscale;


		SDL_RenderCopy(app.p_renderer, _p_font->p_textureData, p_glyph, &dest);

		_x += p_glyph->w * _xscale;

		character = _p_text[i++];
	}

	return 1;
}



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
int Pond_DrawTextAdvanced(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font, int _rotationangle, Pond_Vector2Int _rotationanchor)
{
	int i = 0;
	int character = _p_text[i++];

	SDL_Rect* p_glyph;
	SDL_Rect dest;

	SDL_SetTextureColorMod(_p_font->p_textureData, _colour.r, _colour.g, _colour.b);


	double pi = 3.14159265359;

	double radians = _rotationangle * (pi / 180.0);

	int startx = _x;
	int starty = _y;

	while (character)
	{
		p_glyph = &_p_font->glyphs[character];

		int xpoint = cos(radians) * ((double)_x - (double)startx) - sin(radians) * ((double)_y - (double)startx) + startx;
		int ypoint = sin(radians) * ((double)_x - (double)startx) - cos(radians) * ((double)_y - (double)starty) + starty;

		dest.x = xpoint;
		dest.y = ypoint;
		dest.w = p_glyph->w * _xscale;
		dest.h = p_glyph->h * _yscale;

		// Make text rotate around upper left corner of first character + rotationanchor offset
		SDL_Point point;
		point.x = _rotationanchor.x;
		point.y = _rotationanchor.y;

		// This get's the middle point of the first character, and thus text rotates around that
		// point.x = _rotationanchor.x + (p_glyph->w * _xscale) / 2;
		// point.y = _rotationanchor.y + (p_glyph->h * _yscale) / 2;

		SDL_RenderCopyEx(app.p_renderer, _p_font->p_textureData, p_glyph, &dest, _rotationangle, &point, 0);

		_x += p_glyph->w * _xscale;

		character = _p_text[i++];
	}

	return 1;
}

// TODO: Needs renaming

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
int Pond_DrawTextSpecial(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font, int _rotationangles[], Pond_Vector2Int _rotationanchors[])
{
	if (_p_font == NULL || _p_text == NULL)
		return 0;

	int i = 0;
	int character = _p_text[i++];

	SDL_Rect* p_glyph;
	SDL_Rect dest;

	// int w = 1 * _xscale;
	// int h = 1 * _yscale;

	SDL_SetTextureColorMod(_p_font->p_textureData, _colour.r, _colour.g, _colour.b);

	int index = 0;
	while (character)
	{
		p_glyph = &_p_font->glyphs[character];

		dest.x = _x;
		dest.y = _y;
		dest.w = p_glyph->w * _xscale;
		dest.h = p_glyph->h * _yscale;

		SDL_Point point;
		point.x = _rotationanchors[index].x;
		point.y = _rotationanchors[index].y;

		SDL_RenderCopyEx(app.p_renderer, _p_font->p_textureData, p_glyph, &dest, _rotationangles[index], &point, 0);

		_x += p_glyph->w * _xscale;

		character = _p_text[i++];

		index++;
	}

	return 1;
}

/// <summary>
/// Gets dimensions of passed text with passed font as Pond_Vector2Int.
/// </summary>
/// <param name="_p_text">- the text of which to get the dimensions from</param>
/// <param name="_p_font">- the font of the text of which to get the dimensions from</param>
/// <returns> dimensions of passed text with font</returns>
Pond_Vector2Int Pond_GetTextDimensions(char* _p_text, Pond_Font* _p_font)
{
	int i = 0;
	Pond_Vector2Int dimensions = { 0, 0 };
	int character = _p_text[i++];
	dimensions.y = _p_font->glyphs[character].h;

	while (character)
	{
		dimensions.x += _p_font->glyphs[character].w;

		character = _p_text[i++];
	}

	return dimensions;
}

#pragma endregion


// TODO: Should go somewhere else
SDL_Texture* SurfaceToTexture(SDL_Surface* _p_surface, int _destroysurface)
{
	SDL_Texture* p_texture;

	p_texture = SDL_CreateTextureFromSurface(app.p_renderer, _p_surface);

	if (_destroysurface)
		SDL_FreeSurface(_p_surface);

	return p_texture;
}
