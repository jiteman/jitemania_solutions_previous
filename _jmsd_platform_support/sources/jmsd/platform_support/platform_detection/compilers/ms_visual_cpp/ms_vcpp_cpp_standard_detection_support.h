#pragma once


#include "ms_vcpp_compiler_detection.h"


#if !defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#error This file "jmsd/platform_support/platform_detection/compilers/ms_visual_cpp/ms_vccp_cpp_standard_detection_support.h" is included, but MS Visual C++ compiler is not present.

#endif


#include "ms_vcpp_compiler_information.h"


#if JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1800_VS2013
	#error This file "jmsfl/environment_low/platforming/compilers/ms_visual_cpp/ms_vccp_cpp_standard_detection_support.h" - no support for compilers before MS Visual Studio 2013.

#elif JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1900_VS2015
	// MS Visual Studio 2013
	#define JMSD_CPLUSPLUS_VERSION_VALUE		JMSD_CPLUSPLUS98_VERSION_CONSTANT

#elif JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1910_VS2017
	// MS Visual Studio 2015
	#define JMSD_CPLUSPLUS_VERSION_VALUE		JMSD_CPLUSPLUS11_VERSION_CONSTANT

#elif JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1920_VS2019
	// MS Visual Studio 2017
	#define JMSD_CPLUSPLUS_VERSION_VALUE		JMSD_CPLUSPLUS17_VERSION_CONSTANT_03

#elif JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1924_VS2019
	// MS Visual Studio 2019
	#define JMSD_CPLUSPLUS_VERSION_VALUE		JMSD_CPLUSPLUS17_VERSION_CONSTANT_05

#elif JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_LATEST
	// the plug for new versions
	#define JMSD_CPLUSPLUS_VERSION_VALUE		JMSD_CPLUSPLUS17_VERSION_CONSTANT_05
	#error Add new version of MSVS
#else
	#error This file "jmsd/platform_support/platform_detection/compilers/ms_visual_cpp/ms_vccp_cpp_standard_detection_support.h" - add support for latest compilers MS Visual Studio 2017.

#endif
