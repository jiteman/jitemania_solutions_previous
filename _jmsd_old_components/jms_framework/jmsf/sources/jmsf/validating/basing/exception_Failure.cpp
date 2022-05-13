#include "exception_Failure.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"


namespace jmsf {
namespace validating {
namespace basing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > exception_Failure::get_exception_category() const noexcept {
	if ( _failure_exception_type.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _failure_exception_type.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//exception_Failure::~exception_Failure() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Failure::exception_Failure() noexcept
	:
		_failure_exception_type(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "Failure" ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//exception_Failure::exception_Failure( const exception_Failure &/*another*/ ) noexcept {
//}

//const exception_Failure &exception_Failure::operator =( const exception_Failure &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace basing
} // namespace validating
} // namespace jmsf
