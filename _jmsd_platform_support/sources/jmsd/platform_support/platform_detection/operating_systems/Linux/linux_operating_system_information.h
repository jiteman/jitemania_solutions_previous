#pragma once


#include "linux_operating_system_detection.h"


#if !defined( JMSD_LINUX_OPERATING_SYSTEM_IS_DETECTED )
	#error This file "jmsd/platform_support/platform_detection/operating_systems/Linux/linux_operating_system_information.h" is included, but no Linux operating system detected.

#endif


#define JMSD_OPERATING_SYSTEM_TYPE	JMSD_OPERATING_SYSTEM_TYPE_LINUX
#define JMSD_OPERATING_SYSTEM_NAME	JMSD_OPERATING_SYSTEM_NAME_LINUX
