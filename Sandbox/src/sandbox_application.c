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
	Pond_Run(20, screenWidth, screenHeight, "Pond-Sandbox!");

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
	

	Pond_SetWindowResizable(false);

}


void Update(void)
{
	double deltatime = Pond_GetDeltaTime();

	printf("DeltaTime: %f\n", deltatime);


	if (Pond_GetKey(POND_KEYBOARD_KEY_D))
	{
		x += 500 * deltatime;
	}
	if (Pond_GetKey(POND_KEYBOARD_KEY_A))
	{
		x -= 500 * deltatime;
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		Pond_SetFPS(120);
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_LSHIFT))
	{
		Pond_SetFPS(20);
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

