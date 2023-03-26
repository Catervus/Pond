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


Pond_Colour colours[] =
{
	{ 255, 0, 0, 255 }, // red
	{ 0, 0, 255, 255 }, // blue
	{ 255, 0, 240, 255 }, // pink
	{ 100, 255, 100, 255 }, // green
	{ 255, 255, 100, 255 }, // yellow
};
int currentColourIndex = 0;

Pond_Music* p_testMusic;
Pond_Sound* p_testSound;
Pond_Texture* p_texture;
Pond_Sprite* p_sprite;
Pond_Texture* p_texture2;
Pond_Texture* p_texture3;
Pond_Font* p_font;
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define VIEWPORT_DIMENSIONS 800
Pond_Vector2Int cameraPos;
#define CAMERA_SPEED 1000.0
float cameraMoveSpeed;

#define JOYSTICK_THRESHOLD 0.1

Pond_Vector2Float joystickInput = { 0.0, 0.0 };

bool isWindowResizable = false;

char* screenSizeText = "800x600";

Pond_Vector2Int playerPos = { 100, 100 };

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, SCREEN_WIDTH, SCREEN_HEIGHT, "Pond Input Demo", false);
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
	// if (Pond_GetKey(POND_KEYBOARD_KEY_LEFT) || Pond_GetKey(POND_KEYBOARD_KEY_A))
	// 	cameraPos.x -= cameraMoveSpeed;
	// else if (Pond_GetKey(POND_KEYBOARD_KEY_RIGHT) || Pond_GetKey(POND_KEYBOARD_KEY_D))
	// 	cameraPos.x += cameraMoveSpeed;
	// if (Pond_GetKey(POND_KEYBOARD_KEY_UP) || Pond_GetKey(POND_KEYBOARD_KEY_W))
	// 	cameraPos.y -= cameraMoveSpeed;
	// else if (Pond_GetKey(POND_KEYBOARD_KEY_DOWN) || Pond_GetKey(POND_KEYBOARD_KEY_S))
	// 	cameraPos.y += cameraMoveSpeed;
	// if (Pond_GetKey(POND_KEYBOARD_KEY_SPACE))
	// 	cameraPos.x = cameraPos.y = 0;

	joystickInput.x = Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_X, POND_JOYSTICK_INDEX_MAIN);
	joystickInput.y = Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_Y, POND_JOYSTICK_INDEX_MAIN);

	// UP
	if (Pond_GetKey(POND_KEYBOARD_KEY_W) || Pond_GetKey(POND_KEYBOARD_KEY_UP) ||
		Pond_GetControllerButton(POND_CONTROLLER_BUTTON_DPAD_UP))
	{
		playerPos.y -= cameraMoveSpeed;
	}
	else if (joystickInput.y > JOYSTICK_THRESHOLD)
	{
		playerPos.y -= cameraMoveSpeed * joystickInput.y;
	}

	// DOWN
	if (Pond_GetKey(POND_KEYBOARD_KEY_S) || Pond_GetKey(POND_KEYBOARD_KEY_DOWN) ||
		Pond_GetControllerButton(POND_CONTROLLER_BUTTON_DPAD_DOWN))
	{
		playerPos.y += cameraMoveSpeed;
	}
	else if (joystickInput.y < -JOYSTICK_THRESHOLD)
	{
		playerPos.y -= cameraMoveSpeed * joystickInput.y;
	}

	// LEFT
	if (Pond_GetKey(POND_KEYBOARD_KEY_A) || Pond_GetKey(POND_KEYBOARD_KEY_LEFT) ||
		Pond_GetControllerButton(POND_CONTROLLER_BUTTON_DPAD_LEFT))
	{
		playerPos.x -= cameraMoveSpeed;
	}
	else if (joystickInput.x < -JOYSTICK_THRESHOLD)
	{
		playerPos.x += cameraMoveSpeed * joystickInput.x;
	}

	// RIGHT
	if (Pond_GetKey(POND_KEYBOARD_KEY_D) || Pond_GetKey(POND_KEYBOARD_KEY_RIGHT) ||
		Pond_GetControllerButton(POND_CONTROLLER_BUTTON_DPAD_RIGHT))
	{
		playerPos.x += cameraMoveSpeed;
	}
	else if (joystickInput.x > JOYSTICK_THRESHOLD)
	{
		playerPos.x += cameraMoveSpeed * joystickInput.x;
	}
	

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE) || Pond_GetControllerButtonDown(POND_CONTROLLER_BUTTON_A))
	{
		currentColourIndex++;
		if (currentColourIndex >= Pond_GetArrayLength(colours))
		{
			currentColourIndex = 0;
		}
	}

	if (Pond_GetControllerButtonDown(POND_CONTROLLER_BUTTON_LEFTSHOULDER) ||
		Pond_GetControllerButtonDown(POND_CONTROLLER_BUTTON_LEFTSTICK) ||
		Pond_GetKeyDown(POND_KEYBOARD_KEY_Q))
	{
		currentColourIndex--;
		if (currentColourIndex < 0)
			currentColourIndex = Pond_GetArrayLength(colours) - 1;
	}
	else if (Pond_GetControllerButtonDown(POND_CONTROLLER_BUTTON_RIGHTSHOULDER) ||
		Pond_GetControllerButtonDown(POND_CONTROLLER_BUTTON_RIGHTSTICK) ||
		Pond_GetKeyDown(POND_KEYBOARD_KEY_E))
	{
		currentColourIndex++;
		if (currentColourIndex >= Pond_GetArrayLength(colours))
		{
			currentColourIndex = 0;
		}
	}


}

void Draw(void)
{

	Pond_DrawCircle(playerPos.x, playerPos.y, 50, colours[currentColourIndex], 1);


	Pond_DrawText("WASD -  move", 1, 10, white, 1, 1, p_font);
	Pond_DrawText("Controller Dpad -  move", 1, 20, white, 1, 1, p_font);
	Pond_DrawText("Controller Left Joystick -  move", 1, 30, white, 1, 1, p_font);
	
	Pond_DrawText("Space - change colour", 1, 50, white, 1, 1, p_font);
	Pond_DrawText("Controller A - change colour", 1, 60, white, 1, 1, p_font);

	Pond_DrawText("Q/E - switch through colours", 1, 70, white, 1, 1, p_font);
	Pond_DrawText("Controller LB/RB - switch through colours", 1, 80, white, 1, 1, p_font);

}


