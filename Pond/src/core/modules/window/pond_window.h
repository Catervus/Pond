#pragma once
#include "../../pond_extern_includes.h"
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_basic_structs.h"

typedef enum Pond_WindowMode
{
	POND_WINDOW_MODE_WINDOWED = 0,
	POND_WINDOW_MODE_FULLSCREEN,
	POND_WINDOW_MODE_FULLSCREEN_WINDOWED,

} Pond_WindowMode;

enum
{
	POND_WINDOW_POS_UNDEFINED = -2,
	POND_WINDOW_POS_CENTERED = -1,
};

// ------------------------------------------------------------------------------------------------
// Window Size

/// <summary>
/// Sets the Window's size to the passed values.
/// </summary>
/// <param name="_width">- value to set the Window's width to</param>
/// <param name="_height">- value to set the Window's height to</param>
/// <returns>1 if successful</returns>
POND_API int Pond_SetWindowSize(int _width, int _height);

/// <summary>
/// Returns the Window's current size as Pond_Vector2Int
/// </summary>
/// <returns> window's size as Pond_Vector2Int</returns>
POND_API Pond_Vector2Int Pond_GetWindowSize(void);

/// <summary>
/// Sets if the Window should be resizable or not.
/// </summary>
/// <param name="_flag">- true to make Window rezisable, false to make Window NOT rezisable</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_SetWindowResizable(bool _flag);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Mode

/// <summary>
/// Sets the Window Mode to passed Mode. (POND_WINDOW_MODE_WINDOWED, POND_WINDOW_MODE_FULLSCREEN or POND_WINDOW_MODE_FULLSCREEN_WINDOWED
/// </summary>
/// <param name="_windowmode">- mode to set Window Mode to</param>
/// <returns> 1 if successful, 0 if not</returns>
POND_API int Pond_SetWindowMode(Pond_WindowMode _windowmode); // X
POND_API Pond_WindowMode Pond_GetWindowMode(void);

/// <summary>
/// Minimizes the Window.
/// </summary>
/// <returns>1 if successful</returns>
POND_API int Pond_MinimizeWindow(void);

/// <summary>
/// Maximizes the Window.
/// </summary>
/// <returns>1 if successful</returns>
POND_API int Pond_MaximizeWindow(void);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Pos

POND_API int Pond_SetWindowPos(int _x, int _y);
POND_API Pond_Vector2Int Pond_GetWindowPos(void);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Title

POND_API int Pond_SetWindowTitle(char* _title);
POND_API char* Pond_GetWindowTitle(void);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Icon

POND_API int Pond_SetWindowIcon(void);

// ------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
// Window Border

POND_API int ToggleWindowBorder(bool _toggle);

// ------------------------------------------------------------------------------------------------
