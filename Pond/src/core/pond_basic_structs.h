#pragma once
#include "pond_core.h"
#include "pond_extern_includes.h"

POND_API typedef struct Pond_Point
{
	int x;
	int y;

} Pond_Vector2Int;

POND_API typedef struct Pond_Colour
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;

} Pond_Colour;