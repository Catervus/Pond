#include "player.h"

int xInput = 0;
float jumpTimer;
float groundedTimer = 0;

float gravity = GRAVITY;

bool isFacingRight = true;


void PlayerUpdate(void)
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

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_RETURN))
	{
		p_fireball = CreateEntity(p_fireballTexture, p_player->position.x, p_player->position.y);
		if(isFacingRight)
			p_fireball->velocity.x = 15;
		else
		{
			p_fireball->velocity.x = -15;
			p_fireball->p_sprite->flipX = true;
		}


	}
}

void PlayerLateUpdate(void)
{
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

	if (isFacingRight && xInput < 0)
		isFacingRight = !isFacingRight;
	if (!isFacingRight && xInput > 0)
		isFacingRight = !isFacingRight;
}

