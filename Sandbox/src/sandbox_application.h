#pragma once
#include <stdio.h>
#include "pond.h"

void Init(void);

void Update(void);

void Draw(void);

typedef struct Entity
{
	Pond_Rect rect;
	Pond_Vector2Int pos;
	bool active;
} Entity;

Entity CreateEntity(Pond_Vector2Int _pos);
Entity entities[100];
int entityCount = 0;