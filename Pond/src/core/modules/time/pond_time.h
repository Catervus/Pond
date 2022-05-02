#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"

Uint16 engineFPS;
Uint16 newEngineFPS;

int InitTime(Uint16 _fpscap);

POND_API void Pond_ChangeFPS(Uint16 _fpscap);

POND_API int Pond_GetDeltaTime(void);



