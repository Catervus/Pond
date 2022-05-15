#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Sound* p_testSound;
Pond_Music* p_testMusic;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, 700, 700);

	return 0;
}

void Init(void) 
{
	Pond_SetRenderClearColour(white);
	
	p_testSound = Pond_LoadSound("assets/sound.wav", POND_AUDIO_FILE_TYPE_WAV , POND_VOLUME_MAX);
	p_testMusic = Pond_LoadMusic("assets/music.mp3", -1, 20, true);

	Pond_PlayMusic(p_testMusic);
}


void Update(void)
{
	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		if (!Pond_PlaySound(p_testSound, 0))
			printf("That didn't work out!");
	}

	if (Pond_GetKey(POND_KEYBOARD_KEY_UP))
	{
		Pond_ChangeSoundVolume(p_testSound, 1);
	}
	if (Pond_GetKey(POND_KEYBOARD_KEY_DOWN))
	{
		Pond_ChangeSoundVolume(p_testSound, -1);
	}

	printf("Volume: %i\n", p_testSound->volume);

}

void ChannelStopped(int _channel)
{
	printf("Channel has stopped playing!\n");
}

void Draw(void)
{

}

