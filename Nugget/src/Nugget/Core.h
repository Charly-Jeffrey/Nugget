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

#ifdef NG_ENABLE_ASSERTS
	#define NG_ASSERT(x, ...) {if (!x) {NG_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
	#define NG_CORE_ASSERT(x, ...) {if (!x) {NG_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NG_ASSERT(x, ...)
	#define NG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)