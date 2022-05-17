#pragma once
#include <pond.h>

typedef struct Entity
{
	Pond_Sprite* p_sprite;
	Pond_Vector2Float position;
	Pond_Vector2Float velocity;

	// Entity* p_nextEntity;

} Entity;




