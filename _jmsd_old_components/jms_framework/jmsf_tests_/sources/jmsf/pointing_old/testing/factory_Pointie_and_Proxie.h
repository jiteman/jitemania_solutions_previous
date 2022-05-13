#pragma once


#include "jmsf/patterning/Singleton.hpp"

//#include "jmsf/tests_Factory_maintainer.hxx"

#include "testing_Pointie.hxx"
//#include "testing_Proxie.hxx"
#include "../sensing/sensing_Pointie.hxx"

//#include "jmsf/pointing/Pointer.hxx"
//#include "jmsf/pointing/Proxy.hxx"

#include "jmsf/pointing/Weak.hxx"
#include "jmsf/pointing/Shared.hxx"

//#include "jmsf/memorying/Allocator.hxx"
//#include "jmsf/memorying/Womp.hxx"
//#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace pointing {
namespace testing {


class factory_Pointie_and_Proxie :
	public patterning::Singleton< factory_Pointie_and_Proxie >
{

public:
	virtual pointing::Shared< testing_Pointie > create_pointie(
		const pointing::Weak< sensing::sensing_Pointie > &sensing_pointer ) const noexcept = 0;
//	virtual Proxy< testing_Proxie > create_proxie(
//		const Pointer< sensing::sensing_Pointie > &sensing_pointer ) const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< factory_Pointie_and_Proxie >;
	// virtual Singleton
	~factory_Pointie_and_Proxie() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace pointing
} // namespace jmsf
