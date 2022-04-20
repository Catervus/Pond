#pragma once

int initsdl(void);

#include <SDL.h>
#include <stdio.h>

typedef struct
{
	SDL_Renderer* p_renderer;
	SDL_Window* p_window;
} App;

App app;

