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
	Pond_SetRandomSystemSeed(0);
	p_font = Pond_LoadFont("assets/monogram.ttf");
	p_texture = Pond_LoadTexture("assets/ledian.png", POND_TEXTURE_BLEND_MODE_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);
	p_sprite->rotationAngle = 180;
	p_sprite->flipX = true;
	p_texture2 = Pond_LoadTexture("assets/ship.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_texture3 = Pond_LoadTexture("assets/ship.png", POND_TEXTURE_BLEND_MODE_BLENDING);
	cameraPos.x = 0;
	cameraPos.y = 0;

}


void Update(void)
{
	cameraMoveSpeed = CAMERA_SPEED * Pond_GetDeltaTime();
	if (Pond_GetKey(POND_KEYBOARD_KEY_LEFT) || Pond_GetKey(POND_KEYBOARD_KEY_A))
		cameraPos.x -= cameraMoveSpeed;
	else if (Pond_GetKey(POND_KEYBOARD_KEY_RIGHT) || Pond_GetKey(POND_KEYBOARD_KEY_D))
		cameraPos.x += cameraMoveSpeed;
	if (Pond_GetKey(POND_KEYBOARD_KEY_UP) || Pond_GetKey(POND_KEYBOARD_KEY_W))
		cameraPos.y -= cameraMoveSpeed;
	else if (Pond_GetKey(POND_KEYBOARD_KEY_DOWN) || Pond_GetKey(POND_KEYBOARD_KEY_S))
		cameraPos.y += cameraMoveSpeed;
	if (Pond_GetKey(POND_KEYBOARD_KEY_SPACE))
		cameraPos.x = cameraPos.y = 0;



}

void Draw(void)
{
	// Pond_DrawPixel(20 - cameraPos.x, 70 - cameraPos.y, pink);
	// Pond_DrawPixel(25 - cameraPos.x, 75 - cameraPos.y, pink);
	// Pond_DrawPixel(20 - cameraPos.x, 80 - cameraPos.y, pink);
	// 
	// Pond_DrawLine(20 - cameraPos.x, 40 - cameraPos.y, 119 - cameraPos.x, 139 - cameraPos.y, pink);
	// 
	// Pond_DrawRectByDimensions(140 - cameraPos.x, 40 - cameraPos.y, 100, 100, red, false);
	// Pond_DrawRectByDimensions(260 - cameraPos.x, 40 - cameraPos.y, 100, 100, blue, true);
	// 
	// 
	// Pond_DrawCircle(190 - cameraPos.x, 210 - cameraPos.y, 50, red, false);
	// Pond_DrawCircle(310 - cameraPos.x, 210 - cameraPos.y, 50, blue, true);
	// 
	// Pond_Vector2Int positions[6] =
	// {
	// 	{500 - cameraPos.x,	 40 - cameraPos.y},
	// 	{600 - cameraPos.x,	 10 - cameraPos.y},
	// 	{750 - cameraPos.x,	200 - cameraPos.y},
	// 	{650 - cameraPos.x,	250 - cameraPos.y},
	// 	{450 - cameraPos.x,	200 - cameraPos.y},
	// 	{550 - cameraPos.x,	150 - cameraPos.y},
	// };
	// 
	// Pond_DrawTexture(p_texture, 20 - cameraPos.x, 300 - cameraPos.y, 1, 1, 255);
	// Pond_DrawTexture(p_texture2, 140 - cameraPos.x, 300 - cameraPos.y, 10, 10, 255);
	// Pond_DrawTexture(p_texture3, 260 - cameraPos.x, 300 - cameraPos.y, 10, 10, 255);
	// 
	// Pond_DrawPolygon(positions, 6, pink);
	// 
	// Pond_DrawSprite(p_sprite, 20 - cameraPos.x, 600 - cameraPos.y, 1, 1, 255);
	// 
	// Pond_DrawText("WASD or Arrow Keys to move around. Space to reset camera", 1, -3, white, 1, 1, p_font);

	char* hellotext = "Hello World!";
	Pond_DrawText(hellotext, 10, 100, red, 1, 1, p_font);
	Pond_DrawText(hellotext, 10, 120, blue, 2, 2, p_font);
	Pond_DrawText(hellotext, 10, 150, yellow, 3, 3, p_font);
	Pond_DrawText(hellotext, 10, 190, pink, 4, 4, p_font);
	
	char* text = "Wow!";
	Pond_Vector2Int anchor = Pond_GetTextDimensions(text, p_font);
	anchor.x /= 2 * 3;
	anchor.y /= 2 * 3;
	Pond_DrawTextAdvanced(text, 250, 300, green, 10, 10, p_font, 10, anchor);
}


