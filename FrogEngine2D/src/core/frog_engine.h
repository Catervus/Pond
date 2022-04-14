#pragma once
#include "core.h"
#include "includes.h"

FROGENGINE_API void FrogEngine_Init(void (*init)(), void (*update)(), void (draw)());
FROGENGINE_API void FrogEngine_Run(int _fps);

FROGENGINE_API void FrogEngine_Print(char* _text);
