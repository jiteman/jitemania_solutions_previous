#include "jmsf_Exception.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"


namespace jmsf {
namespace validating {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > jmsf_Exception::get_exception_subsystem() const noexcept {
	if ( _jmsf_exception_subsystem.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _jmsf_exception_subsystem.get_as_cweak();
}
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//jmsf_Exception::~jmsf_Exception() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
jmsf_Exception::jmsf_Exception() noexcept
	:
		_jmsf_exception_subsystem(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "JMSF" ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//jmsf_Exception::jmsf_Exception( const jmsf_Exception &/*another*/ ) noexcept {
//}

//const jmsf_Exception &jmsf_Exception::operator =( const jmsf_Exception &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf
