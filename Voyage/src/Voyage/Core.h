#pragma once

#ifdef VG_PLATFORM_WINDOWS
	#ifdef VG_BUILD_DLL
		#define VOYAGE_API __declspec(dllexport)
	#else
		#define VOYAGE_API __declspec(dllimport)
	#endif
#else
	#error Voyage only supports windows!
#endif

#ifdef VG_ENABLE_ASSERTS
	#define VG_ASSERT(x, ...) { if(!(x)) { VG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VG_CORE_ASSERT(x, ...) { if(!(x)) { VG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VG_ASSERT(x, ...)
	#define VG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define VG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)