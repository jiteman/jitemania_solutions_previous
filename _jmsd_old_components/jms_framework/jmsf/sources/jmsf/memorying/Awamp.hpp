#pragma once

#include "Awamp.hxx"

#include "Wamp.hpp"
#include "Amp.hpp"

#include "Womp.hxx"
#include "Allocator.hxx"


namespace jmsf {
namespace memorying {


template< class A_type >
class Awamp {

public:
	const Amp< A_type > &get_amp() const;
	const Wamp< A_type > &get_wamp() const;
	Amp< A_type > &take_amp();
	Wamp< A_type > &take_wamp();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Awamp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awamp() noexcept;

private:
	Awamp( const Amp< A_type > &an_array_memory_pointer ) noexcept;

public:
	static Awamp create( const Amp< A_type > &an_array_memory_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Awamp( const Awamp &another ) noexcept;
	const Awamp &operator =( const Awamp &another ) noexcept;

	Awamp( Awamp &&another ) noexcept;
	Awamp &operator =( Awamp &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Amp< A_type > _array_memory_pointer;
	Wamp< A_type > _weak_array_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
