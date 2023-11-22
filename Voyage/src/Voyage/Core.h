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