#include "pond_text.h"

int InitFontSystem(void)
{
	TTF_Font* p_font;

	if (TTF_Init())
	{
		printf("ERROR: Couldn't initialise SDL TTF: %s\n", SDL_GetError());
	}

}

Pond_Font* Pond_InitFont(char* _filename)
{

	Pond_Font* p_font;

	p_font = (Pond_Font*)malloc(sizeof(Pond_Font));

	memset(&p_font->glyphs, 0, sizeof(SDL_Rect) * POND_FONT_MAX_GLYPHS);

	p_font->p_fontData = TTF_OpenFont(_filename, 16); // FONT_SIZE: 16

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

int Pond_DrawText(char* _p_text, int _x, int _y, Pond_Colour _colour, float _xscale, float _yscale, Pond_Font* _p_font)
{
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
}

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

		int xpoint = cos(radians) * (_x - startx) - sin(radians) * (_y - startx) + startx;
		int ypoint = sin(radians) * (_x - startx) - cos(radians) * (_y - starty) + starty;

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
}

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

// TODO: Should go somewhere else
SDL_Texture* SurfaceToTexture(SDL_Surface* _p_surface, int _destroysurface)
{
	SDL_Texture* p_texture;

	p_texture = SDL_CreateTextureFromSurface(app.p_renderer, _p_surface);

	if (_destroysurface)
		SDL_FreeSurface(_p_surface);

	return p_texture;
}
