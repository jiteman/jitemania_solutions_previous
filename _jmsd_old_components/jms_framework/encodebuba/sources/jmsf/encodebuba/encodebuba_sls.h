#pragma once


#include "jmsd/platform_support/common_shared_library_support.h"


#if defined( JMSF_ENCODEBUBA_SHARED_INTERFACE_INTERNAL )
	#define JMSF_ENCODEBUBA_SHARED_INTERFACE	JMSD_SHARED_EXPORT_CONVENTION

#else
	#define JMSF_ENCODEBUBA_SHARED_INTERFACE	JMSD_SHARED_IMPORT_CONVENTION

#endif
