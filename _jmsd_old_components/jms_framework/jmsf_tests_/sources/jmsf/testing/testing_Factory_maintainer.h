#pragma once

#include "testing_Factory_maintainer.hxx"


#include "jmsf/patterning/Singleton.hpp"

#include "realizing/realization_testing_Environment.h"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace testing {


class testing_Factory_maintainer :
	public patterning::Singleton< testing_Factory_maintainer >
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< testing_Factory_maintainer >;
	~testing_Factory_maintainer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< testing_Factory_maintainer, testing_Factory_maintainer >;
	testing_Factory_maintainer() noexcept;

private: friend realizing::realization_testing_Environment;
	static void create_instance( const memorying::Womp< memorying::Allocator > &an_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	testing_Factory_maintainer( const testing_Factory_maintainer &another ) noexcept = delete;
	testing_Factory_maintainer &operator =( const testing_Factory_maintainer &another ) noexcept = delete;
	testing_Factory_maintainer( testing_Factory_maintainer &&another ) noexcept = delete;
	testing_Factory_maintainer &operator =( testing_Factory_maintainer &&another ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace jmsf
