#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>

int InitSDL(void);
int OpenSDLWindow(int _screenheight, int _screenwidth);

typedef struct
{
	SDL_Renderer* p_renderer;
	SDL_Window* p_window;

} App;

App app;

