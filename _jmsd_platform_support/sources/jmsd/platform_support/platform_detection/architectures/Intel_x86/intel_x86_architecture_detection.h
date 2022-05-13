#pragma once


#include "jmsd/platform_support/common_preprocessor_constants.h"


#if defined( i386 ) || defined( __i386 ) || defined( __i386__ ) || defined( _M_IX86 )
	#define JMSD_ARCHITECTURE_IS_INTEL_X86				JMSD_CPP_TRUE
	#define JMSD_INTEL_X86_ARCHITECTURE_IS_DEFINED		JMSD_CPP_TRUE

#else
	#define JMSD_INTEL_X86_ARCHITECTURE_IS_DEFINED		JMSD_CPP_FALSE

#endif
