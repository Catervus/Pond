#include "main.h"

Pond_Texture* p_playerTexture;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60, SCREEN_HEIGHT, SCREEN_WIDTH);

	return 0;
}

void Init(void) 
{
	printf("Start!\n");

	p_playerTexture = Pond_LoadTexture("assets/ship.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_player = CreateEntity(0, 0, p_playerTexture);
}

void Update(void)
{
	if (Pond_GetKey(POND_KEYBOARD_KEY_A))
	{
		p_player->pos.x -= PLAYER_MOVE_SPEED;
	}
	if (Pond_GetKey(POND_KEYBOARD_KEY_D))
	{
		p_player->pos.x += PLAYER_MOVE_SPEED;
	}
	if (Pond_GetKey(POND_KEYBOARD_KEY_W))
	{
		p_player->pos.y -= PLAYER_MOVE_SPEED;
	}
	if (Pond_GetKey(POND_KEYBOARD_KEY_S))
	{
		p_player->pos.y += PLAYER_MOVE_SPEED;
	}

}

void Draw(void)
{
	Pond_DrawSprite(p_player->p_sprite, p_player->pos.x, p_player->pos.y, SCALE, SCALE);
}