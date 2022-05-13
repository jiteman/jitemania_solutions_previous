#include "Test_fault_exception.h"


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
const pointing::cWeak< texting::Ansii_text > Test_fault_exception::get_exception_name() const noexcept {
	return _exception_typename.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Test_fault_exception::~Test_fault_exception() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_fault_exception::Test_fault_exception( const pointing::cShared< texting::Ansii_text > &reason, const ::jmsf::validating::File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( reason, file_and_line ),
		_exception_typename(
			texting::Aaa_sl(
				cule_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "Test_fault_exception" ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Test_fault_exception::Test_fault_exception( const Test_fault_exception &another ) noexcept
//	:
//		mixin_Exception( another )
//{}

//const Test_fault_exception &Test_fault_exception::operator =( const Test_fault_exception &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy derived part
//	cule_Failure_exception::operator =( another );
//	mixin_Exception::operator =( another );
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Test_fault_exception::Test_fault_exception( Test_fault_exception &&another ) noexcept
//	:
//		cule_Failure_exception( ::std::move( another ) ),
//		mixin_Exception( ::std::move( another ) ),
//		_exception_typename( ::std::move( another._exception_typename ) )
//{}

//Test_fault_exception &Test_fault_exception::operator =( Test_fault_exception &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move derived part
//	cule_Failure_exception::operator = ( ::std::move( another ) );
//	mixin_Exception::operator = ( ::std::move( another ) );
//	_exception_typename = ::std::move( another._exception_typename );
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace cule
} // namespace jmsf

