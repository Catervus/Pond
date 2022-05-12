#pragma once
#include "../../pond_core.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int InitRandomSystem(void);
POND_API int Pond_GetRandomInt(int _min, int _max);
POND_API float Pond_GetRandomFloat(float _min, float _max);