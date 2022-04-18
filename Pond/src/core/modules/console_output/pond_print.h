#pragma once
#include <stdio.h>
#include "../../pond_core.h"

#define POND_CONSOLE_COLOR_RED "\x1b[31m"
#define POND_CONSOLE_COLOR_BLUE    "\x1b[34m"
#define POND_CONSOLE_COLOR_RESET   "\x1b[0m"

POND_API void Pond_Console_Print(char* _text);
POND_API void Pond_Console_PrintLine(char* _text);
POND_API void Pond_Console_PrintWarning(char* _text);
