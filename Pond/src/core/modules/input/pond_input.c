#include "pond_input.h"

static Pond_Vector2Int mousePosition;

int keyboardInputs[NUMBER_OF_KEYS];
int lastFrameKeyboardInputs[NUMBER_OF_KEYS];

int mouseButtonInputs[NUMBER_OF_MOUSE_BUTTONS];
int lastFrameMouseButtonInputs[NUMBER_OF_MOUSE_BUTTONS];

// Pond_Vector2Float joystickInputAxis = { 0.0, 0.0 };
Pond_Vector2Float joystickInputAxes[2];
unsigned int joystickDeadzone = POND_JOYSTICK_DEADZONE_DEFAULT;
// double joystickAngle;
double joystickAngles[2];
SDL_GameController* p_controller;
int controllerButtonInputs[POND_NUMBER_OF_CONTROLLER_BUTTONS];
int lastFrameControllerButtonInputs[POND_NUMBER_OF_CONTROLLER_BUTTONS];

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

	printf("%i joysticks were found:\n", SDL_NumJoysticks());

	SDL_Joystick* p_joystick;
	SDL_JoystickEventState(SDL_ENABLE);
	p_joystick = SDL_JoystickOpen(0);

	p_controller = SDL_GameControllerOpen(0);

	return 1;
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
		GetJoystickInputs();
	}

	joystickAngles[0] = atan2((double)-joystickInputAxes[0].y, (double)joystickInputAxes[0].x) * (180.0 / M_PI) + 90.0;
	if (joystickInputAxes[0].x == 0 && joystickInputAxes[0].y == 0)
		joystickAngles[0] = 0;

	joystickAngles[1] = atan2((double)-joystickInputAxes[1].y, (double)joystickInputAxes[1].x) * (180.0 / M_PI) + 90.0;
	if (joystickInputAxes[1].x == 0 && joystickInputAxes[1].y == 0)
		joystickAngles[1] = 0;

	return 1;
}

int GetJoystickInputs(void)
{
	for (int i = 0; i < POND_NUMBER_OF_CONTROLLER_BUTTONS; i++)
	{
		controllerButtonInputs[i] = SDL_GameControllerGetButton(p_controller, i);
		
	}

	return 1;
}

double Pond_GetJoyStickAngle(Pond_JoystickIndex _index)
{
	return joystickAngles[_index];
}

Pond_Vector2Float Pond_GetJoystickAxisVector(Pond_JoystickIndex _index)
{
	return joystickInputAxes[_index];
}

float Pond_GetJoystickAxis(Pond_JoystickAxis _axis, Pond_JoystickIndex _index)
{
	if (_axis == POND_JOYSTICK_AXIS_X)
		return joystickInputAxes[_index].x;
	else if (_axis == POND_JOYSTICK_AXIS_Y)
		return joystickInputAxes[_index].y;

	return 0;
}

int Pond_SetJoystickDeadzoneValue(unsigned int _value)
{
	if (_value > POND_JOYSTICK_DEADZONE_MAX)
		_value = POND_JOYSTICK_DEADZONE_MAX;

	joystickDeadzone = _value;
	return 1;
}

unsigned int Pond_GetJoystickDeadzoneValue(void)
{
	return joystickDeadzone;
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

bool Pond_GetKey(Pond_KeyboardKey _key)
{
	if (keyboardInputs[_key])
		return true;

	return false;
}

bool Pond_GetKeyDown(Pond_KeyboardKey _key)
{
	if (keyboardInputs[_key] && !lastFrameKeyboardInputs[_key])
		return true;

	return false;
}

bool Pond_GetKeyUp(Pond_KeyboardKey _key)
{
	if (!keyboardInputs[_key] && lastFrameKeyboardInputs[_key])
		return true;

	return false;
}

bool Pond_GetMouseButton(Pond_MouseButton _button)
{
	if (mouseButtonInputs[_button])
		return true;

	return false;
}

bool Pond_GetMouseButtonDown(Pond_MouseButton _button)
{
	if (mouseButtonInputs[_button] && !lastFrameMouseButtonInputs[_button])
		return true;

	return false;
}

bool Pond_GetMouseButtonUp(Pond_MouseButton _button)
{
	if (!mouseButtonInputs[_button] && lastFrameMouseButtonInputs[_button])
		return true;

	return false;
}

Pond_Vector2Int Pond_GetMousePosition(void)
{
	SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
	return mousePosition;
}

bool Pond_GetControllerButton(Pond_ControllerButton _button)
{
	return controllerButtonInputs[_button];
}

bool Pond_GetControllerButtonDown(Pond_ControllerButton _button)
{
	if (controllerButtonInputs[_button] && !lastFrameControllerButtonInputs[_button])
		return true;

	return false;
}
bool Pond_GetControllerButtonUp(Pond_ControllerButton _button)
{
	if (!controllerButtonInputs[_button] && lastFrameControllerButtonInputs[_button])
		return true;

	return false;
}

