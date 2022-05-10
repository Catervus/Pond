#include "pond_random.h"

int InitRandomSystem(void)
{
	srand(time(NULL));
	printf("Initialised Pond-Module Random!\n");
	return 1;
}

int Pond_GetRandomInt(int _min, int _max)
{
	int value = 0;

	if (_min >= _max)
		return -1;

	int diff = _max - _min; // 3

	value = (rand() % diff + 1) + _min;

	return value;
}
