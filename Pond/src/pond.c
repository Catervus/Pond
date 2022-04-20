// For use by engine applications
#include "pond.h"


void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void))
{
	EngineInit = _init;
	EngineUpdate = _update;
	EngineDraw = _draw;
}

void Pond_Run(int _fps)
{
	initsdl();

	EngineInit();

	atexit(Cleanup);

	while (1)
	{
		SDL_RenderClear(app.p_renderer);

		EngineUpdate();
		EngineDraw();

		SDL_RenderPresent(app.p_renderer);

		SDL_Delay(1000);
	}


	
}


static void Cleanup(void)
{
	printf("Cleanup!");

	SDL_DestroyWindow(app.p_window);
	SDL_DestroyRenderer(app.p_renderer);

	SDL_Quit();
}



