#pragma once

#ifdef NG_PLATFORM_WINDOWS
	#ifdef NG_BUILD_DLL
		#define NUGGET_API __declspec(dllexport)
	#else 
		#define NUGGET_API __declspec(dllimport)
	#endif
#else
	#error Nugget only supports Windows
#endif