#include "player.h"

int xInput = 0;
float jumpTimer;
float groundedTimer = 0;

float gravity = GRAVITY;

Entity* CreateEntity(Pond_Texture* _p_tex, int _x, int _y)
{
	Entity* p_entity = malloc(sizeof(Entity));
	memset(p_entity, 0, sizeof(Entity));

	p_entity->p_sprite = Pond_InitSprite(_p_tex);

	p_entity->position.x = _x;
	p_entity->position.y = _y;
}


void EntityUpdate(void)
{
	GetPlayerInput(); // Getting Input

	PlayerWalkMovement();
	if (p_player->position.x < 0 - 16 * SCALE)
	{
		p_player->position.x = SCREEN_WIDTH - 1;
	}
	else if (p_player->position.x > SCREEN_WIDTH)
		p_player->position.x = 0 - 16 * SCALE + 1;

	p_player->velocity.y += gravity; // gravity

	/*for (int i = 0; i < boxCount; i++)
	{
		if (CheckForBoxCollision(p_player, boxes[i]))
		{
			p_player->velocity.y = 0;
			p_player->position.y = boxes[i].y - 16 * SCALE;
			groundedTimer = PLAYER_GROUNDED_TIME;
		}
	}*/

	if (--jumpTimer > 0) // if jump buffer is up -> should jump when grounded
	{
		if (groundedTimer > 0) // if coyote time is up
		{
			p_player->velocity.y = -PLAYER_JUMP_FORCE; // JUMP
			jumpTimer = 0; // reset jump buffer
			groundedTimer = 0; // reset coyote time
		}

	}

	p_player->position.x += p_player->velocity.x; // add y velocity to position
	p_player->position.y += p_player->velocity.y; // add y velocity to position

	// check if player is grounded
	if (p_player->position.y > SCREEN_HEIGHT - 16 * SCALE)
	{
		p_player->position.y = SCREEN_HEIGHT - 16 * SCALE;
		p_player->velocity.y = 0;
		groundedTimer = PLAYER_GROUNDED_TIME;
	}


	// check if player is putting an input left/right, if not apply friction
	if (xInput == 0)
		p_player->velocity.x *= PLAYER_FRICTION_MULTIPLIER;
	// if player is almost coming to a stop, stop him
	if (fabs(p_player->velocity.x) < PLAYER_VELOCITY_MIN)
		p_player->velocity.x = 0;

	if (p_player->velocity.y >= 0)
	{
		for (int i = 0; i < boxCount; i++)
		{
			if (CheckForBoxCollision(p_player, boxes[i]))
			{
				p_player->velocity.y = 0;
				p_player->position.y = boxes[i].y - 16 * SCALE;
				groundedTimer = PLAYER_GROUNDED_TIME;
			}
		}
	}

	groundedTimer--; // decrease coyote time

}

void PlayerWalkMovement(void)
{
	p_player->velocity.x += PLAYER_ACCELERATION * xInput; // adding left-right movement

	if (p_player->velocity.x > PLAYER_VELOCITY_MAX)
		p_player->velocity.x = PLAYER_VELOCITY_MAX;
	else if (p_player->velocity.x < -PLAYER_VELOCITY_MAX)
		p_player->velocity.x = -PLAYER_VELOCITY_MAX;
}
bool fireBallActive = false;

void GetPlayerInput(void)
{
	xInput = 0;
	if (Pond_GetKey(POND_KEYBOARD_KEY_A))
	{
		xInput = -1;
	}
	else if (Pond_GetKey(POND_KEYBOARD_KEY_D))
	{
		xInput = 1;
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		jumpTimer = PLAYER_JUMP_TIME;
		gravity = GRAVITY_LIGHT;
	}
	if (Pond_GetKeyUp(POND_KEYBOARD_KEY_SPACE))
	{
		gravity = GRAVITY;
	}

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_RETURN))
	{
		// TODO: SPAWN FIREBALL
		// p_fireball = CreateEntity();
		fireBallActive = true;
	}
}

bool CheckForBoxCollision(Entity* _p_entity, Pond_Rect _box)
{
	bool result = false;

	int x1, y1 = 0, w1, h1 = 0;

	x1 = _p_entity->position.x;
	y1 = _p_entity->position.y;
	w1 = 16 * SCALE;
	h1 = 16 * SCALE + 1;

	// if (y1 + h1 >= _box.y)
	if ((y1 + h1 > _box.y && y1 + h1 < _box.y + _box.h))
	{
		if ((x1 > _box.x && x1 < _box.x + _box.w) || (x1 + w1 > _box.x && x1 + w1 < _box.x + _box.w))
			result = true;
	}

	return result;
}