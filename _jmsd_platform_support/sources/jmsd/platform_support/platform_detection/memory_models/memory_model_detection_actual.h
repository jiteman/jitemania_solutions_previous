#pragma once


#if defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )
	#error This file "jmsd/platform_support/platform_detection/memory_models/memory_model_detection_actual.h" - memory model is already detected.

#endif


#include "jmsd/platform_support/common_preprocessor_constants.h"


#if !defined( JMSD_COMPILER_DETECTION_IS_COMPLETED )
	#include "jmsd/platform_support/platform_detection/compiler_detection.h"
#endif

#if !defined( JMSD_ARCHITECTURE_DETECTION_IS_COMPLETED )
	#include "jmsd/platform_support/platform_detection/architecture_detection.h"
#endif


#define JMSD_MEMORY_MODEL_TYPE_UNKNOWN			0x01
#define JMSD_MEMORY_MODEL_NAME_UNKNOWN			"Unknown"

// not used
#define JMSD_MEMORY_MODEL_TYPE_MODEL_LP32		0x10
#define JMSD_MEMORY_MODEL_NAME_MODEL_LP32		"LP32  char8 short16 int16 long32 longlong64 pointer32"

#define JMSD_MEMORY_MODEL_TYPE_MODEL_ILP32		0x11
#define JMSD_MEMORY_MODEL_NAME_MODEL_ILP32		"ILP32 char8 short16 int32 long32 longlong64 pointer32"
#define JMSD_MEMORY_MODEL_TYPE_MODEL_LLP64		0x20
#define JMSD_MEMORY_MODEL_NAME_MODEL_LLP64		"LLP64 char8 short16 int32 long32 longlong64 pointer64"
#define JMSD_MEMORY_MODEL_TYPE_MODEL_LP64		0x21
#define JMSD_MEMORY_MODEL_NAME_MODEL_LP64		"LP64  char8 short16 int32 long64 longlong64 pointer64"

// not supported
#define JMSD_MEMORY_MODEL_TYPE_MODEL_ILP64		0x22
#define JMSD_MEMORY_MODEL_NAME_MODEL_ILP64		"ILP64 char8 short16 int64 long64 longlong64 pointer64"


// detect LP64
// Linux 64bit memory model
#if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )
	#include "LP64/memory_model_lp64_detection.h"

	#if JMSD_MEMORY_MODEL_LP64_IS_DEFINED == JMSD_CPP_TRUE
		#define JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED	JMSD_CPP_TRUE
		#define JMSD_MEMORY_MODEL_TYPE						JMSD_MEMORY_MODEL_TYPE_MODEL_LP64
		#define JMSD_MEMORY_MODEL_NAME						JMSD_MEMORY_MODEL_NAME_MODEL_LP64

	#endif // #if JMSD_MEMORY_MODEL_LP64_IS_DEFINED == JMSD_CPP_TRUE

#endif // #if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )


// detect LLP64
// Microsoft Windows 64bit memory model
#if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )
	#include "LLP64/memory_model_llp64_detection.h"

	#if JMSD_MEMORY_MODEL_LLP64_IS_DEFINED == JMSD_CPP_TRUE
		#define JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED	JMSD_CPP_TRUE
		#define JMSD_MEMORY_MODEL_TYPE						JMSD_MEMORY_MODEL_TYPE_MODEL_LLP64
		#define JMSD_MEMORY_MODEL_NAME						JMSD_MEMORY_MODEL_NAME_MODEL_LLP64

	#endif // #if JMSD_MEMORY_MODEL_LLP64_IS_DEFINED == JMSD_CPP_TRUE

#endif // #if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )


// detect ILP32
// Linux and Microsoft Windows 32bit memory model
#if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )
	#include "ILP32/memory_model_ilp32_detection.h"

	#if JMSD_MEMORY_MODEL_ILP32_IS_DEFINED == JMSD_CPP_TRUE
		#define JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED	JMSD_CPP_TRUE
		#define JMSD_MEMORY_MODEL_TYPE						JMSD_MEMORY_MODEL_TYPE_MODEL_ILP32
		#define JMSD_MEMORY_MODEL_NAME						JMSD_MEMORY_MODEL_NAME_MODEL_ILP32

	#endif // #if JMSD_MEMORY_MODEL_ILP32_IS_DEFINED == JMSD_CPP_TRUE

#endif // #if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )


#if !defined( JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED )
	#define JMSD_MEMORY_MODEL_DETECTION_IS_COMPLETED	JMSD_CPP_FALSE
	#define JMSD_MEMORY_MODEL_TYPE						JMSD_MEMORY_MODEL_TYPE_UNKNOWN
	#define JMSD_MEMORY_MODEL_NAME						JMSD_MEMORY_MODEL_NAME_UNKNOWN

	#error This file "jmsd/platform_support/platform_detection/memory_models/memory_model_detection_actual.h" - no memory model is detected
#endif
