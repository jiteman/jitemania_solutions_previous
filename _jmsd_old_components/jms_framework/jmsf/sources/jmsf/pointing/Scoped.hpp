#pragma once

#include "Scoped.hxx"


#include "jmsf/memorying/Omp.hpp"

//#include "Nonlinked.hxx"
#include "cScoped.hxx"
#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class Scoped {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	A_type &operator *();
	A_type *operator ->();

	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	Nonlinked< A_type > get_as_nonlinked() noexcept;
	cScoped< A_type > move_as_cscoped() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Scoped() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Scoped() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Scoped( const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Scoped create( const memorying::Omp< A_type > &object_memory_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: // neither copy nor copy assignment
	Scoped( const Scoped &another ) noexcept;
	const Scoped &operator =( const Scoped &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Scoped( Scoped &&another ) noexcept;
	Scoped &operator =( Scoped &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< A_type > _object_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace pointing
} // namespace jmsf
