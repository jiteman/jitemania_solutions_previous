#include "native_Reference_counters.h"


#include "jmsf/encodebuba/validating/macroses_native_Should.h"


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


native_memory_natural native_Reference_counters::get_shared_counter() const noexcept {
	return this->_the_shared_counter;
}

native_memory_natural native_Reference_counters::get_total_counter() const noexcept {
	return this->_the_shared_counter + this->_the_weak_counter;
}

native_boolean native_Reference_counters::is_shared_counter_nil() const noexcept {
	return this->get_shared_counter() == 0;
}

native_boolean native_Reference_counters::is_total_counter_nil() const noexcept {
	return this->get_total_counter() == 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void native_Reference_counters::increase_shared_counter() {
	jmsf_native_Should_never_be( is_shared_counter_nil() );

	this->_the_shared_counter += 1;
}

void native_Reference_counters::decrease_shared_counter() {
	jmsf_native_Should_never_be( this->_the_shared_counter == 0 );

	this->_the_shared_counter -= 1;
}

void native_Reference_counters::increase_weak_counter() {
	jmsf_native_Should_never_be( this->is_total_counter_nil() );

	this->_the_weak_counter += 1;
}

void native_Reference_counters::decrease_weak_counter() {
	jmsf_native_Should_never_be( this->_the_weak_counter == 0 );

	this->_the_weak_counter -= 1;
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
native_Reference_counters::~native_Reference_counters() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
native_Reference_counters::native_Reference_counters() noexcept {
	_the_shared_counter = 1;
	_the_weak_counter = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//native_Reference_counters::native_Reference_counters() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
native_Reference_counters *native_Reference_counters::create_new() {
	return new native_Reference_counters;
}

void native_Reference_counters::destroy() noexcept {
	delete this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//native_Reference_counters::native_Reference_counters( const native_Reference_counters &/*another*/ ) noexcept {
//}

//native_Reference_counters &native_Reference_counters::operator =( const native_Reference_counters &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//native_Reference_counters::native_Reference_counters( native_Reference_counters &&/*another*/ ) noexcept {
//}

//native_Reference_counters &native_Reference_counters::operator =( native_Reference_counters &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf

