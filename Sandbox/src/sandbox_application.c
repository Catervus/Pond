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

Pond_Font* p_font;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;
#define VIEWPORT_DIMENSIONS 800


char testText[49] = "Hello Pond! I am excited to see how this goes...";
int textIndex = 0;
#define TEXT_COOLDOWN 0.1
float curTextCooldown = TEXT_COOLDOWN;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, screenWidth, screenHeight, "Pond-Sandbox!");

	return 0;
}

int positions[SCREEN_WIDTH][SCREEN_HEIGHT];
int startingPoint = 0;

int GenerateRandomNoise()
{
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			positions[x][y] = Pond_GetRandomInt(0,255);

		}


	}
}

void Init(void) 
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);

	Pond_SetRenderClearColour(black);

	Pond_SetWindowResizable(false);

	Pond_SetRandomSystemSeed(0);

	GenerateRandomNoise();

	p_font = Pond_InitFont("assets/monogram.ttf");

}


void Update(void)
{
	// GenerateRandomNoise();

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
		GenerateRandomNoise();

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_ESCAPE))
		Pond_Quit();


	if (curTextCooldown <= 0)
	{
		textIndex++;
		if (textIndex >= 49) textIndex = 49;
		curTextCooldown = TEXT_COOLDOWN;
	}
	else
		curTextCooldown -= Pond_GetDeltaTime();
}

void Draw(void)
{
	/*for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			Pond_Colour col = { positions[x][y], positions[x][y], positions[x][y], 255 };

			Pond_DrawPixel(x, y, col);

		}

	}*/

	char textbuffer[1024];

	for (int i = 0; i < textIndex; i++)
	{
		textbuffer[i] = testText[i];
	}

	Pond_DrawText(textbuffer, 0, 0, white, 2, 2, p_font);
}

