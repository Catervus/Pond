#include "pond.h"
#include <stdio.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 230 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 150 };

Pond_Sprite* p_sprite;
Pond_Sprite* spriteArray[100];
Pond_Texture* textureArray[100];

Pond_Texture* p_testTex;
Pond_Sprite* p_testSprite;


void Init(void) 
{
	Pond_SetRenderClearColour(white);

	p_testTex = Pond_LoadTexture("assets/ledian_pixel.png", 0);

	// p_sprite = Pond_InitSprite(p_testTex);
}

int timer = 300;
int freed = 0;

void Update(void)
{

	// p_testSprite->p_texture->p_tex = p_testTex->p_tex;

	// free(p_tex);


	// p_sprite->rotationAngle++;

	// p_sprite->colour.a--;

	for (int i = 0; i < 100; i++)
	{
		// spriteArray[i] = Pond_InitSprite(p_testTex);
		// Pond_FreeSprite(spriteArray[i]);
		
		/*p_testTex = Pond_LoadTexture("assets/ledian_pixel.png", 0);
		Pond_FreeTexture(p_testTex);*/

		textureArray[i] = Pond_LoadTexture("assets/ledian_pixel.png", 0);
		Pond_FreeTexture(textureArray[i]);
	}


	if (--timer < 0)
	{
		if (!freed)
		{
			/*Pond_FreeTexture(p_testTex);

			Pond_FreeTexture(p_testTex1);
			Pond_FreeTexture(p_testTex2);
			Pond_FreeTexture(p_testTex3);
			Pond_FreeTexture(p_testTex4);
			Pond_FreeTexture(p_testTex5);
			Pond_FreeTexture(p_testTex6);
			Pond_FreeTexture(p_testTex7);*/

			freed = 1;
		}
	}
	
	

}


void Draw(void)
{
	Pond_DrawRect(50, 50, 250, 250, red, 1);
	Pond_DrawRect(200, 200, 400, 400, blue, 1);

	/*if(!freed)
		Pond_DrawTexture(p_testTex, 500, 500, 1, 1, 255);*/
}


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	//Pond_SetWindowSize(1820, 980);
	Pond_Run(60);

	return 0;
}