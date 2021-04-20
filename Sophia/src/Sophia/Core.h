#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SOPHIA_API __declspec(dllexport)
	#else
		#define SOPHIA_API __declspec(dllimport)
	#endif 
#else
	#error Sophia only supports windows
#endif