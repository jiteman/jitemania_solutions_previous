#pragma once


#include "native_File_and_line.h"


#define JMSF_ENCODEBUBA_FILE \
	( __FILE__ )

#define JMSF_ENCODEBUBA_LINE \
	( __LINE__ )

#define JMSF_ENCODEBUBA_FILE_AND_LINE_SEQUENCE \
	JMSF_ENCODEBUBA_FILE, JMSF_ENCODEBUBA_LINE

#define JMSF_ENCODEBUBA_FILE_AND_LINE \
	::jmsf::encodebuba::validating::native_File_and_line::create( JMSF_ENCODEBUBA_FILE_AND_LINE_SEQUENCE )
