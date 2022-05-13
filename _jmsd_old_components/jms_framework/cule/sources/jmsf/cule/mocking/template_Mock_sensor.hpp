#pragma once

#include "template_Mock_sensor.hxx"


#include "Mock_sensor.h"

#include "jmsf/typeing/Boolean.h"
#include "jmsf/typeing/Naturals.hpp"


namespace jmsf {
namespace cule {
namespace mocking {


template< int Boolean_quantity, int Natural_quantity >
class template_Mock_sensor :
	public Mock_sensor
{

private: // virtuals Mock_sensor
	typeing::Boolean is_touched( typeing::Memory_natural::my_natural_integral_type an_index ) const override;
	typeing::Memory_natural get_counter( typeing::Memory_natural::my_natural_integral_type an_index ) const override;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: // virtuals Mock_sensor
	void touch( typeing::Memory_natural::my_natural_integral_type an_index ) const override;
	void untouch( typeing::Memory_natural::my_natural_integral_type an_index ) const override;
	void increase( typeing::Memory_natural::my_natural_integral_type an_index ) const override;
	void decrease( typeing::Memory_natural::my_natural_integral_type an_index ) const override;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Mock_sensor
	~template_Mock_sensor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	template_Mock_sensor() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	template_Mock_sensor( const template_Mock_sensor &another ) noexcept = delete;
	template_Mock_sensor &operator =( const template_Mock_sensor &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	template_Mock_sensor( template_Mock_sensor &&another ) noexcept = delete;
	template_Mock_sensor &operator =( template_Mock_sensor &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable typeing::Boolean _the_boolean_array[ Boolean_quantity ];
	mutable typeing::Memory_natural _the_natural_array[ Natural_quantity ];

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mocking
} // namespace cule
} // namespace jmsf
