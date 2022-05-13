#pragma once


//#include "jmsf/pointing/Pointer.hpp"
#include "jmsf/pointing/Shared.hpp"

#include "jmsf/cule/user_interfacing/Ui_output.hxx"
#include "jmsf/cule/resulting/Test_result_collection.hxx"


namespace jmsf {
namespace cule {
namespace executing {


class Test_runner {

public:
	virtual ~Test_runner();
	Test_runner( const pointing::Shared< user_interfaces::Ui_output > &uiOutput );

	void run();

private:
	void new_print( const pointing::cShared< resulting::Test_result_collection > &test_result );

	Test_runner( const Test_runner & ) {}
	const Test_runner &operator=( const Test_runner & ) { return *this; }

private:
	pointing::Shared< user_interfaces::Ui_output > _uiOutput;

};


} // namespace
}
}
