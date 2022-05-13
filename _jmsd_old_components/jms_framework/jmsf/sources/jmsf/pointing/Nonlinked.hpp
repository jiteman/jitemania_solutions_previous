#pragma once

#include "Nonlinked.hxx"


#include "jmsf/memorying/Womp.hpp"

#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "cShared.hxx"
#include "cNonlinked.hxx"
//#include "Scoped.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class Nonlinked {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	A_type &operator *();
	A_type *operator ->();

	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cNonlinked< A_type > get_as_cnonlinked() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Nonlinked &another ) const noexcept;
	typeing::Boolean operator !=( const Nonlinked &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Nonlinked() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Nonlinked() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Nonlinked( const memorying::Womp< A_type > &weak_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Nonlinked create_from_static( const memorying::Womp< A_type > &weak_memory_pointer );

//private: friend Scoped< A_type >;
//	static Nonlinked create_from_scoped( const memorying::Womp< A_type > &weak_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Nonlinked( const Nonlinked &another ) noexcept;
	const Nonlinked &operator =( const Nonlinked &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Nonlinked( Nonlinked &&another ) noexcept;
	Nonlinked &operator =( Nonlinked &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< A_type > _weak_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace pointing
} // namespace jmsf
