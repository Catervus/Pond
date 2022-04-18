#pragma once
#include "core/pond_core.h"
#include "core/pond_includes.h"
#include "core/Modules/ConsoleOutput/pond_print.h"



POND_API void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void));
POND_API void Pond_Run(int _fps);




static void (*EngineInit)(void);
static void (*EngineUpdate)(void);
static void (*EngineDraw)(void);

