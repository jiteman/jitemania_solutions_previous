#pragma once

#include "Money.hxx"


#include "Expression.h"

#include "jmsf/pointing/cShared.hpp"
#include "jmsf/typeing/Reals.hpp"


#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/Ansii_allocating_assistor.hxx"
#include "jmsf/memorying/Womp.hxx"

#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/encodebuba/nativing/native_Scoped.hxx"

#include "tdd_learning.h"


namespace tdd_learning {


class TDD_LEARNING_SHARED_INTERFACE Money :
	public Expression
{

public:
	::jmsf::encodebuba::nativing::native_Scoped< Money > times( ::jmsf::typeing::Short_real a_multiplier ) const;
	::jmsf::encodebuba::nativing::native_Scoped< Expression > plus( const Money &another ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &get_currency() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	::jmsf::typeing::Boolean is_equal( const Money &another ) const noexcept;
	::jmsf::typeing::Boolean is_not_equal( const Money &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > to_ansii_text( const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &an_aaa ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Money() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Money() noexcept;
	Money( const ::jmsf::typeing::Short_real &an_amount, const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &a_currency ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::encodebuba::nativing::native_Scoped< Money > create( const ::jmsf::typeing::Short_real &an_amount, const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &a_currency );
	static ::jmsf::encodebuba::nativing::native_Scoped< Expression > create_as_expression( const ::jmsf::typeing::Short_real &an_amount, const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > &a_currency );
	static ::jmsf::encodebuba::nativing::native_Scoped< Money > create_as_dollar( const ::jmsf::typeing::Short_real &an_amount );
	static ::jmsf::encodebuba::nativing::native_Scoped< Money > create_as_franc( const ::jmsf::typeing::Short_real &an_amount );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Money( const Money &another ) noexcept;
	const Money &operator =( const Money &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Money( Money &&another ) noexcept;
	Money &operator =( Money &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
protected:
	::jmsf::typeing::Short_real _the_amount;
	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > _the_currency;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace tdd_learning
