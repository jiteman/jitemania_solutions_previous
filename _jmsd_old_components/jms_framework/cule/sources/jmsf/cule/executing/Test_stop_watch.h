#pragma once


#include "jmsf/patterning/Singleton.hpp"

#include "jmsf/typeing/Naturals.hxx"
////#include "jmsf/Pointers.hpp"
////#include "jmsf/types.h"

#include "jmsf/cule/to_libs/system/System_time.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace cule {
namespace executing {


// Seinsei: todonext - remove the singleton, use custom instance
class Test_stop_watch :
	public patterning::Singleton< Test_stop_watch >
{

public:
	virtual typeing::Natural get_global_duration() = 0;
	virtual typeing::Natural get_local_duration() = 0;
	virtual void start_global() = 0;
	virtual void start_local() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< Test_stop_watch >;
	// virtual Singleton
	~Test_stop_watch() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace executing
} // namespace cule
} // namespace jmsf
