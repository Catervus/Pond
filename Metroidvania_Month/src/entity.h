#pragma once
#include <pond.h>
#include <malloc.h>
#include "main.h"
#include <math.h>

#define PLAYER_VELOCITY_MAX 1.25 * SCALE
#define PLAYER_ACCELERATION 0.15 * SCALE
#define PLAYER_VELOCITY_MIN 0.0125 * SCALE
#define PLAYER_FRICTION_MULTIPLIER 0.92

#define PLAYER_JUMP_FORCE 3.9 * SCALE;
#define PLAYER_JUMP_TIME 20 // jump input buffer
#define PLAYER_GROUNDED_TIME 1 // coyote time

#define GRAVITY 0.225 * SCALE
#define GRAVITY_LIGHT 0.125 * SCALE;

typedef struct Entity
{
	Pond_Sprite* p_sprite;
	Pond_Vector2Float position;
	Pond_Vector2Float velocity;

} Entity;

Entity* CreateEntity(Pond_Texture* _p_tex, int _x, int _y);
void EntityUpdate(void);
void PlayerWalkMovement(void);
void GetPlayerInput(void);

Entity* p_player;
