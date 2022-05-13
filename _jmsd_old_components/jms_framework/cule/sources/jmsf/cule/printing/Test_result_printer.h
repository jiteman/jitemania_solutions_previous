#pragma once


//#include "jmsf/pointing/Pointer.hpp"
//#include "jmsf/pointing/Constant_pointer.hpp"

#include "jmsf/pointing/Shared.hpp"
#include "jmsf/pointing/cShared.hpp"


#include "jmsf/cule/user_interfacing/Ui_output.hxx"
#include "jmsf/cule/resulting/Test_result_collection.hxx"
#include "jmsf/cule/resulting/Test_fault.hxx"
#include "jmsf/texting/Ansii_text.hxx"
#include "jmsf/texting/macroses_String_literal.h"
#include "jmsf/pointing/cNonlinked.hxx"

#include "jmsf/al_std/stl_hin/vector_al_std.hin"


namespace jmsf {
namespace cule {
namespace printing {


class Test_result_printer {

private:
	const texting::String_literal FOREIGN_ERROR_NAME = JMSF_SL( "foreign error" );
	const texting::String_literal ERROR_NAME = JMSF_SL( "error" );
	const texting::String_literal FAILURE_NAME = JMSF_SL( "failure" );
	const texting::String_literal DISABLED_NAME = JMSF_SL( "disabled test" );

public:
	void print();

public:
	~Test_result_printer();

public:
	Test_result_printer(
		const pointing::Shared< user_interfaces::Ui_output > &ui_output,
		const pointing::cShared< resulting::Test_result_collection > &test_result_collection );

private:
	Test_result_printer( const Test_result_printer &another );
	const Test_result_printer &operator=( const Test_result_printer &another );

private:
	void print_test_faults( const ::std::vector< pointing::cShared< resulting::Test_fault > > &vector, const pointing::cShared< texting::Ansii_text > &name );

private:
	pointing::Shared< user_interfaces::Ui_output > _ui_output;
	const pointing::cShared< resulting::Test_result_collection > _test_result_collection;

};


} // namespace
}
}
