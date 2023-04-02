#pragma once
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"

#define POND_SOUND_CHANNELS_MAX 100
#define POND_VOLUME_MAX 128

typedef struct Pond_Sound
{
	Mix_Chunk* p_audioChunk;
	int volume;

} Pond_Sound;

typedef struct Pond_Music
{
	Mix_Music* p_musicChunk;
	int volume;
	bool loop;

} Pond_Music;


typedef enum POND_AUDIO_FILE_TYPE
{
	POND_AUDIO_FILE_TYPE_WAV = 0,
	POND_AUDIO_FILE_TYPE_OGG,

} POND_AUDIO_FILE_TYPE;

/// <summary>
/// Initialises the Pond-Audio System.
/// </summary>
/// <param name="_soundchannelcount">- amount of channels to open, can be changed later (max defined with POND_SOUND_CHANNELS_MAX)</param>
/// <param name="_channelvolume">- default volume for all soundchannels (range is 0-128), can be changed later</param>
/// <param name="_musicvolume">- default volume for music (range is 0-128), can be changed later</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_InitAudioSystem(int _numberofchannels, int _channelvolume, int _musicvolume);

/// <summary>
/// Loads a sound-file with given filetype and returns a Pond_Sound pointer.
/// Returned pointer is allocated in memory, can be freed with Pond_FreeSound.
/// </summary>
/// <param name="_filepath">- the filepath </param>
/// <param name="_filetype">- the filetype of the sound to load (currently supports only WAV-files)</param>
/// <returns>returns the pointer to allocated Pond_Sound</returns>
POND_API Pond_Sound* Pond_LoadSound(char* _filepath, POND_AUDIO_FILE_TYPE _filetype, int _volume);

/// <summary>
/// Plays passed sound through passed soundchannel.
/// </summary>
/// <param name="_p_sound">- the sound to play</param>
/// <param name="_soundchannel">- the soundchannel to play through</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_PlaySound(Pond_Sound* _p_sound, int _soundchannel);
POND_API int Pond_FreeSound(Pond_Sound* _p_sound);

POND_API int Pond_SetSoundVolume(Pond_Sound* _p_sound, int _volume);
POND_API int Pond_GetSoundVolume(Pond_Sound* _p_sound);
POND_API int Pond_ChangeSoundVolume(Pond_Sound* _p_sound, int _value);


POND_API int Pond_SetChannelVolume(int _soundchannel, int _volume);
POND_API int Pond_GetChannelVolume(int _soundchannel);
POND_API int Pond_ChangeChannelVolume(int _soundchannel, int _value);
POND_API int Pond_ChangeAllChannelVolumes(int _value);

POND_API int Pond_SetAllChannelVolumes(int _volume);
POND_API int Pond_PauseChannel(int _soundchannel);
POND_API int Pond_PauseAllChannels(void);
POND_API int Pond_ResumeChannel(int _soundchannel);
POND_API int Pond_ResumeAllChannels(void);
POND_API int Pond_StopChannel(int _soundchannel);
POND_API int Pond_StopAllChannels(void);
POND_API int Pond_IsChannelPaused(int _soundchannel);
POND_API int Pond_SetChannelCount(int _numberofchannels);
POND_API int Pond_GetChannelCount(void);
POND_API int Pond_TerminateAllChannels(void);

POND_API Pond_Music* Pond_LoadMusic(char* _filepath, POND_AUDIO_FILE_TYPE _filetype, int _volume, bool _loop);
POND_API int Pond_PlayMusic(Pond_Music* _p_music);
POND_API int Pond_FreeMusic(Pond_Music* _p_music);

POND_API int Pond_SetMusicLoop(Pond_Music* _p_music, bool _loop);
POND_API int Pond_SetMusicVolume(Pond_Music* _p_music, int _volume);
POND_API int Pond_ChangeMusicVolume(Pond_Music* _p_music, int _value);
POND_API int Pond_GetMusicVolume(Pond_Music* _p_music);
POND_API int Pond_SetMusicChannelVolume(int _volume);
POND_API int Pond_ChangeMusicChannelVolume(int _value);
POND_API int Pond_GetMusicChannelVolume(void);
POND_API int Pond_GetMusicCombinedVolume(Pond_Music* _p_music);

POND_API int Pond_PauseMusic(void);
POND_API int Pond_ResumeMusic(void);
POND_API int Pond_StopMusic(void);
POND_API int Pond_RestartMusic(void);
POND_API int Pond_IsMusicPlaying(void);
POND_API int Pond_IsMusicPaused(void);

