#include "pond_time.h"

int engineFPS;
int newEngineFPS;

int currentTime = 0.0;
int oldTime = 0.0;

double deltaTime = 1.0;

Uint64 startOfFrameCounter = 0;

int InitTimeSystem(int _fpscap)
{
	///*engineFPS = (1000.0 / _fpscap);
	//newEngineFPS = (1000.0 / _fpscap);*/
	engineFPS = _fpscap > 0 ? _fpscap : POND_FPS_DEFAULT; // set's engine FPS
	newEngineFPS = engineFPS;

	return 1;
}

int startTicks, pausedTicks;

int UpdateFrameCounter(void)
{
	startOfFrameCounter = SDL_GetPerformanceCounter();
}

int HandleFramerateCap(void)
{
	Uint64 end = SDL_GetPerformanceCounter();
	double frameMS = (end - startOfFrameCounter) / (double)SDL_GetPerformanceFrequency() * 1000.0; // amount of milliseconds the frame took
	float delay = 1000.0 / engineFPS - frameMS; // 1000.0 / engineFPS => 1000.0 / 60fps = 16.6666 milliseconds per frame, subtracting time the frame took
	if (delay < 0)
		delay = 0;

	// printf("Value: %i\n", engineFPS);


	SDL_Delay(floor(delay)); // DELAY TO CAP FRAMERATE TO ENGINE FPS CAP

	end = SDL_GetPerformanceCounter();
	double elapsedMS = (end - startOfFrameCounter) / (double)SDL_GetPerformanceFrequency() * 1000.0;
	int fps = floor(1.0 / (elapsedMS / 1000.0));
	// printf("FPS: %i\n", fps);

	engineFPS = newEngineFPS;
}

int FPSGetTicks(void)
{
	return SDL_GetTicks() - startTicks;
}


int Pond_SetFPS(int _fpscap)
{
	//newEngineFPS = (1000.0 / _fpscap);
	newEngineFPS = _fpscap;
}

int UpdateDeltaTime(void)
{
	if (currentTime == 0)
	{
		currentTime = (double)SDL_GetPerformanceCounter();
		return;
	}

	oldTime = currentTime;
	int time = SDL_GetPerformanceCounter();
	currentTime = time;
	// printf("CurrentTime: %i\nOldTime: %i\n-----------\n", currentTime, oldTime);
	deltaTime = (double)(currentTime - (double)oldTime) / (double)SDL_GetPerformanceFrequency();

}

double Pond_GetDeltaTime(void)
{
	return deltaTime;
}