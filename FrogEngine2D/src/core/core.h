#pragma once

#ifdef FE_PLATFORM_WINDOWS
	#ifdef FE_BUILD_DLL
		#define FROGENGINE_API __declspec(dllexport)
	#else
		#define FROGENGINE_API __declspec(dllimport)
	#endif
#else
	#error FrogEngine2D currently only supports Windows! :(
#endif