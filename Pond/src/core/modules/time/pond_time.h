#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"

#define POND_FPS_DEFAULT 60
#define POND_FPS_UNLIMITED -1



int InitTimeSystem(int _fpscap);

int UpdateFrameCounter(void);
int HandleFramerateCap(void);
int FPSGetTicks(void);

POND_API int Pond_SetFPS(int _fpscap);

int UpdateDeltaTime(void);
POND_API double Pond_GetDeltaTime(void);




