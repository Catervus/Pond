#include "pond_window.h"

#pragma region WINDOW_SIZE

/// <summary>
/// Sets the Window's size to the passed values.
/// </summary>
/// <param name="_width">- value to set the Window's width to</param>
/// <param name="_height">- value to set the Window's height to</param>
/// <returns>1 if successful</returns>
int Pond_SetWindowSize(int _width, int _height)
{
	SDL_SetWindowSize(app.p_window, _width, _height);

	return 1;
}

/// <summary>
/// Returns the Window's current size as Pond_Vector2Int
/// </summary>
/// <returns> window's size as Pond_Vector2Int</returns>
Pond_Vector2Int Pond_GetWindowSize(void)
{
	Pond_Vector2Int windowsize = { 0, 0 };

	SDL_GetWindowSize(app.p_window, &windowsize.x, &windowsize.y);

	return windowsize;
}

/// <summary>
/// Sets if the Window should be resizable or not.
/// </summary>
/// <param name="_flag">- true to make Window rezisable, false to make Window NOT rezisable</param>
/// <returns> 1 if successful</returns>
int Pond_SetWindowResizable(bool _flag)
{
	SDL_SetWindowResizable(app.p_window, _flag);

	return 1;
}

#pragma endregion

#pragma region WINDOW_MODE

/// <summary>
/// Sets the Window Mode to passed Mode. (POND_WINDOW_MODE_WINDOWED, POND_WINDOW_MODE_FULLSCREEN or POND_WINDOW_MODE_FULLSCREEN_WINDOWED
/// </summary>
/// <param name="_windowmode">- mode to set Window Mode to</param>
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

	return result == 0 ? 1 : 0; // convert SDL's return System into Pond's, in SDL 0 is success and negative value a failure
}

/// <summary>
/// Minimizes the Window.
/// </summary>
/// <returns>1 if successful</returns>
int Pond_MinimizeWindow(void)
{
	SDL_MinimizeWindow(app.p_window);
	return 1;
}

/// <summary>
/// Maximizes the Window.
/// </summary>
/// <returns>1 if successful</returns>
int Pond_MaximizeWindow(void)
{
	SDL_MaximizeWindow(app.p_window);
	return 1;
}
#pragma endregion

#pragma region WINDOW_POSITION

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

Pond_Vector2Int Pond_GetWindowPos(void)
{
	Pond_Vector2Int windowpos = { 0,0 };
	SDL_GetWindowPosition(app.p_window, &windowpos.x, &windowpos.y);

	return windowpos;
}
#pragma endregion

#pragma region WINDOW_MISC

int Pond_SetWindowTitle(char* _title)
{
	SDL_SetWindowTitle(app.p_window, _title);

	return 1;
}

char* Pond_GetWindowTitle(void)
{
	return SDL_GetWindowTitle(app.p_window);
}

int ToggleWindowBorder(bool _toggle)
{
	SDL_SetWindowBordered(app.p_window, _toggle);

	return 1;
}

#pragma endregion

