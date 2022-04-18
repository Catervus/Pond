#include "pond_print.h"

void Pond_Console_Print(char* _text)
{
	printf(_text);

}

void Pond_Console_PrintLine(char* _text)
{
	printf("%s\n", _text);
}

void Pond_Console_PrintWarning(char* _text) 
{
	printf(POND_CONSOLE_COLOR_BLUE "WARNING: %s" POND_CONSOLE_COLOR_RESET "\n", _text);
}