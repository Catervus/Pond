#include "pond.h"
#include <stdio.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 230 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 150 };

Pond_Sprite* p_sprite;

Pond_Texture* p_testTex;
Pond_Texture* p_otherTex;


float scale = 3.0;


void Init(void) 
{
	Pond_SetRenderClearColour(gray);
	p_testTex = Pond_LoadTexture("assets/ledian_pixel.png", 0);
	p_otherTex = Pond_LoadTexture("assets/Ledian.png", 0);

	p_sprite = Pond_InitSprite(p_otherTex);

	p_sprite->flipX = false;
	p_sprite->flipY = false;
	
}

int timer = 50;
int col = 0;

void Update(void)
{
	Pond_SetSpriteColour(p_sprite, 0, col, col, 255);

	if (--timer < 0)
	{
		// p_sprite->p_texture = p_otherTex;
		Pond_SetSpriteTexture(p_sprite, p_otherTex);
		
	}

	col++;
	
}

void Draw(void)
{
	Pond_DrawSprite(p_sprite, 100, 100, 1, 1);

	// Pond_DrawRect(500, 500, 700, 700, Pond_GetColour(200, 100, 200, 255), true);
}



int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	//Pond_SetWindowSize(1820, 980);
	Pond_Run(60);

	return 0;
}