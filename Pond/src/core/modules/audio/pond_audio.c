#include "pond_audio.h"
#include <memory.h>


/// <summary>
/// Initialises the Pond-Audio System.
/// </summary>
/// <param name="_soundchannelcount">- amount of channels to open, can be changed later (max defined with POND_SOUND_CHANNELS_MAX)</param>
/// <param name="_soundvolume">- default volume for all the soundchannels (range is 0-128), can be changed later</param>
/// <param name="_musicvolume">- default volume for music (range is 0-128), can be changed later</param>
/// <returns>returns 1 if successful</returns>
int Pond_InitAudioSystem(int _soundchannelcount, int _soundvolume, int _musicvolume)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024))
	{
		return 0;
	}
	
	if (_soundchannelcount > POND_SOUND_CHANNELS_MAX)
		_soundchannelcount = POND_SOUND_CHANNELS_MAX;
	else if (_soundchannelcount < 0)
		_soundchannelcount = 0;
	
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

	return 1;
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// SOUND
#pragma region Sound

/// <summary>
/// Loads a sound-file with given filetype and returns a Pond_Sound pointer.
/// Returned pointer is allocated in memory, can be freed with Pond_FreeSound.
/// </summary>
/// <param name="_filepath">- the filepath </param>
/// <param name="_filetype">- the filetype of the sound to load (currently supports only WAV-files)</param>
/// <returns></returns>
Pond_Sound* Pond_LoadSound(char* _filepath, POND_AUDIO_FILE_TYPE _filetype)
{
	Pond_Sound* p_sound = malloc(sizeof(Pond_Sound));
	memset(p_sound, 0, sizeof(Pond_Sound));

	if (_filetype == POND_AUDIO_FILE_TYPE_WAV)
		p_sound->p_audioChunk = Mix_LoadWAV(_filepath);

	return p_sound;
}

/// <summary>
/// Plays passed sound through passed soundchannel.
/// </summary>
/// <param name="_p_sound">- the sound to play</param>
/// <param name="_soundchannel">- the soundchannel to play through</param>
/// <returns></returns>
int Pond_PlaySound(Pond_Sound* _p_sound, int _soundchannel)
{
	if (_soundchannel < 0 || _soundchannel > Pond_GetChannelCount() - 1)
		return 0;

	Mix_PlayChannel(_soundchannel, _p_sound->p_audioChunk, 0);

	return 1;
}

/// <summary>
/// Frees allocated Pond_Sound pointer memory space.
/// </summary>
/// <param name="_p_sound">- the pointer to free</param>
/// <returns></returns>
int Pond_FreeSound(Pond_Sound* _p_sound)
{
	// checks if pointer is not a null pointer, could be if memory was not freed for pointer, would throw error at free
	if (_p_sound == NULL)
		return 0;

	Mix_FreeChunk(_p_sound->p_audioChunk);
	free(_p_sound);

	return 1;
}
#pragma endregion

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// CHANNEL
#pragma region Channel

/// <summary>
/// Sets the volume of the passed channel (volume ranges 0-128).
/// Could fail if passed channel index is smaller then 0 or higher then highest channel index. 
/// Channel count can be checked with Pond_GetChannelCount().
/// </summary>
/// <param name="_channelindex">- index of the channel to change volume</param>
/// <param name="_volume">- the volume to set the channel volume to</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
int Pond_SetChannelVolume(int _channelindex, int _volume)
{
	if (_channelindex < 0 || _channelindex > Pond_GetChannelCount() - 1)
		return 0;

	Mix_Volume(_channelindex, _volume);
	return 1;
}

/// <summary>
/// Returns the volume of passed channel.
/// </summary>
/// <param name="_soundchannel">- index of channel to get volume from</param>
/// <returns>returns volume of channel, returns -1 if unsuccessful (is the passed index in range of channel count?)</returns>
int Pond_GetChannelVolume(int _channelindex)
{
	if (_channelindex < 0 || _channelindex > Pond_GetChannelCount() - 1)
		return -1;

	return Mix_Volume(_channelindex, -1);
}

/// <summary>
/// Sets the volume of all channels (volume ranges 0-128).
/// </summary>
/// <param name="_volume">- the volume to set the channels volume to</param>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount())</returns>
int Pond_SetAllChannelVolume(int _volume)
{
	if (Pond_GetChannelCount() <= 0)
		return 0;

	Mix_Volume(-1, _volume);
	return 1;
}

/// <summary>
/// Pauses the passed channel if playing. Channel can be resumed with Pond_ResumeChannel, or by playing a new sound through this channel.
/// </summary>
/// <param name="_channelindex">- index of channel to pause</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
int Pond_PauseChannel(int _channelindex)
{
	if (_channelindex < 0 || _channelindex > Pond_GetChannelCount() - 1)
		return 0;

	Mix_Pause(_channelindex);
	return 1;
}

/// <summary>
/// Pauses all playing sound-channels.
/// </summary>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount())</returns>
int Pond_PauseAllChannels(void)
{
	if (Pond_GetChannelCount() <= 0)
		return 0;

	Mix_Pause(-1);
	return 1;
}

/// <summary>
/// Resumes the passed sound-channel.
/// </summary>
/// <param name="_soundchannel">- index of channel to resume</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
int Pond_ResumeChannel(int _soundchannel)
{
	if (_soundchannel < 0 || _soundchannel > Pond_GetChannelCount() - 1)
		return 0;

	Mix_Resume(_soundchannel);
	return 1;
}

/// <summary>
/// Resumes all sound-channels
/// </summary>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount()</returns>
int Pond_ResumeAllChannels(void)
{
	if (Pond_GetChannelCount() <= 0)
		return 0;

	Mix_Resume(-1);
	return 1;
}

/// <summary>
/// Stops a playing channel.
/// Unlike Pond_PauseChannel a stopped channel can't be resumed other then by playing a new sound in that channel.
/// </summary>
/// <param name="_soundchannel">- index of channel to stop</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
int Pond_StopChannel(int _soundchannel)
{
	if (_soundchannel < 0 || _soundchannel > Pond_GetChannelCount() - 1)
		return 0;

	Mix_HaltChannel(_soundchannel);
	return 1;
}

/// <summary>
/// Stops all playing channels. 
/// Unlike Pond_PauseChannel a stopped channel can't be resumed other then by playing a new sound in that channel.
/// </summary>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount()</returns>
int Pond_StopAllChannels(void)
{
	if (Pond_GetChannelCount() <= 0)
		return 0;

	Mix_HaltChannel(-1);
	return 1;
}

/// <summary>
/// Returns if the passed channel is paused or not.
/// </summary>
/// <param name="_soundchannel">- the index of the channel that is checked if it's paused or not</param>
/// <returns>returns 1 if channel is paused, 0 if not, -1 if something went wrong (is the passed index in range of channel count?)</returns>
int Pond_IsChannelPaused(int _soundchannel)
{
	if (_soundchannel < 0 || _soundchannel > Pond_GetChannelCount() - 1)
		return -1;

	return Mix_Paused(_soundchannel);
}

/// <summary>
/// Sets the amount of sound-channels.
/// If count is higher than previously opened channels, new channels are opened.
/// If count is smaller then obsolete channels are closed and freed.
/// </summary>
/// <param name="_soundchannelcount">- new count of sound-channels (max defined with POND_SOUND_CHANNELS_MAX)</param>
/// <returns>returns 1 if successful</returns>
int Pond_SetChannelCount(int _soundchannelcount)
{
	if (_soundchannelcount > POND_SOUND_CHANNELS_MAX)
		_soundchannelcount = POND_SOUND_CHANNELS_MAX;
	else if (_soundchannelcount < 0)
		_soundchannelcount = 0;

	Mix_AllocateChannels(_soundchannelcount);

	return 1;
}

/// <summary>
/// Returns the amount of open sound-channels.
/// </summary>
/// <returns>returns sound-channel count</returns>
int Pond_GetChannelCount(void)
{
	return Mix_AllocateChannels(-1);
}

/// <summary>
/// Terminates all open sound-channels.
/// Afterwards open sound-channel count will be 0 since no channel is open anymore.
/// </summary>
/// <returns>returns 1 if successful.</returns>
int Pond_TerminateAllChannels(void)
{
	Mix_AllocateChannels(0);
	return 1;
}

#pragma endregion


// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// MUSIC
#pragma region Music
Pond_Music* Pond_LoadMusic(char* _filepath, POND_AUDIO_FILE_TYPE _filetype, bool _loop)
{
	Pond_Music* p_music = malloc(sizeof(Pond_Music));
	memset(p_music, 0, sizeof(Pond_Music));

	p_music->p_musicChunk = Mix_LoadMUS(_filepath);
	if (!p_music->p_musicChunk)
		printf("Pond Error: Loading '%s' didn't work. Further info: %s\n", _filepath, Mix_GetError()); // ERROR-HANDLING

	p_music->loop = _loop;

	return p_music;
}

int Pond_PlayMusic(Pond_Music* _p_music)
{
	if (_p_music == NULL)
		return 0;
	else if (_p_music->p_musicChunk == NULL)
		return 0;

	Mix_PlayMusic(_p_music->p_musicChunk, (_p_music->loop) ? -1 : 0);
	return 1;
}

int Pond_FreeMusic(Pond_Music* _p_music)
{
	if (_p_music == NULL)
		return 0;

	Mix_FreeMusic(_p_music->p_musicChunk);
	free(_p_music);

	return 1;
}
#pragma endregion

