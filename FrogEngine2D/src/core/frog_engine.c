// For use by engine applications

#include "frog_engine.h"


void FrogEngine_Init(void (*_init)(), void (*_update)(), void (_draw)())
{
	engine.Init = _init;
	engine.Update = _update;
	engine.Draw = _draw;
}

void FrogEngine_Run(int _fps)
{
	engine.Init();

	while (1)
	{
		engine.Update();
		engine.Draw();
	}
}

void FrogEngine_Print(char* _text)
{
	printf(_text);
}