#pragma once

#define Pond_GetArrayLength(Array) sizeof(Array)/sizeof(Array[0])

char* Pond_ConvertIntToString(int _num, char* _buffer, int _buffersize)
{
	snprintf(_buffer, _buffersize, "%d", _num);

	return _buffer;
}

char* Pond_ConvertFloatToString(float _num, char* _buffer, int _buffersize)
{
	snprintf(_buffer, _buffersize, "%f", _num);

	return _buffer;
}