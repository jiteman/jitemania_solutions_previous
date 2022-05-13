#pragma once

#include "cNonlinked.hxx"


#include "jmsf/memorying/Womp.hpp"

#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "Nonlinked.hxx"
#include "cShared.hxx"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class cNonlinked {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	const A_type &operator *();
	const A_type *operator ->();

	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const cNonlinked &another ) const noexcept;
	typeing::Boolean operator !=( const cNonlinked &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~cNonlinked() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cNonlinked() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	cNonlinked( const memorying::Womp< A_type > &weak_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static cNonlinked create_from_static( const memorying::Womp< A_type > &weak_memory_pointer );

private: friend Nonlinked< A_type >;
	static cNonlinked create_from_nonlinked( const memorying::Womp< A_type > &weak_memory_pointer ) noexcept;

//private: friend cScoped< A_type >;
//	static cNonlinked create_from_scoped( const memorying::Womp< A_type > &weak_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cNonlinked( const cNonlinked &another ) noexcept;
	const cNonlinked &operator =( const cNonlinked &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	cNonlinked( cNonlinked &&another ) noexcept;
	cNonlinked &operator =( cNonlinked &&another ) noexcept;

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
