#include "entity.h"

Entity* CreateEntity(Pond_Texture* _p_tex, int _x, int _y)
{
	Entity* p_entity = malloc(sizeof(Entity));
	memset(p_entity, 0, sizeof(Entity));

	p_entity->p_sprite = Pond_InitSprite(_p_tex);

	p_entity->position.x = _x;
	p_entity->position.y = _y;

	p_entityTail->p_nextEntity = p_entity;
	p_entityTail = p_entity;

	return p_entity;
}

void EntityUpdate(void)
{
	Entity* p_e;

	for (p_e = entityHead.p_nextEntity; p_e != NULL; p_e = p_e->p_nextEntity)
	{
		p_e->position.x += p_e->velocity.x; // add y velocity to position
		p_e->position.y += p_e->velocity.y; // add y velocity to position
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



void EntityDraw(void)
{
	Entity* p_e;

	for (p_e = entityHead.p_nextEntity; p_e != NULL; p_e = p_e->p_nextEntity)
	{
		Pond_DrawSprite(p_e->p_sprite, p_e->position.x, p_e->position.y, SCALE, SCALE);
	}
}