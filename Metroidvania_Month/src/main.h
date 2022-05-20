#pragma once
#include <pond.h>
#include <math.h>
#include <malloc.h>

#include "entity.h"
#include "player.h"
#include "settings.h"

void Init(void);
void Update(void);
void Draw(void);

void CreateBox(int _x, int _y, int _w, int _h);

Pond_Texture* p_playerTexture;
Pond_Texture* p_fireballTexture;

Pond_Rect boxes[10];
int boxCount;