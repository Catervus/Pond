#include "pond.h"

void Init(void) 
{
	Pond_Console_PrintLine("Initialising FrogEngine2D!");
	Pond_Console_PrintWarning("Oh oh");
	Pond_Console_PrintLine("This should be white, right?");
	Pond_Console_PrintLine("I'm a frog!", E_POND_CONSOLE_COLOUR_GREEN);
	Pond_Console_PrintLine("I'm a frog!");
	Pond_Console_ResetColour();
	Pond_Console_PrintLine("Not anymore...");


}

void Update(void)
{

}

void Draw(void)
{
	SDL_Color red = { 255, 0, 0, 255 };
	Pond_DrawPixel(50, 50, red);
}


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60);

	return 0;
}