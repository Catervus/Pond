#include "entity.h"

void CreateEntity(int _x, int _y, Pond_Colour _col)
{
	if (entityHead.p_next == NULL)
	{
		entityHead.p_next = (Entity*) malloc(sizeof(Entity));
	
		entityHead.p_next->x = _x;
		entityHead.p_next->y = _y;
		entityHead.p_next->col = _col;
		entityHead.p_next->p_next = NULL;
	
		return;
	}

	printf("CreateEntity");
	
	for (Entity* p_e = entityHead.p_next; p_e != NULL; p_e = p_e->p_next)
	{

		if (p_e->p_next == NULL)
		{
			p_e->p_next = (Entity*)malloc(sizeof(Entity));
			p_e->p_next->x = _x;
			p_e->p_next->y = _y;
			p_e->p_next->col = _col;;
			p_e->p_next->p_next = NULL;

			return;
		}
	}

}

void EntityUpdate()
{
	Entity* p_prev = &entityHead;

	for (Entity* p_e = entityHead.p_next; p_e != NULL; p_e = p_e->p_next)
	{
		p_e->y++;

		if (p_e->y > WINDOW_HEIGHT - 100)
		{
			Pond_Colour col = { 100, 100, 100, 255 };
			p_e->col = col;

			p_prev->p_next = p_e->p_next;
			free(p_e);
		}
	}
}

void EntityDraw()
{
	// printf("EntityDraw!\n");
	Entity* p_e;
	for (p_e = entityHead.p_next; p_e != NULL; p_e = p_e->p_next)
	{
		//printf("E!\n");
		Pond_DrawCircle(p_e->x, p_e->y, 10, p_e->col, 1);
	}
}
