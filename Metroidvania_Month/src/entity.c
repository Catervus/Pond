#include "entity.h"

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
	
	if (--jumpTimer > 0) // if jump buffer is up -> should jump when grounded
	{
		if (groundedTimer > 0) // if coyote time is up
		{
			p_player->velocity.y = -PLAYER_JUMP_FORCE; // JUMP
			jumpTimer = 0; // reset jump buffer
			groundedTimer = 0; // reset coyote time
		}
		
	}

	groundedTimer--; // decrease coyote time

	p_player->velocity.y += gravity; // gravity

	p_player->position.x += p_player->velocity.x; // add y velocity to position
	p_player->position.y += p_player->velocity.y; // add y velocity to position


	// check if player is grounded
	if (p_player->position.y > SCREEN_HEIGHT - 16 * SCALE)
	{
		p_player->position.y = SCREEN_HEIGHT - 16 * SCALE;
		p_player->velocity.y = 0;
		groundedTimer = PLAYER_GROUNDED_TIME;
	}
	else
		groundedTimer = 0;

	// check if player is putting an input left/right, if not apply friction
	if(xInput == 0)
		p_player->velocity.x *= PLAYER_FRICTION_MULTIPLIER;
	// if player is almost coming to a stop, stop him
	if (fabs(p_player->velocity.x) < PLAYER_VELOCITY_MIN)
		p_player->velocity.x = 0;
}

void PlayerWalkMovement(void)
{
	p_player->velocity.x += PLAYER_ACCELERATION * xInput; // adding left-right movement

	if (p_player->velocity.x > PLAYER_VELOCITY_MAX)
		p_player->velocity.x = PLAYER_VELOCITY_MAX;
	else if (p_player->velocity.x < -PLAYER_VELOCITY_MAX)
		p_player->velocity.x = -PLAYER_VELOCITY_MAX;
}

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
}