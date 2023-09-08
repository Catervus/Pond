
// DISCLAIMER: This Module is currently a WIP as of v1.0 and should NOT be used!

#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"

enum
{
	E_POND_CONSOLE_COLOUR_RED = 1,
	E_POND_CONSOLE_COLOUR_BLUE,
	E_POND_CONSOLE_COLOUR_GREEN,
	E_POND_CONSOLE_COLOUR_YELLOW,
	E_POND_CONSOLE_COLOUR_MAGENTA,
	E_POND_CONSOLE_COLOUR_CYAN,
};

/// <summary>
/// WIP! Do not use!
/// </summary>
POND_API void Pond_Console_Print(char* _text);

/// <summary>
/// WIP! Do not use!
/// </summary>
POND_API void Pond_Console_PrintLine();

/// <summary>
/// WIP! Do not use!
/// </summary>
POND_API void Pond_Console_PrintWarning(char* _text);

/// <summary>
/// WIP! Do not use!
/// </summary>
POND_API void Pond_Console_SetColour(int _col);

/// <summary>
/// WIP! Do not use!
/// </summary>
POND_API void Pond_Console_ResetColour();

/// <summary>
/// WIP! Do not use!
/// </summary>
static char* currentConsoleColour = "\x1b[0m";


