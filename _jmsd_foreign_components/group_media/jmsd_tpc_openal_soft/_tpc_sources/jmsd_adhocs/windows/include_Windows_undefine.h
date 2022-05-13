#pragma once


#include "jmsd/platform_support/platform_detection/compiler_detection.h"


#if !defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#error This file "include_Windows_undefine.h" is included, but there is no MS Windows detected.

#endif


#if defined( max )
	#undef max
#endif

#if defined( min )
	#undef min
#endif

#if defined( small )
	#undef small
#endif
