#include "Test_fault.h"


#include "jmsf/cule/testing/Test.h"
#include "jmsf/cule/cule_Allocators.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"

#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Constructor.hin"

#include "jmsf/validating/Exception_information.h"
#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace cule {
namespace resulting {


const pointing::cWeak< texting::Ansii_text > Test_fault::get_test_file_name() const noexcept {
	if ( _test_filename.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _test_filename.get_as_cweak();
}

typeing::Memory_natural Test_fault::get_test_line_number() const noexcept {
	return _test_line_number;
}

const pointing::cWeak< texting::Ansii_text > Test_fault::get_test_name() const noexcept {
	if ( _test_name.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _test_name.get_as_cweak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< ::jmsf::validating::Exception_information > Test_fault::get_exception_information() const noexcept {
	return _exception_information.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Test_fault::~Test_fault() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_fault::Test_fault(
	const pointing::cShared< texting::Ansii_text > &test_filename,
	const typeing::Memory_natural test_line_number,
	const pointing::cShared< texting::Ansii_text > &test_name,
	const pointing::cShared< ::jmsf::validating::Exception_information > &exception_information ) noexcept
	:
		_test_filename( test_filename ),
		_test_line_number( test_line_number ),
		_test_name( test_name ),
		_exception_information( exception_information )
{}

// static
pointing::cShared< Test_fault > Test_fault::create(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &test_fault_allocator,
	const pointing::cNonlinked< testing::Test > a_test,
	const pointing::cShared< ::jmsf::validating::Exception_information > &exception_information )
{
	jmsf_Should_never_be_empty( reference_counters_allocator );
	jmsf_Should_never_be_empty( test_fault_allocator );
	jmsf_Should_never_be_empty( a_test );
//	jmsf_Should_never_be_empty( exception_information );

	const memorying::Womp< texting::Ansii_allocating_assistor > &aaa = cule_Allocators::instance()->get_ansii_allocating_assistor();

	return
		pointing::cShared< Test_fault >::create(
			reference_counters_allocator,
			memorying::Constructor< Test_fault, Test_fault >::construct(
				test_fault_allocator,
				texting::Aaa_sl( aaa, a_test->get_filename() ),
				a_test->get_line_number(),
				texting::Aaa_sl( aaa, a_test->get_name() ),
				exception_information ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_fault::Test_fault( const Test_fault &/*another*/ ) noexcept
{}

const Test_fault &Test_fault::operator =( const Test_fault &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace resulting
} // namespace cule
} // namespace jmsf
