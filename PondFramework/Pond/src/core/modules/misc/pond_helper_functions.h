#pragma once
#define Pond_GetArrayLength(Array) sizeof(Array)/sizeof(Array[0])

// TODO: Implement these
char* Pond_ConvertIntToString(int _num, char* _buffer, int _buffersize);
char* Pond_ConvertFloatToString(float _num, char* _buffer, int _buffersize);

