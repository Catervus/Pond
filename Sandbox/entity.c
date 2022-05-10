#include "entity.h"

Entity* CreateEntity(int _x, int _y, Pond_Texture* _p_tex)
{
	Entity* p_entity;
	p_entity = (Entity*)malloc(sizeof(Entity));
	memset(p_entity, 0, sizeof(Entity));

	p_entity->pos.x = _x;
	p_entity->pos.y = _y;
	p_entity->p_sprite = Pond_InitSprite(_p_tex);
	// p_entity->tex = _p_tex;

	return p_entity;
}