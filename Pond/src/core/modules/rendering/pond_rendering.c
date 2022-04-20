#include "pond_rendering.h"

void Pond_DrawPixel(int x, int y, SDL_Color _col)
{
	SDL_SetRenderDrawColor(app.p_renderer, _col.r, _col.g, _col.b, _col.a);
	SDL_RenderDrawPoint(app.p_renderer, x, y);
	SDL_SetRenderDrawColor(app.p_renderer, 0, 0, 0, 0);
}