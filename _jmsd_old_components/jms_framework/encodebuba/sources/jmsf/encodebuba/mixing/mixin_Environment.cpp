#include "mixin_Environment.h"

#include <limits>


namespace jmsf {
namespace encodebuba {
namespace mixing {


bool mixin_Environment::is_ok() const noexcept  {
	return _status_code == 0;
}

bool mixin_Environment::is_not_ok() const noexcept {
	return !is_ok();
}

int mixin_Environment::get_status_code() const noexcept {
	return _status_code;
}

const char *mixin_Environment::get_status_text_message() const noexcept {
	if ( static_cast< size_t >( _status_code ) >= _quantity_of_codes ) return "Status code is out of status code quantity range";

	return _status_text_messages[ _status_code ];
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void mixin_Environment::increase_instance_counter() noexcept {
	++_instance_counter;
}

void mixin_Environment::decrease_instance_counter() noexcept {
	if ( _instance_counter > 0 ) {
		--_instance_counter;
	}
}

bool mixin_Environment::no_valid_instances() const noexcept {
	return _instance_counter == 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void mixin_Environment::initialize_mixin_environment() {
	mixin_initialize_status_text_messages();
	_status_code = mixin_initialize_environment();
}

void mixin_Environment::terminate_mixin_environment() noexcept {
	mixin_terminate_environment();
}

void mixin_Environment::set_status_code( const int status_code ) noexcept {
	if ( static_cast< size_t >( status_code ) < _quantity_of_codes ) {
		_status_code = status_code;
	}
}

void mixin_Environment::append_status_text_message( const char *const status_text_message ) noexcept {
	if ( _quantity_of_codes < TOTAL_QUANTITY_OF_CODES ) {
		_status_text_messages[ _quantity_of_codes ] = status_text_message;
		++_quantity_of_codes;
	}
}

size_t mixin_Environment::get_quantity_of_status_codes() const noexcept {
	return _quantity_of_codes;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Environment::~mixin_Environment() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Environment::mixin_Environment() noexcept {
	_instance_counter = 0;
	_status_code = ::std::numeric_limits< int >::max();
	_quantity_of_codes = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Environment::mixin_Environment( const mixin_Environment &/*another*/ ) noexcept {
}

const mixin_Environment &mixin_Environment::operator =( const mixin_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
void mixin_Environment::mixin_initialize_status_text_messages() {
	append_status_text_message( "Ok" );
	append_status_text_message( "Not Ok" );

	initialize_status_text_messages();
}

int mixin_Environment::mixin_initialize_environment() {
	return initialize_environment();
}

void mixin_Environment::mixin_terminate_environment() noexcept {
	terminate_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace encodebuba
} // namespace jmsf
