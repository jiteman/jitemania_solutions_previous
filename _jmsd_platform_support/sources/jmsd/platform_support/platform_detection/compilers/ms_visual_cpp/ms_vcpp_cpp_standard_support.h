#pragma once


#include "jmsd/platform_support/platform_detection/compilers/compiler_detection_actual.h"


#if !defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#error This file "jmsd/platform_support/platform_detection/compilers/ms_visual_cpp/ms_vcpp_cpp_standard_support.h" is included, but there is no MS Visual C++ compiler detected.

#endif


#include "ms_vcpp_compiler_information.h"


#if JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1900_VS2015
//	#if !defined( _ALLOW_KEYWORD_MACROS )
		#define _ALLOW_KEYWORD_MACROS

//	#endif // #if !defined( _ALLOW_KEYWORD_MACROS )

//	#if !defined( noexcept )
		#define noexcept throw()

//	#endif // #if !defined( noexcept )

#endif // #if JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_VALUE < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1900_VS2015
