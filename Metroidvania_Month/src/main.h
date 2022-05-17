#pragma once
#include <pond.h>
#include <math.h>
#include <malloc.h>

#define SCALE 5
#define SCREEN_WIDTH 160 * SCALE
#define SCREEN_HEIGHT 144 * SCALE

#include "entity.h"
#include "player.h"

void Init(void);
void Update(void);
void Draw(void);

void CreateBox(int _x, int _y, int _w, int _h);

Pond_Rect boxes[10];
int boxCount;