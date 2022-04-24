#include "pond_time.h"

int InitTime(Uint16 _fpscap)
{
	///*engineFPS = (1000.0 / _fpscap);
	//newEngineFPS = (1000.0 / _fpscap);*/


	return 1;
}


POND_API void Pond_ChangeFPS(Uint16 _fpscap)
{
	//newEngineFPS = (1000.0 / _fpscap);
	newEngineFPS = _fpscap;
}

POND_API int Pond_GetDeltaTime(void);