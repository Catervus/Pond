
// DISCLAIMER: This Module is currently a WIP as of v1.0 and should NOT be used!

#include "pond_console.h"

#define CONSOLE_COLOUR_RED		"\x1b[31m"
#define CONSOLE_COLOUR_BLUE    "\x1b[34m"
#define CONSOLE_COLOUR_WHITE   "\x1b[0m"
#define CONSOLE_COLOUR_DEFAULT   "\x1b[0m"

#define CONSOLE_COLOUR_GREEN   "\x1b[32m"
#define CONSOLE_COLOUR_YELLOW  "\x1b[33m"
#define CONSOLE_COLOUR_MAGENTA "\x1b[35m"
#define CONSOLE_COLOUR_CYAN    "\x1b[36m"


void Pond_Console_Print(char* _text)
{
	printf(_text);

}

/// <summary>
/// Print something to console. 0 for no colour configuration. Will draw with current Console Colour.
/// </summary>
/// <param name="_text">String to print.</param>
/// <param name="_col">Colour to print in. 0 for current Console Colour.</param>
void Pond_Console_PrintLine(char* _text, int _col)
{
	Pond_Console_SetColour(_col);
	printf("%s%s\n", currentConsoleColour, _text);
}

void Pond_Console_PrintWarning(char* _text) 
{
	printf(CONSOLE_COLOUR_RED "WARNING: %s%s\n", _text, currentConsoleColour);
}

// --------------------------------- COLOUR

void Pond_Console_SetColour(int _col)
{
	char* ansicol = currentConsoleColour;

	switch (_col)
	{
		case E_POND_CONSOLE_COLOUR_RED:
			ansicol = CONSOLE_COLOUR_RED;
			break;
		case E_POND_CONSOLE_COLOUR_BLUE:
			ansicol = CONSOLE_COLOUR_BLUE;
			break;
		case E_POND_CONSOLE_COLOUR_GREEN:
			ansicol = CONSOLE_COLOUR_GREEN;
			break;
		case E_POND_CONSOLE_COLOUR_YELLOW:
			ansicol = CONSOLE_COLOUR_YELLOW;
			break;
		case E_POND_CONSOLE_COLOUR_MAGENTA:
			ansicol = CONSOLE_COLOUR_MAGENTA;
			break;
		case E_POND_CONSOLE_COLOUR_CYAN:
			ansicol = CONSOLE_COLOUR_CYAN;
			break;
	}

	currentConsoleColour = ansicol;
}

POND_API void Pond_Console_ResetColour()
{
	currentConsoleColour = CONSOLE_COLOUR_DEFAULT;
}


#undef CONSOLE_COLOUR_RED		"\x1b[31m"
#undef CONSOLE_COLOUR_BLUE    "\x1b[34m"
#undef CONSOLE_COLOUR_WHITE   "\x1b[0m"

#undef CONSOLE_COLOUR_GREEN   "\x1b[32m"
#undef CONSOLE_COLOUR_YELLOW  "\x1b[33m"
#undef CONSOLE_COLOUR_MAGENTA "\x1b[35m"
#undef CONSOLE_COLOUR_CYAN    "\x1b[36m"