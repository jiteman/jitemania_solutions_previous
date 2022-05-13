#pragma once


#include "jmsd/platform_support/common_shared_library_support.h"


#if defined( TDD_LEARNING_SHARED_INTERFACE_INTERNAL )
	#define TDD_LEARNING_SHARED_INTERFACE JMSD_SHARED_EXPORT_CONVENTION

#else
	#define TDD_LEARNING_SHARED_INTERFACE JMSD_SHARED_IMPORT_CONVENTION

#endif
