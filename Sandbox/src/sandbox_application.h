#pragma once
#include <stdio.h>
#include "pond.h"

void Init(void);
void Update(void);
void Draw(void);

#define ENTITY_COUNT 100
#define RECT_SIZE 10

typedef struct Entity
{
	Pond_Rect rect;
	Pond_Vector2Int pos;
	Pond_Colour col;

	int size;
	bool active;

} Entity;

Entity CreateEntity(Pond_Vector2Int _pos, Pond_Colour _col, int _size);
void ClearAllEntities(void);
Entity entities[ENTITY_COUNT];
int entityIndex = 0;
int entityCounter = 0;