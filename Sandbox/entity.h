#pragma once
#include "pond.h"
#include <memory.h>

typedef struct Entity
{
	// Pond_Sprite* p_sprite;
	// Pond_Texture* tex;
	Pond_Sprite* p_sprite;
	Pond_Vector2Int pos;

} Entity;


Entity* CreateEntity(int _x, int _y, Pond_Texture* _p_tex);