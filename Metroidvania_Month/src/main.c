#include "main.h"

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Colour lightBlue = { 137, 196, 244, 255 };

Pond_Texture* p_playerTexture;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
 	Pond_Run(60, 700, 700);

	return 0;
}

void Init(void) 
{
	printf("Hello Metroidvania Month!\n");
	Pond_SetRenderClearColour(lightBlue);

	p_playerTexture = Pond_LoadTexture("assets/playerSprite.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);

	p_player = CreateEntity(p_playerTexture, 100, 100);
}


void Update(void)
{
	EntityUpdate();

}

void Draw(void)
{
	Pond_DrawSprite(p_player->p_sprite, p_player->position.x, p_player->position.y, SCALE, SCALE);
}