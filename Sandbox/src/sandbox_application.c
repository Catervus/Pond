#include "pond.h"

// POST BUILD COMMAND TO COPY SDL2.DLL
// xcopy /y "..\dependencies\SDL2\bin\x64\SDL2.dll" "$(OutDir)"

Pond_Texture* p_testSprite;

void Init(void) 
{
	Pond_Console_PrintLine("Initialising FrogEngine2D!");
	Pond_Console_PrintWarning("Oh oh");
	Pond_Console_PrintLine("This should be white, right?");
	Pond_Console_PrintLine("I'm a frog!", E_POND_CONSOLE_COLOUR_GREEN);
	Pond_Console_PrintLine("I'm a frog!");
	Pond_Console_ResetColour();
	Pond_Console_PrintLine("Not anymore...");

	SDL_Color col = { 0,0,0, 255 };
	p_testSprite = Pond_LoadTexture("assets/Ledian.png", 200, 200, col);

}

int i = 120;
int switchIt = 0;
int x = 0;

void Update(void)
{
	if (--i <= 0)
	{
		switchIt = 1;
		// Pond_ChangeFPS(100);
		x = 100;
		Pond_Colour col = { 255, 100, 20, 255 };
		// Pond_SetRenderClearColour(col);
	}
}

void Draw(void)
{
	Pond_Colour red = { 255, 0, 0, 255 };
	/*
	Pond_DrawPixel(50, 50, red);

	Pond_DrawLine(50, 100, 200, 150, red);

	Pond_Vector2Int points[5] =
	{
		{10, 10},
		{20, 100},
		{50, 150},
		{100, 120},
		{120, 50},
	};

	Pond_DrawPolygon(points,  Pond_GetArraySize(points),red);

	Pond_DrawTexture(p_testSprite, x, 0, 255);

	Pond_Colour col = { 100, 255, 255, 255 };
	Pond_DrawRect(300, 300, 500, 500, col, 0);*/

	Pond_Colour green = { 0, 255, 100, 255 };
	Pond_DrawCircle(350, 350, 101, green, 0);




}


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60);

	return 0;
}