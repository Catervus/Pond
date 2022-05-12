#include "pond_random.h"

int InitRandomSystem(void)
{
	srand(time(NULL));
	return 1;
}

// max value is inclusive
int Pond_GetRandomInt(int _min, int _max)
{
	int value = 0;

	if (_min >= _max)
		return -1;

	int diff;
	diff = _max - _min;
	value = (rand() % (diff + 1)) + _min;

	return value;
}

float Pond_GetRandomFloat(float _min, float _max)
{

	float value = 0.0;

	if (_min >= _max)
		return -1;

	float diff;
	diff = _max - _min;

	value = (float)rand() / (float)(RAND_MAX / _max);

	return value;
}
