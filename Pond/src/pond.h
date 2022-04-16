#pragma once
#include "core/pond_core.h"
#include "core/pond_includes.h"



POND_API void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void));
POND_API void Pond_Run(int _fps);

POND_API void Pond_Print(char* _text);


static void (*EngineInit)(void);
static void (*EngineUpdate)(void);
static void (*EngineDraw)(void);

