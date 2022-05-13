#include "Test_disabled.h"


#include "jmsf/cule/registering/Test_registry.h"

#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Object_pointer.hin"


namespace jmsf {
namespace cule {
namespace testing {


void Test_disabled::run() const
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const texting::String_literal &Test_disabled::get_name() const noexcept {
	return _disabled_test_name;
}

const texting::String_literal &Test_disabled::get_filename() const noexcept {
	return _disabled_test_file_and_line.get_filename();
}

typeing::Memory_natural Test_disabled::get_line_number() const noexcept {
	return _disabled_test_file_and_line.get_line_number();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Test_disabled::~Test_disabled() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_disabled::Test_disabled(
	const texting::String_literal &test_name,
	const validating::File_and_line &file_and_line ) noexcept
	:
		_disabled_test_name( test_name ),
		_disabled_test_file_and_line( file_and_line )
{
	Test::take_test_registry().register_disabled_test(
		pointing::cNonlinked< Test >::create_from_static(
			memorying::Womp< Test >::create(
				memorying::Object_pointer< Test >::create_from_pointer(
					this ) ) ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Test_disabled::Test_disabled( const Test_disabled &/*another*/ ) noexcept {
//}

//const Test_disabled &Test_disabled::operator =( const Test_disabled &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Test_disabled::Test_disabled( Test_disabled &&/*another*/ ) noexcept {
//}

//Test_disabled &Test_disabled::operator =( Test_disabled &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace testing
} // namespace cule
} // namespace jmsf

