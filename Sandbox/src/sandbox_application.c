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



Pond_Sound* p_demoSounds[4];
Pond_Music* p_demoMusic[3];


Pond_Texture* p_texture;
Pond_Sprite* p_sprite;
Pond_Texture* p_texture2;
Pond_Texture* p_texture3;
Pond_Font* p_font;
#define SCREEN_WIDTH 600
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define VIEWPORT_DIMENSIONS 800
Pond_Vector2Int cameraPos;
#define CAMERA_SPEED 1000
int cameraMoveSpeed;

bool isWindowResizable = false;

char* screenSizeText = "800x600";

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, SCREEN_WIDTH, SCREEN_HEIGHT, "Pond Window Demo", true);
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


	p_demoSounds[0] = Pond_LoadSound("assets/audio_demo/sound1.wav", POND_AUDIO_FILE_TYPE_WAV, 128);
	p_demoSounds[1] = Pond_LoadSound("assets/audio_demo/sound4.wav", POND_AUDIO_FILE_TYPE_WAV, 128);
	p_demoSounds[2] = Pond_LoadSound("assets/audio_demo/sound3.wav", POND_AUDIO_FILE_TYPE_WAV, 128);
	p_demoSounds[3] = Pond_LoadSound("assets/audio_demo/sound2.wav", POND_AUDIO_FILE_TYPE_WAV, 128);


	p_demoMusic[0] = Pond_LoadMusic("assets/audio_demo/music1.wav", POND_AUDIO_FILE_TYPE_WAV, 30, false);
	p_demoMusic[1] = Pond_LoadMusic("assets/audio_demo/music2.wav", POND_AUDIO_FILE_TYPE_WAV, 30, false);
	p_demoMusic[2] = Pond_LoadMusic("assets/audio_demo/music3.wav", POND_AUDIO_FILE_TYPE_WAV, 30, false);

}

void Update(void)
{

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_1))
	{
		Pond_PlaySound(p_demoSounds[0], 0);
	}

	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_2))
	{
		Pond_PlaySound(p_demoSounds[1], 0);
	}

	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_3))
	{
		Pond_PlaySound(p_demoSounds[2], 1);
	}

	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_4))
	{
		Pond_PlaySound(p_demoSounds[3], 1);
	}

	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_5))
	{
		Pond_PlayMusic(p_demoMusic[0]);
	}
	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_6))
	{
		Pond_PlayMusic(p_demoMusic[1]);
	}
	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_7))
	{
		Pond_PlayMusic(p_demoMusic[2]);
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		Pond_StopAllChannels();
		Pond_StopMusic();
	}
	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_P))
	{
		Pond_PauseMusic();
	}
	else if (Pond_GetKeyDown(POND_KEYBOARD_KEY_R))
	{
		if (Pond_ResumeMusic() == false)
			printf("NO MUSIC!\n");
	}




}

void Draw(void)
{
	Pond_DrawText("1 - Play Sound 1 (in Channel 0)", 1, 10, white, 1, 1, p_font);
	Pond_DrawText("2 - Play Sound 2 (in Channel 0)", 1, 20, white, 1, 1, p_font);
	Pond_DrawText("3 - Play Sound 3 (in Channel 1)", 1, 30, white, 1, 1, p_font);
	Pond_DrawText("4 - Play Sound 4 (in Channel 1)", 1, 40, white, 1, 1, p_font);
	Pond_DrawText("5 - Play Music 1", 1, 50, white, 1, 1, p_font);
	Pond_DrawText("6 - Play Music 2", 1, 60, white, 1, 1, p_font);
	Pond_DrawText("7 - Play Music 3", 1, 70, white, 1, 1, p_font);

	Pond_DrawText("SPACE - Stop all Sounds and Music", 1, 80, white, 1, 1, p_font);
	
}


