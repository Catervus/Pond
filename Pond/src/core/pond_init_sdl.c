///*This source code copyrighted by Lazy Foo' Productions (2004-2020)
//and may not be redistributed without written permission.*/
//
////Using SDL and standard IO
#include "pond_init_sdl.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int initsdl(void)
{
	//The window we'll be rendering to
	app.p_window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(1);
		
	}
	
	app.p_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!app.p_window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	app.p_renderer = SDL_CreateRenderer(app.p_window, -1, SDL_RENDERER_ACCELERATED);
	if (!app.p_renderer)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	

	return 0;
}