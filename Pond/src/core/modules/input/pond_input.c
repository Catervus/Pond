#include "pond_input.h"

static Pond_Vector2Int mousePosition;

int keyboardInputs[NUMBER_OF_KEYS];
int lastFrameKeyboardInputs[NUMBER_OF_KEYS];

int mouseButtonInputs[NUMBER_OF_MOUSE_BUTTONS];
int lastFrameMouseButtonInputs[NUMBER_OF_MOUSE_BUTTONS];

int InitInputSystem(void)
{
	for (int i = 0; i < NUMBER_OF_KEYS; i++)
	{
		lastFrameKeyboardInputs[i] = 0;
		keyboardInputs[i] = 0;
	}

	for (int i = 0; i < NUMBER_OF_MOUSE_BUTTONS; i++)
	{
		lastFrameMouseButtonInputs[i] = 0;
		mouseButtonInputs[i] = 0;
	}

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

	return 1;
}

int GatherSystemInput(void)
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		
		const Uint8* state = SDL_GetKeyboardState(NULL);

		for (int i = 0; i < NUMBER_OF_KEYS; i++)
		{
			if (state[i])
				keyboardInputs[i] = 1;
			else if (!state[i])
				keyboardInputs[i] = 0;
		}



		const Uint32 buttons = SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
		if (buttons & SDL_BUTTON_LMASK)
			mouseButtonInputs[POND_MOUSE_BUTTON_LEFT] = 1;
		else if(!(buttons & SDL_BUTTON_LMASK))
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

	return 1;
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

