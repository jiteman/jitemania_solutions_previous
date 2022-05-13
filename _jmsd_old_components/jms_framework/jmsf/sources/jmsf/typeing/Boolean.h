#pragma once


#include "internals/internal_types.h"

#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/memorying/Womp.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace typeing {


class JMSF_SHARED_INTERFACE Boolean {

public:
	typedef internals::platform_boolean my_boolean_integral_type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
	Boolean operator !() const noexcept;
	Boolean operator &&( const Boolean &other ) const noexcept;
	Boolean operator ||( const Boolean &other ) const noexcept;

public: // logical synonyms
	Boolean inversion() const noexcept;
	Boolean equal( Boolean other ) const noexcept;
	Boolean notEqual( Boolean other ) const noexcept;
	Boolean conjunction( Boolean other ) const noexcept;
	Boolean disjunction( Boolean other ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Boolean &other ) const noexcept;
	Boolean operator !=( const Boolean &other ) const noexcept;
	Boolean operator <( const Boolean &other ) const noexcept;
	Boolean operator <=( const Boolean &other ) const noexcept;
	Boolean operator >( const Boolean &other ) const noexcept;
	Boolean operator >=( const Boolean &other ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( validating::Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( validating::Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	operator internals::platform_boolean() const noexcept;
	internals::platform_boolean get_native_value() const noexcept;
	const pointing::cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Boolean() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean() noexcept;

public:
	static Boolean create( internals::platform_boolean boolean_value = internals::platform_boolean( 0 ) );

private:
	Boolean( internals::platform_boolean boolean_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // Seinsei - todonext create move construction and move assignment
	Boolean( const Boolean &other ) noexcept;
	const Boolean &operator =( const Boolean &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_boolean _boolean_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


JMSF_SHARED_INTERFACE extern const Boolean True;
JMSF_SHARED_INTERFACE extern const Boolean False;


} // namespace typeing
} // namespace jmsf
