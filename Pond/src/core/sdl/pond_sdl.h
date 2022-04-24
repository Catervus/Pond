#pragma once

int Init_SDL(void);

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>

typedef struct
{
	SDL_Renderer* p_renderer;
	SDL_Window* p_window;

} App;

App app;

