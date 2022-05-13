#include "Reference_counters_connectivity.h"


#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace pointing {
namespace internalling {


typeing::Memory_natural Reference_counters_connectivity::get_strong_connectivity() const noexcept {
	return _strong_connectivity;
}

typeing::Memory_natural Reference_counters_connectivity::get_weak_connectivity() const noexcept {
	return _weak_connectivity;
}

typeing::Memory_natural Reference_counters_connectivity::get_total_connectivity() const noexcept {
	return _strong_connectivity + _weak_connectivity;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Reference_counters_connectivity::~Reference_counters_connectivity() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Reference_counters_connectivity::Reference_counters_connectivity() noexcept
{}

Reference_counters_connectivity::Reference_counters_connectivity( typeing::Memory_natural strong_connectivity, typeing::Memory_natural weak_connectivity ) noexcept
	:
		_strong_connectivity( strong_connectivity ),
		_weak_connectivity( weak_connectivity )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Reference_counters_connectivity::Reference_counters_connectivity( const Reference_counters_connectivity &another ) noexcept
	:
		_strong_connectivity( another._strong_connectivity ),
		_weak_connectivity( another._weak_connectivity )
{}

const Reference_counters_connectivity &Reference_counters_connectivity::operator =( const Reference_counters_connectivity &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	_strong_connectivity = another._strong_connectivity;
	_weak_connectivity = another._weak_connectivity;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Reference_counters_connectivity::Reference_counters_connectivity( Reference_counters_connectivity &&another ) noexcept
	:
		_strong_connectivity( another._strong_connectivity ),
		_weak_connectivity( another._weak_connectivity )
{
	// no need to null another
}

Reference_counters_connectivity &Reference_counters_connectivity::operator =( Reference_counters_connectivity &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	_strong_connectivity = another._strong_connectivity;
	_weak_connectivity = another._weak_connectivity;
	// no need to null another
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace internalling_dev
} // namespace pointing
} // namespace jmsf
