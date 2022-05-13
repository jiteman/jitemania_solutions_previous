#pragma once


#if defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )
	#error This file "jmsd/platform_support/platform_detection/operating_systems/operating_system_detection_actual.h" - operating system is already detected.

#endif


// detect Linux
#if !defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )
	#include "Linux/linux_operating_system_detection.h"

	#if defined ( JMSD_LINUX_OPERATING_SYSTEM_IS_DETECTED )
		#define JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED

	#endif // #if defined ( JMSD_LINUX_OPERATING_SYSTEM_IS_DETECTED )

#endif // #if !defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )


// detect Microsoft Windows
#if !defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )
	#include "MS_Windows/ms_windows_operating_system_detection.h"

	#if defined( JMSD_MICROSOFT_WINDOWS_OPERATING_SYSTEM_IS_DETECTED )
		#define JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED

	#endif // #if defined( JMSD_MICROSOFT_WINDOWS_OPERATING_SYSTEM_IS_DETECTED )

#endif // #if !defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )


// set unknown
#if !defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )
	#define JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED
	#define JMSD_OPERATING_SYSTEM_TYPE	JMSD_OPERATING_SYSTEM_TYPE_UNKNOWN
	#define JMSD_OPERATING_SYSTEM_NAME	JMSD_OPERATING_SYSTEM_NAME_UNKNOWN

	#error This file "jmsd/platform_support/platform_detection/operating_systems/operating_system_detection_actual.h" - no supported operating system is detected

#endif // #if !defined( JMSD_OPERATING_SYSTEM_DETECTION_IS_COMPLETED )
