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

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// SOUND
#pragma region Sound

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
/// <param name="_filepath">- the filepath</param>
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

/// <summary>
/// Frees allocated Pond_Sound pointer memory space.
/// This HAS TO BE USED to free Pond_Music pointer, in comparison to doing it manually with free().
/// </summary>
/// <param name="_p_sound">- the pointer to free</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_FreeSound(Pond_Sound* _p_sound);

/// <summary>
/// Changes the volume of passed sound by the amount of the passed value.
/// Increases sound's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_p_sound">- the sound to change the volume of</param>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_ChangeSoundVolume(Pond_Sound* _p_sound, int _value);

/// <summary>
/// Sets the volume of the passed sound to the passed volume.
/// Volume is clamped between 0-128.
/// </summary>
/// <param name="_p_sound">- the sound to set the volume of</param>
/// <param name="_volume">- the volume to set the sound volume to</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_SetSoundVolume(Pond_Sound* _p_sound, int _volume);

/// <summary>
/// Returns the volume of the passed sound.
/// </summary>
/// <param name="_p_sound">- the sound to get the volume from</param>
/// <returns>returns the volume of the sound, returns -1 if an error occurs</returns>
POND_API int Pond_GetSoundVolume(Pond_Sound* _p_sound);

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
POND_API int Pond_SetChannelVolume(int _soundchannel, int _volume);

/// <summary>
/// Returns the volume of passed channel.
/// </summary>
/// <param name="_soundchannel">- index of channel to get volume from</param>
/// <returns>returns volume of channel, returns -1 if unsuccessful (is the passed index in range of channel count?)</returns>
POND_API int Pond_GetChannelVolume(int _soundchannel);

/// <summary>
/// Changes the volume of passed channel by the amount of the passed value.
/// Increases channel's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_p_sound">- the channel to change the volume of</param>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
POND_API int Pond_ChangeChannelVolume(int _soundchannel, int _value);

/// <summary>
/// Changes the volume of all channels by the amount of the passed value.
/// Increases channel's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount()</returns>
POND_API int Pond_ChangeAllChannelVolumes(int _value);

/// <summary>
/// Sets the volume of all channels (range is 0-128).
/// </summary>
/// <param name="_volume">- the volume to set the channels volume to</param>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount())</returns>
POND_API int Pond_SetAllChannelVolumes(int _volume);

/// <summary>
/// Pauses the passed channel if playing. Channel can be resumed with Pond_ResumeChannel, or by playing a new sound through this channel.
/// </summary>
/// <param name="_channelindex">- index of channel to pause</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
POND_API int Pond_PauseChannel(int _soundchannel);

/// <summary>
/// Pauses all playing sound-channels.
/// </summary>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount())</returns>
POND_API int Pond_PauseAllChannels(void);

/// <summary>
/// Resumes the passed sound-channel.
/// </summary>
/// <param name="_soundchannel">- index of channel to resume</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
POND_API int Pond_ResumeChannel(int _soundchannel);

/// <summary>
/// Resumes all sound-channels.
/// </summary>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount()</returns>
POND_API int Pond_ResumeAllChannels(void);

/// <summary>
/// Stops a playing channel.
/// Unlike Pond_PauseChannel a stopped channel can't be resumed other then by playing a new sound in that channel.
/// </summary>
/// <param name="_soundchannel">- index of channel to stop</param>
/// <returns>returns 1 if successful, 0 if not (is the passed index in range of channel count?)</returns>
POND_API int Pond_StopChannel(int _soundchannel);

/// <summary>
/// Stops all playing channels. 
/// Unlike Pond_PauseChannel a stopped channel can't be resumed other then by playing a new sound in that channel.
/// </summary>
/// <returns>returns 1 if successful, 0 if not (are there channels? Channel count can be checked with Pond_GetChannelCount()</returns>
POND_API int Pond_StopAllChannels(void);

/// <summary>
/// Returns if the passed channel is paused or not.
/// </summary>
/// <param name="_soundchannel">- the index of the channel that is checked if it's paused or not</param>
/// <returns>returns 1 if channel is paused, 0 if not, -1 if something went wrong (is the passed index in range of channel count?)</returns>
POND_API int Pond_IsChannelPaused(int _soundchannel);

/// <summary>
/// Sets the amount of sound-channels.
/// If count is higher than previously opened channels, new channels are opened.
/// If count is smaller then obsolete channels are closed and freed.
/// </summary>
/// <param name="_soundchannelcount">- new count of sound-channels (max defined with POND_SOUND_CHANNELS_MAX)</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetChannelCount(int _numberofchannels);

/// <summary>
/// Returns the amount of open sound-channels.
/// </summary>
/// <returns>returns sound-channel count</returns>
POND_API int Pond_GetChannelCount(void);

/// <summary>
/// Terminates all open sound-channels.
/// Afterwards open sound-channel count will be 0 since no channel is open anymore.
/// </summary>
/// <returns>returns 1 if successful.</returns>
POND_API int Pond_TerminateAllChannels(void);

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
POND_API Pond_Music* Pond_LoadMusic(char* _filepath, POND_AUDIO_FILE_TYPE _filetype, int _volume, bool _loop);

/// <summary>
/// Plays passed music through the music channel.
/// Other music that is currently played will stop.
/// </summary>
/// <param name="_p_music">- the music to play</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_PlayMusic(Pond_Music* _p_music);

/// <summary>
/// Frees allocated Pond_Music pointer memory space.
/// This HAS TO BE USED to free Pond_Music pointer, in comparison to doing it manually with free().
/// </summary>
/// <param name="_p_music">- the pointer to free</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_FreeMusic(Pond_Music* _p_music);

/// <summary>
/// Sets the passed music's loop setting by passed bool
/// </summary>
/// <param name="_p_music">- the music to configure loop setting</param>
/// <param name="_loop">- the bool value to change music's loop setting to</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_SetMusicLoop(Pond_Music* _p_music, bool _loop);

/// <summary>
/// Sets the volume of the passed music to the passed volume.
/// Volume is clamped between 0-128.
/// </summary>
/// <param name="_p_music">- the sound to set the volume of</param>
/// <param name="_volume">- the volume to set the sound volume to</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_SetMusicVolume(Pond_Music* _p_music, int _volume);

/// <summary>
/// Changes the volume of passed music by the amount of the passed value.
/// Increases music's volume if a positive value gets passed, and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_p_music">- the music to change the volume of</param>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful, 0 if not</returns>
POND_API int Pond_ChangeMusicVolume(Pond_Music* _p_music, int _value);

/// <summary>
/// Returns the volume of the passed music.
/// </summary>
/// <param name="_p_music">- the music to get the volume from</param>
/// <returns>returns the volume of the music, returns -1 if an error occurs</returns>
POND_API int Pond_GetMusicVolume(Pond_Music* _p_music);

/// <summary>
/// Sets the volume of the music channel.
/// Volume is clamped between 0-128.
/// </summary>
/// <param name="_volume">- the volume to set the music channel's volume to</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetMusicChannelVolume(int _volume);

/// <summary>
/// Changes the volume of the music channel by the amount of the passed value.
/// Increases music channel's volume if a positive value gets passed and decreases it if a negative value is passed.
/// Volume is clamped between 0 and 128.
/// </summary>
/// <param name="_value">- the value by which amount to change the volume</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_ChangeMusicChannelVolume(int _value);

/// <summary>
/// Returns the volume of the music channel.
/// </summary>
/// <returns>returns volume of music channel</returns>
POND_API int Pond_GetMusicChannelVolume(void);

/// <summary>
/// Returns the volume which is played and results from the volume of the music that is being played and that of the music channel.
/// </summary>
/// <returns>returns the actual music volume which is being played, returns -1 if an error occured</returns>
POND_API int Pond_GetMusicCombinedVolume(Pond_Music* _p_music);

/// <summary>
/// Stops the current playing Music. Music cannot be resumed (use Pond_PauseMusic() to pause music).
/// </summary>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_StopMusic(void);

/// <summary>
/// Pauses current playing music. music can be resumed with Pond_ResumeMusic().
/// </summary>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_PauseMusic(void);

/// <summary>
/// Pauses current playing music. music can be resumed with Pond_ResumeMusic().
/// </summary>
/// <returns>returns 1 if successful, 0 if there is no paused music</returns>
POND_API int Pond_ResumeMusic(void);

/// <summary>
/// Checks if there is music playing.
/// </summary>
/// <returns>returns 1 if there is music playing, 0 if not</returns>
POND_API int Pond_IsMusicPlaying(void);

/// <summary>
/// Checks if there is music paused.
/// </summary>
/// <returns>returns 1 if there is music paused, 0 if not</returns>
POND_API int Pond_IsMusicPaused(void);

#pragma endregion

