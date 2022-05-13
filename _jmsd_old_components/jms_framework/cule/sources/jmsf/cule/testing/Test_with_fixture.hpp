#pragma once

#include "Test_with_fixture.hxx"


#include "Test.h"


namespace jmsf {
namespace cule {
namespace testing {


template< class A_type >
class Test_with_fixture :
	public virtual Test
{

private:
	// virtuals Test
	void set_up_fixture() const override;
	void tear_down_fixture() const override;
	//~virtuals Test

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	A_type *get_test_fixture() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Test
	~Test_with_fixture() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Test_with_fixture( const texting::String_literal &test_name, const ::jmsf::validating::File_and_line &file_and_line ) noexcept;
//	Test_with_fixture() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_with_fixture( const Test_with_fixture &another ) noexcept = delete;
	const Test_with_fixture &operator =( const Test_with_fixture &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_with_fixture( Test_with_fixture &&another ) noexcept = delete;
	Test_with_fixture &operator =( Test_with_fixture &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable A_type *_the_fixture;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace cule
} // namespace jmsf
