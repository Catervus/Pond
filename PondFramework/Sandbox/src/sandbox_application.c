#include "sandbox_application.h"



Pond_Colour black = { 0, 0, 0, 0 };

Pond_Colour red = { 255, 100, 100, 255 };

float size = 0;
float growth = 1;

Pond_Font* p_font;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, WINDOW_WIDTH, WINDOW_HEIGHT, "Sandbox", true);
	return 0;
}

void Init(void)
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);
	Pond_SetRenderClearColour(black);
	Pond_SetWindowResizable(false);

	p_font = Pond_LoadFont("assets/monogram.ttf");

}

void Update(void)
{
	EntityUpdate();
	if (Pond_GetMouseButtonDown(POND_MOUSE_BUTTON_LEFT))
	{
		Pond_Vector2Int mousepos = Pond_GetMousePosition();
		CreateEntity(mousepos.x, mousepos.y, red);
	}
}

void Draw(void)
{
	EntityDraw();
}


