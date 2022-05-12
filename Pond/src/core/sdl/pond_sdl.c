///*This source code copyrighted by Lazy Foo' Productions (2004-2020)
//and may not be redistributed without written permission.*/
//
////Using SDL and standard IO
#include "pond_sdl.h"

//Screen dimension constants
int Init_SDL(int _screenheight, int _screenwidth)
{
	//The window we'll be rendering to
	//The surface contained by the window

	int rendererflag, windowflag;

	rendererflag = SDL_RENDERER_ACCELERATED;
	windowflag = 0;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(1);
		
	}
	
	app.p_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenheight, _screenwidth, windowflag);
	if (!app.p_window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_SetWindowBordered(app.p_window, SDL_ENABLE);
	SDL_ShowCursor(SDL_ENABLE);


	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"); // ??
	app.p_renderer = SDL_CreateRenderer(app.p_window, -1, rendererflag);
	if (!app.p_renderer)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_SetRenderDrawBlendMode(app.p_renderer, SDL_BLENDMODE_BLEND);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024))
	{
		exit(1);
	}
	Mix_AllocateChannels(24); // 24 = MAX_SND_CHANNELS

	for (int i = 0; i < 24; i++)
	{
		Mix_Volume(i, 1); // 1 = SFX_VOLUME
	}
	Mix_VolumeMusic(2);

	return 0;
}

