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

	while (1)
	{
		EngineUpdate();
		EngineDraw();

		SDL_Delay(10);
	}
}

void Pond_Print(char* _text)
{
	printf(_text);
}


