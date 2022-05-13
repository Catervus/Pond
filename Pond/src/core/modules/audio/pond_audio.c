#include "pond_audio.h"
#include <memory.h>

int Pond_InitAudioSystem(int _soundchannelcount, int _soundvolume, int _musicvolume)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024))
	{
		exit(1);
	}

	int maxsoundchannels = 100;
	
	if (_soundchannelcount > maxsoundchannels)
		_soundchannelcount = maxsoundchannels;
	else if (_soundchannelcount < 1)
		_soundchannelcount = 1;
	
	Mix_AllocateChannels(_soundchannelcount);

	if (_soundvolume < 0)
		_soundvolume = 0;

	for (int i = 0; i < _soundchannelcount; i++)
	{
		Mix_Volume(i, _soundvolume); // 1 = SFX_VOLUME
	}

	if (_musicvolume < 0)
		_musicvolume = 0;
	Mix_VolumeMusic(_musicvolume); // 2 = MUSIC_VOLUME
}

// SOUND
Pond_Sound* Pond_LoadSound(char* _filename, POND_AUDIO_FILE_TYPE _filetype)
{
	Pond_Sound* p_sound = malloc(sizeof(Pond_Sound));
	memset(p_sound, 0, sizeof(Pond_Sound));

	if(_filetype == POND_AUDIO_FILE_TYPE_WAV)
		p_sound->p_audioChunk = Mix_LoadWAV(_filename);

	return p_sound;
}

int Pond_PlaySound(Pond_Sound* _p_sound, int _soundchannel)
{
	Mix_PlayChannel(_soundchannel, _p_sound->p_audioChunk, 0);
	printf("Test Info: Played Sound!\n");

	return 1;
}

int Pond_FreeSound(Pond_Sound* _p_sound)
{
	Mix_FreeChunk(_p_sound->p_audioChunk);
	free(_p_sound);

	return 1;
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// MUSIC

Pond_Music* Pond_LoadMusic(char* _filename, POND_AUDIO_FILE_TYPE _filetype, bool _loop)
{
	Pond_Music* p_music = malloc(sizeof(Pond_Music));
	memset(p_music, 0, sizeof(Pond_Music));

	p_music->p_musicChunk = Mix_LoadMUS(_filename);
	if (!p_music->p_musicChunk)
		printf("Pond Error: Loading '%s' didn't work. Further info: %s\n", _filename, Mix_GetError()); // ERROR-HANDLING

	p_music->loop = _loop;

	return p_music;
}

int Pond_PlayMusic(Pond_Music* _p_music)
{
	Mix_PlayMusic(_p_music->p_musicChunk, (_p_music->loop) ? -1 : 0);
}

int Pond_FreeMusic(Pond_Music* _p_music)
{
	Mix_FreeMusic(_p_music->p_musicChunk);
	free(_p_music);
}