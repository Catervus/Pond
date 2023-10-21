#pragma once
#include "sandbox_application.h"

typedef struct Entity Entity;

struct Entity
{
	int x;
	int y;

	Pond_Colour col;

	Entity* p_next;
};

Entity entityHead;

void CreateEntity(int _x, int _y, Pond_Colour _col);
void EntityUpdate();
void EntityDraw();
