#pragma once
#include "main.h"
#include "entity.h"

#define PLAYER_VELOCITY_MAX 1.25 * SCALE
#define PLAYER_ACCELERATION 0.15 * SCALE
#define PLAYER_VELOCITY_MIN 0.0125 * SCALE
#define PLAYER_FRICTION_MULTIPLIER 0.92

#define PLAYER_JUMP_FORCE 3.9 * SCALE;
#define PLAYER_JUMP_TIME 20 // jump input buffer
#define PLAYER_GROUNDED_TIME 6 // coyote time

#define GRAVITY 0.225 * SCALE
#define GRAVITY_LIGHT 0.125 * SCALE;

Entity* CreateEntity(Pond_Texture* _p_tex, int _x, int _y);
void EntityUpdate(void);
void PlayerWalkMovement(void);
void GetPlayerInput(void);

bool CheckForBoxCollision(Entity* _p_entity, Pond_Rect _box);

Entity* p_player;
Entity* p_fireball;