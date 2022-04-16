// For use by engine applications

#include "frog_engine.h"


void FrogEngine_Init(void (*_init)(), void (*_update)(), void (_draw)())
{
	EngineInit = _init;
	EngineUpdate = _update;
	EngineDraw = _draw;
}

void FrogEngine_Run(int _fps)
{
	initsdl();

	EngineInit();

	while (1)
	{
		EngineUpdate();
		EngineDraw();
	}
}

void FrogEngine_Print(char* _text)
{
	printf(_text);
}


