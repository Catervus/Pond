#pragma once

#ifdef POND_PLATFORM_WINDOWS
	#ifdef POND_BUILD_DLL
		#define POND_API __declspec(dllexport)
	#else
		#define POND_API __declspec(dllimport)
	#endif
#else
	#error Pond currently only supports Windows! :(
#endif

