// For use by engine applications
#include "pond.h"

void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void))
{
	ClientInit = _init;
	ClientUpdate = _update;
	ClientDraw = _draw;

	InitSDL();
	InitInputSystem();
	InitFontSystem();
	InitRandomSystem();

	atexit(Cleanup);
}

void Pond_Run(int _fpscap, int _screenwidth, int _screenheight, char* _title)
{
	InitTimeSystem(_fpscap);
	UpdateDeltaTime();

	OpenSDLWindow(_screenwidth, _screenheight, _title);

	// SDL_RenderSetScale(app.p_renderer, 2, 2);

	ClientInit();
	while (1)
	{
		UpdateDeltaTime();

		UpdateFrameCounter();

		GatherSystemInput();
		
		PrepareScene();

		ClientUpdate();
		ClientDraw();

		RenderScene();
		SaveInputs();

		/*int tickcount = FPSGetTicks();
		if (tickcount < screenticksperframe)
			SDL_Delay(screenticksperframe - tickcount);*/

		// -----
		HandleFramerateCap();
		// -----


	}

}

int Pond_Quit(void)
{
	exit(1);

	return 1;
}

static void Cleanup(void)
{
	printf("Cleanup!");

	ShutTimeSystem();
	SDL_DestroyWindow(app.p_window);
	SDL_DestroyRenderer(app.p_renderer);
	Mix_CloseAudio();
	CloseInputSystem();
	ShutFontSystem();

	SDL_Quit();
}


