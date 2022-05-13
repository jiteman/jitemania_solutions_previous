#include "Test.h"


#include "jmsf/cule/registering/Test_registry.h"

#include "jmsf/pointing/cNonlinked.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Object_pointer.hin"


namespace jmsf {
namespace cule {
namespace testing {


//----------------------------------------------------------------------------------------------------------------------
// static
const registering::Test_registry &Test::get_test_registry() noexcept {
	return _test_registry;
}

// static
registering::Test_registry &Test::take_test_registry() noexcept {
	return _test_registry;
}

//----------------------------------------------------------------------------------------------------------------------
// virtual
void Test::set_up_fixture() const
{}

// virtual
void Test::tear_down_fixture() const
{}

Test::~Test() noexcept
{}

Test::Test( const texting::String_literal &test_name, const validating::File_and_line &file_and_line ) noexcept
	:
		_test_name( test_name ),
		_file_and_line( file_and_line )
{
	_test_registry.register_test(
		pointing::cNonlinked< Test >::create_from_static(
			memorying::Womp< Test >::create(
				memorying::Object_pointer< Test >::create_from_pointer(
					this ) ) ) );
}

Test::Test() noexcept
{}

Test::Test( const Test &/*another*/ ) noexcept
{}

const Test &Test::operator =( const Test &/*another*/ ) noexcept {
	return *this;
}

const texting::String_literal &Test::get_name() const noexcept {
	return _test_name;
}

const texting::String_literal &Test::get_filename() const noexcept {
	return _file_and_line.get_filename();
}

typeing::Memory_natural Test::get_line_number() const noexcept {
	return _file_and_line.get_line_number();
}

const validating::File_and_line &Test::get_file_and_line() const noexcept {
	return _file_and_line;
}

// static
registering::Test_registry Test::_test_registry;


} // namespace testing
} // namespace cule
} // namespace jmsf
