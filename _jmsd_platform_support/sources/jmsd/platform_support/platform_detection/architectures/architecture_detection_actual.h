#pragma once


#if defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )
	#error This file "jmsd/platform_support/platform_detection/architectures/architecture_detection_actual.h" - architecture is already detected.

#endif

#define JMSD_ARCHITECTURE_TYPE_UNKNOWN					0x01
#define JMSD_ARCHITECTURE_NAME_UNKNOWN					JMSD_UNKNOWN_STRING_LITERAL
#define JMSD_ARCHITECTURE_TYPE_AMD64					0x02
#define JMSD_ARCHITECTURE_NAME_AMD64					"AMD64"
#define JMSD_ARCHITECTURE_TYPE_INTEL_X86				0x03
#define JMSD_ARCHITECTURE_NAME_INTEL_X86				"Intel x86"


// detect AMD64
#if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )
	#include "AMD64/amd64_architecture_detection.h"

	#if JMSD_AMD64_ARCHITECTURE_IS_DEFINED == JMSD_CPP_TRUE
		#define JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED	JMSD_CPP_TRUE
		#define JMSD_ARCHITECTURE_TYPE						JMSD_ARCHITECTURE_TYPE_AMD64
		#define JMSD_ARCHITECTURE_NAME						JMSD_ARCHITECTURE_NAME_AMD64

	#endif // #if JMSD_AMD64_ARCHITECTURE_IS_DEFINED == JMSD_CPP_TRUE

#endif // #if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )


// detect Intel x86
#if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )
	#include "Intel_x86/intel_x86_architecture_detection.h"

	#if JMSD_INTEL_X86_ARCHITECTURE_IS_DEFINED == JMSD_CPP_TRUE
		#define JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED	JMSD_CPP_TRUE
		#define JMSD_ARCHITECTURE_TYPE						JMSD_ARCHITECTURE_TYPE_INTEL_X86
		#define JMSD_ARCHITECTURE_NAME						JMSD_ARCHITECTURE_NAME_INTEL_X86

	#endif // #if JMSD_INTEL_X86_ARCHITECTURE_IS_DEFINED == JMSD_CPP_TRUE

#endif // #if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )


// set unknown
#if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )
	#define JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED	JMSD_CPP_FALSE
	#define JMSD_ARCHITECTURE_TYPE						JMSD_ARCHITECTURE_TYPE_UNKNOWN
	#define JMSD_ARCHITECTURE_NAME						JMSD_ARCHITECTURE_NAME_UNKNOWN

	#error This file "jmsd/platform_support/platform_detection/architectures/architecture_detection_actual.h" - no supported architecture is detected.
#endif // #if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )
