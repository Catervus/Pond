#include "main.h"

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Colour lightBlue = { 137, 196, 244, 255 };




int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
 	Pond_Run(60, SCREEN_WIDTH, SCREEN_HEIGHT);

	return 0;
}

void Init(void) 
{
	printf("Hello Metroidvania Month!\n");
	Pond_SetRenderClearColour(lightBlue);

	// memset(&gameworld, 0, sizeof(Gameworld));
	p_entityTail = &entityHead;


	p_playerTexture = Pond_LoadTexture("assets/playerSprite.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_fireballTexture = Pond_LoadTexture("assets/fireballSprite.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_player = CreateEntity(p_playerTexture, 100, 100);


	CreateBox(100, 500, 200, 50);

}


void Update(void)
{

	Pond_Vector2Int mousePos = Pond_GetMousePosition();

	if (Pond_GetMouseButtonDown(POND_MOUSE_BUTTON_LEFT))
	{
		CreateBox(mousePos.x - 100, mousePos.y - 25, 200, 50);
	}

	if (Pond_GetMouseButton(POND_MOUSE_BUTTON_RIGHT))
	{
		Entity* p_entity = CreateEntity(p_playerTexture, mousePos.x, mousePos.y);
	}

	PlayerUpdate();
	EntityUpdate();
	PlayerLateUpdate();

	
	
}

void Draw(void)
{
	// Pond_DrawSprite(p_player->p_sprite, p_player->position.x, p_player->position.y, SCALE, SCALE);

	EntityDraw();

	Pond_Rect rect;
	for (int i = 0; i < boxCount; i++)
	{
		rect = boxes[i];
		Pond_DrawRectByDimensions(rect.x, rect.y, rect.w, rect.h, red, 1);
	}
}


void CreateBox(int _x, int _y, int _w, int _h)
{
	if (boxCount >= 10)
		return;
	Pond_Rect rect = { _x, _y , _w, _h};
	boxes[boxCount] = rect;

	boxCount++;
}