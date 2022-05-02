#include "pond.h"

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 230 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 150 };

Pond_Texture* p_testTexture;

void Init(void) 
{
	Pond_SetRenderClearColour(white);
	p_testTexture = Pond_LoadTexture("assets/ledian_pixel.png");


	//Pond_SetWindowMode(POND_WINDOW_MODE_FULLSCREEN);
}

int timer;

void Update(void)
{
	if (++timer > 100)
	{
		if (p_testTexture->flipX == 0)
			p_testTexture->flipX = 1;
		else
			p_testTexture->flipX = 0;

		timer = 0;

		printf("FlipX: %i\n", p_testTexture->flipX);
	}


}

void Draw(void)
{
	Pond_DrawRect(50, 50, 250, 250, red, 1);
	Pond_DrawRect(200, 200, 400, 400, blue, 1);

	Pond_DrawTexture(p_testTexture, 500, 500, 1, 1, 100);
}

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	//Pond_SetWindowSize(1820, 980);
	Pond_Run(60);

	return 0;
}