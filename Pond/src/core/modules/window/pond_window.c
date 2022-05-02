#include "pond_window.h"

static int windowWidth = 1000;
static int windowHeight = 1000;

//int Pond_SetWindowSize(int _width, int _height)
//{
//	screenWidth = _width;
//	screenHeight = _height;
//
//	SDL_SetWindowSize(app.p_window, screenWidth, screenHeight);
//
//	return 1;
//}
//
Pond_Vector2Int Pond_GetWindowSize(void)
{
	Pond_Vector2Int windowsize = { windowWidth, windowHeight };
	return windowsize;
}
//
//int Pond_SetWindowMode(int _windowmode) 
//{
//	switch (_windowmode)
//	{
//		case POND_WINDOW_MODE_FULLSCREEN:
//			SDL_SetWindowFullscreen(app.p_window, SDL_WINDOW_FULLSCREEN);
//			break;
//	}
//
//	return 1;
//}