#include "entity.h"

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
	p_player->velocity.y += 0.1 * SCALE;

	p_player->position.x += p_player->velocity.x;
	p_player->position.y += p_player->velocity.y;


	if (p_player->position.y > 700 - 16 * SCALE)
	{
		p_player->position.y = 700 - 16 * SCALE;
		p_player->velocity.y = 0;
	}
}