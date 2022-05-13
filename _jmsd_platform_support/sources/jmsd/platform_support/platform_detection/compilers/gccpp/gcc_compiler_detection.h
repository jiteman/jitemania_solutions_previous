#pragma once


#if defined( __GNUC__ )
	#define JMSD_GNU_CCPP_COMPILER_IS_DETECTED
	
#endif


// #if defined( __GNUC__ )
// 	#define JMSD_COMPILER_IS_GNU_CCPP			JMSD_CPP_TRUE
// 	#define JMSD_GNU_CCPP_COMPILER_IS_DEFINED	JMSD_CPP_TRUE
// 	
// 	#if defined( __GNUC_PATCHLEVEL__ )
// 		#define JMSD_GNU_CCPP_COMPILER_VERSION_VALUE ( __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ )
// 	#else
// 		#define JMSD_GNU_CCPP_COMPILER_VERSION_VALUE (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 )
// 	#endif
// 	
// #else
// 	#define JMSD_GNU_CCPP_COMPILER_IS_DEFINED	JMSD_CPP_FALSE
// 	
// #endif
