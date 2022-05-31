#include "pond_window.h"

static Pond_WindowMode windowMode; // current window mode

#pragma region WINDOW_SIZE

/// <summary>
/// Sets the window's size to the passed values.
/// </summary>
/// <param name="_width">- value to set the window's width to</param>
/// <param name="_height">- value to set the window's height to</param>
/// <returns> 1 if successful</returns>
int Pond_SetWindowSize(int _width, int _height)
{
	SDL_SetWindowSize(app.p_window, _width, _height);

	return 1;
}

/// <summary>
/// Returns the window's current size as Pond_Vector2Int
/// </summary>
/// <returns> window's size as Pond_Vector2Int</returns>
Pond_Vector2Int Pond_GetWindowSize(void)
{
	Pond_Vector2Int windowsize = { 0, 0 };

	SDL_GetWindowSize(app.p_window, &windowsize.x, &windowsize.y);

	return windowsize;
}

/// <summary>
/// Sets if the window should be resizable or not.
/// </summary>
/// <param name="_flag">- true to make window rezisable, false to make window NOT rezisable</param>
/// <returns> 1 if successful</returns>
int Pond_SetWindowResizable(bool _flag)
{
	SDL_SetWindowResizable(app.p_window, _flag);

	return 1;
}

#pragma endregion

#pragma region WINDOW_MODE

/// <summary>
/// Sets the window mode to passed mode. (POND_WINDOW_MODE_WINDOWED, POND_WINDOW_MODE_FULLSCREEN or POND_WINDOW_MODE_FULLSCREEN_WINDOWED
/// </summary>
/// <param name="_windowmode">- mode to set window mode to</param>
/// <returns> 1 if successful, 0 if not</returns>
int Pond_SetWindowMode(Pond_WindowMode _windowmode)
{
	int result = -1;

	switch (_windowmode)
	{
		case POND_WINDOW_MODE_WINDOWED:
			result = SDL_SetWindowFullscreen(app.p_window, 0);
			break;
		case POND_WINDOW_MODE_FULLSCREEN:
			result = SDL_SetWindowFullscreen(app.p_window, SDL_WINDOW_FULLSCREEN);
			break;
		case POND_WINDOW_MODE_FULLSCREEN_WINDOWED:
			result = SDL_SetWindowFullscreen(app.p_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			break;
	}

	return result == 0 ? 1 : 0; // convertint SDL's return System into Pond's, in SDL 0 is success and negative value a failure
}

// TODO: Decide how to do this
Pond_WindowMode Pond_GetWindowMode(void)
{
	return windowMode;
}

/// <summary>
/// Minimizes the window.
/// </summary>
/// <returns>1 if successful</returns>
int Pond_MinimizeWindow(void)
{
	SDL_MinimizeWindow(app.p_window);
	return 1;
}

/// <summary>
/// Maximizes the window.
/// </summary>
/// <returns>1 if successful</returns>
int Pond_MaximizeWindow(void)
{
	SDL_MaximizeWindow(app.p_window);
	return 1;
}
#pragma endregion

#pragma region WINDOW_POSITION

/// <summary>
/// Sets the window's position on Screen to passed values.
/// Bounds of possible position are the combined bounds of all screens.
/// </summary>
/// <param name="_x">- the x pos to set the window's position to</param>
/// <param name="_y">- the x pos to set the window's position to</param>
/// <returns>1 if sucessful</returns>
int Pond_SetWindowPos(int _x, int _y)
{
	if (_x == POND_WINDOW_POS_CENTERED)
		_x = SDL_WINDOWPOS_CENTERED;
	else if (_x < -1)
		_x = SDL_WINDOWPOS_UNDEFINED;

	if (_y == POND_WINDOW_POS_CENTERED)
		_y = SDL_WINDOWPOS_CENTERED;
	else if (_x < -1)
		_x = SDL_WINDOWPOS_UNDEFINED;

	SDL_SetWindowPosition(app.p_window, _x, _y);

	return 1;
}

/// <summary>
/// Gets the windows current position as Pond_Vector2Int.
/// </summary>
/// <returns> windows position</returns>
Pond_Vector2Int Pond_GetWindowPos(void)
{
	Pond_Vector2Int windowpos = { 0,0 };
	SDL_GetWindowPosition(app.p_window, &windowpos.x, &windowpos.y);

	return windowpos;
}
#pragma endregion

#pragma region WINDOW_MISC

/// <summary>
/// Sets the window title to passed char-array.
/// </summary>
/// <param name="_title">- title to set the window title to</param>
/// <returns> 1 if sucessful</returns>
int Pond_SetWindowTitle(char* _title)
{
	SDL_SetWindowTitle(app.p_window, _title);

	return 1;
}

/// <summary>
/// Gets the current window title.
/// </summary>
/// <returns>- current window title as char pointer</returns>
char* Pond_GetWindowTitle(void)
{
	return SDL_GetWindowTitle(app.p_window);
}

/// <summary>
/// Sets if the window border should be visible or not to passed value.
/// </summary>
/// <param name="_toggle">- true to show border, false to hide border</param>
/// <returns> 1 if successful</returns>
int ToggleWindowBorder(bool _toggle)
{
	SDL_SetWindowBordered(app.p_window, _toggle);

	return 1;
}

#pragma endregion

