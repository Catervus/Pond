#include "pond_window.h"

int Pond_SetWindowSize(int _width, int _height)
{
	SDL_SetWindowSize(app.p_window, _width, _height);

	return 1;
}

Pond_Vector2Int Pond_GetWindowSize(void)
{
	Pond_Vector2Int windowsize = { 0, 0 };

	SDL_GetWindowSize(app.p_window, &windowsize.x, &windowsize.y);

	return windowsize;
}