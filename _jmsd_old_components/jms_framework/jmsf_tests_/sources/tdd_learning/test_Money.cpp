#include "jmsf/cule/macroses_Test.h"


#include "tdd_learning/Money.h"
#include "tdd_learning/Expression.h"
#include "tdd_learning/Bank.h"

#include "jmsf/testing/testing_Allocators.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/String_literal.h"
#include "jmsf/pointing/cScoped.hin"

#include "jmsf/typeing/Naturals.hin"

#include "jmsf/encodebuba/nativing/native_Scoped.hin"

//#include "jmsf/memorying/excepting/exception_Memory_is_depleted.h"
//#include "jmsf/memorying/excepting/exception_Nullptr_is_dereferenced.h"
//#include <exception>


namespace tdd_learning {


CULE_TEST_FIXTURE( Money ) {

private:
	void set_up() override {
		usd_currency =
			::jmsf::texting::Aaa_sl(
				::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "USD" ) );

		franc_currency =
			::jmsf::texting::Aaa_sl(
				::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "CHF" ) );

	}

//	void tear_down() override {
//	}

public:
	::jmsf::typeing::Short_real real_1 = ::jmsf::typeing::Short_real::create( 1 );
	::jmsf::typeing::Short_real real_2 = ::jmsf::typeing::Short_real::create( 2 );
	::jmsf::typeing::Short_real real_3 = ::jmsf::typeing::Short_real::create( 3 );
	::jmsf::typeing::Short_real real_4 = ::jmsf::typeing::Short_real::create( 4 );
	::jmsf::typeing::Short_real real_5 = ::jmsf::typeing::Short_real::create( 5 );

	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > usd_currency;
	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > franc_currency;
};


CULE_TEST_F( Money, should_return_correct_currencies ) {
	Cule_this( fx_.usd_currency ).should_be_equal_to( Money::create_as_dollar( fx_.real_1 )->get_currency() );
	Cule_this( fx_.franc_currency ).should_be_equal_to( Money::create_as_franc( fx_.real_1 )->get_currency() );
}

CULE_TEST_F( Money, should_be_equal ) {
	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.real_5 );
	::jmsf::encodebuba::nativing::native_Scoped< Money > another_five = Money::create_as_dollar( fx_.real_5 );

	these_objects_should_be_equal( *five, *another_five );
}

CULE_TEST_F( Money, should_not_be_equal ) {
	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.real_5 );
	::jmsf::encodebuba::nativing::native_Scoped< Money > tree = Money::create_as_dollar( fx_.real_3 );

	these_objects_should_not_be_equal( *five, *tree );
}

CULE_TEST_F( Money, should_not_compare_dollars_and_francs ) {
	::jmsf::encodebuba::nativing::native_Scoped< Money > five_dollars = Money::create_as_dollar( fx_.real_5 );
	::jmsf::encodebuba::nativing::native_Scoped< Money > five_francs = Money::create_as_franc( fx_.real_5 );

	these_objects_should_not_be_equal( *five_dollars, *five_francs  );
}

CULE_TEST_F( Money, should_do_multiplication ) {
	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.real_5 );

	these_objects_should_be_equal( *Money::create_as_dollar( fx_.real_5 * fx_.real_2 ), *five->times( fx_.real_2 ) );
}

CULE_TEST_F( Money, should_do_sequence_of_multiplications ) {
	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.real_5 );

	these_objects_should_be_equal( *Money::create_as_dollar( fx_.real_5 * fx_.real_2 ), *five->times( fx_.real_2 ) );
	these_objects_should_be_equal( *Money::create_as_dollar( fx_.real_5 * fx_.real_3 ), *five->times( fx_.real_3 ) );
}

CULE_TEST_F( Money, should_do_simple_addition ) {
	const ::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > usd_currency =
		::jmsf::texting::Aaa_sl(
			::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor(),
			JMSF_SL( "USD" ) );

	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.real_5 );
	::jmsf::encodebuba::nativing::native_Scoped< Expression > sum = five->plus( *five );
	::jmsf::encodebuba::nativing::native_Scoped< Bank > bank = Bank::create();
	::jmsf::encodebuba::nativing::native_Scoped< Money > reduced = bank->reduce( *sum, *usd_currency );

	these_objects_should_be_equal( *Money::create_as_dollar( fx_.real_5 + fx_.real_5 ), *reduced  );
}

//CULE_TEST( Money, plus_should_return_sum ) {
//	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.money_5 );
//	::jmsf::encodebuba::nativing::native_Scoped< Expression > result = five->plus( *five );
//	::jmsf::encodebuba::nativing::native_Scoped< Sum > sum = Sum::create_from_expression( *result );
//}


//==============================================================================================================================

//CULE_TEST( Money, will_throw_unknown_exception ) {
//	throw 1;
//}

//CULE_TEST( Money, will_throw_std_bad_cast_exception ) {
//	throw ::std::bad_cast();
//}

//CULE_TEST( Money, will_throw_jmsf_exception_Memory_is_depleted ) {
//	const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

//	throw
//		::jmsf::memorying::excepting::exception_Memory_is_depleted(
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in the name of TDD" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in TDD we trust" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "the best way to program" ) ),
//			JMSF_FILE_AND_LINE );
//}

//CULE_DISABLED_TEST( Money, disabled_will_throw_jmsf_exception_Memory_is_depleted ) {
//	const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

//	throw
//		::jmsf::memorying::excepting::exception_Memory_is_depleted(
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in the name of TDD" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in TDD we trust" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "the best way to program" ) ),
//			JMSF_FILE_AND_LINE );
//}

//CULE_DISABLED_TEST_F( Money, fixtured_should_do_sequence_of_multiplications ) {
//	::jmsf::encodebuba::nativing::native_Scoped< Money > five = Money::create_as_dollar( fx_.real_5 );

//	these_objects_should_be_equal( *Money::create_as_dollar( fx_.real_5 * fx_.real_2 ), *five->times( fx_.real_2 ) );
//	these_objects_should_be_equal( *Money::create_as_dollar( fx_.real_5 * fx_.real_3 ), *five->times( fx_.real_3 ) );
//}

//CULE_TEST_E( Money, will_throw_unknown_exception_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	throw 1;
//}

//CULE_TEST_E( Money, will_throw_std_bad_cast_exception_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	throw ::std::bad_cast();
//}

//CULE_TEST_E( Money, will_throw_jmsf_exception_Memory_is_depleted_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

//	throw
//		::jmsf::memorying::excepting::exception_Memory_is_depleted(
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in the name of TDD" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in TDD we trust" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "the best way to program" ) ),
//			JMSF_FILE_AND_LINE );
//}

//CULE_DISABLED_TEST_E( Money, disabled_will_throw_jmsf_exception_Memory_is_depleted_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

//	throw
//		::jmsf::memorying::excepting::exception_Memory_is_depleted(
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in the name of TDD" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in TDD we trust" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "the best way to program" ) ),
//			JMSF_FILE_AND_LINE );
//}

//CULE_TEST_EF( Money, fixtured_will_throw_unknown_exception_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > usd_currency = fx_.usd_currency;
//	throw 1;
//}

//CULE_TEST_EF( Money, fixtured_will_throw_std_bad_cast_exception_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > usd_currency = fx_.usd_currency;
//	throw ::std::bad_cast();
//}

//CULE_TEST_EF( Money, fixtured_will_throw_jmsf_exception_Memory_is_depleted_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > usd_currency = fx_.usd_currency;

//	const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

//	throw
//		::jmsf::memorying::excepting::exception_Memory_is_depleted(
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in the name of TDD" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in TDD we trust" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "the best way to program" ) ),
//			JMSF_FILE_AND_LINE );
//}

//CULE_DISABLED_TEST_EF( Money, disabled_fixtured_will_throw_jmsf_exception_Memory_is_depleted_instead_of, ::jmsf::memorying::excepting::exception_Nullptr_is_dereferenced ) {
//	::jmsf::pointing::cShared< ::jmsf::texting::Ansii_text > usd_currency = fx_.usd_currency;

//	const ::jmsf::memorying::Womp< ::jmsf::texting::Ansii_allocating_assistor > &aaa = ::jmsf::testing::testing_Allocators::instance()->get_ansii_allocating_assistor();

//	throw
//		::jmsf::memorying::excepting::exception_Memory_is_depleted(
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in the name of TDD" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "in TDD we trust" ) ),
//			::jmsf::texting::Aaa_sl( aaa, JMSF_SL( "the best way to program" ) ),
//			JMSF_FILE_AND_LINE );
//}


} // namespace tdd_learning
