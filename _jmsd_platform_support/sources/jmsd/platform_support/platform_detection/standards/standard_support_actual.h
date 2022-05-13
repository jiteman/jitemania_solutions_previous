#pragma once


#if defined( __cplusplus )
	// detect C++ standard
	#include "cpp_language/cpp_standard_support.h"

#else // #if defined( __cplusplus ) // C language
	// detect C standard
	#include "c_language/c_standard_support.h"

#endif
