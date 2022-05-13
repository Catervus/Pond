#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Vector2Int mousePos;
Pond_Colour drawColour;

int drawSize = 10;

Pond_Sound* p_testSound;
Pond_Music* p_testMusic;



int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 1, 1);
	Pond_Run(60, 700, 700);

	return 0;
}

Pond_Vector2Int points[5];
void Init(void) 
{
	Pond_SetRenderClearColour(white);

	drawColour = red;

	for (int i = 0; i < 5; i++)
	{
		int x = Pond_GetRandomInt(0, 699);
		int y = Pond_GetRandomInt(0, 699);
		Pond_Vector2Int point = { x, y };
		points[i] = point;
	}

	p_testSound = Pond_LoadSound("assets/sound.wav", POND_AUDIO_FILE_TYPE_WAV);
	p_testMusic = Pond_LoadMusic("assets/music.mp3", -1, 1);

	// Pond_PlaySound(p_testSound, 0);
	// Pond_PlayMusic(p_testMusic);

}

xPos = 10;
yPos = 10;

bool fade = false;

void Update(void)
{
	if (Pond_GetKey(POND_KEYBOARD_KEY_Q))
	{
		Pond_SetChannelVolume(0, Pond_GetChannelVolume(0) - 1);
		printf("Volume: %i\n", Pond_GetChannelVolume(0));
	}
	else if (Pond_GetKey(POND_KEYBOARD_KEY_E))
	{
		Pond_SetChannelVolume(0, Pond_GetChannelVolume(0) + 1);
		printf("Volume: %i\n", Pond_GetChannelVolume(0));
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		if (Pond_PlaySound(p_testSound, 0))
			printf("Sound played!\n");
	}
	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_S))
	{
		if(Pond_PauseChannel(0))
			printf("Channel paused!\n");
	}
	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_W))
	{
		if (Pond_ResumeChannel(0))
			printf("Channel resumed!\n");
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_D))
	{
		if (Pond_IsChannelPaused(0))
			printf("Channel is indeed paused.\n");
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_T))
	{
		if (Pond_TerminateAllChannels(0))
			printf("TERMINATED!\n");
	}
	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_N))
	{
		printf("Number of channels: %i\n", Pond_GetChannelCount());
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_UP))
	{
		fade = true;
	}

	if (fade)
	{
		Pond_SetChannelVolume(0, Pond_GetChannelVolume(0) * 0.99);
		if (Pond_GetChannelVolume(0) <= 0)
			fade = false;
	}

}

void ChannelStopped(int _channel)
{
	printf("Channel has stopped playing!\n");
}

void Draw(void)
{

}

