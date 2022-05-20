#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Sound* p_testSound;
Pond_Music* p_testMusic;

Pond_Texture* p_texture;
Pond_Sprite* p_sprite;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, 700, 700);

	return 0;
}

int x = 100;
int y = 100;

void Init(void) 
{
	Pond_SetRenderClearColour(white);
	
	p_testSound = Pond_LoadSound("assets/sound.wav", POND_AUDIO_FILE_TYPE_WAV , 50);
	p_testMusic = Pond_LoadMusic("assets/music.mp3", -1, 20, true);

	p_texture = Pond_LoadTexture("assets/ledian_pixel.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);
	
	Pond_SetJoystickDeadzoneValue(8000);
	printf("Deadzone Value: %i", Pond_GetJoystickDeadzoneValue());
}


void Update(void)
{
	/*if (Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_Y) > 0)
		y -= 3;
	else if (Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_Y) < 0)
		y += 3;
	else if (Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_X) > 0)
		x += 3;
	else if (Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_X) < 0)
		x -= 3;*/

	x += Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_X, POND_JOYSTICK_INDEX_SECONDARY) * 3;
	y -= Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_Y, POND_JOYSTICK_INDEX_SECONDARY) * 3;
	

	double d = Pond_GetJoystickAxis(POND_JOYSTICK_AXIS_Y, POND_JOYSTICK_INDEX_MAIN);

	if (Pond_GetControllerButtonDown(POND_CONTROLLER_BUTTON_LEFTSTICK))
		Pond_PlaySound(p_testSound, 0);

	// printf("Value: %f\n", d);

}


void Draw(void)
{
	// Pond_DrawTexture(p_texture, 100, 100, 1, 1, 255);
	p_sprite->rotationAngle = 0;
	Pond_DrawSprite(p_sprite, x, y, 1, 1);
}

