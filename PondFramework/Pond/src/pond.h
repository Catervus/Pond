#pragma once
#include "core/pond_includes.h"

#define _WIN32_WINNT 0x0500

#define Pond_GetArrayLength(Array) sizeof(Array)/sizeof(Array[0])

POND_API void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void));
POND_API void Pond_Run(int _fpscap, int _screenwidth, int _screenheight, char* _title, bool _showconsolewindow);

POND_API int Pond_Quit(void);

static void Cleanup(void);
static void (*ClientInit)(void);
static void (*ClientUpdate)(void);
static void (*ClientDraw)(void);

/// <summary>
/// Toggles if the Console Window is shown or not.
/// </summary>
/// <param name="_showconsole">- boolean value if Console Window should be shown or not</param>
POND_API void Pond_ToggleConsoleWindow(bool _showconsole);

// -----------------------------
// - SETTINGS -
// fps

// window settings

// POST BUILD COMMAND TO COPY SDL2.DLL
// xcopy /y "..\dependencies\SDL2\bin\x64\SDL2.dll" "$(OutDir)"

