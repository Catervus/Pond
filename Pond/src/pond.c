// For use by engine applications
#include "pond.h"

void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void))
{
	ClientInit = _init;
	ClientUpdate = _update;
	ClientDraw = _draw;

	InitSDL();

}

void Pond_Run(int _fpscap, int _screenwidth, int _screenheight)
{
	engineFPS = _fpscap;
	newEngineFPS = engineFPS;

	// Init_SDL(Pond_GetWindowSize().x, Pond_GetWindowSize().y);
	// Init_SDL(_screenwidth, _screenheight);

	atexit(Cleanup);

	InitInputSystem();
	InitRandomSystem();

	OpenSDLWindow(_screenwidth, _screenheight);

	ClientInit();


	while (1)
	{
		GatherSystemInput();

		Uint64 start = SDL_GetPerformanceCounter();
		// PrepareRenderingScene();

		PrepareScene();

		ClientUpdate();
		ClientDraw();

		RenderScene();



		Uint64 frametime = SDL_GetPerformanceCounter();
		SDL_Delay(floor((1000.0 / engineFPS) - 1.0 / frametime));
		Uint64 end = SDL_GetPerformanceCounter();
		float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
		// printf("FPS: %f\n", 1.0 / elapsed);

		engineFPS = newEngineFPS;
		SaveInputs();
	}
}

//void Pond_Run(int _fpscap)
//{
//
//
//	InitTime(_fpscap);
//
//	InitSDL();
//
//	EngineInit();
//
//	atexit(Cleanup);
//
//	while (1)
//	{
//		Uint64 start = SDL_GetPerformanceCounter();
//		SDL_RenderClear(app.p_renderer);
//		// PrepareRenderingScene();
//
//		EngineUpdate();
//		EngineDraw();
//
//		RenderScene();
//
//
//		Uint64 frametime = SDL_GetPerformanceCounter();
//		SDL_Delay(floor(engineFPS - 1.0 / frametime));
//		Uint64 end = SDL_GetPerformanceCounter();
//		float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
//		printf("FPS: %f\n", 1.0 / elapsed);
//
//		engineFPS = newEngineFPS;
//	}
//}



static void Cleanup(void)
{
	printf("Cleanup!");

	SDL_DestroyWindow(app.p_window);
	SDL_DestroyRenderer(app.p_renderer);
	Mix_CloseAudio();

	SDL_Quit();
}



