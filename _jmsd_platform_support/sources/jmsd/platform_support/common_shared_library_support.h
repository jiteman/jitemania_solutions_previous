#pragma once


#include "platform_detection/compiler_detection.h"


#if defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )

//#if !defined( JMSD_APIENTRY_CONVENTION )
	//	#define JMSD_APIENTRY_CONVENTION	__stdcall
	//#endif


	#if !defined( JMSD_SHARED_EXPORT_CONVENTION )
		#define JMSD_SHARED_EXPORT_CONVENTION	__declspec( dllexport )
	#endif


	#if !defined( JMSD_SHARED_IMPORT_CONVENTION )
		#define JMSD_SHARED_IMPORT_CONVENTION	__declspec( dllimport )
	#endif


#else // #if defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED ) // Another compiler (GCC/Linux) build

	#if !defined( JMSD_APIENTRY_CONVENTION )
		#define JMSD_APIENTRY_CONVENTION
	#endif


	#if !defined( JMSD_SHARED_EXPORT_CONVENTION )
		#define JMSD_SHARED_EXPORT_CONVENTION	__attribute__( ( visibility( "default" ) ) )
	#endif


	#if !defined( JMSD_SHARED_IMPORT_CONVENTION )
		#define JMSD_SHARED_IMPORT_CONVENTION	__attribute__( ( visibility( "default" ) ) )
	#endif


#endif
