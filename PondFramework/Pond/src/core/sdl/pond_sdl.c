#include "pond_sdl.h"

//Screen dimension constants
int InitSDL(void)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0)
	{
		printf("ERROR! SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	return 0;
}

int OpenSDLWindow(int _screenheight, int _screenwidth, char* _title)
{
	//The window we'll be rendering to
	//The surface contained by the window
	int rendererflag, windowflag;
	rendererflag = SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC;
	windowflag = 0;

	app.p_window = SDL_CreateWindow(_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenheight, _screenwidth, windowflag);
	if (!app.p_window)
	{
		printf("ERROR! Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_SetWindowBordered(app.p_window, SDL_ENABLE);
	SDL_ShowCursor(SDL_ENABLE);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	app.p_renderer = SDL_CreateRenderer(app.p_window, -1, rendererflag);
	if (!app.p_renderer)
	{
		printf("ERROR! Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_SetRenderDrawBlendMode(app.p_renderer, SDL_BLENDMODE_BLEND);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	return 1;
}

