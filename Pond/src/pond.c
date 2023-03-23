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

void Pond_Run(int _fpscap, int _screenwidth, int _screenheight, char* _title, bool _showconsolewindow)
{
	InitTimeSystem(_fpscap);
	UpdateDeltaTime();
	OpenSDLWindow(_screenwidth, _screenheight, _title);
	Pond_ToggleConsoleWindow(_showconsolewindow);
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


void Pond_ToggleConsoleWindow(bool _showconsole)
{
	HWND hwnd = GetConsoleWindow();
	if (!_showconsole)
	{
		ShowWindow(hwnd, SW_MINIMIZE);
		ShowWindow(hwnd, SW_HIDE);
	}
	else
	{
		ShowWindow(hwnd, SW_NORMAL);
		ShowWindow(hwnd, SW_SHOW);
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


