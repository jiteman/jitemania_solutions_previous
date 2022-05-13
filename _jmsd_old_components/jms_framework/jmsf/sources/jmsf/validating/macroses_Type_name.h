#pragma once


#include "jmsf/encodebuba/nativing/native_type_name.hin"


#define JMSF_TYPE_NAME( type ) \
	::jmsf::encodebuba::nativing::get_type_name_literal< type >()

#define JMSF_OBJECT_TYPE_NAME( type ) \
	::jmsf::encodebuba::nativing::get_type_name_literal( type )


#define JMSF_TYPE_IDENTIFIER( type ) \
	::jmsf::encodebuba::nativing::get_type_identifier< type >()

#define JMSF_OBJECT_TYPE_IDENTIFIER( type ) \
	::jmsf::encodebuba::nativing::get_type_identifier( type )
