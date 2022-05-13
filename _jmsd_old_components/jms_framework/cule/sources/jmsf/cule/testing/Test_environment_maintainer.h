#pragma once

#include "Test_environment_maintainer.hxx"


#include "jmsf/pointing/cShared.hpp"
#include "jmsf/pointing/cNonlinked.hpp"

#include "Test.hxx"

#include "jmsf/validating/Exception_information.hxx"


namespace jmsf {
namespace cule {
namespace testing {


class Test_environment_maintainer {

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Test_environment_maintainer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Test_environment_maintainer(
		pointing::cShared< ::jmsf::validating::Exception_information > *an_exception_information,
		const pointing::cNonlinked< Test > &a_test );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_environment_maintainer( const Test_environment_maintainer &another ) noexcept = delete;
	const Test_environment_maintainer &operator =( const Test_environment_maintainer &another ) noexcept = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_environment_maintainer( Test_environment_maintainer &&another ) noexcept = delete;
	Test_environment_maintainer &operator =( Test_environment_maintainer &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const pointing::cNonlinked< Test > &_the_current_test;
	pointing::cShared< ::jmsf::validating::Exception_information > *_the_exception_information;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace cule
} // namespace jmsf
