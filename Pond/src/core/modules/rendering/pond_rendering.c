#include "pond_rendering.h"


void RenderScene()
{
	SDL_RenderPresent(app.p_renderer);
}

void Pond_DrawPixel(int x, int y, SDL_Color _col)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);
	SDL_RenderDrawPoint(app.p_renderer, x, y);
	SDL_SetRenderDrawColor(app.p_renderer, 0, 0, 0, 0);
}

void Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, SDL_Color _col)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);
	SDL_RenderDrawLine(app.p_renderer, _x1, _y1, _x2, _y2);
	SDL_SetRenderDrawColor(app.p_renderer, 0, 0, 0, 0);
}

void Pond_DrawPolygon(Pond_Point _points[], int _arraysize, SDL_Color _col)
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
}

void Pond_DrawSprite(Pond_Sprite* _sprite, int _x, int _y, int _alpha)
{
	SDL_Rect rect;

	rect.x = _x;
	rect.y = _y;

	SDL_SetTextureAlphaMod(_sprite->p_texture, _alpha);

	SDL_QueryTexture(_sprite->p_texture, NULL, NULL, &rect.w, &rect.h);

	SDL_RenderCopy(app.p_renderer, _sprite->p_texture, NULL, &rect);
}

static SDL_Texture* LoadTexture(char* _filename) 
{
	SDL_Texture* p_tex;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", _filename);

	p_tex = IMG_LoadTexture(app.p_renderer, _filename);

	return p_tex;
	
}

Pond_Sprite* Pond_LoadSprite(char* _filename, float _w, float _h, SDL_Color _col)
{
	Pond_Sprite* p_sprite = (Pond_Sprite*) malloc(sizeof(Pond_Sprite));

	p_sprite->p_texture = LoadTexture(_filename);

	return p_sprite;

}
