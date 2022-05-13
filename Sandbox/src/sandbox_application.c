#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Vector2Int mousePos;
Pond_Colour drawColour;

int drawSize = 10;

Pond_Sound* p_testSound;
Pond_Music* p_testMusic;



int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 1, 1);
	Pond_Run(60, 700, 700);

	return 0;
}

Pond_Vector2Int points[5];
void Init(void) 
{
	Pond_SetRenderClearColour(white);

	drawColour = red;

	for (int i = 0; i < 5; i++)
	{
		int x = Pond_GetRandomInt(0, 699);
		int y = Pond_GetRandomInt(0, 699);
		Pond_Vector2Int point = { x, y };
		points[i] = point;
	}

	p_testSound = Pond_LoadSound("assets/sound.wav", POND_AUDIO_FILE_TYPE_WAV);
	p_testMusic = Pond_LoadMusic("assets/music.mp3", -1, 1);

	Pond_PlaySound(p_testSound, 0);
	Pond_PlayMusic(p_testMusic);

	
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


	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		for (int i = 0; i < 5; i++)
		{
			int x = Pond_GetRandomInt(0, 699);
			int y = Pond_GetRandomInt(0, 699);
			Pond_Vector2Int point = { x, y };
			points[i] = point;
		}
	}


}

void Draw(void)
{
	Pond_DrawPolygon(points, Pond_GetArrayLength(points), red);

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

void ClearAllEntities(void)
{
	entityCounter = 0;
	entityIndex = 0;
}
