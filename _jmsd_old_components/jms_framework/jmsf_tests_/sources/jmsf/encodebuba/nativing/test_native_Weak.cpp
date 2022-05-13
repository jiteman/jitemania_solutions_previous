#include "jmsf/cule/macroses_Test.h"


#include "jmsf/encodebuba/nativing/native_Weak.hin"
#include "jmsf/encodebuba/nativing/native_Shared.hin"


namespace jmsf {
namespace encodebuba {
namespace nativing {


CULE_TEST( native_Weak, should_be_empty_after_creation ) {
	native_Weak< int > empty_native_weak;

	Cule_this_native( empty_native_weak ).should_be_empty();
}

CULE_TEST( native_Weak, should_delete_empty ) {
	{
		native_Weak< int > empty_native_weak;
	}
}

CULE_TEST( native_Weak, should_be_equal_empty_empty ) {
	native_Weak< int > empty_native_weak;

	Cule_this_native( native_Weak< int >() == native_Weak< int >() ).should_be();
	Cule_this_native( empty_native_weak == empty_native_weak ).should_be();
	Cule_this_native( empty_native_weak == native_Weak< int >() ).should_be();
	Cule_this_native( native_Weak< int >() == empty_native_weak ).should_be();
}

CULE_TEST( native_Weak, should_copy_empty ) {
	native_Weak< int > empty_native_weak;
	native_Weak< int > empty_native_weak_1;
	empty_native_weak_1 = empty_native_weak;

	Cule_this_native( empty_native_weak ).should_be_empty();
	Cule_this_native( empty_native_weak_1 ).should_be_empty();
	Cule_this_native( empty_native_weak_1.is_not_empty() ).should_not_be();
//	Cule_tThis( typeing::Memory_natural_nil ).should_be_equal_to( empty_native_shared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( native_Weak, should_copy_construct_empty ) {
	native_Weak< int > empty_native_weak;
	native_Weak< int > empty_native_weak_1 = empty_native_weak;

	Cule_this_native( empty_native_weak ).should_be_empty();
	Cule_this_native( empty_native_weak_1 ).should_be_empty();
	Cule_this_native( empty_native_weak_1.is_not_empty() ).should_not_be();
//	Cule_this( typeing::Memory_natural_nil).should_be_equal_to( empty_native_shared_1.get_connectivity().get_total_connectivity() );
}

CULE_TEST( native_Weak, should_move_empty ) {
	native_Weak< int > empty_native_weak;
	native_Weak< int > empty_native_weak_1;
	empty_native_weak_1 = ::std::move( empty_native_weak );

	Cule_this_native( empty_native_weak_1 ).should_be_empty();
	Cule_this_native( empty_native_weak ).should_be_empty();
	Cule_this_native( empty_native_weak == empty_native_weak_1 ).should_be();
}

CULE_TEST( native_Weak, should_move_construct_empty ) {
	native_Weak< int > empty_native_weak;
	native_Weak< int > empty_native_weak_1 = ::std::move( empty_native_weak );

	Cule_this_native( empty_native_weak_1 ).should_be_empty();
	Cule_this_native( empty_native_weak ).should_be_empty();
	Cule_this_native( empty_native_weak == empty_native_weak_1 ).should_be();
}

CULE_TEST( native_Weak, should_share_empty_to_paired ) {
	native_Weak< int > empty_native_weak;
	native_Shared< int > empty_native_shared = empty_native_weak.get_as_shared();

	Cule_this_native( empty_native_weak ).should_be_empty();
	Cule_this_native( empty_native_shared ).should_be_empty();
}


} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
