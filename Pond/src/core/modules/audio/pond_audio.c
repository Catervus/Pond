#include "pond_audio.h"
#include <memory.h>


/// <summary>
/// Initialises the Pond-Audio System.
/// </summary>
/// <param name="_soundchannelcount">- amount of channels to open, can be changed later (max defined with POND_SOUND_CHANNELS_MAX)</param>
/// <param name="_channelvolume">- default volume for all soundchannels (range is 0-128), can be changed later</param>
/// <param name="_musicvolume">- default volume for music (range is 0-128), can be changed later</param>
/// <returns>returns 1 if successful</returns>
int Pond_InitAudioSystem(int _soundchannelcount, int _channelvolume, int _musicchannelvolume)
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

	if (_channelvolume < 0)
		_channelvolume = 0;

	for (int i = 0; i < _soundchannelcount; i++)
	{
		Mix_Volume(i, _channelvolume); // 1 = SFX_VOLUME
	}

	if (_musicchannelvolume < 0)
		_musicchannelvolume = 0;
	Mix_VolumeMusic(_musicchannelvolume); // 2 = MUSIC_VOLUME

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
/// <param name="_filepath">- the filepath</param>
/// <param name="_filetype">- the filetype of the sound to load (currently supports only WAV-files)</param>
/// <returns>returns the pointer to allocated Pond_Sound</returns>
Pond_Sound* Pond_LoadSound(char* _filepath, POND_AUDIO_FILE_TYPE _filetype, int _volume)
{
	Pond_Sound* p_sound = malloc(sizeof(Pond_Sound));
	memset(p_sound, 0, sizeof(Pond_Sound));

	if (_filetype == POND_AUDIO_FILE_TYPE_WAV)
		p_sound->p_audioChunk = Mix_LoadWAV(_filepath);

	if (p_sound->p_audioChunk == NULL)
		return; // ERROR

	// p_sound->p_audioChunk->volume = _volume;
	p_sound->volume = _volume;

	return p_sound;
}

/// <summary>
/// Plays passed sound through passed soundchannel.
/// </summary>
/// <param name="_p_sound">- the sound to play</param>
/// <param name="_soundchannel">- the soundchannel to play through</param>
/// <returns>returns 1 if successful, 0 if not</returns>
int Pond_PlaySound(Pond_Sound* _p_sound, int _soundchannel)
{
	if (_soundchannel < 0 || _soundchannel > Pond_GetChannelCount() - 1)
		return 0;

	_p_sound->p_audioChunk->volume = _p_sound->volume;
	Mix_PlayChannel(_soundchannel, _p_sound->p_audioChunk, 0);

	return 1;
}

/// <summary>
/// Frees allocated Pond_Sound pointer memory space.
/// This HAS TO BE USED to free Pond_Music pointer, in comparison to doing it manually with free().
/// </summary>
/// <param name="_p_sound">- the pointer to free</param>
/// <returns>returns 1 if successful, 0 if not</returns>
int Pond_FreeSound(Pond_Sound* _p_sound)
{
	// checks if pointer is not a null pointer, could be if memory was not freed for pointer, would throw error at free
	if (_p_sound == NULL)
		return 0;

	Mix_FreeChunk(_p_sound->p_audioChunk);
	free(_p_sound);

	return 1;
}

/// <summary>
/// Changes the volume of passed sound by the amount of the passed value.
/// Increases sound's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_p_sound">- the sound to change the volume of</param>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not</returns>
int Pond_ChangeSoundVolume(Pond_Sound* _p_sound, int _value)
{
	if (_p_sound == NULL)
		return 0;

	_p_sound->volume += _value;
	if (_p_sound->volume > POND_VOLUME_MAX)
		_p_sound->volume = POND_VOLUME_MAX;
	if (_p_sound->volume < 0)
		_p_sound->volume = 0;

	return 1;
}

/// <summary>
/// Sets the volume of the passed sound to the passed volume.
/// Volume is clamped between 0-128.
/// </summary>
/// <param name="_p_sound">- the sound to set the volume of</param>
/// <param name="_volume">- the volume to set the sound volume to</param>
/// <returns>returns 1 if successful, 0 if not</returns>
int Pond_SetSoundVolume(Pond_Sound* _p_sound, int _volume)
{
	if (_p_sound == NULL)
		return 0;

	if (_volume > POND_VOLUME_MAX)
		_volume = POND_VOLUME_MAX;
	else if (_volume < 0)
		_volume = 0;

	_p_sound->volume = _volume;

	return 1;
}

/// <summary>
/// Returns the volume of the passed sound.
/// </summary>
/// <param name="_p_sound">- the sound to get the volume from</param>
/// <returns>returns the volume of the sound, returns -1 if an error occurs</returns>
int Pond_GetSoundVolume(Pond_Sound* _p_sound)
{
	if (_p_sound == NULL)
		return -1;

	return _p_sound->volume;
}

#pragma endregion

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// CHANNEL
#pragma region Channel

/// <summary>
/// Sets the volume of the passed channel (range is 0-128).
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
/// Changes the volume of passed channel by the amount of the passed value.
/// Increases channel's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_p_sound">- the channel to change the volume of</param>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
int Pond_ChangeChannelVolume(int _channelindex, int _value)
{
	if (_channelindex < 0 || _channelindex > Pond_GetChannelCount() - 1)
		return 0;


	int volume = Pond_GetChannelVolume(_channelindex) + _value;
	
	if (volume > POND_VOLUME_MAX)
		volume = POND_VOLUME_MAX;
	if (volume < 0)
		volume = 0;

	Mix_Volume(_channelindex, volume);

	return 1;
}

/// <summary>
/// Changes the volume of all channels by the amount of the passed value.
/// Increases channel's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount()</returns>
int Pond_ChangeAllChannelVolumes(int _value)
{
	int channelcount = Pond_GetChannelCount();
	if (channelcount <= 0)
		return 0;

	for (int i = 0; i < channelcount; i++)
	{
		Pond_ChangeChannelVolume(i, _value);
	}
	
	return 1;
}


/// <summary>
/// Sets the volume of all channels (range is 0-128).
/// </summary>
/// <param name="_volume">- the volume to set the channels volume to</param>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount())</returns>
int Pond_SetAllChannelVolumes(int _volume)
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

/// <summary>
/// Loads a music file with given filetype and returns a Pond_Music pointer.
/// Returned pointer is allocated in memory, can be freed with Pond_FreeMusic.
/// </summary>
/// <param name="_filepath">- the filepath </param>
/// <param name="_filetype">- the filetype of the sound to load (currently supports only WAV-files)</param>
/// /// <param name="_volume">- the volume of the loaded music (can be changed later)</param>
/// /// <param name="_loop">- if the music should loop or not (can be changed later</param>
/// <returns>returns the pointer to allocated Pond_Music</returns>
Pond_Music* Pond_LoadMusic(char* _filepath, POND_AUDIO_FILE_TYPE _filetype, int _volume, bool _loop)
{
	Pond_Music* p_music = malloc(sizeof(Pond_Music));
	memset(p_music, 0, sizeof(Pond_Music));

	p_music->p_musicChunk = Mix_LoadMUS(_filepath);
	if (!p_music->p_musicChunk)
		printf("Pond Error: Loading '%s' didn't work. Further info: %s\n", _filepath, Mix_GetError()); // ERROR-HANDLING

	if (_volume > POND_VOLUME_MAX)
		_volume = POND_VOLUME_MAX;
	else if (_volume < 0)
		_volume = 0;

	p_music->volume = _volume;
	p_music->loop = _loop;

	return p_music;
}

/// <summary>
/// Plays passed music through the music channel.
/// Other music that is currently played will stop.
/// </summary>
/// <param name="_p_music">- the music to play</param>
/// <returns>returns 1 if successful, 0 if not</returns>
int Pond_PlayMusic(Pond_Music* _p_music)
{
	if (_p_music == NULL)
		return 0;
	else if (_p_music->p_musicChunk == NULL)
		return 0;

	int channelvolume = Pond_GetMusicChannelVolume();
	int volume = (_p_music->volume + channelvolume) / 2;

	if (_p_music->volume <= 0 || channelvolume <= 0)
		volume = 0;

	Mix_VolumeMusic(volume);
	Mix_PlayMusic(_p_music->p_musicChunk, (_p_music->loop) ? -1 : 0);
	return 1;
}

/// <summary>
/// Frees allocated Pond_Music pointer memory space.
/// This HAS TO BE USED to free Pond_Music pointer, in comparison to doing it manually with free().
/// </summary>
/// <param name="_p_music">- the pointer to free</param>
/// <returns>returns 1 if successful, 0 if not</returns>
int Pond_FreeMusic(Pond_Music* _p_music)
{
	if (_p_music == NULL)
		return 0;

	Mix_FreeMusic(_p_music->p_musicChunk);
	free(_p_music);

	return 1;
}

/// <summary>
/// Sets the passed music's loop setting by passed bool
/// </summary>
/// <param name="_p_music">- the music to configure loop setting</param>
/// <param name="_loop">- the bool value to change music's loop setting to</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_SetMusicLoop(Pond_Music* _p_music, bool _loop)
{
	if (_p_music == NULL)
		return 0;

	_p_music->loop = _loop;

	return 1;
}

/// <summary>
/// Sets the volume of the passed music to the passed volume.
/// Volume is clamped between 0-128.
/// </summary>
/// <param name="_p_music">- the sound to set the volume of</param>
/// <param name="_volume">- the volume to set the sound volume to</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_SetMusicVolume(Pond_Music* _p_music, int _volume)
{
	if (_p_music == NULL)
		return 0;

	if (_volume > POND_VOLUME_MAX)
		_volume = POND_VOLUME_MAX;
	else if (_volume < 0)
		_volume = 0;

	_p_music->volume = _volume;

	return 1;
}

/// <summary>
/// Changes the volume of passed music by the amount of the passed value.
/// Increases music's volume if a positive value gets passed, and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_p_music">- the music to change the volume of</param>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_ChangeMusicVolume(Pond_Music* _p_music, int _value)
{
	if (_p_music == NULL)
		return 0;

	_p_music->volume += _value;
	if (_p_music->volume > POND_VOLUME_MAX)
		_p_music->volume = POND_VOLUME_MAX;
	if (_p_music->volume < 0)
		_p_music->volume = 0;

	return 1;
}

/// <summary>
/// Returns the volume of the passed music.
/// </summary>
/// <param name="_p_music">- the music to get the volume from</param>
/// <returns>returns the volume of the music, returns -1 if an error occurs</returns>
POND_API int Pond_GetMusicVolume(Pond_Music* _p_music)
{
	if (_p_music == NULL)
		return -1;

	return _p_music->volume;
}

/// <summary>
/// Sets the volume of the music channel.
/// Volume is clamped between 0-128.
/// </summary>
/// <param name="_volume">- the volume to set the music channel's volume to</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetMusicChannelVolume(int _volume)
{
	if (_volume < 0)
		_volume = 0;

	Mix_VolumeMusic(_volume);

	return 1;
}

/// <summary>
/// Changes the volume of the music channel by the amount of the passed value.
/// Increases music channel's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_ChangeMusicChannelVolume(int _value)
{

	int volume = Pond_GetMusicChannelVolume() + _value;

	if (volume > POND_VOLUME_MAX)
		volume = POND_VOLUME_MAX;
	if (volume < 0)
		volume = 0;

	Mix_VolumeMusic(volume);

	return 1;
}

/// <summary>
/// Returns the volume of the music channel.
/// </summary>
/// <returns>returns volume of music channel</returns>
POND_API int Pond_GetMusicChannelVolume(void)
{
	return Mix_VolumeMusic(-1);
}

/// <summary>
/// Returns the volume which is played and results from the volume of the music that is being played and that of the music channel.
/// </summary>
/// <returns>returns the actual music volume which is being played, returns -1 if an error occured</returns>
POND_API int Pond_GetMusicCombinedVolume(Pond_Music* _p_music)
{
	if (_p_music == NULL)
		return -1;

	int channelvolume = Pond_GetMusicChannelVolume();
	int volume = (_p_music->volume + channelvolume) / 2;

	if (_p_music->volume <= 0 || channelvolume <= 0)
		volume = 0;

	return volume;
}

/// <summary>
/// Stops the current playing music. music cannot be resumed (use Pond_PauseMusic() to pause music).
/// </summary>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_StopMusic(void)
{
	Mix_HaltMusic();

	return 1;
}

/// <summary>
/// Pauses current playing music. music can be resumed with Pond_ResumeMusic().
/// </summary>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_PauseMusic(void)
{
	Mix_PauseMusic();

	return 1;
}

/// <summary>
/// Pauses current playing music. music can be resumed with Pond_ResumeMusic().
/// </summary>
/// <returns>returns 1 if successful, 0 if there is no paused music</returns>
POND_API int Pond_ResumeMusic(void)
{
	if (!Mix_PlayingMusic())
		return 0;

	Mix_ResumeMusic();

	return 1;
}

/// <summary>
/// Checks if there is music playing.
/// </summary>
/// <returns>returns 1 if there is music playing, 0 if not</returns>
POND_API int Pond_IsMusicPlaying(void)
{
	if (Mix_PlayingMusic())
		return 1;

	return 0;
}

/// <summary>
/// Checks if there is music paused.
/// </summary>
/// <returns>returns 1 if there is music paused, 0 if not</returns>
POND_API int Pond_IsMusicPaused(void)
{
	if (Mix_PausedMusic())
		return 1;

	return 0;
}

#pragma endregion

