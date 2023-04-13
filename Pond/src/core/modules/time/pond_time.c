#include "pond_time.h"

typedef struct TimeManager
{
	int engineFPS;
	int newEngineFPS;

	Uint64 currentTime;
	Uint64 oldTime;

	double deltaTime;
	double lastDeltaTime;

	int currentFPS;

	Uint64 startOfFrameCounter;

} TimeManager;

TimeManager* p_timeManager;

#pragma region Intern_Functions

int InitTimeSystem(int _fpscap)
{
	p_timeManager = malloc(sizeof(TimeManager));
	memset(p_timeManager, 0, sizeof(TimeManager));

	p_timeManager->engineFPS = _fpscap; // set's engine FPS
	p_timeManager->newEngineFPS = p_timeManager->engineFPS;

	return 1;
}

int ShutTimeSystem(void)
{
	free(p_timeManager);

	return 1;
}

int UpdateFrameCounter(void)
{
	p_timeManager->startOfFrameCounter = SDL_GetPerformanceCounter();
}

int HandleFramerateCap(void)
{
	Uint64 end = SDL_GetPerformanceCounter();
	double frameMS = (end - p_timeManager->startOfFrameCounter) / (double)SDL_GetPerformanceFrequency() * 1000.0; // amount of milliseconds the frame took
	float delay = 1000.0 / p_timeManager->engineFPS - frameMS; // 1000.0 / engineFPS => 1000.0 / 60fps = 16.6666 milliseconds per frame, subtracting time the frame took
	if (delay < 0)
		delay = 0.0;
	if (p_timeManager->engineFPS < 0)
		delay = 0.0;

	SDL_Delay(floor(delay)); // DELAY TO CAP FRAMERATE TO ENGINE FPS CAP

	end = SDL_GetPerformanceCounter();
	double elapsedMS = (end - p_timeManager->startOfFrameCounter) / (double)SDL_GetPerformanceFrequency() * 1000.0;
	p_timeManager->currentFPS = floor(1.0 / (elapsedMS / 1000.0));

	p_timeManager->engineFPS = p_timeManager->newEngineFPS;
}

bool shouldShow = false; // DEBUG
int UpdateDeltaTime(void)
{
	if (p_timeManager->currentTime == 0)
	{
		p_timeManager->currentTime = SDL_GetPerformanceCounter();
		return;
	}

	p_timeManager->oldTime = p_timeManager->currentTime;
	Uint64 time = SDL_GetPerformanceCounter();
	p_timeManager->currentTime = time;

	if (p_timeManager->currentTime < 0)
		p_timeManager->currentTime *= -1;

	p_timeManager->deltaTime = (double)(p_timeManager->currentTime - (double)p_timeManager->oldTime) / (double)SDL_GetPerformanceFrequency();

	if (p_timeManager->deltaTime > 1.0)
	{
		p_timeManager->deltaTime = p_timeManager->lastDeltaTime;
		printf("AH HUGE DELTA TIME!!!! DeltaTime: %f\n", p_timeManager->deltaTime); // DEBUG
		printf("CurrentTime: %llu\nOldTime: %llu\n-----------\n", p_timeManager->currentTime, p_timeManager->oldTime);
	}
	if (p_timeManager->deltaTime < 0)
	{
		p_timeManager->deltaTime = p_timeManager->lastDeltaTime;
		printf("AH tiny delta time...DeltaTime: %f\n", p_timeManager->deltaTime);
		printf("CurrentTime: %llu\nOldTime: %llu\n-----------\n", p_timeManager->currentTime, p_timeManager->oldTime);
	}

	p_timeManager->lastDeltaTime = p_timeManager->deltaTime;
}

#pragma endregion

/// <summary>
/// Sets the FPS cap for the next frame.
/// </summary>
/// <param name="_fpscap">- value to cap FPS at</param>
/// <returns> 1 if successful</returns>
int Pond_SetFPSCap(int _fpscap)
{
	p_timeManager->newEngineFPS = _fpscap;

	return 1;
}

/// <summary>
/// Gets the current FPS cap.
/// If fps cap is changed on the same frame, it has not updated yet and thus this function will return the old FPS cap.
/// </summary>
/// <returns> FPS cap as int value</returns>
int Pond_GetFPSCap(void)
{
	return p_timeManager->engineFPS;
}

/// <summary>
/// Gets the current FPS.
/// </summary>
/// <returns> FPS as int value</returns>
int Pond_GetCurrentFPS(void)
{
	return p_timeManager->currentFPS;
}

/// <summary>
/// Gets the delta time. (Time that has passed since last frame)
/// </summary>
/// <returns> delta time as double value</returns>
double Pond_GetDeltaTime(void)
{
	return p_timeManager->deltaTime;
}