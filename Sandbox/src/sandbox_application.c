#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };
Pond_Colour pink = { 255, 0, 240, 255 };
Pond_Colour green = { 100, 255, 100, 255 };
Pond_Colour yellow = { 255, 255, 100, 255 };


Pond_Music* p_testMusic;
Pond_Sound* p_testSound;


Pond_Texture* p_texture;
Pond_Sprite* p_sprite;

Pond_Texture* p_texture2;
Pond_Texture* p_texture3;
Pond_Font* p_font;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define VIEWPORT_DIMENSIONS 800

Pond_Vector2Int cameraPos;

#define CAMERA_SPEED 1000
int cameraMoveSpeed;


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(100, SCREEN_WIDTH, SCREEN_HEIGHT, "Pond Rendering Demo", false);
	

	return 0;
}




void Init(void) 
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);

	Pond_SetRenderClearColour(black);

	Pond_SetWindowResizable(false);
	Pond_ToggleConsoleWindow(true);

	Pond_SetRandomSystemSeed(0);

	p_font = Pond_LoadFont("assets/monogram.ttf");

	p_texture = Pond_LoadTexture("assets/ledian.png", POND_TEXTURE_BLEND_MODE_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);

}

void Update(void)
{

}

void Draw(void)
{
	Pond_DrawTexture(p_texture, 0, 0, 1, 1, 255);
}

