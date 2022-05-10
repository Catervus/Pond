#include "sandbox_application.h"

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Vector2Int mousePos;
Pond_Colour drawColour;

int drawSize = 10;

#include <time.h>

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60, 700, 700);

	return 0;
}

int RandomNum(void)
{
	return rand() % 5;
}

void Init(void) 
{
	Pond_SetRenderClearColour(white);

	drawColour = red;

	int i;

	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	i = Pond_GetRandomInt(-5, 0); printf("Random Int: %i\n", i);
	
	
}

xPos = 10;
yPos = 10;

void Update(void)
{

	mousePos = Pond_GetMousePosition();

	if (Pond_GetMouseButton(POND_MOUSE_BUTTON_LEFT))
	{
		entities[entityIndex] = CreateEntity(mousePos, drawColour, drawSize);
		entityIndex++;
		entityCounter++;
		if (entityCounter >= ENTITY_COUNT)
			entityCounter = ENTITY_COUNT;
		if (entityIndex >= ENTITY_COUNT)
			entityIndex = 0;
		printf("Number of Rects: %i\n", entityCounter);
	}

	if (Pond_GetMouseButton(POND_MOUSE_BUTTON_RIGHT))
		drawSize++;

	if (Pond_GetMouseButton(POND_MOUSE_BUTTON_MIDDLE))
	{
		drawSize--;
		if (drawSize <= 0)
			drawSize = 2;
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
		ClearAllEntities();

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_1))
		drawColour = red;

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_2))
		drawColour = blue;

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_3))
		drawColour = black;

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_4))
		drawColour = gray;

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_5))
		drawColour = white;


}

void Draw(void)
{


	for (int i = 0; i < entityCounter; i++)
	{
		// Pond_DrawCircle(entities[i].pos.x, entities[i].pos.y, RECT_SIZE, red, 1);
		Pond_DrawRect(entities[i].pos.x - entities[i].size / 2, entities[i].pos.y - entities[i].size / 2,
			entities[i].pos.x + entities[i].size / 2, entities[i].pos.y + entities[i].size / 2, entities[i].col, true);
	}

	Pond_DrawRect(mousePos.x - drawSize / 2, mousePos.y - drawSize / 2, mousePos.x + drawSize / 2, mousePos.y + drawSize / 2, drawColour, false);

}

Entity CreateEntity(Pond_Vector2Int _pos, Pond_Colour _col, int _size)
{
	Entity entity;
	memset(&entity, 0, sizeof(Entity));
	entity.pos = _pos;
	entity.active = true;
	entity.size = _size;
	entity.col = _col;

	return entity;
}

void ClearAllEntities()
{
	entityCounter = 0;
	entityIndex = 0;
}
