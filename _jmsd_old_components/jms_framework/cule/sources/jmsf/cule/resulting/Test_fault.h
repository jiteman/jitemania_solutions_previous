#pragma once

#include "Test_fault.hxx"


//#include "jmsf/pointing/Constant_pointer.hpp"

#include "jmsf/pointing/cNonlinked.hpp"
#include "jmsf/pointing/cShared.hpp"

#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/cule/testing/Test.hxx"
#include "jmsf/texting/Ansii_text.hxx"

#include "jmsf/pointing/cWeak.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"

#include "jmsf/validating/Exception_information.hxx"


namespace jmsf {
namespace cule {
namespace resulting {


// Seinsei: todonext - create Test_failure and Test_error classes for different reasons
// Test has: name, file name, test line
// Fault has: file name, fault line, fault reason
// Figure out how to configure the failure and the error
// Figure out how to print both
class Test_fault {

public:
	const pointing::cWeak< texting::Ansii_text > get_test_file_name() const noexcept;
	typeing::Memory_natural get_test_line_number() const noexcept;
	const pointing::cWeak< texting::Ansii_text > get_test_name() const noexcept;

	const pointing::cWeak< ::jmsf::validating::Exception_information > get_exception_information() const noexcept;

//	const pointing::cWeak< texting::Ansii_text > get_fault_file_name() const noexcept;
//	typeing::Memory_natural get_fault_line_number() const noexcept;
//	const pointing::cWeak< texting::Ansii_text > get_fault_reason() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Test_fault >;
	~Test_fault() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Test_fault, Test_fault >;
	Test_fault(
		const pointing::cShared< texting::Ansii_text > &test_filename,
		typeing::Memory_natural test_line_number,
		const pointing::cShared< texting::Ansii_text > &test_name,
		const pointing::cShared< ::jmsf::validating::Exception_information > &exception_information ) noexcept;

public:
	static pointing::cShared< Test_fault > create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &test_fault_allocator,
		const pointing::cNonlinked< testing::Test > a_test,
		const pointing::cShared< ::jmsf::validating::Exception_information > &exception_information );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_fault( const Test_fault &another ) noexcept;
	const Test_fault &operator =( const Test_fault &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const pointing::cShared< texting::Ansii_text > _test_filename;
	const typeing::Memory_natural _test_line_number;
	const pointing::cShared< texting::Ansii_text > _test_name;
	const pointing::cShared< ::jmsf::validating::Exception_information > _exception_information;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace resulting
} // namespace cule
} // namespace jmsf
