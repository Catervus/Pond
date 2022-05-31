#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Music* p_testMusic;
Pond_Sound* p_testSound;


Pond_Texture* p_texture;
Pond_Sprite* p_sprite;

int screenWidth = 1280;
int screenHeight = 1024;
#define VIEWPORT_DIMENSIONS 800

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, screenWidth, screenHeight, "Pond-Sandbox!");

	return 0;
}

int x = 100;
int y = 100;

void Init(void) 
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);

	Pond_SetRenderClearColour(black);

	p_testSound = Pond_LoadSound("assets/sound.wav", POND_AUDIO_FILE_TYPE_WAV, 50);
	p_testMusic = Pond_LoadMusic("assets/music.mp3", -1, 20, true);

	p_texture = Pond_LoadTexture("assets/ledian_pixel.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);
	
	Pond_SetJoystickDeadzoneValue(8000);
	printf("Deadzone Value: %i\n", Pond_GetJoystickDeadzoneValue());

	Pond_PlaySound(p_testSound, 0);

	int i = Pond_GetNumberOfControllers();
	printf("%i Controller(s) has/have been found\n", i);

	Pond_SetWindowTitle("SKROOD SKROOD SKROOD");

	printf("Window Title: %s\n", Pond_GetWindowTitle());

	Pond_SetWindowResizable(true);

}


void Update(void)
{

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		Pond_MinimizeWindow();

	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_LCTRL))
	{
		Pond_MaximizeWindow();
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_LSHIFT))
	{
		Pond_Vector2Int windowpos = Pond_GetWindowPos();
		printf("Window Position:\nX: %i\nY: %i\n\n", windowpos.x, windowpos.y);
	}


	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_ESCAPE))
		Pond_Quit();
}


int xOffset;
int yOffset;

void Draw(void)
{
	xOffset = screenWidth / 2 - VIEWPORT_DIMENSIONS / 2;
	yOffset = screenHeight / 2 - VIEWPORT_DIMENSIONS / 2;

	Pond_DrawRectByDimensions(xOffset, yOffset, VIEWPORT_DIMENSIONS, VIEWPORT_DIMENSIONS, white, 1);

	Pond_DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, red);

	Pond_DrawSprite(p_sprite, xOffset + x, yOffset + y, 1, 1);

	Pond_DrawRectByDimensions(xOffset + 100, yOffset + 100, 50, 50, red, false);
}

