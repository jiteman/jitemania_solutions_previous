#pragma once


#if !defined( __cplusplus )
	#error This file "jmsd/platform_support/platform_detection/standards/cpp_language/cpp_standard_detection.h" is included, but not in C++ context.

#endif // #if !defined( __cplusplus )


#include "jmsd/platform_support/common_preprocessor_constants.h"


#define JMSD_CPLUSPLUS98_VERSION_CONSTANT		199711L
#define JMSD_CPLUSPLUS11_VERSION_CONSTANT		201103L
#define JMSD_CPLUSPLUS14_VERSION_CONSTANT		201402L
#define JMSD_CPLUSPLUS17_VERSION_CONSTANT_03	201703L
#define JMSD_CPLUSPLUS17_VERSION_CONSTANT_04	201704L
#define JMSD_CPLUSPLUS17_VERSION_CONSTANT_05	201705L
#define JMSD_CPLUSPLUS20_VERSION_CONSTANT		202001L

#define JMSD_CPLUSPLUS_IS_DEFINED				JMSD_CPP_TRUE


#include "jmsd/platform_support/platform_detection/compiler_detection.h"
#include "jmsd/platform_support/platform_detection/compiler_information.h"


#if defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED ) && ( JMSD_COMPILER_VERSION < JMSD_MICROSOFT_VISUAL_CPP_COMPILER_VERSION_1920_VS2019 )
	#include "jmsd/platform_support/platform_detection/compilers/ms_visual_cpp/ms_vcpp_cpp_standard_detection_support.h"

#else
	#define JMSD_CPLUSPLUS_VERSION_VALUE		__cplusplus

//	#define STRING2(x) #x
//	#define STRING(x) STRING2(x)
//	#pragma message(STRING(__cplusplus))
//	#error __cplusplus

#endif
