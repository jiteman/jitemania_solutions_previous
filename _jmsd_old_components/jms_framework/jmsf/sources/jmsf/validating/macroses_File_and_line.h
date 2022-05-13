#pragma once


#include "jmsf/texting/macroses_String_literal.h"
#include "jmsf/validating/File_and_line.h"

#include "jmsf/encodebuba/validating/macroses_File_and_line.h"


#define	JMSF_FILE_AND_LINE \
	( ::jmsf::validating::File_and_line::create( JMSF_SL( JMSF_ENCODEBUBA_FILE ), JMSF_ENCODEBUBA_LINE ) )

#define	JMSF_FILE_AND_LINE_OPTIONAL( boolean_expression ) \
	( boolean_expression ) ? \
		( ::jmsf::validating::File_and_line::create( JMSF_SL( JMSF_ENCODEBUBA_FILE ), JMSF_ENCODEBUBA_LINE ) ) : \
		( ::jmsf::validating::File_and_line::EMPTY_FILE_AND_LINE )


//#define	JMSF_FILE_AND_LINE
//	( ::jmsf::validating::File_and_line::create( JMSF_SL( __FILE__ ), __LINE__ ) )

//#define	JMSF_FILE_AND_LINE_OPTIONAL( boolean_expression )
//	( boolean_expression ) ? ( ::jmsf::validating::File_and_line::create( JMSF_SL( __FILE__ ), __LINE__ ) ) : ( ::jmsf::validating::File_and_line::EMPTY_FILE_AND_LINE )
