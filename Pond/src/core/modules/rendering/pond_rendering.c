#include "pond_rendering.h"

int PrepareScene()
{
	SDL_SetRenderDrawColor(app.p_renderer, renderClearColour.r, renderClearColour.g, renderClearColour.b, renderClearColour.a);
	SDL_RenderClear(app.p_renderer);

	return 1;
}

int RenderScene()
{
	SDL_RenderPresent(app.p_renderer);

	return 1;
}

/// <summary>
/// Sets the Render Clear Colour.
/// The Renderer clears the screen at the start of each frame with the Render Clear Colour.
/// </summary>
/// <param name="_col">- the colour to set as Render Clear Colour</param>
/// <returns>returns 1 if successful</returns>
int Pond_SetRenderClearColour(Pond_Colour _col)
{
	renderClearColour = _col;

	return 1;
}

int Pond_SetTextureScaleQuality(int _rendermode)
{
	char* value = "0";

	switch (_rendermode)
	{
		case 0:
			value = "0";
			break;
		case 1:
			value = "1";
			break;
		default:
			return 0;
			break;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, value);

	return 1;
}

/// <summary>
/// Returns a Pond_Colour with given RGBA-values.
/// </summary>
/// <param name="_r">- R value</param>
/// <param name="_g">- G value</param>
/// <param name="_b">- B value</param>
/// <param name="_a">- A value</param>
/// <returns>returns the Pond_Colour</returns>
Pond_Colour Pond_GetColour(int _r, int _g, int _b, int _a)
{
	Pond_Colour col = { _r, _g, _b, _a };
	return col;
}

/// <summary>
/// Renders a pixel at x and y with colour to the screen.
/// </summary>
/// <param name="_x">- the x-pos of the pixel to render</param>
/// <param name="_y">- the y-pos of the pixel to render</param>
/// <param name="_col">- the colour of the pixel</param>
/// <returns>returns 1 if successful</returns>
int Pond_DrawPixel(int _x, int _y, Pond_Colour _col)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);
	SDL_RenderDrawPoint(app.p_renderer, _x, _y);

	return 1;
}

/// <summary>
/// Renders a line between two coordinates with colour to the screen.
/// </summary>
/// <param name="_x1">- x pos of 1. coordinate of line</param>
/// <param name="_y1">- y pos of 1. coordinate of line</param>
/// <param name="_x2">- x pos of 2. coordinate of line</param>
/// <param name="_y2">- x pos of 2. coordinate of line</param>
/// <param name="_col">- the colour of the line</param>
/// <returns>returns 1 if successful</returns>
int Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);
	SDL_RenderDrawLine(app.p_renderer, _x1, _y1, _x2, _y2);

	return 1;
}

int Pond_DrawPolygon(Pond_Vector2Int _points[], int _arraysize, Pond_Colour _col)
{
	for (int i = 0; i < _arraysize; i++)
	{
		if (i == _arraysize - 1)
		{
			Pond_DrawLine(_points[i].x, _points[i].y, _points[0].x, _points[0].y, _col);

		}
		else
		{
			Pond_DrawLine(_points[i].x, _points[i].y, _points[i + 1].x, _points[i + 1].y, _col);

		}
	}

	return 1;
}

/// <summary>
/// Renders a rectangle by giving top-left and bottom-right coordinates with colour to the screen.
/// </summary>
/// <param name="_x1">- x pos of the top-left coordinate of the rectangle</param>
/// <param name="_y1">- y pos of the top-left coordinate of the rectangle</param>
/// <param name="_x2">- x pos of the bottom-right coordinate of the rectangle</param>
/// <param name="_y2">- y pos of the bottom-right coordinate of the rectangle</param>
/// <param name="_col">- the colour of the rectangle</param>
/// <param name="_fill">- true or 1 if the rectangle should be filled, false or 0 if not</param>
/// <returns>returns 1 if successful</returns>
int Pond_DrawRect(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col, bool _fill)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);

	int width = _x2 - _x1;
	int height = _y2 - _y1;

	SDL_Rect rect = { _x1, _y1, width, height };

	if (_fill)
	{
		SDL_RenderFillRect(app.p_renderer, &rect);
		return 1;
	}

	SDL_RenderDrawRect(app.p_renderer, &rect);

	return 1;
}

/// <summary>
/// Renders a rectangle by giving a coordinate, width and height values.
/// </summary>
/// <param name="_x">- x pos of the rectangle, corresponds to the top-left position of the rectangle</param>
/// <param name="_y">- y pos of the rectangle, corresponds to the top-left position of the rectangle</param>
/// <param name="_w">- width of the rectangle</param>
/// <param name="_h">- height of the rectangle</param>
/// <param name="_col">- the colour of the rectangle</param>
/// <param name="_fill">- true or 1 if the rectangle should be filled, false or 0 if not</param>
/// <returns>returns 1 if successful</returns>
int Pond_DrawRectByDimensions(int _x, int _y, int _w, int _h, Pond_Colour _col, bool _fill)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);


	SDL_Rect rect = { _x, _y, _w, _h };

	if (_fill)
	{
		SDL_RenderFillRect(app.p_renderer, &rect);
		return 1;
	}

	SDL_RenderDrawRect(app.p_renderer, &rect);

	return 1;
}


int Pond_DrawCircle(int _x, int _y, int _radius, Pond_Colour _col, bool _fill)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);

	if (_fill)
	{
		for (int i = _radius; i > 0; i--) 
		{
			DrawCircleAlgorithm(_x, _y, i);
		}

		return 1;
	}

	DrawCircleAlgorithm(_x, _y, _radius);

	return 1;
}

static int DrawCircleAlgorithm(int _x, int _y, int _radius)
{
	const int d = _radius * 2;

	int32_t x = _radius - 1;
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - d);

	while (x >= y)
	{
		SDL_RenderDrawPoint(app.p_renderer, _x + x, _y - y);
		SDL_RenderDrawPoint(app.p_renderer, _x + x, _y + y);
		SDL_RenderDrawPoint(app.p_renderer, _x - x, _y - y);
		SDL_RenderDrawPoint(app.p_renderer, _x - x, _y + y);

		SDL_RenderDrawPoint(app.p_renderer, _x + y, _y - x);
		SDL_RenderDrawPoint(app.p_renderer, _x + y, _y + x);
		SDL_RenderDrawPoint(app.p_renderer, _x - y, _y - x);
		SDL_RenderDrawPoint(app.p_renderer, _x - y, _y + x);


		if (error > 0)
		{
			x--;
			tx += 2;
			error += tx - d;
		}
		else
		{
			y++;
			error += ty;
			ty += 2;
		}
	}
}

int Pond_DrawTexture(Pond_Texture* _tex, int _x, int _y, float _xscale, float _yscale, int _alpha)
{
	SDL_Rect rect;

	rect.x = _x;
	rect.y = _y;

	SDL_SetTextureAlphaMod(_tex->p_textureData, _alpha);

	SDL_QueryTexture(_tex->p_textureData, NULL, NULL, &rect.w, &rect.h);
	rect.w *= _xscale;
	rect.h *= _yscale;

	SDL_RenderCopy(app.p_renderer, _tex->p_textureData, NULL, &rect);

	// SDL_RenderCopyEx(app.p_renderer, _tex->p_texture, NULL, &rect, _tex->rotationAngle, NULL, _tex->flipX);
	return 1;
}

int Pond_DrawTextureAdvanced(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, Pond_Colour _colour, int _rotationangle, Pond_Vector2Int _rotation)
{
	SDL_Rect portion = { _portion.x, _portion.y, _portion.w, _portion.h };

	SDL_Rect rect;

	rect.x = _x;
	rect.y = _y;

	// SDL_QueryTexture(_tex->p_texture, NULL, NULL, &rect.w, &rect.h);

	rect.w = portion.w * _xscale;
	rect.h = portion.h * _yscale;
	SDL_SetTextureColorMod(_tex->p_textureData, _colour.r, _colour.g, _colour.b);
	SDL_SetTextureAlphaMod(_tex->p_textureData, _colour.a);


	// SDL_RenderCopyEx(app.p_renderer, _tex->p_textureData, &portion, &rect, _rotationangle, NULL, NULL);
}

int Pond_DrawSprite(Pond_Sprite* _sprite, int _x, int _y, float _xscale, float _yscale)
{
	SDL_Rect portion = { _sprite->spriteRect.x, _sprite->spriteRect.y, _sprite->spriteRect.w, _sprite->spriteRect.h};
	SDL_Rect rect;

	rect.x = _x;
	rect.y = _y;

	SDL_SetTextureAlphaMod(_sprite->p_texture->p_textureData, _sprite->colour.a);
	SDL_SetTextureColorMod(_sprite->p_texture->p_textureData, _sprite->colour.r, _sprite->colour.g, _sprite->colour.b);

	SDL_QueryTexture(_sprite->p_texture->p_textureData, NULL, NULL, &rect.w, &rect.h);

	
	rect.w = portion.w * _xscale;
	rect.h = portion.h * _yscale;


	// SDL_RenderCopy(app.p_renderer, _tex->p_tex, NULL, &rect);

	SDL_RendererFlip flip = 0;

	if (_sprite->flipX && !_sprite->flipY)
		flip = SDL_FLIP_HORIZONTAL;
	else if (_sprite->flipX && _sprite->flipY)
		flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
	else if (!_sprite->flipX && _sprite->flipY)
		flip = SDL_FLIP_VERTICAL;

	SDL_Point rotanchor = { _sprite->rotationAnchor.x, _sprite->rotationAnchor.y };

	SDL_RenderCopyEx(app.p_renderer, _sprite->p_texture->p_textureData, &portion, &rect, _sprite->rotationAngle, &rotanchor, flip);
	return 1;
}

int Pond_DrawTexturePortion(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, int _alpha)
{
	SDL_Rect portion = { _portion.x, _portion.y, _portion.w, _portion.h };

	SDL_Rect rect;

	rect.x = _x;
	rect.y = _y;

	// SDL_QueryTexture(_tex->p_texture, NULL, NULL, &rect.w, &rect.h);

	rect.w = portion.w * _xscale;
	rect.h = portion.h * _yscale;
	SDL_SetTextureAlphaMod(_tex->p_textureData, _alpha);


	SDL_RenderCopy(app.p_renderer, _tex->p_textureData, &portion, &rect);
}

static int SetTextureBlendMode(POND_TEXTURE_BLEND_MODE _quality)
{
	char* value = "0";

	switch (_quality)
	{
		case POND_TEXTURE_BLEND_MODE_NO_BLENDING:
			value = "0";
			break;
		case POND_TEXTURE_BLEND_MODE_BLENDING:
			value = "1";
			break;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, value);

	return 1;
}

static SDL_Texture* LoadTexture(char* _filename, POND_TEXTURE_BLEND_MODE _quality)
{
	SDL_Texture* p_tex;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", _filename);
	p_tex = IMG_LoadTexture(app.p_renderer, _filename);

	return p_tex;
	
}

Pond_Texture* Pond_LoadTexture(char* _filename, POND_TEXTURE_BLEND_MODE _quality)
{
	SetTextureBlendMode(_quality);

	Pond_Texture* p_tex = (Pond_Texture*) malloc(sizeof(Pond_Texture));
	memset(p_tex, 0, sizeof(Pond_Texture));

	p_tex->p_textureData = LoadTexture(_filename, _quality);

	return p_tex;

}

int Pond_FreeTexture(Pond_Texture* _p_texture)
{
	SDL_DestroyTexture(_p_texture->p_textureData);

	free(_p_texture);

	return 1;
}

Pond_Sprite* Pond_InitSprite(Pond_Texture* _p_texture)
{
	Pond_Sprite* p_sprite = malloc(sizeof(Pond_Sprite));
	memset(p_sprite, 0, sizeof(Pond_Sprite));

	p_sprite->p_texture = _p_texture;
	Pond_Colour white = { 255, 255, 255, 255 };
	p_sprite->colour = white;

	Pond_Vector2Int texturesize = Pond_GetTextureSize(p_sprite->p_texture);
	Pond_Rect spriterect = { 0, 0, texturesize.x, texturesize.y };
	p_sprite->spriteRect = spriterect;
	Pond_Vector2Int rotationAnchor = { texturesize.x / 2, texturesize.y / 2 };
	p_sprite->rotationAnchor = rotationAnchor;

	return p_sprite;
}

int Pond_FreeSprite(Pond_Sprite* _p_sprite)
{
	free(_p_sprite);

	return 1;
}

int Pond_SetSpriteValues(Pond_Rect _spriterect, Pond_Colour _colour, double _rotationangle, SDL_Point _rotationanchor, bool _flipx, bool _flipy)
{


	return 1;
}

int Pond_SetSpriteTexture(Pond_Sprite* _p_sprite, Pond_Texture* _p_texture)
{
	_p_sprite->p_texture = _p_texture;

	Pond_Vector2Int texturesize = Pond_GetTextureSize(_p_sprite->p_texture);
	Pond_Rect spriterect = { 0, 0, texturesize.x, texturesize.y };
	_p_sprite->spriteRect = spriterect;

	return 1;
}

int Pond_SetSpriteRect(Pond_Sprite* _p_sprite, int _x, int _y, int _w, int _h)
{
	Pond_Rect spriterect = { _x, _y, _w, _h };
	_p_sprite->spriteRect = spriterect;

	return 1;
}

int Pond_SetSpriteColour(Pond_Sprite* _p_sprite, int _r, int _g, int _b, int _a)
{
	Pond_Colour col = { _r, _g, _b, _a };
	_p_sprite->colour = col;

	return 1;
}

int Pond_SetSpriteRotationAnchor(Pond_Sprite* _p_sprite, int _x, int _y)
{
	Pond_Vector2Int pos = { _x, _y };
	_p_sprite->rotationAnchor = pos;

	return 1;
}

Pond_Vector2Int Pond_GetTextureSize(Pond_Texture* _p_texture) 
{
	SDL_Point size;
	SDL_QueryTexture(_p_texture->p_textureData, NULL, NULL, &size.x, &size.y);
	Pond_Vector2Int rect = {size.x, size.y};

	return rect;
}
