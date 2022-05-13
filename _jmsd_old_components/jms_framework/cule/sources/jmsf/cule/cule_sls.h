#pragma once

#include "jmsd/platform_support/common_shared_library_support.h"


#if defined( JMSF_CULE_SHARED_INTERFACE_INTERNAL )
	#define JMSF_CULE_SHARED_INTERFACE JMSD_SHARED_EXPORT_CONVENTION
#else
	#define JMSF_CULE_SHARED_INTERFACE JMSD_SHARED_IMPORT_CONVENTION
#endif
