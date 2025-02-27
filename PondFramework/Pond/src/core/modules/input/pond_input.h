#pragma once
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_basic_structs.h"
#include "../../pond_extern_includes.h"
#include <SDL_gamecontroller.h>

#define NUMBER_OF_KEYS 283
#define NUMBER_OF_MOUSE_BUTTONS 5
#define POND_NUMBER_OF_CONTROLLER_BUTTONS 22

#define POND_JOYSTICK_DEADZONE_DEFAULT 8000
#define POND_JOYSTICK_DEADZONE_MAX 32767.0

#define POND_CONTROLLER_RUMBLE_INTENSITY_MAX 100
#define POND_CONTROLLER_RUMBLE_DURATIN_MAX 500

typedef enum Pond_KeyboardKey
{
	POND_KEYBOARD_KEY_UNKNOWN_0 = 0,
	POND_KEYBOARD_KEY_UNKNOWN_1 = 1,
	POND_KEYBOARD_KEY_UNKNOWN_2 = 2,
	POND_KEYBOARD_KEY_UNKNOWN_3 = 3,
		 
	POND_KEYBOARD_KEY_A = 4,
	POND_KEYBOARD_KEY_B = 5,
	POND_KEYBOARD_KEY_C = 6,
	POND_KEYBOARD_KEY_D = 7,
	POND_KEYBOARD_KEY_E = 8,
	POND_KEYBOARD_KEY_F = 9,
	POND_KEYBOARD_KEY_G = 10,
	POND_KEYBOARD_KEY_H = 11,
	POND_KEYBOARD_KEY_I = 12,
	POND_KEYBOARD_KEY_J = 13,
	POND_KEYBOARD_KEY_K = 14,
	POND_KEYBOARD_KEY_L = 15,
	POND_KEYBOARD_KEY_M = 16,
	POND_KEYBOARD_KEY_N = 17,
	POND_KEYBOARD_KEY_O = 18,
	POND_KEYBOARD_KEY_P = 19,
	POND_KEYBOARD_KEY_Q = 20,
	POND_KEYBOARD_KEY_R = 21,
	POND_KEYBOARD_KEY_S = 22,
	POND_KEYBOARD_KEY_T = 23,
	POND_KEYBOARD_KEY_U = 24,
	POND_KEYBOARD_KEY_V = 25,
	POND_KEYBOARD_KEY_W = 26,
	POND_KEYBOARD_KEY_X = 27,
	POND_KEYBOARD_KEY_Y = 28,
	POND_KEYBOARD_KEY_Z = 29,
		 
	POND_KEYBOARD_KEY_1 = 30,
	POND_KEYBOARD_KEY_2 = 31,
	POND_KEYBOARD_KEY_3 = 32,
	POND_KEYBOARD_KEY_4 = 33,
	POND_KEYBOARD_KEY_5 = 34,
	POND_KEYBOARD_KEY_6 = 35,
	POND_KEYBOARD_KEY_7 = 36,
	POND_KEYBOARD_KEY_8 = 37,
	POND_KEYBOARD_KEY_9 = 38,
	POND_KEYBOARD_KEY_0 = 39,
		 
	POND_KEYBOARD_KEY_RETURN = 40,
	POND_KEYBOARD_KEY_ESCAPE = 41,
	POND_KEYBOARD_KEY_BACKSPACE = 42,
	POND_KEYBOARD_KEY_TAB = 43,
	POND_KEYBOARD_KEY_SPACE = 44,
		 
	POND_KEYBOARD_KEY_MINUS = 45,
	POND_KEYBOARD_KEY_EQUALS = 46,
	POND_KEYBOARD_KEY_LEFTBRACKET = 47,
	POND_KEYBOARD_KEY_RIGHTBRACKET = 48,
	POND_KEYBOARD_KEY_BACKSLASH = 49,
	POND_KEYBOARD_KEY_NONUSHASH = 50,
	POND_KEYBOARD_KEY_SEMICOLON = 51,
	POND_KEYBOARD_KEY_APOSTROPHE = 52,
	POND_KEYBOARD_KEY_GRAVE = 53,
	POND_KEYBOARD_KEY_COMMA = 54,
	POND_KEYBOARD_KEY_PERIOD = 55,
	POND_KEYBOARD_KEY_SLASH = 56,
		 
	POND_KEYBOARD_KEY_CAPSLOCK = 57,
		 
	POND_KEYBOARD_KEY_F1 = 58,
	POND_KEYBOARD_KEY_F2 = 59,
	POND_KEYBOARD_KEY_F3 = 60,
	POND_KEYBOARD_KEY_F4 = 61,
	POND_KEYBOARD_KEY_F5 = 62,
	POND_KEYBOARD_KEY_F6 = 63,
	POND_KEYBOARD_KEY_F7 = 64,
	POND_KEYBOARD_KEY_F8 = 65,
	POND_KEYBOARD_KEY_F9 = 66,
	POND_KEYBOARD_KEY_F10 = 67,
	POND_KEYBOARD_KEY_F11 = 68,
	POND_KEYBOARD_KEY_F12 = 69,
		 
	POND_KEYBOARD_KEY_PRINTSCREEN = 70,
	POND_KEYBOARD_KEY_SCROLLLOCK = 71,
	POND_KEYBOARD_KEY_PAUSE = 72,
	POND_KEYBOARD_KEY_INSERT = 73,
	POND_KEYBOARD_KEY_HOME = 74,
	POND_KEYBOARD_KEY_PAGEUP = 75,
	POND_KEYBOARD_KEY_DELETE = 76,
	POND_KEYBOARD_KEY_END = 77,
	POND_KEYBOARD_KEY_PAGEDOWN = 78,
	POND_KEYBOARD_KEY_RIGHT = 79,
	POND_KEYBOARD_KEY_LEFT = 80,
	POND_KEYBOARD_KEY_DOWN = 81,
	POND_KEYBOARD_KEY_UP = 82,
		 
	POND_KEYBOARD_KEY_NUMLOCKCLEAR = 83,
	POND_KEYBOARD_KEY_KP_DIVIDE = 84,
	POND_KEYBOARD_KEY_KP_MULTIPLY = 85,
	POND_KEYBOARD_KEY_KP_MINUS = 86,
	POND_KEYBOARD_KEY_KP_PLUS = 87,
	POND_KEYBOARD_KEY_KP_ENTER = 88,
	POND_KEYBOARD_KEY_KP_1 = 89,
	POND_KEYBOARD_KEY_KP_2 = 90,
	POND_KEYBOARD_KEY_KP_3 = 91,
	POND_KEYBOARD_KEY_KP_4 = 92,
	POND_KEYBOARD_KEY_KP_5 = 93,
	POND_KEYBOARD_KEY_KP_6 = 94,
	POND_KEYBOARD_KEY_KP_7 = 95,
	POND_KEYBOARD_KEY_KP_8 = 96,
	POND_KEYBOARD_KEY_KP_9 = 97,
	POND_KEYBOARD_KEY_KP_0 = 98,
	POND_KEYBOARD_KEY_KP_PERIOD = 99,
		 
	POND_KEYBOARD_KEY_NONUSBACKSLASH = 100,
	POND_KEYBOARD_KEY_APPLICATION = 101,
	POND_KEYBOARD_KEY_POWER = 102,
	POND_KEYBOARD_KEY_KP_EQUALS = 103,
	POND_KEYBOARD_KEY_F13 = 104,
	POND_KEYBOARD_KEY_F14 = 105,
	POND_KEYBOARD_KEY_F15 = 106,
	POND_KEYBOARD_KEY_F16 = 107,
	POND_KEYBOARD_KEY_F17 = 108,
	POND_KEYBOARD_KEY_F18 = 109,
	POND_KEYBOARD_KEY_F19 = 110,
	POND_KEYBOARD_KEY_F20 = 111,
	POND_KEYBOARD_KEY_F21 = 112,
	POND_KEYBOARD_KEY_F22 = 113,
	POND_KEYBOARD_KEY_F23 = 114,
	POND_KEYBOARD_KEY_F24 = 115,
	POND_KEYBOARD_KEY_EXECUTE = 116,
	POND_KEYBOARD_KEY_HELP = 117,
	POND_KEYBOARD_KEY_MENU = 118,
	POND_KEYBOARD_KEY_SELECT = 119,
	POND_KEYBOARD_KEY_STOP = 120,
	POND_KEYBOARD_KEY_AGAIN = 121,
	POND_KEYBOARD_KEY_UNDO = 122,
	POND_KEYBOARD_KEY_CUT = 123,
	POND_KEYBOARD_KEY_COPY = 124,
	POND_KEYBOARD_KEY_PASTE = 125,
	POND_KEYBOARD_KEY_FIND = 126,
	POND_KEYBOARD_KEY_MUTE = 127,
	POND_KEYBOARD_KEY_VOLUMEUP = 128,
	POND_KEYBOARD_KEY_VOLUMEDOWN = 129,
		 
	POND_KEYBOARD_KEY_LOCKINGCAPSLOCK = 130,
	POND_KEYBOARD_KEY_LOCKINGNUMLOCK = 131,
	POND_KEYBOARD_KEY_LOCKINGSCROLLLOCK = 132,
		 
	POND_KEYBOARD_KEY_KP_COMMA = 133,
	POND_KEYBOARD_KEY_KP_EQUALSAS400 = 134,
		 
	POND_KEYBOARD_KEY_INTERNATIONAL1 = 135,
		 
	POND_KEYBOARD_KEY_INTERNATIONAL2 = 136,
	POND_KEYBOARD_KEY_INTERNATIONAL3 = 137,
	POND_KEYBOARD_KEY_INTERNATIONAL4 = 138,
	POND_KEYBOARD_KEY_INTERNATIONAL5 = 139,
	POND_KEYBOARD_KEY_INTERNATIONAL6 = 140,
	POND_KEYBOARD_KEY_INTERNATIONAL7 = 141,
	POND_KEYBOARD_KEY_INTERNATIONAL8 = 142,
	POND_KEYBOARD_KEY_INTERNATIONAL9 = 143,
	POND_KEYBOARD_KEY_LANG1 = 144,
	POND_KEYBOARD_KEY_LANG2 = 145,
	POND_KEYBOARD_KEY_LANG3 = 146,
	POND_KEYBOARD_KEY_LANG4 = 147,
	POND_KEYBOARD_KEY_LANG5 = 148,
	POND_KEYBOARD_KEY_LANG6 = 149,
	POND_KEYBOARD_KEY_LANG7 = 150,
	POND_KEYBOARD_KEY_LANG8 = 151,
	POND_KEYBOARD_KEY_LANG9 = 152,
		 
	POND_KEYBOARD_KEY_ALTERASE = 153,
	POND_KEYBOARD_KEY_SYSREQ = 154,
	POND_KEYBOARD_KEY_CANCEL = 155,
	POND_KEYBOARD_KEY_CLEAR = 156,
	POND_KEYBOARD_KEY_PRIOR = 157,
	POND_KEYBOARD_KEY_RETURN2 = 158,
	POND_KEYBOARD_KEY_SEPARATOR = 159,
	POND_KEYBOARD_KEY_OUT = 160,
	POND_KEYBOARD_KEY_OPER = 161,
	POND_KEYBOARD_KEY_CLEARAGAIN = 162,
	POND_KEYBOARD_KEY_CRSEL = 163,
	POND_KEYBOARD_KEY_EXSEL = 164,
		 
	POND_KEYBOARD_KEY_KP_00 = 176,
	POND_KEYBOARD_KEY_KP_000 = 177,
	POND_KEYBOARD_KEY_THOUSANDSSEPARATOR = 178,
	POND_KEYBOARD_KEY_DECIMALSEPARATOR = 179,
	POND_KEYBOARD_KEY_CURRENCYUNIT = 180,
	POND_KEYBOARD_KEY_CURRENCYSUBUNIT = 181,
	POND_KEYBOARD_KEY_KP_LEFTPAREN = 182,
	POND_KEYBOARD_KEY_KP_RIGHTPAREN = 183,
	POND_KEYBOARD_KEY_KP_LEFTBRACE = 184,
	POND_KEYBOARD_KEY_KP_RIGHTBRACE = 185,
	POND_KEYBOARD_KEY_KP_TAB = 186,
	POND_KEYBOARD_KEY_KP_BACKSPACE = 187,
	POND_KEYBOARD_KEY_KP_A = 188,
	POND_KEYBOARD_KEY_KP_B = 189,
	POND_KEYBOARD_KEY_KP_C = 190,
	POND_KEYBOARD_KEY_KP_D = 191,
	POND_KEYBOARD_KEY_KP_E = 192,
	POND_KEYBOARD_KEY_KP_F = 193,
	POND_KEYBOARD_KEY_KP_XOR = 194,
	POND_KEYBOARD_KEY_KP_POWER = 195,
	POND_KEYBOARD_KEY_KP_PERCENT = 196,
	POND_KEYBOARD_KEY_KP_LESS = 197,
	POND_KEYBOARD_KEY_KP_GREATER = 198,
	POND_KEYBOARD_KEY_KP_AMPERSAND = 199,
	POND_KEYBOARD_KEY_KP_DBLAMPERSAND = 200,
	POND_KEYBOARD_KEY_KP_VERTICALBAR = 201,
	POND_KEYBOARD_KEY_KP_DBLVERTICALBAR = 202,
	POND_KEYBOARD_KEY_KP_COLON = 203,
	POND_KEYBOARD_KEY_KP_HASH = 204,
	POND_KEYBOARD_KEY_KP_SPACE = 205,
	POND_KEYBOARD_KEY_KP_AT = 206,
	POND_KEYBOARD_KEY_KP_EXCLAM = 207,
	POND_KEYBOARD_KEY_KP_MEMSTORE = 208,
	POND_KEYBOARD_KEY_KP_MEMRECALL = 209,
	POND_KEYBOARD_KEY_KP_MEMCLEAR = 210,
	POND_KEYBOARD_KEY_KP_MEMADD = 211,
	POND_KEYBOARD_KEY_KP_MEMSUBTRACT = 212,
	POND_KEYBOARD_KEY_KP_MEMMULTIPLY = 213,
	POND_KEYBOARD_KEY_KP_MEMDIVIDE = 214,
	POND_KEYBOARD_KEY_KP_PLUSMINUS = 215,
	POND_KEYBOARD_KEY_KP_CLEAR = 216,
	POND_KEYBOARD_KEY_KP_CLEARENTRY = 217,
	POND_KEYBOARD_KEY_KP_BINARY = 218,
	POND_KEYBOARD_KEY_KP_OCTAL = 219,
	POND_KEYBOARD_KEY_KP_DECIMAL = 220,
	POND_KEYBOARD_KEY_KP_HEXADECIMAL = 221,
		 
	POND_KEYBOARD_KEY_LCTRL = 224,
	POND_KEYBOARD_KEY_LSHIFT = 225,
	POND_KEYBOARD_KEY_LALT = 226,
	POND_KEYBOARD_KEY_LGUI = 227,
	POND_KEYBOARD_KEY_RCTRL = 228,
	POND_KEYBOARD_KEY_RSHIFT = 229,
	POND_KEYBOARD_KEY_RALT = 230,
	POND_KEYBOARD_KEY_RGUI = 231,
	POND_KEYBOARD_KEY_MODE = 257,
	POND_KEYBOARD_KEY_AUDIONEXT = 258,
	POND_KEYBOARD_KEY_AUDIOPREV = 259,
	POND_KEYBOARD_KEY_AUDIOSTOP = 260,
	POND_KEYBOARD_KEY_AUDIOPLAY = 261,
	POND_KEYBOARD_KEY_AUDIOMUTE = 262,
	POND_KEYBOARD_KEY_MEDIASELECT = 263,
	POND_KEYBOARD_KEY_WWW = 264,
	POND_KEYBOARD_KEY_MAIL = 265,
	POND_KEYBOARD_KEY_CALCULATOR = 266,
	POND_KEYBOARD_KEY_COMPUTER = 267,
	POND_KEYBOARD_KEY_AC_SEARCH = 268,
	POND_KEYBOARD_KEY_AC_HOME = 269,
	POND_KEYBOARD_KEY_AC_BACK = 270,
	POND_KEYBOARD_KEY_AC_FORWARD = 271,
	POND_KEYBOARD_KEY_AC_STOP = 272,
	POND_KEYBOARD_KEY_AC_REFRESH = 273,
	POND_KEYBOARD_KEY_AC_BOOKMARKS = 274,
		 
	POND_KEYBOARD_KEY_BRIGHTNESSDOWN = 275,
	POND_KEYBOARD_KEY_BRIGHTNESSUP = 276,
	POND_KEYBOARD_KEY_DISPLAYSWITCH = 277,
	POND_KEYBOARD_KEY_KBDILLUMTOGGLE = 278,
	POND_KEYBOARD_KEY_KBDILLUMDOWN = 279,
	POND_KEYBOARD_KEY_KBDILLUMUP = 280,
	POND_KEYBOARD_KEY_EJECT = 281,
	POND_KEYBOARD_KEY_SLEEP = 282,

} Pond_KeyboardKey;

typedef enum Pond_MouseButton
{
	POND_MOUSE_BUTTON_LEFT = 0,
	POND_MOUSE_BUTTON_MIDDLE,
	POND_MOUSE_BUTTON_RIGHT,
	POND_MOUSE_BUTTON_X1,
	POND_MOUSE_BUTTON_X2,
} Pond_MouseButton;

typedef enum Pond_JoystickAxis
{
	POND_JOYSTICK_AXIS_X = 0,
	POND_JOYSTICK_AXIS_Y
} Pond_JoystickAxis;

typedef enum Pond_JoystickIndex
{
	POND_JOYSTICK_INDEX_MAIN = 0,
	POND_JOYSTICK_INDEX_SECONDARY,

} Pond_JoystickIndex;

typedef enum Pond_ControllerButton
{
	POND_CONTROLLER_BUTTON_A = 0,
	POND_CONTROLLER_BUTTON_B,
	POND_CONTROLLER_BUTTON_X,
	POND_CONTROLLER_BUTTON_Y,
	POND_CONTROLLER_BUTTON_SELECT,
	POND_CONTROLLER_BUTTON_GUIDE,
	POND_CONTROLLER_BUTTON_START,
	POND_CONTROLLER_BUTTON_LEFTSTICK,
	POND_CONTROLLER_BUTTON_RIGHTSTICK,
	POND_CONTROLLER_BUTTON_LEFTSHOULDER,
	POND_CONTROLLER_BUTTON_RIGHTSHOULDER,
	POND_CONTROLLER_BUTTON_DPAD_UP,
	POND_CONTROLLER_BUTTON_DPAD_DOWN,
	POND_CONTROLLER_BUTTON_DPAD_LEFT,
	POND_CONTROLLER_BUTTON_DPAD_RIGHT,
	POND_CONTROLLER_BUTTON_MISC1,
	POND_CONTROLLER_BUTTON_PADDLE1,
	POND_CONTROLLER_BUTTON_PADDLE2,
	POND_CONTROLLER_BUTTON_PADDLE3,
	POND_CONTROLLER_BUTTON_PADDLE4,
	POND_CONTROLLER_BUTTON_TOUCHPAD,
	POND_CONTROLLER_BUTTON_MAX,

} Pond_ControllerButton;


int InitInputSystem(void);
int CloseInputSystem(void);

#pragma region Internal_Input_Gathering
int GatherSystemInput(void);
int GetKeyboardInputs(void);
int GetMouseInputs(void);
int GetControllerButtonInputs(void);
int SaveInputs(void);
#pragma endregion

#pragma region Input_Presses

/// <summary>
/// Checks if passed keyboard key is currently pressed or not.
/// </summary>
/// <param name="_key">- the keyboard key to check</param>
/// <returns> true if key is pressed, false if not</returns>
POND_API bool Pond_GetKey(Pond_KeyboardKey _key);

/// <summary>
/// Checks if passed keyboard key has been pressed down. 
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_key">- the keyboard key to check</param>
/// <returns> true if key is pressed down, false if not or when continuously pressing down</returns>
POND_API bool Pond_GetKeyDown(Pond_KeyboardKey _key);

/// <summary>
/// Checks if passed keyboard key has been released.
/// </summary>
/// <param name="_key">- the keyboard key to check</param>
/// <returns> true if key has been released, false if not or if it has not been pressed</returns>
POND_API bool Pond_GetKeyUp(Pond_KeyboardKey _key);

/// <summary>
/// Checks if passed mouse button is currently pressed or not.
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_button">- the mouse button to check</param>
/// <returns> true if button is pressed, false if not</returns>
POND_API bool Pond_GetMouseButton(Pond_MouseButton _button);

/// <summary>
/// Checks if passed mouse button has been pressed down.
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_button">- the mouse button to check</param>
/// <returns> true if button is pressed down, false if not or when continuously pressing down</returns>
POND_API bool Pond_GetMouseButtonDown(Pond_MouseButton _button);

/// <summary>
/// Checks if passed mouse button has been released.
/// </summary>
/// <param name="_button">- the mouse button to check</param>
/// <returns> true if button has been released, false if not or if it has not been pressed</returns>
POND_API bool Pond_GetMouseButtonUp(Pond_MouseButton _button);

/// <summary>
/// Checks if passed controller button is currently pressed or not.
/// </summary>
/// <param name="_button">- the controller button to check</param>
/// <returns> true if button is pressed, false if not</returns>
POND_API bool Pond_GetControllerButton(Pond_ControllerButton _button);

/// <summary>
/// Checks if passed controller button has been pressed down.
/// Does not check for continues pressing down.
/// </summary>
/// <param name="_button">- the controller button to check</param>
/// <returns> true if button is pressed down, false if not or when continuously pressing down</returns>
POND_API bool Pond_GetControllerButtonDown(Pond_ControllerButton _button);

/// <summary>
/// Checks if passed controller button has been released.
/// </summary>
/// <param name="_button">- the controller button to check</param>
/// <returns> true if button has been released, false if not or if it has not been pressed</returns>
POND_API bool Pond_GetControllerButtonUp(Pond_ControllerButton _button);
#pragma endregion

#pragma region Mouse

/// <summary>
/// Gets the current mouse position relative to the game window's top-left corner.
/// </summary>
/// <returns> mouse position as Pond_Vector2Int</returns>
POND_API Pond_Vector2Int Pond_GetMousePosition(void);

/// <summary>
/// Gets the current mouse position relative to the desktop's top-left corner.
/// (This function is less efficient than Pond_GetMousePosition)
/// </summary>
/// <returns> mouse position as Pond_Vector2Int</returns>
POND_API Pond_Vector2Int Pond_GetMousePositionDesktop(void);

/// <summary>
/// Sets mouse position to passed coordinates relative to the game window.
/// </summary>
/// <param name="_x">- the x coordinate to set the mouse position to</param>
/// <param name="_y">- the y coordinate to set the mouse position to</param>
/// <returns>1 if successful</returns>
POND_API int Pond_SetMousePosition(int _x, int _y);

/// <summary>
/// Sets mouse position to passed coordinates relative to the current desktop.
/// </summary>
/// <param name="_x">- the x coordinate to set the mouse position to</param>
/// <param name="_y">- the y coordinate to set the mouse position to</param>
/// <returns>1 if successful</returns>
POND_API int Pond_SetMousePositionDesktop(int _x, int _y);


/// <summary>
/// Toggles the cursor by passed value.
/// If passed true the cursor is shown, if false the cursor is hidden.
/// </summary>
/// <param name="_toggle">- the boolean value deciding to set the cursor on or off</param>
/// <returns>1 if successful</returns>
POND_API int Pond_ToggleCursor(bool _toggle);

/// <summary>
/// Gets the cursor's toggle state.
/// True means the cursor is showing, false means the cursor is hiding.
/// The default is true.
/// </summary>
/// <returns> if cursor is on or off</returns>
POND_API bool Pond_GetCursorToggleState(void);

#pragma endregion

#pragma region Joystick

/// <summary>
/// Gets the angle of joystick with passed index in degrees where 0� is up, 90� right, 180� down and 270� left.
/// </summary>
/// <param name="_index">- the index of the joystick (POND_JOYSTICK_INDEX_MAIN or POND_JOYSTICK_INDEX_SECONDARY)</param>
/// <returns> angle of joystick in degrees</returns>
POND_API double Pond_GetJoyStickAngle(Pond_JoystickIndex _index);

/// <summary>
/// Gets the current position of joystick with passed index as a Pond_Vector2Float. 
/// Returns for example {0.5, 0.75}.
/// </summary>
/// <param name="_index">- the index of the joystick (POND_JOYSTICK_INDEX_MAIN or POND_JOYSTICK_INDEX_SECONDARY)</param>
/// <returns> the current joystick's axis position</returns>
POND_API Pond_Vector2Float Pond_GetJoystickAxisVector(Pond_JoystickIndex _index);

/// <summary>
/// Gets the current input (-1 to 1) on passed axis of joystick with passed index.
/// </summary>
/// <param name="_axis">- the axis to get the input from (POND_JOYSTICK_AXIS_X or POND_JOYSTICK_AXIS_Y)</param>
/// <param name="_index">- the index of the joystick (POND_JOYSTICK_INDEX_MAIN for left Joystick or POND_JOYSTICK_INDEX_SECONDARY for right Joystick)</param>
/// <returns> the input of joystick on axis between -1 and 1</returns>
POND_API float Pond_GetJoystickAxisValue(Pond_JoystickAxis _axis, Pond_JoystickIndex _index);

/// <summary>
/// Sets the current joystick deadzone value. Any input less than the deadzone value is not registered. Min for deadzone value is 0, max is 32767 (POND_JOYSTICK_DEADZONE_MAX).
/// </summary>
/// <param name="_value">- value to set deadzone value to</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_SetJoystickDeadzoneValue(unsigned int _value);

/// <summary>
/// Gets the current joystick deadzone value.
/// </summary>
/// <returns> current joystick deadzone value</returns>
POND_API unsigned int Pond_GetJoystickDeadzoneValue(void);

#pragma endregion

#pragma region Controller

/// <summary>
/// Returns the number of controller registered.
/// </summary>
/// <returns> number of registered controllers</returns>
POND_API int Pond_GetNumberOfControllers(void);

/// <summary>
/// When called gives feedback via controller rumble.
/// Any successful call to this function will stop the current rumble effect.
/// Calling this function with 0 intensity stops the current rumble effect.
/// </summary>
/// <param name="_msduration">- the amount of time to rumble in Milliseconds (ms), min is 0 and max is 500</param>
/// <param name="_lowfrequenceintensity">- the intensity of the low frequence rumble, min is 0 and max is 100</param>
/// <param name="_highfrequenceintensity">- the intensity of the high frequence rumble, min is 0 and max is 100</param>
/// <returns> 1 if successful, 0 if not</returns>
POND_API int Pond_ControllerRumble(int _msduration, float _lowfrequenceintensity, int _highfrequenceintensity);

#pragma endregion