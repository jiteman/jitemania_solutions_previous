#pragma once


#include "Wamp.hxx"


#include "internalling/Amp_data.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "Awa_iterator.hxx"


namespace jmsf {
namespace memorying {


template< class A_type >
class Wamp {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	Awa_iterator< A_type > get() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awa_iterator< A_type > take();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_address get_object_address() const;
	typeing::Memory_natural get_quantity() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Wamp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Wamp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Wamp(
		const internalling::Amp_data< A_type > &an_amp_data,
		typeing::Memory_natural a_quantity ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Wamp create(
		const internalling::Amp_data< A_type > &an_amp_data,
		typeing::Memory_natural a_quantity );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Wamp( const Wamp &another ) noexcept;
	const Wamp &operator =( const Wamp &another ) noexcept;

	Wamp( Wamp &&another ) noexcept;
	Wamp &operator =( Wamp &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internalling::Amp_data< A_type > _the_amp_data;
	typeing::Memory_natural _the_quantity;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
