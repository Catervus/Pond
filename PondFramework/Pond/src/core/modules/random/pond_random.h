#pragma once
#include "../../pond_core.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int InitRandomSystem(void);

POND_API double Pond_NoiseTest(void);

/// <summary>
/// Sets the seed used by the random system to generate random values.
/// The default seed is set with time.
/// </summary>
/// <param name="_seed">- the seed to use</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetRandomSystemSeed(unsigned int _seed);

/// <summary>
/// Gets a random integer value in between the passed min and max values.
/// (Min and max values are INCLUSIVE)
/// </summary>
/// <param name="_min">- the min of the random value range (inclusive)</param>
/// <param name="_max">- the max of the random value range (inclusive)</param>
/// <returns> random int value</returns>
POND_API int Pond_GetRandomInt(int _min, int _max);

/// <summary>
/// Gets a random float value in between the passed min and max values.
/// (Min and max values are INCLUSIVE)
/// </summary>
/// <param name="_min">- the min of the random value range (inclusive)</param>
/// <param name="_max">- the max of the random value range (inclusive)</param>
/// <returns> random float value</returns>
POND_API float Pond_GetRandomFloat(float _min, float _max);
