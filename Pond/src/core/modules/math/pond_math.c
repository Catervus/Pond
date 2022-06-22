#include "pond_math.h"
/*
	"If all the components of x-> are zero, it is called the zero vector.
	 If the length of a vector x-> is zero then it is called the null vector.
	 In n dimensional Euclidean space(En), there is no distinction between zero vectorand null vector. 
	 But it is not true in other than Euclidean space."
*/

Pond_Vector2Int Pond_GetNullVector2(void)
{
	Pond_Vector2Int vector = { 0, 0 };
	return vector;
}

