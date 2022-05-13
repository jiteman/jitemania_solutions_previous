#pragma once

#include "Integers.hxx"


#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/pointing/cShared.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "Naturals.hxx"
#include "Boolean.hxx"


namespace jmsf {
namespace typeing {


template< class, int > class Naturals;


template< class A_type, int dummy >
class Integers {

public:
	typedef A_type my_integer_integral_type;

public:
	static const Integers INTEGERS_NIL;
	static const Integers INTEGERS_ONE;
	static const Integers INTEGERS_MINUS;
	static const Integers INTEGERS_MIN;
	static const Integers INTEGERS_MAX;

	static const Integers GET_INTEGERS_NIL() noexcept;
	static const Integers GET_INTEGERS_ONE() noexcept;
	static const Integers GET_INTEGERS_MINUS() noexcept;
	static const Integers GET_INTEGERS_MIN() noexcept;
	static const Integers GET_INTEGERS_MAX() noexcept;
//	static const Integers INTEGERS_BADMAX;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // math
	Integers operator +( const Integers &another ) const noexcept;
	Integers &operator +=( const Integers &another ) noexcept;

	Integers operator -( const Integers &another ) const noexcept;
	Integers operator -=( const Integers &another ) noexcept;

	Integers operator -() const noexcept;

	Integers operator *( const Integers &another ) const noexcept;
	Integers &operator *=( const Integers &another ) noexcept;

	Integers operator /( const Integers &another ) const;
	Integers &operator /=( const Integers &another );

	Integers operator %( const Integers &another ) const;
	Integers &operator %=( const Integers &another );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Integers operator ^( const Integers &another ) const noexcept;
	Integers &operator ^=( const Integers &another ) noexcept;

	Integers operator &( const Integers &another ) const noexcept;
	Integers &operator &=( const Integers &another ) noexcept;

	Integers operator |( const Integers &another ) const noexcept;
	Integers &operator |=( const Integers &another ) noexcept;

	Integers operator ~() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Integers operator !() const noexcept;
// 	Integers operator &&( const Integers &another ) const noexcept;
// 	Integers operator ||( const Integers &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Integers &another ) const noexcept;
	Boolean operator !=( const Integers &another ) const noexcept;
	Boolean operator <( const Integers &another ) const noexcept;
	Boolean operator <=( const Integers &another ) const noexcept;
	Boolean operator >( const Integers &another ) const noexcept;
	Boolean operator >=( const Integers &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Integers get_shifted_left() const noexcept;
	Integers &shift_left() noexcept;
	Integers operator <<( Memory_natural shift_value ) const noexcept;
	Integers &operator <<=( Memory_natural shift_value ) noexcept;

	Integers get_shifted_right() const noexcept;
	Integers &shift_right() noexcept;
	Integers operator >>( Memory_natural shift_value ) const noexcept;
	Integers &operator >>=( Memory_natural shift_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Integers &operator ++() noexcept;
	Integers operator ++( int ) noexcept;
	Integers &operator --() noexcept;
	Integers operator --( int ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // access
// 	ret_type &operator *() noexcept;
// 	const ret_type &operator *() const noexcept;
// 	ret_type *operator ->() noexcept;
// 	const ret_type *operator ->() const noexcept;

// 	ret_type &operator []( Unsigned index ) noexcept;
// 	const ret_type &operator []( Unsigned index ) const noexcept;

// 	ret_type operator()( parameters ) const noexcept;
// 	ret_type operator()( parameters ) noexcept;

//	operator ->*(); // pointer-to-member selection

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate );
//	void *operator new[]( Unsigned quantityToAllocate );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_nil() const noexcept;
	Boolean is_not_nil() const noexcept;
	Boolean is_positive() const noexcept; // _integer_value > 0
	Boolean is_negative() const noexcept;
	Boolean is_min() const noexcept;
	Boolean is_not_min() const noexcept;
	Boolean is_max() const noexcept;
	Boolean is_not_max() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_template_type() const noexcept;
	A_type get_native_value() const noexcept;
	Memory_natural get_sizeof() const noexcept;
	const pointing::cShared< texting::Ansii_text > to_ansii_text( const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Integers() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integers() noexcept;

public:
	static Integers create( A_type integer_value = A_type( 0 ) ) noexcept;
	static Integers create_min() noexcept;
	static Integers create_max() noexcept;
//	static Integers create_badmax() noexcept;

private:
	Integers( A_type integer_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // Seinsei - todonext create move construction and move assignment
	Integers( const Integers &another ) noexcept;
	const Integers &operator =( const Integers &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _integer_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


JMSF_SHARED_INTERFACE extern const Memory_integer Memory_integer_nil;
JMSF_SHARED_INTERFACE extern const Memory_integer Memory_integer_one;
JMSF_SHARED_INTERFACE extern const Memory_integer Memory_integer_minus;
JMSF_SHARED_INTERFACE extern const Memory_integer Memory_integer_min;
JMSF_SHARED_INTERFACE extern const Memory_integer Memory_integer_max;
//extern const Memory_integer Memory_integer_badmax;

JMSF_SHARED_INTERFACE extern const File_integer File_integer_nil;
JMSF_SHARED_INTERFACE extern const File_integer File_integer_one;
JMSF_SHARED_INTERFACE extern const File_integer File_integer_minus;
JMSF_SHARED_INTERFACE extern const File_integer File_integer_min;
JMSF_SHARED_INTERFACE extern const File_integer File_integer_max;
//extern const File_integer File_integer_badmax;

JMSF_SHARED_INTERFACE extern const Shortest_integer Shortest_integer_nil;
JMSF_SHARED_INTERFACE extern const Shortest_integer Shortest_integer_one;
JMSF_SHARED_INTERFACE extern const Shortest_integer Shortest_integer_minus;
JMSF_SHARED_INTERFACE extern const Shortest_integer Shortest_integer_min;
JMSF_SHARED_INTERFACE extern const Shortest_integer Shortest_integer_max;
//extern const Shortest_integer Shortest_integer_badmax;

JMSF_SHARED_INTERFACE extern const Shortest_integer_small Shortest_integer_small_nil;
JMSF_SHARED_INTERFACE extern const Shortest_integer_small Shortest_integer_small_one;
JMSF_SHARED_INTERFACE extern const Shortest_integer_small Shortest_integer_small_minus;
JMSF_SHARED_INTERFACE extern const Shortest_integer_small Shortest_integer_small_min;
JMSF_SHARED_INTERFACE extern const Shortest_integer_small Shortest_integer_small_max;
//extern const Shortest_integer_small Shortest_integer_small_badmax;

JMSF_SHARED_INTERFACE extern const Short_integer Short_integer_nil;
JMSF_SHARED_INTERFACE extern const Short_integer Short_integer_one;
JMSF_SHARED_INTERFACE extern const Short_integer Short_integer_minus;
JMSF_SHARED_INTERFACE extern const Short_integer Short_integer_min;
JMSF_SHARED_INTERFACE extern const Short_integer Short_integer_max;
//extern const Short_integer Short_integer_badmax;

JMSF_SHARED_INTERFACE extern const Short_integer_small Short_integer_small_nil;
JMSF_SHARED_INTERFACE extern const Short_integer_small Short_integer_small_one;
JMSF_SHARED_INTERFACE extern const Short_integer_small Short_integer_small_minus;
JMSF_SHARED_INTERFACE extern const Short_integer_small Short_integer_small_min;
JMSF_SHARED_INTERFACE extern const Short_integer_small Short_integer_small_max;
//extern const Short_integer_small Short_integer_small_badmax;

JMSF_SHARED_INTERFACE extern const Integer Integer_nil;
JMSF_SHARED_INTERFACE extern const Integer Integer_one;
JMSF_SHARED_INTERFACE extern const Integer Integer_minus;
JMSF_SHARED_INTERFACE extern const Integer Integer_min;
JMSF_SHARED_INTERFACE extern const Integer Integer_max;
//extern const Integer Integer_badmax;

JMSF_SHARED_INTERFACE extern const Integer_small Integer_small_nil;
JMSF_SHARED_INTERFACE extern const Integer_small Integer_small_one;
JMSF_SHARED_INTERFACE extern const Integer_small Integer_small_minus;
JMSF_SHARED_INTERFACE extern const Integer_small Integer_small_min;
JMSF_SHARED_INTERFACE extern const Integer_small Integer_small_max;
//extern const Integer_small Integer_small_badmax;

JMSF_SHARED_INTERFACE extern const Long_integer Long_integer_nil;
JMSF_SHARED_INTERFACE extern const Long_integer Long_integer_one;
JMSF_SHARED_INTERFACE extern const Long_integer Long_integer_minus;
JMSF_SHARED_INTERFACE extern const Long_integer Long_integer_min;
JMSF_SHARED_INTERFACE extern const Long_integer Long_integer_max;
//extern const Long_integer Long_integer_badmax;

JMSF_SHARED_INTERFACE extern const Long_integer_small Long_integer_small_nil;
JMSF_SHARED_INTERFACE extern const Long_integer_small Long_integer_small_one;
JMSF_SHARED_INTERFACE extern const Long_integer_small Long_integer_small_minus;
JMSF_SHARED_INTERFACE extern const Long_integer_small Long_integer_small_min;
JMSF_SHARED_INTERFACE extern const Long_integer_small Long_integer_small_max;
//extern const Long_integer_small Long_integer_small_badmax;


} // namespace typeing
} // namespace jmsf
