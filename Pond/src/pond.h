#pragma once
#include "core/pond_includes.h"

#define Pond_GetArraySize(Array) sizeof(Array)/sizeof(Array[0])

POND_API void Pond_Init(void (*_init)(void), void (*_update)(void), void (_draw)(void));
POND_API void Pond_Run(int _fps);

static void Cleanup(void);

static void (*EngineInit)(void);
static void (*EngineUpdate)(void);
static void (*EngineDraw)(void);

// -----------------------------
// - SETTINGS -
// fps
static Uint16 engineFPS;
static Uint16 newEngineFPS;

void SetEngineFPS();
POND_API Pond_ChangeFPS(Uint16 _fps);
// window settings

