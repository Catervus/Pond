#pragma once
#include "../../pond_extern_includes.h"
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_basic_structs.h"

enum
{
	POND_WINDOW_MODE_WINDOWED = 0,
	POND_WINDOW_MODE_FULLSCREEN,
	POND_WINDOW_MODE_FULLSCREEN_WINDOWED,
};

POND_API int Pond_SetWindowSize(int _width, int _height);
POND_API Pond_Vector2Int Pond_GetWindowSize(void);
// POND_API int Pond_SetWindowPosition(void);
POND_API int Pond_SetWindowMode(int _windowmode);
