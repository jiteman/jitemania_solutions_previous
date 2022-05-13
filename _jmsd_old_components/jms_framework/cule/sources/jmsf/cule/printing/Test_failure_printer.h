#pragma once


#include "jmsf/pointing/Shared.hpp"


#include "jmsf/cule/user_interfacing/Ui_output.hxx"
#include "jmsf/cule/resulting/Test_fault.hxx"

#include "jmsf/pointing/cShared.hxx"
#include "jmsf/typeing/Naturals.hxx"
#include "jmsf/validating/Exception_information.hxx"


namespace jmsf {
namespace cule {
namespace printing {


class Test_failure_printer {

public:
	virtual ~Test_failure_printer();
	Test_failure_printer( const pointing::Shared< user_interfaces::Ui_output > &ui_output );

	void print_test_fault( typeing::Memory_natural number, const pointing::cShared< resulting::Test_fault > &test_fault );

private:
	Test_failure_printer( const Test_failure_printer & ) {}
	const Test_failure_printer &operator=( const Test_failure_printer & ) { return *this; }

private:
	pointing::Shared< user_interfaces::Ui_output > _ui_output;

	void print_test_failure_information( typeing::Memory_natural number, const pointing::cShared< resulting::Test_fault > &test_fault );
	void print_main_exception_information( typeing::Memory_natural number, const pointing::cShared< validating::Exception_information > &exception_information );
	void print_detailed_description( typeing::Memory_natural number, const pointing::cShared< validating::Exception_information > &exception_information );
	void print_type_information( typeing::Memory_natural number, const pointing::cShared< validating::Exception_information > &exception_information );
	void print_exception_hierarchy( typeing::Memory_natural number, const pointing::cShared< validating::Exception_information > &exception_information );
};


} // namespace
}
}
