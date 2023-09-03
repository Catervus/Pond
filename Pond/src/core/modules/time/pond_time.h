#pragma once
#include "../../pond_core.h"
#include "../../pond_extern_includes.h"

#define POND_FPS_DEFAULT 60
#define POND_FPS_UNLIMITED -1

#pragma region Intern_Functions
int InitTimeSystem(int _fpscap);
int ShutTimeSystem(void);

int UpdateFrameCounter(void);
int HandleFramerateCap(void);

int UpdateDeltaTime(void);
#pragma endregion


/// <summary>
/// Sets the FPS cap starting from the next frame.
/// </summary>
/// <param name="_fpscap">- value to cap FPS at</param>
/// <returns> 1 if successful</returns>
POND_API int Pond_SetFPSCap(int _fpscap);

/// <summary>
/// Gets the current FPS cap.
/// If FPS cap is changed on the same frame, it has not updated yet and thus this function will return the old FPS cap.
/// </summary>
/// <returns> FPS cap as int value</returns>
POND_API int Pond_GetFPSCap(void);

/// <summary>
/// Gets the current FPS.
/// </summary>
/// <returns> FPS as int value</returns>
POND_API int Pond_GetCurrentFPS(void);


/// <summary>
/// Gets the delta time. (Time that has passed since last frame)
/// </summary>
/// <returns> delta time as double value</returns>
POND_API double Pond_GetDeltaTime(void);



