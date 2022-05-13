#pragma once

#include "Test_registry.hxx"


#include "jmsf/al_std/stl_hin/vector_al_std.hin"
#include "jmsf/cule/cule.h"

#include "jmsf/cule/testing/Test.hxx"
#include "jmsf/pointing/cNonlinked.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace cule {
namespace registering {


class JMSF_CULE_SHARED_INTERFACE Test_registry {

public:
	void register_test( const pointing::cNonlinked< testing::Test > &new_test ) noexcept;
	void register_disabled_test( const pointing::cNonlinked< testing::Test > &new_test ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const ::std::vector< pointing::cNonlinked< testing::Test > > &get_registered_tests() const noexcept;
	const ::std::vector< pointing::cNonlinked< testing::Test > > &get_registered_disabled_tests() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Test_registry() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Test_registry() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_registry( const Test_registry &other ) noexcept = delete;
	Test_registry &operator =( const Test_registry &other ) = delete;

private:
	Test_registry( Test_registry &&other ) noexcept = delete;
	Test_registry &operator =( Test_registry &&other ) = delete;


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::std::vector< pointing::cNonlinked< testing::Test > > _registered_tests;
	::std::vector< pointing::cNonlinked< testing::Test > > _registered_disabled_tests;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace registering
} // namespace cule
} // namespace jmsf
