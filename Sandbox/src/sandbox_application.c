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

	Pond_DrawLine(50, 100, 200, 150, red);

	Pond_Point points[5] =
	{
		{10, 10},
		{20, 100},
		{50, 150},
		{100, 120},
		{120, 50},
	};

	Pond_DrawPolygon(points,  sizeof(points) / sizeof(Pond_Point),red);
}


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60);

	return 0;
}