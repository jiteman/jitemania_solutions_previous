#pragma once

#include "jmsd/platform_support/common_preprocessor_constants.h"


#define JMSD_COMPILER_TYPE_UNKNOWN					0x01
#define JMSD_COMPILER_NAME_UNKNOWN					JMSD_UNKNOWN_STRING_LITERAL
#define JMSD_COMPILER_TYPE_GCC_CCPP					0x02
#define JMSD_COMPILER_NAME_GCC_CCPP					"GCC C/C++"
#define JMSD_COMPILER_TYPE_MICROSOFT_VISUAL_CPP		0x03
#define JMSD_COMPILER_NAME_MICROSOFT_VISUAL_CPP		"Microsoft Visual C++"


#include "compiler_detection_actual.h"


#if defined( JMSD_GNU_CCPP_COMPILER_IS_DETECTED )
	#include "gccpp/gcc_compiler_information.h"

#elif defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#include "ms_visual_cpp/ms_vcpp_compiler_information.h"

#else
	#error This file "jmsd/platform_support/platform_detection/operating_systems/operating_system_information_actual.h" - no supported compiler infromation found.

#endif
