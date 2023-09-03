#include "pond_input.h"

#pragma region Global_Variables
static Pond_Vector2Int mousePosition;

int keyboardInputs[NUMBER_OF_KEYS];
int lastFrameKeyboardInputs[NUMBER_OF_KEYS];

int mouseButtonInputs[NUMBER_OF_MOUSE_BUTTONS];
int lastFrameMouseButtonInputs[NUMBER_OF_MOUSE_BUTTONS];

Pond_Vector2Float joystickInputAxes[2];
unsigned int joystickDeadzone = POND_JOYSTICK_DEADZONE_DEFAULT;
double joystickAngles[2];
SDL_Joystick* p_joystick;
SDL_GameController* p_controller;
int controllerButtonInputs[POND_NUMBER_OF_CONTROLLER_BUTTONS];
int lastFrameControllerButtonInputs[POND_NUMBER_OF_CONTROLLER_BUTTONS];


bool mouseToggleState = true;

#pragma endregion

#pragma region Internal_Input_Gathering
int InitInputSystem(void)
{
	for (int i = 0; i < NUMBER_OF_KEYS; i++)
	{
		keyboardInputs[i] = 0;
		lastFrameKeyboardInputs[i] = 0;
	}

	for (int i = 0; i < NUMBER_OF_MOUSE_BUTTONS; i++)
	{
		mouseButtonInputs[i] = 0;
		lastFrameMouseButtonInputs[i] = 0;
	}

	for (int i = 0; i < POND_NUMBER_OF_CONTROLLER_BUTTONS; i++)
	{
		controllerButtonInputs[i] = 0;
		lastFrameControllerButtonInputs[i] = 0;
	}

	p_joystick = SDL_JoystickOpen(0);
	SDL_JoystickEventState(SDL_ENABLE);

	p_controller = SDL_GameControllerOpen(0);


	return 1;
}

int CloseInputSystem(void)
{
	SDL_JoystickClose(p_joystick);
	p_joystick = NULL;

	SDL_GameControllerClose(p_controller);
	p_controller = NULL;
}

int SaveInputs(void)
{
	for (int i = 0; i < NUMBER_OF_KEYS; i++)
	{
		lastFrameKeyboardInputs[i] = keyboardInputs[i];
	}

	for (int i = 0; i < NUMBER_OF_MOUSE_BUTTONS; i++)
	{
		lastFrameMouseButtonInputs[i] = mouseButtonInputs[i];
	}

	for (int i = 0; i < POND_NUMBER_OF_CONTROLLER_BUTTONS; i++)
	{
		lastFrameControllerButtonInputs[i] = controllerButtonInputs[i];
	}

	return 1;
}

int GatherSystemInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		GetKeyboardInputs();
		GetMouseInputs();
		switch (event.type)
		{
		case SDL_JOYAXISMOTION:
			if (event.jaxis.axis == 0)
			{
				if ((event.jaxis.value < (Sint16)-joystickDeadzone))
				{
					joystickInputAxes[0].x = ((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[0].x < -1)
						joystickInputAxes[0].x = -1;
				}
				else if (event.jaxis.value > (Sint16)joystickDeadzone)
				{
					joystickInputAxes[0].x = ((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[0].x > 1)
						joystickInputAxes[0].x = 1;
				}
				else
					joystickInputAxes[0].x = 0;
			}
			if (event.jaxis.axis == 1)
			{
				if ((event.jaxis.value < (Sint16)-joystickDeadzone))
				{
					joystickInputAxes[0].y = -((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[0].y > 1)
						joystickInputAxes[0].y = 1;
				}
				else if (event.jaxis.value > (Sint16)joystickDeadzone)
				{
					joystickInputAxes[0].y = -((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[0].y < -1)
						joystickInputAxes[0].y = -1;
				}
				else
					joystickInputAxes[0].y = 0;
			}
			// secondary (right) stick on controller
			if (event.jaxis.axis == 2)
			{
				if ((event.jaxis.value < (Sint16)-joystickDeadzone))
				{
					joystickInputAxes[1].x = ((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[1].x < -1)
						joystickInputAxes[1].x = -1;
				}
				else if (event.jaxis.value > (Sint16)joystickDeadzone)
				{
					joystickInputAxes[1].x = ((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[1].x > 1)
						joystickInputAxes[1].x = 1;
				}
				else
					joystickInputAxes[1].x = 0;
			}
			if (event.jaxis.axis == 3)
			{
				if ((event.jaxis.value < (Sint16)-joystickDeadzone))
				{
					joystickInputAxes[1].y = -((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[1].y > 1)
						joystickInputAxes[1].y = 1;
				}
				else if (event.jaxis.value > (Sint16)joystickDeadzone)
				{
					joystickInputAxes[1].y = -((double)event.jaxis.value / (double)POND_JOYSTICK_DEADZONE_MAX);
					if (joystickInputAxes[1].y < -1)
						joystickInputAxes[1].y = -1;
				}
				else
					joystickInputAxes[1].y = 0;
			}

			break;

		}
		if (event.type == SDL_QUIT)
			exit(1);


		GetControllerButtonInputs();
	}

	joystickAngles[0] = atan2((double)-joystickInputAxes[0].y, (double)joystickInputAxes[0].x) * (180.0 / M_PI) + 90.0;
	if (joystickInputAxes[0].x == 0 && joystickInputAxes[0].y == 0)
		joystickAngles[0] = 0;

	joystickAngles[1] = atan2((double)-joystickInputAxes[1].y, (double)joystickInputAxes[1].x) * (180.0 / M_PI) + 90.0;
	if (joystickInputAxes[1].x == 0 && joystickInputAxes[1].y == 0)
		joystickAngles[1] = 0;

	return 1;
}

int GetControllerButtonInputs(void)
{
	for (int i = 0; i < POND_NUMBER_OF_CONTROLLER_BUTTONS; i++)
	{
		controllerButtonInputs[i] = SDL_GameControllerGetButton(p_controller, i);
	}
	return 1;
}

int GetKeyboardInputs(void)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < NUMBER_OF_KEYS; i++)
	{
		if (state[i])
			keyboardInputs[i] = 1;
		else if (!state[i])
			keyboardInputs[i] = 0;
	}
}

int GetMouseInputs(void)
{
	const Uint32 buttons = SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
	if (buttons & SDL_BUTTON_LMASK)
		mouseButtonInputs[POND_MOUSE_BUTTON_LEFT] = 1;
	else if (!(buttons & SDL_BUTTON_LMASK))
		mouseButtonInputs[POND_MOUSE_BUTTON_LEFT] = 0;

	if (buttons & SDL_BUTTON_RMASK)
		mouseButtonInputs[POND_MOUSE_BUTTON_RIGHT] = 1;
	else if (!(buttons & SDL_BUTTON_RMASK))
		mouseButtonInputs[POND_MOUSE_BUTTON_RIGHT] = 0;

	if (buttons & SDL_BUTTON_MMASK)
		mouseButtonInputs[POND_MOUSE_BUTTON_MIDDLE] = 1;
	else if (!(buttons & SDL_BUTTON_MMASK))
		mouseButtonInputs[POND_MOUSE_BUTTON_MIDDLE] = 0;

	if (buttons & SDL_BUTTON_X1MASK)
		mouseButtonInputs[POND_MOUSE_BUTTON_X1] = 1;
	else if (!(buttons & SDL_BUTTON_X1MASK))
		mouseButtonInputs[POND_MOUSE_BUTTON_X1] = 0;

	if (buttons & SDL_BUTTON_X2MASK)
		mouseButtonInputs[POND_MOUSE_BUTTON_X2] = 1;
	else if (!(buttons & SDL_BUTTON_X2MASK))
		mouseButtonInputs[POND_MOUSE_BUTTON_X2] = 0;
}
#pragma endregion

#pragma region Joystick

/// <summary>
/// Gets the angle of joystick with passed index in degrees where 0° is up, 90° right, 180° down and 270° left.
/// </summary>
/// <param name="_index">- the index of the joystick (POND_JOYSTICK_INDEX_MAIN or POND_JOYSTICK_INDEX_SECONDARY)</param>
/// <returns>angle of joystick in degrees</returns>
double Pond_GetJoyStickAngle(Pond_JoystickIndex _index)
{
	return joystickAngles[_index];
}

/// <summary>
/// Gets the current position of joystick with passed index as a Pond_Vector2Float. 
/// Returns for example {0.5, 0.75}.
/// </summary>
/// <param name="_index">- the index of the joystick (POND_JOYSTICK_INDEX_MAIN or POND_JOYSTICK_INDEX_SECONDARY)</param>
/// <returns> the current joystick's axis position</returns>
Pond_Vector2Float Pond_GetJoystickAxisVector(Pond_JoystickIndex _index)
{
	return joystickInputAxes[_index];
}

/// <summary>
/// Gets the current input (-1 to 1) on passed axis of joystick with passed index.
/// </summary>
/// <param name="_axis">- the axis to get the input from (POND_JOYSTICK_AXIS_X or POND_JOYSTICK_AXIS_Y)</param>
/// <param name="_index">- the index of the joystick (POND_JOYSTICK_INDEX_MAIN for left Joystick or POND_JOYSTICK_INDEX_SECONDARY for right Joystick)</param>
/// <returns> the input of joystick on axis between -1 and 1</returns>
float Pond_GetJoystickAxisValue(Pond_JoystickAxis _axis, Pond_JoystickIndex _index)
{
	if (_axis == POND_JOYSTICK_AXIS_X)
		return joystickInputAxes[_index].x;
	else if (_axis == POND_JOYSTICK_AXIS_Y)
		return joystickInputAxes[_index].y;

	return 0;
}

/// <summary>
/// Sets the current joystick deadzone value. Any input less than the deadzone value is not registered. Min for deadzone value is 0, max is 32767 (POND_JOYSTICK_DEADZONE_MAX).
/// </summary>
/// <param name="_value">- value to set deadzone value to</param>
/// <returns> 1 if successful</returns>
int Pond_SetJoystickDeadzoneValue(unsigned int _value)
{
	if (_value > POND_JOYSTICK_DEADZONE_MAX)
		_value = POND_JOYSTICK_DEADZONE_MAX;

	joystickDeadzone = _value;
	return 1;
}

/// <summary>
/// Gets the current joystick deadzone value.
/// </summary>
/// <returns> current joystick deadzone value</returns>
unsigned int Pond_GetJoystickDeadzoneValue(void)
{
	return joystickDeadzone;
}
#pragma endregion

#pragma region Input_Presses

/// <summary>
/// Checks if passed Keyboard Key is currently pressed or not.
/// </summary>
/// <param name="_key">- the Keyboard Key to check</param>
/// <returns> true if Key is pressed, false if not</returns>
bool Pond_GetKey(Pond_KeyboardKey _key)
{
	if (keyboardInputs[_key])
		return true;

	return false;
}

/// <summary>
/// Checks if passed Keyboard Key has been pressed down.
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_key">- the Keyboard Key to check</param>
/// <returns> true if Key is pressed down, false if not or when continuously pressing down</returns>
bool Pond_GetKeyDown(Pond_KeyboardKey _key)
{
	if (keyboardInputs[_key] && !lastFrameKeyboardInputs[_key])
		return true;

	return false;
}

/// <summary>
/// Checks if passed Keyboard Key has been released.
/// </summary>
/// <param name="_key">- the Keyboard Key to check</param>
/// <returns> true if Key has been released, false if not or if it has not been pressed</returns>
bool Pond_GetKeyUp(Pond_KeyboardKey _key)
{
	if (!keyboardInputs[_key] && lastFrameKeyboardInputs[_key])
		return true;

	return false;
}

/// <summary>
/// Checks if passed mouse button is currently pressed or not.
/// </summary>
/// <param name="_button">- the mouse button to check</param>
/// <returns> true if button is pressed, false if not</returns>
bool Pond_GetMouseButton(Pond_MouseButton _button)
{
	if (mouseButtonInputs[_button])
		return true;

	return false;
}

/// <summary>
/// Checks if passed mouse button has been pressed down.
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_button">- the mouse button to check</param>
/// <returns> true if button is pressed down, false if not or when continuously pressing down</returns>
bool Pond_GetMouseButtonDown(Pond_MouseButton _button)
{
	if (mouseButtonInputs[_button] && !lastFrameMouseButtonInputs[_button])
		return true;

	return false;
}

/// <summary>
/// Checks if passed mouse button has been released.
/// </summary>
/// <param name="_button">- the mouse button to check</param>
/// <returns> true if button has been released, false if not or if it has not been pressed</returns>
bool Pond_GetMouseButtonUp(Pond_MouseButton _button)
{
	if (!mouseButtonInputs[_button] && lastFrameMouseButtonInputs[_button])
		return true;

	return false;
}

/// <summary>
/// Checks if passed controller button is currently pressed or not.
/// </summary>
/// <param name="_button">- the controller button to check</param>
/// <returns> true if button is pressed, false if not</returns>
bool Pond_GetControllerButton(Pond_ControllerButton _button)
{
	return controllerButtonInputs[_button];
}

/// <summary>
/// Checks if passed controller button has been pressed down.
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_button">- the controller button to check</param>
/// <returns> true if button is pressed down, false if not or when continuously pressing down</returns>
bool Pond_GetControllerButtonDown(Pond_ControllerButton _button)
{
	if (controllerButtonInputs[_button] && !lastFrameControllerButtonInputs[_button])
		return true;

	return false;
}

/// <summary>
/// Checks if passed controller button has been released.
/// </summary>
/// <param name="_button">- the controller button to check</param>
/// <returns> true if button has been released, false if not or if it has not been pressed</returns>
bool Pond_GetControllerButtonUp(Pond_ControllerButton _button)
{
	if (!controllerButtonInputs[_button] && lastFrameControllerButtonInputs[_button])
		return true;

	return false;
}
#pragma endregion

#pragma region Mouse

/// <summary>
/// Gets the current mouse position relative to the game window.
/// </summary>
/// <returns>returns mouse position as Pond_Vector2Int</returns>
Pond_Vector2Int Pond_GetMousePosition(void)
{
	SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
	return mousePosition;
}

/// <summary>
/// Gets the current mouse position relative to the desktop's top-left corner.
/// (This function is less efficient than Pond_GetMousePosition)
/// </summary>
/// <returns> mouse position as Pond_Vector2Int</returns>
Pond_Vector2Int Pond_GetMousePositionDesktop(void)
{
	Pond_Vector2Int pos = { 0, 0 };
	SDL_GetGlobalMouseState(&pos.x, &pos.y);
	return pos;
}

/// <summary>
/// Sets mouse position to passed coordinates relative to the game window.
/// </summary>
/// <param name="_x">- the x coordinate to set the mouse position to</param>
/// <param name="_y">- the y coordinate to set the mouse position to</param>
/// <returns>1 if successful</returns>
int Pond_SetMousePosition(int _x, int _y)
{
	SDL_WarpMouseInWindow(app.p_window, _x, _y);

	return 1;
}

/// <summary>
/// Sets mouse position to passed coordinates relative to the current desktop.
/// </summary>
/// <param name="_x">- the x coordinate to set the mouse position to</param>
/// <param name="_y">- the y coordinate to set the mouse position to</param>
/// <returns>1 if successful</returns>
int Pond_SetMousePositionDesktop(int _x, int _y)
{
	SDL_WarpMouseGlobal(_x, _y);

	return 1;
}

/// <summary>
/// Toggles the cursor by passed value.
/// If passed true the cursor is shown, if false the cursor is hidden.
/// </summary>
/// <param name="_toggle">- the boolean value deciding to set the cursor on or off</param>
/// <returns>1 if successful</returns>
int Pond_ToggleCursor(bool _toggle)
{
	if (_toggle > 0)
		_toggle = 1;
	mouseToggleState = _toggle;

	SDL_ShowCursor(mouseToggleState);
	
	return 1;
}

/// <summary>
/// Gets the cursor's toggle state.
/// True means the cursor is showing, false means the cursor is hiding.
/// The default is true.
/// </summary>
/// <returns>if cursor is on or off</returns>
bool Pond_GetCursorToggleState(void)
{
	return mouseToggleState;
}


#pragma endregion

#pragma region Controller

/// <summary>
/// Returns the number of controller registered.
/// </summary>
/// <returns> number of registered controllers</returns>
POND_API int Pond_GetNumberOfControllers(void) 
{
	return SDL_NumJoysticks();
}

/// <summary>
/// When called gives feedback via controller rumble.
/// Any successful call to this function will stop the current rumble effect.
/// Calling this function with 0 intensity stops the current rumble effect.
/// </summary>
/// <param name="_msduration">- the amount of time to rumble in Milliseconds (ms), min is 0 and max is 500</param>
/// <param name="_lowfrequenceintensity">- the intensity of the low frequence rumble, min is 0 and max is 100</param>
/// <param name="_highfrequenceintensity">- the intensity of the high frequence rumble, min is 0 and max is 100</param>
/// <returns> 1 if successful, 0 if not</returns>
int Pond_ControllerRumble(int _msduration, float _lowfrequenceintensity, int _highfrequenceintensity)
{
	if (_msduration > 500)
		_msduration = 500;
	else if (_msduration < 0)
		_msduration = 0;

	if (_lowfrequenceintensity > 100)
		_lowfrequenceintensity = 100;
	else if (_lowfrequenceintensity < 0)
		_lowfrequenceintensity = 0;

	if (_highfrequenceintensity > 100)
		_highfrequenceintensity = 100;
	else if (_highfrequenceintensity < 0)
		_highfrequenceintensity = 0;

	float l = (float)_lowfrequenceintensity / 100;
	float h = (float)_highfrequenceintensity / 100;

	Uint16 lstrength = l * 0xFFFF;
	Uint16 hstrength = h * 0xFFFF;

	if (p_controller)
	{
		if (SDL_GameControllerRumble(p_controller, lstrength, hstrength, _msduration) == 0)
			return 1;
	}
	else
	{
		if (SDL_JoystickRumble(p_joystick, lstrength, hstrength, _msduration) == 0)
			return 1;
	}

	return 0;
}
#pragma endregion



