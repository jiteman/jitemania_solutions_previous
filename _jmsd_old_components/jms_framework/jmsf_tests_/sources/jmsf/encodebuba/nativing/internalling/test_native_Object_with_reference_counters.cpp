#include "jmsf/cule/macroses_Test.h"

#include "jmsf/cule/mocking/template_Mock_sensor.hin"
#include "jmsf/cule/mocking/Mock_sensing.h"


#include "jmsf/encodebuba/nativing/internalling/native_Object_with_reference_counters.hin"

#include "jmsf/encodebuba/nativing/testing/Nativing_testing_class.h"
#include "jmsf/encodebuba/nativing/internalling/native_Reference_counters.h"



#include "jmsf/encodebuba/nativing/native_Scoped.hin"
//#include "jmsf/encodebuba/validating/excepting/exception_native_Should.h"


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


#define CULE_CREATE_MOCK_NAME( class_name ) \
	Mock_##class_name


#define CULE_MOCK( class_name ) \
	class CULE_CREATE_MOCK_NAME( class_name ) : \
		public class_name, \
		public cule::mocking::Mock_sensing


CULE_MOCK( native_Reference_counters ) {

public:
//	void increase_shared_counter() override {
//		native_Reference_counters::increase_shared_counter();
//		Cule_this->take_sensor().increase( 0 );
//	}

//	void decrease_shared_counter() override {
//		native_Reference_counters::decrease_shared_counter();
//		Cule_this->take_sensor().decrease( 0 );
//	}

//	void increase_weak_counter() override {
//		native_Reference_counters::increase_weak_counter();
//		Cule_this->take_sensor().increase( 1 );
//	}

//	void decrease_weak_counter() override {
//		native_Reference_counters::decrease_weak_counter();
//		Cule_this->take_sensor().decrease( 1 );
//	}

public: // virtual native_Reference_counter
	~CULE_CREATE_MOCK_NAME( native_Reference_counters )() override {
		this->take_sensor().touch( 0 );
	}

public:
	CULE_CREATE_MOCK_NAME( native_Reference_counters )( cule::mocking::Mock_sensor *a_sensor )
		:
			Mock_sensing( a_sensor )
	{}

};


native_Object_with_reference_counters< testing::Nativing_testing_class > create_native_object_with_reference_counter();


CULE_TEST( native_Object_with_reference_counters, should_be_empty_after_creation ) {
	native_Object_with_reference_counters< testing::Nativing_testing_class > empty_object;

	Cule_this_native( empty_object ).should_be_empty();
}

CULE_TEST( native_Object_with_reference_counters, not_be_empty_when_created_with_object ) {
	native_Object_with_reference_counters< testing::Nativing_testing_class > native_object =
		create_native_object_with_reference_counter();

	Cule_this_native( native_object ).should_not_be_empty();
}

CULE_TEST( native_Object_with_reference_counters, should_delete_reference_counters ) {
	native_Scoped< cule::mocking::Mock_sensor > the_mock_sensor =
		native_Scoped< cule::mocking::Mock_sensor >::create(
			new cule::mocking::template_Mock_sensor< 1, 1 > );

	{
		native_Object_with_reference_counters< testing::Nativing_testing_class > native_object =
			native_Object_with_reference_counters< testing::Nativing_testing_class >::create(
				new CULE_CREATE_MOCK_NAME( native_Reference_counters )( the_mock_sensor.operator->() ),
				testing::Nativing_testing_class::create_new() );
	}

	Cule_this( the_mock_sensor->is_touched( 0 ) ).should_be(); // destructor
}


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf


namespace jmsf {
namespace encodebuba {
namespace nativing {
namespace internalling {


native_Object_with_reference_counters< testing::Nativing_testing_class > create_native_object_with_reference_counter() {
	return
		native_Object_with_reference_counters< testing::Nativing_testing_class >::create(
			native_Reference_counters::create_new(),
			testing::Nativing_testing_class::create_new() );
}


} // namespace internalling
} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
