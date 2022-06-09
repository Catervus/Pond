#include "pond_random.h"
#define PI 3.141592653589793

int InitRandomSystem(void)
{
	srand(time(NULL));
	return 1;
}

double Pond_NoiseTest(int _i)
{
	return sin(_i);
}

/// <summary>
/// Set's the seed used by the random system to generate random values.
/// The default seed is set with time.
/// </summary>
/// <param name="_seed">- the seed to use</param>
/// <returns>returns 1 if successful</returns>
int Pond_SetRandomSystemSeed(unsigned int _seed)
{
	srand(_seed);
	return 1;
}

/// <summary>
/// Get's a random integer value in between the passed min and max values.
/// (Min and max values are INCLUSIVE)
/// </summary>
/// <param name="_min">- the min of the random value range (inclusive)</param>
/// <param name="_max">- the max of the random value range (inclusive)</param>
/// <returns> random int value</returns>
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

/// <summary>
/// Get's a random float value in between the passed min and max values.
/// (Min and max values are INCLUSIVE)
/// </summary>
/// <param name="_min">- the min of the random value range (inclusive)</param>
/// <param name="_max">- the max of the random value range (inclusive)</param>
/// <returns> random float value</returns>
float Pond_GetRandomFloat(float _min, float _max)
{
	double value = 0.0;

	if (_min >= _max)
		return -1;

	float diff;
	diff = _max - _min;
	value = (double)rand() / (double)(RAND_MAX) * diff;

	return (float)value + _min;
}
