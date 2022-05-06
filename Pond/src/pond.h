#pragma once
#include "core/pond_includes.h"

#define Pond_GetArraySize(Array) sizeof(Array)/sizeof(Array[0])

POND_API void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void));
POND_API void Pond_Run(int _fpscap, int _screenwidth, int _screenheight);

static void Cleanup(void);
static void (*ClientInit)(void);
static void (*ClientUpdate)(void);
static void (*ClientDraw)(void);

// -----------------------------
// - SETTINGS -
// fps

// window settings

// POST BUILD COMMAND TO COPY SDL2.DLL
// xcopy /y "..\dependencies\SDL2\bin\x64\SDL2.dll" "$(OutDir)"

