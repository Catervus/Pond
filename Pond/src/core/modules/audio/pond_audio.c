#include "pond_audio.h"

Mix_Chunk* Pond_LoadWav(char* _filename)
{
	return Mix_LoadWAV(_filename);
}

int Pond_PlaySound(Mix_Chunk* _p_chunk, int _channel)
{
	Mix_PlayChannel(_channel, _p_chunk, 0);
	printf("Test Info: Played Sound!\n");
}