#include "Environment_status_printer.h"


#include "Environment.h"
#include "boolean_c_text.h"

#include <typeinfo>
#include <iostream>


namespace jmsf {
namespace encodebuba {


// static
void Environment_status_printer::print( const Environment *const an_environment ) noexcept {
	if ( an_environment == nullptr ) {
		::std::cout << "::jmsf::encodebuba::Environment_status_printer::print(...): - an_environment == nullptr" << ::std::endl;
		return;
	}

	::std::cout << ::std::endl;
//	::std::cout << typeid( an_environment ).name() << ":" << ::std::endl;
	::std::cout << "status is ok: " << boolean_to_c_text( an_environment->is_ok() ) << ::std::endl;
	::std::cout << "status code is: " << an_environment->get_status_code() << ::std::endl;
	::std::cout << "status message is: " << an_environment->get_status_text_message() << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Environment_status_printer::~Environment_status_printer() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Environment_status_printer::Environment_status_printer() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Environment_status_printer::Environment_status_printer( const Environment_status_printer &/*another*/ ) noexcept {
}

const Environment_status_printer &Environment_status_printer::operator =( const Environment_status_printer &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace encodebuba
} // namespace jmsf
