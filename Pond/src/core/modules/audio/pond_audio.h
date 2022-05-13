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

POND_API int Pond_InitAudioSystem(int _numberofchannels, int _soundvolume, int _musicvolume);

POND_API Pond_Sound* Pond_LoadSound(char* _filename, POND_AUDIO_FILE_TYPE _filetype);
POND_API int Pond_PlaySound(Pond_Sound* _p_sound, int _soundchannel);
POND_API int Pond_FreeSound(Pond_Sound* _p_sound);

POND_API int Pond_SetChannelVolume(int _soundchannel, int _volume);
POND_API int Pond_GetChannelVolume(int _soundchannel, int _volume);
POND_API int Pond_SetAllChannelVolume(int _volume);
POND_API int Pond_PauseChannel(int _soundchannel);
POND_API int Pond_ResumeChannel(int _soundchannel);
POND_API int Pond_IsChannelPaused(int _soundchannel);
POND_API int Pond_SetChannelCount(int _numberofchannels);

POND_API Pond_Music* Pond_LoadMusic(char* _filename, POND_AUDIO_FILE_TYPE _filetype, bool _loop);
POND_API int Pond_PlayMusic(Pond_Music* _p_music);
POND_API int Pond_FreeMusic(Pond_Music* _p_music);

POND_API int Pond_SetMusicVolume(Pond_Music* _p_music, int _volume);

