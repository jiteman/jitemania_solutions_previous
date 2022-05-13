#include "jmsf/cule/macroses_Test.h"


#include "jmsf/pointing_old/testing/factory_Pointie_and_Proxie.h"
#include "jmsf/pointing_old/sensing/factory_Sensing.h"
#include "jmsf/pointing_old/testing/testing_Pointie.h"
#include "jmsf/pointing_old/sensing/sensing_Pointie.h"

#include "jmsf/patterning/Singleton.hin"


#include <iostream>


namespace jmsf {
namespace pointing {


//CULE_TEST( shouldCorrectlyDeleteReference ) {
//	::std::cout << "CULE_TEST( shouldCorrectlyDeleteReference )" << ::std::endl;

////	memorying::Womp< sensing::factory_Sensing > test_factory = sensing::factory_Sensing::instance();
//	pointing::Pointer< sensing::sensing_Pointie > sensing_pointie = sensing::factory_Sensing::instance()->create_pointie();

//	::std::cout << "CULE_TEST( shouldCorrectlyDeleteReference ) - point 1" << ::std::endl;

//	{
//		::std::cout << "CULE_TEST( shouldCorrectlyDeleteReference ) - point 2" << ::std::endl;
//		pointing::Pointer< testing::testing_Pointie > testingPointie = testing::factory_Pointie_and_Proxie::instance()->create_pointie( sensing_pointie.get_nonlinked() );
//		::std::cout << "CULE_TEST( shouldCorrectlyDeleteReference ) - point 3" << ::std::endl;
//		this_pointer_should_not_be_null( testingPointie );

//		these_naturals_should_be_equal( typeing::Memory_natural_one, sensing_pointie->getConstructionCounter() );
//		these_naturals_should_be_equal( typeing::Memory_natural_nill, sensing_pointie->getDestrutionCounter() );
//	}

//	these_naturals_should_be_equal( typeing::Memory_natural_one, sensing_pointie->getDestrutionCounter() );
//	these_naturals_should_be_equal( sensing_pointie->getConstructionCounter(), sensing_pointie->getDestrutionCounter() );

//	::std::cout << "~CULE_TEST( shouldCorrectlyDeleteReference )" << ::std::endl;
//}

//CULE_TEST( shouldCorrectlyConstuctWeakReference ) {
//	pointing::Pointer< sensing::sensing_Pointie > sensingPointie = sensing::factory_Sensing::instance()->createPointie( cule::Cule_allocators::instance()->get_global_allocator() );

//	{
//		pointing::Pointer< testing::testing_Pointie > testingPointie = testing::factory_Pointie_and_Proxie::instance()->createPointie( sensingPointie.get_nonlinked() );
//		this_pointer_should_not_be_null( testingPointie );

//		these_naturals_should_be_equal( typeing::Memory_natural_one, sensingPointie->getConstructionCounter() );
//		these_naturals_should_be_equal( typeing::Memory_natural_nill, sensingPointie->getDestrutionCounter() );

//		pointing::Pointer< testing::testing_Pointie > weakTestingPointie = testingPointie.get_nonlinked();

//		these_naturals_should_be_equal( typeing::Memory_natural_one, sensingPointie->getConstructionCounter() );
//		these_naturals_should_be_equal( typeing::Memory_natural_nill, sensingPointie->getDestrutionCounter() );
//	}

//	these_naturals_should_be_equal( typeing::Memory_natural_one, sensingPointie->getDestrutionCounter() );
//	these_naturals_should_be_equal( sensingPointie->getConstructionCounter(), sensingPointie->getDestrutionCounter() );
//}

CULE_TEST( test_Pointer, shouldBeNillAfterCreation ) {
//	this_test_is_not_implemented_yet( JMSF_SL( "Nulling during creation without parameter" ) );
}

//CULE_TEST( shouldBeAsCreated ) {
//	this_test_is_not_implemented_yet( AS_string_literal( "Identity after creation with parameter" ) );
//}

//CULE_TEST( shouldBeCopiedCorrectly ) {
//	this_test_is_not_implemented_yet( AS_string_literal( "Copying" ) );
//	this_test_is_not_implemented_yet( AS_string_literal( "Copy construction" ) );
//}

//CULE_TEST( shouldOperateCorrectly ) {
//	this_test_is_not_implemented_yet( AS_string_literal( "Operating (series of tests) " ) );
//}


} // namespace pointing
} // namespace jmsf


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
