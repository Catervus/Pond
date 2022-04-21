#include "pond_rendering.h"


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
	printf("%i\n", _arraysize);


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