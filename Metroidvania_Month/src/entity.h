#pragma once
#include <pond.h>
#include "settings.h"
#include "main.h"

typedef struct Entity Entity;
struct Entity
{
	Pond_Sprite* p_sprite;
	Pond_Vector2Float position;
	Pond_Vector2Float velocity;

	Entity* p_nextEntity;

};

Entity entityHead;
Entity* p_entityTail;

Entity* p_player;
Entity* p_fireball;

Entity* CreateEntity(Pond_Texture* _p_tex, int _x, int _y);
bool CheckForBoxCollision(Entity* _p_entity, Pond_Rect _box);
void EntityDraw(void);
void EntityUpdate(void);





