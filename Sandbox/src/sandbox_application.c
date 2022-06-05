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

int screenWidth = 1000;
int screenHeight = 1000;
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
	

	Pond_SetWindowResizable(false);

	Pond_SetRandomSystemSeed(0);

}


float cooldown = 1;

void Update(void)
{
	if (cooldown <= 0)
	{
		// do stuff

		x = Pond_GetRandomInt(0, Pond_GetWindowSize().x - 100);
		y = Pond_GetRandomInt(0, Pond_GetWindowSize().y - 100);

		cooldown = 1;
	}
	else
		cooldown -= Pond_GetDeltaTime();


	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_ESCAPE))
		Pond_Quit();
}


void Draw(void)
{

	// Pond_DrawSprite(p_sprite, xOffset + x, yOffset + y, 1, 1);

	Pond_DrawRectByDimensions(x, y, 100, 100, red, true);

}

