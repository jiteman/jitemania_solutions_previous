#pragma once


#include "jmsd/platform_support/common_preprocessor_constants.h"


#if defined( __amd64__ ) || defined( __amd64 ) || defined( __x86_64__ ) || defined( __x86_64 ) || defined( _M_X64 ) || defined( _M_AMD64 )
	#define JMSD_ARCHITECTURE_IS_AMD64			JMSD_CPP_TRUE
	#define JMSD_AMD64_ARCHITECTURE_IS_DEFINED	JMSD_CPP_TRUE

#else
	#define JMSD_AMD64_ARCHITECTURE_IS_DEFINED	JMSD_CPP_FALSE

#endif
