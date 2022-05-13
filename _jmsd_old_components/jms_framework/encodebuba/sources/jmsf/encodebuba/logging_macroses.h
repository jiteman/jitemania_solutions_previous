#pragma once


#include "Log.h"


#define JMSF_ENCODEBUBA_LOG_OUTPUT( log_name, message ) \
	::jmsf::encodebuba::Log::write( ( log_name ), ( message ), __FILE__, __LINE__ )

#define JMSF_ENCODEBUBA_LOG_OUTPUT_TYPED( log_name, message, type ) \
	::jmsf::encodebuba::Log::write( ( log_name ), ( message ), ( type ), __FILE__, __LINE__ )

#define JMSF_ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( log_name, condition, message ) \
	if ( ( condition ) ) { ::jmsf::encodebuba::Log::write( ( log_name ), ( message ), __FILE__, __LINE__ );  }

#define JMSF_ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( log_name, condition, message, type ) \
	if ( ( condition ) ) { ::jmsf::encodebuba::Log::write( ( log_name ), ( message ), ( type ), __FILE__, __LINE__ );  }

//// a_type parameter left without parentheses intentionally
//#define JMSF_ENCODEBUBA_TYPE( a_type )
//	::jmsf::encodebuba::nativing::get_type_name_literal< a_type >()

//#define JMSF_ENCODEBUBA_TYPE_OBJECT( an_object )
//	::jmsf::encodebuba::nativing::get_type_name_literal( ( an_object ) )
