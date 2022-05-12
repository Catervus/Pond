#pragma once
#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"

POND_API Mix_Chunk* Pond_LoadWav(char* _filename);
POND_API int Pond_PlaySound(Mix_Chunk* _p_chunk, int _channel);
