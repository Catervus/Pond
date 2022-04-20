#pragma once
#include "core/pond_core.h"
#include "core/pond_extern_includes.h"
#include "core/pond_engine_includes.h"




POND_API void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void));
POND_API void Pond_Run(int _fps);

static void Cleanup(void);



static void (*EngineInit)(void);
static void (*EngineUpdate)(void);
static void (*EngineDraw)(void);

