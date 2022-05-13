#pragma once


#include "jmsd/platform_support/common_shared_library_support.h"


#if defined( JMSF_AL_QT_SHARED_INTERFACE_INTERNAL )
	#define JMSF_AL_QT_SHARED_INTERFACE JMSD_SHARED_EXPORT_CONVENTION
#else
	#define JMSF_AL_QT_SHARED_INTERFACE JMSD_SHARED_IMPORT_CONVENTION
#endif
