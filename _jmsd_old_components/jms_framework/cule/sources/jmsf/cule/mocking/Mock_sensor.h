#pragma once

#include "Mock_sensor.hxx"


#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/cule/cule.h"


namespace jmsf {
namespace cule {
namespace mocking {


class JMSF_CULE_SHARED_INTERFACE Mock_sensor {

public:
	virtual typeing::Boolean is_touched( typeing::Memory_natural::my_natural_integral_type an_index ) const = 0;
	virtual typeing::Memory_natural get_counter( typeing::Memory_natural::my_natural_integral_type an_index ) const = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual void touch( typeing::Memory_natural::my_natural_integral_type an_index ) const = 0;
	virtual void untouch( typeing::Memory_natural::my_natural_integral_type an_index ) const = 0;
	virtual void increase( typeing::Memory_natural::my_natural_integral_type an_index ) const = 0;
	virtual void decrease( typeing::Memory_natural::my_natural_integral_type an_index ) const = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Mock_sensor() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Mock_sensor() noexcept = default;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Mock_sensor( const Mock_sensor &another ) noexcept = delete;
	Mock_sensor &operator =( const Mock_sensor &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Mock_sensor( Mock_sensor &&another ) noexcept = delete;
	Mock_sensor &operator =( Mock_sensor &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mocking
} // namespace cule
} // namespace jmsf
