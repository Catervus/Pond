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
/// Sets the window's size to the passed values.
/// </summary>
/// <param name="_width">- value to set the window's width to</param>
/// <param name="_height">- value to set the window's height to</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_SetWindowSize(int _width, int _height);

/// <summary>
/// Returns the window's current size as Pond_Vector2Int
/// </summary>
/// <returns> window's size as Pond_Vector2Int</returns>
POND_API Pond_Vector2Int Pond_GetWindowSize(void);

/// <summary>
/// Sets if the window should be resizable or not.
/// </summary>
/// <param name="_flag">- true to make window rezisable, false to make window NOT rezisable</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_SetWindowResizable(bool _flag);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Mode

/// <summary>
/// Sets the window mode to passed mode. (POND_WINDOW_MODE_WINDOWED, POND_WINDOW_MODE_FULLSCREEN or POND_WINDOW_MODE_FULLSCREEN_WINDOWED
/// </summary>
/// <param name="_windowmode">- mode to set window mode to</param>
/// <returns> 1 if successful, 0 if not</returns>
POND_API int Pond_SetWindowMode(Pond_WindowMode _windowmode); // X
POND_API Pond_WindowMode Pond_GetWindowMode(void);

/// <summary>
/// Minimizes the window.
/// </summary>
/// <returns>1 if successful</returns>
POND_API int Pond_MinimizeWindow(void);

/// <summary>
/// Maximizes the window.
/// </summary>
/// <returns>1 if successful</returns>
POND_API int Pond_MaximizeWindow(void);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Pos

/// <summary>
/// Sets the window's position on Screen to passed values.
/// Bounds of possible position are the combined bounds of all screens.
/// </summary>
/// <param name="_x">- the x pos to set the window's position to</param>
/// <param name="_y">- the x pos to set the window's position to</param>
/// <returns>1 if sucessful</returns>
POND_API int Pond_SetWindowPos(int _x, int _y);

/// <summary>
/// Gets the windows current position as Pond_Vector2Int.
/// </summary>
/// <returns> windows position</returns>
POND_API Pond_Vector2Int Pond_GetWindowPos(void);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Title

/// <summary>
/// Sets the window title to passed char-array.
/// </summary>
/// <param name="_title">- title to set the window title to</param>
/// <returns> 1 if sucessful</returns>
POND_API int Pond_SetWindowTitle(char* _title);

/// <summary>
/// Gets the current window title.
/// </summary>
/// <returns>- current window title as char pointer</returns>
POND_API char* Pond_GetWindowTitle(void);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Window Icon

POND_API int Pond_SetWindowIcon(void); // TODO: decide how to go about this, because SDL takes a Surface and I don't have that yet...

// ------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
// Window Border

/// <summary>
/// Sets if the window border should be visible or not to passed value.
/// </summary>
/// <param name="_toggle">- true to show border, false to hide border</param>
/// <returns> 1 if successful</returns>
POND_API int ToggleWindowBorder(bool _toggle);

// ------------------------------------------------------------------------------------------------
