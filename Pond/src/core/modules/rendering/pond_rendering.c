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

int Pond_DrawPixel(int x, int y, Pond_Colour _col)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);
	SDL_RenderDrawPoint(app.p_renderer, x, y);

	return 1;
}

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

int Pond_DrawRect(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col, int _fill)
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

int Pond_DrawCircle(int _x, int _y, int _radius, Pond_Colour _col, int _fill)
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

	SDL_SetTextureAlphaMod(_tex->p_tex, _alpha);

	SDL_QueryTexture(_tex->p_tex, NULL, NULL, &rect.w, &rect.h);
	rect.w *= _xscale;
	rect.h *= _yscale;

	SDL_RenderCopy(app.p_renderer, _tex->p_tex, NULL, &rect);

	// SDL_RenderCopyEx(app.p_renderer, _tex->p_texture, NULL, &rect, _tex->rotationAngle, NULL, _tex->flipX);
	return 1;
}

int Pond_DrawSprite(Pond_Sprite* _sprite, int _x, int _y, float _xscale, float _yscale)
{
	SDL_Rect portion = { _sprite->spriteRect.x, _sprite->spriteRect.y, _sprite->spriteRect.w, _sprite->spriteRect.h};
	SDL_Rect rect;

	rect.x = _x;
	rect.y = _y;

	SDL_SetTextureAlphaMod(_sprite->p_texture->p_tex, _sprite->colour.a);

	SDL_QueryTexture(_sprite->p_texture->p_tex, NULL, NULL, &rect.w, &rect.h);

	
	rect.w = portion.w * _xscale;
	rect.h = portion.h * _yscale;


	// SDL_RenderCopy(app.p_renderer, _tex->p_tex, NULL, &rect);

	SDL_RenderCopyEx(app.p_renderer, _sprite->p_texture->p_tex, &portion, &rect, _sprite->rotationAngle, NULL, _sprite->flipX);
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
	SDL_SetTextureAlphaMod(_tex->p_tex, _alpha);


	SDL_RenderCopy(app.p_renderer, _tex->p_tex, &portion, &rect);
}

static SDL_Texture* LoadTexture(char* _filename) 
{
	SDL_Texture* p_tex;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", _filename);

	p_tex = IMG_LoadTexture(app.p_renderer, _filename);

	return p_tex;
	
}

Pond_Texture* Pond_LoadTexture(char* _filename, E_ImportQuality _quality)
{
	Pond_Texture* p_tex = (Pond_Texture*) malloc(sizeof(Pond_Texture));
	memset(p_tex, 0, sizeof(Pond_Texture));

	p_tex->p_tex = LoadTexture(_filename);

	return p_tex;

}

Pond_Sprite* Pond_InitSprite(char* _filename, E_ImportQuality _quality)
{
	Pond_Sprite* p_sprite = malloc(sizeof(Pond_Sprite));
	memset(p_sprite, 0, sizeof(Pond_Sprite));

	p_sprite->p_texture = Pond_LoadTexture(_filename, _quality);
	Pond_Colour white = { 255, 255, 255, 255 };
	p_sprite->colour = white;

	p_sprite->spriteRect = GetTextureSize(p_sprite->p_texture);

	return p_sprite;
}

Pond_Rect GetTextureSize(Pond_Texture* _p_texture) 
{
	SDL_Point size;
	SDL_QueryTexture(_p_texture->p_tex, NULL, NULL, &size.x, &size.y);
	Pond_Rect rect = {0, 0, size.x, size.y};

	return rect;
}
