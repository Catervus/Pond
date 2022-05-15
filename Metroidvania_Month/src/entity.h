#pragma once
#include <pond.h>
#include <malloc.h>
#include "main.h"

typedef struct Entity
{
	Pond_Sprite* p_sprite;
	Pond_Vector2Float position;
	Pond_Vector2Float velocity;

} Entity;

Entity* CreateEntity(Pond_Texture* _p_tex, int _x, int _y);
void EntityUpdate(void);

Entity* p_player;
