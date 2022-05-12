#pragma once
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"

typedef struct Pond_Sound
{
	Mix_Chunk* p_audioChunk;
	int audioChannel;

} Pond_Sound;

typedef struct Pond_Music
{
	Mix_Music* p_musicChunk;
	bool loop;

} Pond_Music;


typedef enum POND_AUDIO_FILE_TYPE
{
	POND_AUDIO_FILE_TYPE_WAV = 0,
	POND_AUDIO_FILE_TYPE_OGG,
} POND_AUDIO_FILE_TYPE;

POND_API Pond_Sound* Pond_LoadSound(char* _filename, POND_AUDIO_FILE_TYPE _filetype);
POND_API int Pond_PlaySound(Pond_Sound* _p_sound, int _soundchannel);
POND_API int Pond_FreeSound(Pond_Sound* _p_sound);

POND_API Pond_Music* Pond_LoadMusic(char* _filename, POND_AUDIO_FILE_TYPE _filetype);
POND_API int Pond_PlayMusic(Pond_Music* _p_music);
POND_API int Pond_FreeMusic(Pond_Music* _p_music);