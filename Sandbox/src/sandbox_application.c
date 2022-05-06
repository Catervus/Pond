#include "sandbox_application.h"

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 230 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 150 };

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60, 700, 700);

	return 0;
}

void Init(void) 
{
	Pond_SetRenderClearColour(gray);
}

xPos = 10;
yPos = 10;


void Update(void)
{
	if (entityCount >= 100)
		return;

	Pond_Vector2Int mousePos = Pond_GetMousePosition();

	if (Pond_GetMouseButtonDown(POND_MOUSE_BUTTON_LEFT))
	{
		Pond_Vector2Int pos = { xPos, yPos };
		entities[entityCount] = CreateEntity(mousePos);
		xPos += 10;
		yPos += 10;
		printf("MousePosX: %i\n", mousePos.x);
		printf("MousePosY: %i\n", mousePos.y);
		printf("-------------------\n");
	}

}

void Draw(void)
{

	for (int i = 0; i < entityCount; i++)
	{
		if (!entities[i].active)
			continue;
		int x = entities[i].pos.x;
		int y = entities[i].pos.y;
		//Pond_DrawRect(x, y, x + 200, y + 200, red, false);
		Pond_DrawPixel(x, y, red);
	}
}

Entity CreateEntity(Pond_Vector2Int _pos)
{
	Entity entity;
	memset(&entity, 0, sizeof(Entity));
	entity.pos = _pos;
	entity.active = true;

	entityCount++;

	return entity;
}
