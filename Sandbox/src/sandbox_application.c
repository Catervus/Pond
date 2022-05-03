#include "pond.h"

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 230 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 150 };

Pond_Sprite* p_sprite;
Pond_Sprite* p_test;

void Init(void) 
{
	Pond_SetRenderClearColour(white);
	p_sprite = Pond_InitSprite("assets/ledian_pixel.png", 0);
	p_sprite->colour.a = 100;
	p_test = Pond_InitSprite("assets/ledian_pixel.png", 0);
	p_test->spriteRect.w = 150;

	//Pond_SetWindowMode(POND_WINDOW_MODE_FULLSCREEN);
}

int timer = 0;

void Update(void)
{
	/*if (++timer > 40)
	{
		if (p_sprite->flipX == 0)
			p_sprite->flipX = 1;
		else
			p_sprite->flipX = 0;

		timer = 0;

		printf("FlipX: %i\n", p_sprite->flipX);
	}*/

	// p_sprite->rotationAngle++;

	// p_sprite->colour.a--;

}

int x;

void Draw(void)
{
	Pond_DrawRect(50, 50, 250, 250, red, 1);
	Pond_DrawRect(200, 200, 400, 400, blue, 1);

	// Pond_DrawTexture(p_sprite->p_texture, 500, 500, 1, 1, 100);
	Pond_DrawSprite(p_sprite, 400, 400, 1, 1);
	Pond_DrawSprite(p_test, 400, 400, 1, 1);

}


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	//Pond_SetWindowSize(1820, 980);
	Pond_Run(60);

	return 0;
}