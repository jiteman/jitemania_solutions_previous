#include "Money.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_stream.hin"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/typeing/Reals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/macroses_Type_name.h"

#include "jmsf/encodebuba/nativing/native_Scoped.hin"


namespace tdd_learning {

::jmsf::encodebuba::nativing::native_Scoped< Money > Money::times( const ::jmsf::typeing::Short_real a_multiplier ) const {
	return create( _the_amount * a_multiplier, _the_currency );

//	return create( _the_amount * a_multiplier, _the_currency );
//	return Money::create_as_dollar( _the_amount * a_multiplier );
}

::jmsf::encodebuba::nativing::native_Scoped< Expression > Money::plus( const Money &another ) const {
	return create_as_expression( _the_amount + another._the_amount, _the_currency );
}

const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &Money::get_currency() const {
	return _the_currency;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::typeing::Boolean Money::is_equal( const Money &another ) const noexcept {
	if ( *_the_currency != *another._the_currency ) return ::jmsf::typeing::False;

//	if ( ::jmsf::encodebuba::nativing::get_type_identifier( *this ) != ::jmsf::encodebuba::nativing::get_type_identifier( another ) ) return ::jmsf::typeing::False;

	return _the_amount == another._the_amount;
}

::jmsf::typeing::Boolean Money::is_not_equal( const Money &another ) const noexcept {
	return !is_equal( another );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > Money::to_ansii_text( const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &an_aaa ) const {
	::jmsf::pointing::Shared< ::jmsf::texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( _the_amount );
	ansii_stream->put( ::jmsf::texting::Aaa_sl( an_aaa, JMSF_SL( " " ) ) );
	ansii_stream->put( _the_currency );

	return ::jmsf::texting::Aaa_cs( an_aaa, ansii_stream );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Money::~Money() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Money::Money() noexcept
{}

Money::Money( const ::jmsf::typeing::Short_real &an_amount, const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &a_currency ) noexcept
	:
		_the_amount( an_amount ),
		_the_currency( a_currency )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::encodebuba::nativing::native_Scoped< Money > Money::create(
	const ::jmsf::typeing::Short_real &an_amount,
	const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &a_currency )
{
	return ::jmsf::encodebuba::nativing::native_Scoped< Money >::create( new Money( an_amount, a_currency) );
}

// static
::jmsf::encodebuba::nativing::native_Scoped< Expression > Money::create_as_expression(
	const ::jmsf::typeing::Short_real &an_amount,
	const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &a_currency )
{
	return ::jmsf::encodebuba::nativing::native_Scoped< Expression >::create( new Money( an_amount, a_currency) );
}

// static
::jmsf::encodebuba::nativing::native_Scoped< Money > Money::create_as_dollar( const ::jmsf::typeing::Short_real &an_amount ) {
	return
		::jmsf::encodebuba::nativing::native_Scoped< Money >::create(
			new Money(
				an_amount,
				::jmsf::texting::Aaa_sl(
					::jmsf::jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
					JMSF_SL( "USD" ) ) ) );
}

// static
::jmsf::encodebuba::nativing::native_Scoped< Money > Money::create_as_franc( const ::jmsf::typeing::Short_real &an_amount ) {
	return
		::jmsf::encodebuba::nativing::native_Scoped< Money >::create(
			new Money(
				an_amount,
				::jmsf::texting::Aaa_sl(
					::jmsf::jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
					JMSF_SL( "CHF" ) ) ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Money::Money( const Money &/*another*/ ) noexcept {
}

const Money &Money::operator =( const Money &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Money::Money( Money &&/*another*/ ) noexcept {
}

Money &Money::operator =( Money &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace tdd_learning
