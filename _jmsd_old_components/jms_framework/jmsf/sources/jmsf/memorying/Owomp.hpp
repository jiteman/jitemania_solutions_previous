#pragma once

#include "Owomp.hxx"


#include "Womp.hpp"
#include "Omp.hpp"

#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace memorying {


template< class A_type >
class Owomp {

public:
	const Omp< A_type > &get_omp() const;
	const Womp< A_type > &get_womp() const;
	Omp< A_type > &take_omp();
	Womp< A_type > &take_womp();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Owomp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Owomp() noexcept;

private:
	Owomp( const Omp< A_type > &an_object_memory_pointer ) noexcept;

public:
	static Owomp create( const Omp< A_type > &an_object_memory_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Owomp( const Owomp &another ) noexcept;
	const Owomp &operator =( const Owomp &another ) noexcept;

	Owomp( Owomp &&another ) noexcept;
	Owomp &operator =( Owomp &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Omp< A_type > _object_memory_pointer; // for holding
	Womp< A_type > _weak_object_memory_pointer; // for reference return

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
