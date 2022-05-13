#include "Fixture_tear_down_exception.h"


#include "jmsf/cule/cule_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/validating/File_and_line.h"


//#include <utility>


namespace jmsf {
namespace cule {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > Fixture_tear_down_exception::get_exception_name() const noexcept {
	return _exception_typename.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Fixture_tear_down_exception::~Fixture_tear_down_exception() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Fixture_tear_down_exception::Fixture_tear_down_exception( const pointing::cShared< texting::Ansii_text > &reason, const ::jmsf::validating::File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( reason, file_and_line ),
		_exception_typename(
			texting::Aaa_sl(
				cule_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "Fixture_tear_down_exception" ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Fixture_tear_down_exception::Fixture_tear_down_exception( const Fixture_tear_down_exception &/*another*/ ) noexcept {
//}

//const Fixture_tear_down_exception &Fixture_tear_down_exception::operator =( const Fixture_tear_down_exception &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy derived part
//	static_cast< base_class_name & >( *this ) = another;
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Fixture_tear_down_exception::Fixture_tear_down_exception( Fixture_tear_down_exception &&/*another*/ ) noexcept {
//}

//Fixture_tear_down_exception &Fixture_tear_down_exception::operator =( Fixture_tear_down_exception &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move derived part
//	static_cast< base_class_name & >( *this ) = another;
//	another = Fixture_tear_down_exception();
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace cule
} // namespace jmsf

