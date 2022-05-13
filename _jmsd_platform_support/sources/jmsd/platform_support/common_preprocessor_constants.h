#pragma once


#define JMSD_UNKNOWN_STRING_LITERAL		"unknown"
#define JMSD_UNKNOWN_LITERAL			-1
#define JMSD_DUMMY_DEFINE				-1
#define JMSD_C_TRUE						1
#define JMSD_C_FALSE					0


#include "platform_detection/compilers/cpp_preprocessor_boolean_values_support.h"


#if defined( JMSD_CPP_PREPROCESSOR_SUPPORTS_BOOLEAN_VALUES )
	#define JMSD_CPP_TRUE				true
	#define	JMSD_CPP_FALSE				false

#else
	#define JMSD_CPP_TRUE				JMSD_C_TRUE
	#define	JMSD_CPP_FALSE				JMSD_C_FALSE

#endif
