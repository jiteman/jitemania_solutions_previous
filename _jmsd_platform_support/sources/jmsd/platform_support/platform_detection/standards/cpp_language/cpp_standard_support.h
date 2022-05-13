#pragma once


// detect compiler
// if it is MS Visual C++ -> include jmsfl/environment_low/platforming/compilers/ms_visual_cpp/...

#include "jmsd/platform_support/platform_detection/compiler_detection.h"


#if defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#include "jmsd/platform_support/platform_detection/compilers/ms_visual_cpp/ms_vcpp_cpp_standard_support.h"

#endif // #if defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
