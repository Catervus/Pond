#pragma once
#include <stdio.h>
#include "../../pond_core.h"

enum
{
	E_POND_CONSOLE_COLOUR_RED = 1,
	E_POND_CONSOLE_COLOUR_BLUE,
	E_POND_CONSOLE_COLOUR_GREEN,
	E_POND_CONSOLE_COLOUR_YELLOW,
	E_POND_CONSOLE_COLOUR_MAGENTA,
	E_POND_CONSOLE_COLOUR_CYAN,
};


POND_API void Pond_Console_Print(char* _text);

/// <summary>
/// Print something to console. 0 for no colour configuration. Will draw with current Console Colour.
/// </summary>
/// <param name="_text:">String to print.</param>
/// <param name="_col:">Colour to print in. 0 for current Console Colour.</param>
POND_API void Pond_Console_PrintLine();
POND_API void Pond_Console_PrintWarning(char* _text);
POND_API void Pond_Console_SetColour(int _col);
POND_API void Pond_Console_ResetColour();

static char* currentConsoleColour = "\x1b[0m"; // White as default colour


