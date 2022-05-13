#pragma once


#include "String_literal.h"


#define JMSF_SL( some_string ) \
	::jmsf::texting::String_literal::create( some_string )
