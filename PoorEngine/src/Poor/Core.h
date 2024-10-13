#pragma once

#ifdef PR_PlATFORM_WINDOWS
	#ifdef PR_BUILD_DLL
		#define POOR_API __declspec(dllexport)
	#else
		#define POOR_API __declspec(dllimport)
	#endif 
#else
	#error Poor only supports Windows!
#endif // PR_PlATFORM_WINDOWS
