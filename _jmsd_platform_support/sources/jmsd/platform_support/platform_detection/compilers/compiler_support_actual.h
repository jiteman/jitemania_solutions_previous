#pragma once


#include "compiler_detection_actual.h"


#if defined( JMSD_GNU_CCPP_COMPILER_IS_DETECTED )
	#include "gccpp/gcc_compiler_support.h"

#elif defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#include "ms_visual_cpp/ms_vcpp_compiler_support.h"

#else
	#error This file "jmsd/platform_support/platform_detection/compilers/compiler_support_actual.h" - no compiler support found.

#endif
