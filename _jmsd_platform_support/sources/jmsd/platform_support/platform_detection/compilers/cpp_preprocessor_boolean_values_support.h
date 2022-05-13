#pragma once


#include "compiler_detection_actual.h"


#if !defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	// Microsoft compiler does not support true/false in define comparing, integer constants only.

	#if !defined( JMSD_C_TRUE )
		#error This file "jmsd/platform_support/platform_detection/compilers/cpp_preprocessor_boolean_values_support.h" should be included by that file "jmsfl/environment_low/common_preprocessor_constants.h" only.

	#endif // #if !defined( JMSD_C_TRUE )

	#define JMSD_CPP_PREPROCESSOR_SUPPORTS_BOOLEAN_VALUES	JMSD_C_TRUE

#endif
