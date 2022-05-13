#pragma once

#include "Test_disabled.hxx"


#include "Test.h"

#include "jmsf/cule/cule.h"


namespace jmsf {
namespace cule {
namespace testing {


class JMSF_CULE_SHARED_INTERFACE Test_disabled :
	public Test
{

public:
	// virtuals Test
	void run() const override;
	//~virtuals Test

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Test
	const texting::String_literal &get_name() const noexcept override;
	const texting::String_literal &get_filename() const noexcept override;
	typeing::Memory_natural get_line_number() const noexcept override;
	//~virtuals Test

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Test
	~Test_disabled() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Test_disabled( const texting::String_literal &test_name, const validating::File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_disabled( const Test_disabled &another ) noexcept = delete;
	const Test_disabled &operator =( const Test_disabled &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_disabled( Test_disabled &&another ) noexcept = delete;
	Test_disabled &operator =( Test_disabled &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const texting::String_literal _disabled_test_name;
	const validating::File_and_line _disabled_test_file_and_line;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace cule
} // namespace jmsf

