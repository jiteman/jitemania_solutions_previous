#include "jmsf/cule/macroses_Test.h"


#include "jmsf/encodebuba/nativing/native_Shared.hin"
#include "jmsf/encodebuba/nativing/native_Weak.hin"

#include "jmsf/encodebuba/validating/excepting/exception_native_Should_with_type_information.h"


namespace jmsf {
namespace encodebuba {
namespace nativing {


CULE_TEST( native_Shared, should_be_empty_after_creation ) {
	native_Shared< int > empty_native_shared;

	Cule_this_native( empty_native_shared ).should_be_empty();
}

CULE_TEST( native_Shared, should_delete_empty ) {
	{
		native_Shared< int > empty_native_shared;
	}
}

CULE_TEST( native_Shared, should_be_equal_empty_empty ) {
	native_Shared< int > empty_native_shared;

	Cule_this_native( native_Shared< int >() == native_Shared< int >() ).should_be();
	Cule_this_native( empty_native_shared == empty_native_shared ).should_be();
	Cule_this_native( empty_native_shared == native_Shared< int >() ).should_be();
	Cule_this_native( native_Shared< int >() == empty_native_shared ).should_be();
}

CULE_TEST( native_Shared, should_copy_empty ) {
	native_Shared< int > empty_native_shared;
	native_Shared< int > empty_native_shared_1;
	empty_native_shared_1 = empty_native_shared;

	Cule_this_native( empty_native_shared ).should_be_empty();
	Cule_this_native( empty_native_shared_1 ).should_be_empty();
	Cule_this_native( empty_native_shared_1.is_not_empty() ).should_not_be();
//	Cule_this( typeing::Memory_natural_nil ).should_be_equal_to( empty_native_shared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( native_Shared, should_copy_construct_empty ) {
	native_Shared< int > empty_native_shared;
	native_Shared< int > empty_native_shared_1 = empty_native_shared;

	Cule_this_native( empty_native_shared ).should_be_empty();
	Cule_this_native( empty_native_shared_1 ).should_be_empty();
	Cule_this_native( empty_native_shared_1.is_not_empty() ).should_not_be();
//	Cule_this( typeing::Memory_natural_nil).should_be_equal_to( empty_native_shared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( native_Shared, should_move_empty ) {
	native_Shared< int > empty_native_shared;
	native_Shared< int > empty_native_shared_1;
	empty_native_shared_1 = ::std::move( empty_native_shared );

	Cule_this_native( empty_native_shared_1 ).should_be_empty();
	Cule_this_native( empty_native_shared ).should_be_empty();
	Cule_this_native( empty_native_shared == empty_native_shared_1 ).should_be();
}

CULE_TEST( native_Shared, should_move_construct_empty ) {
	native_Shared< int > empty_native_shared;
	native_Shared< int > empty_native_shared_1 = ::std::move( empty_native_shared );

	Cule_this_native( empty_native_shared_1 ).should_be_empty();
	Cule_this_native( empty_native_shared ).should_be_empty();
	Cule_this_native( empty_native_shared == empty_native_shared_1 ).should_be();
}

CULE_TEST_E( native_Shared, should_not_dereference_empty, ::jmsf::encodebuba::validating::excepting::exception_native_Should_with_type_information ) {
	native_Shared< int > empty_native_shared;
	*empty_native_shared;
}

CULE_TEST( native_Shared, should_share_empty_to_paired ) {
	native_Shared< int > empty_native_shared;
	native_Weak< int > empty_native_weak = empty_native_shared.get_as_weak();

	Cule_this_native( empty_native_shared ).should_be_empty();
	Cule_this_native( empty_native_weak ).should_be_empty();
}


} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
