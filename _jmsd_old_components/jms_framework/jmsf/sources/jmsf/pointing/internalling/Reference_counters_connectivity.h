#pragma once

#include "Reference_counters_connectivity.hxx"


#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace pointing {
namespace internalling {


class JMSF_SHARED_INTERFACE Reference_counters_connectivity {

public:
	typeing::Memory_natural get_strong_connectivity() const noexcept;
	typeing::Memory_natural get_weak_connectivity() const noexcept;
	typeing::Memory_natural get_total_connectivity() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Reference_counters_connectivity() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reference_counters_connectivity() noexcept;
	Reference_counters_connectivity( typeing::Memory_natural strong_connectivity, typeing::Memory_natural weak_connectivity ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reference_counters_connectivity( const Reference_counters_connectivity &another ) noexcept;
	const Reference_counters_connectivity &operator =( const Reference_counters_connectivity &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reference_counters_connectivity( Reference_counters_connectivity &&another ) noexcept;
	Reference_counters_connectivity &operator =( Reference_counters_connectivity &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _strong_connectivity;
	typeing::Memory_natural _weak_connectivity;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internalling_dev
} // namespace pointing
} // namespace jmsf
