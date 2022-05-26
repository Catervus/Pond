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

	p_testSound = Pond_LoadSound("assets/sound.wav", POND_AUDIO_FILE_TYPE_WAV, 50);
	p_testMusic = Pond_LoadMusic("assets/music.mp3", -1, 20, true);

	p_texture = Pond_LoadTexture("assets/ledian_pixel.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);
	
	Pond_SetJoystickDeadzoneValue(8000);
	printf("Deadzone Value: %i\n", Pond_GetJoystickDeadzoneValue());

	Pond_PlaySound(p_testSound, 0);

	Pond_SetWindowSize(1200, 800);

	int i = Pond_GetNumberOfControllers();
	printf("%i Controller(s) has/have been found\n", i);
}


void Update(void)
{

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
		Pond_SetWindowSize(300, 300);

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_LSHIFT))
	{
		Pond_Vector2Int windowsize = Pond_GetWindowSize();
		printf("Window Size:\nX: %i\nY: %i\n\n", windowsize.x, windowsize.y);
	}


	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_ESCAPE))
		Pond_Quit();
}


void Draw(void)
{
	Pond_DrawSprite(p_sprite, x, y, 1, 1);

	Pond_DrawRectByDimensions(100, 100, 50, 50, red, false);
}

