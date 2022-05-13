#pragma once


#include "../testing_Pointie.h"

//#include "jmsf/pointing/Pointer.hpp"

//#include "realizing_factory_Pointie_and_Proxie.hxx"
//#include "../../sensing/sensing_Pointie.hxx"

#include "jmsf/pointing/Shared.hpp"


#include "jmsf/pointing_old/testing/realizing/realizing_factory_Pointie_and_Proxie.hxx"
#include "jmsf/pointing_old/sensing/sensing_Pointie.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace pointing {
namespace testing {
namespace realizing {


class realizing_testing_Pointie :
	public testing_Pointie
{

public:
	// virtuals

	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realizing_testing_Pointie() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< testing_Pointie, realizing_testing_Pointie >;
	realizing_testing_Pointie( const pointing::Shared< sensing::sensing_Pointie > &sensing_pointer ) noexcept;

private: friend realizing_factory_Pointie_and_Proxie;
	static pointing::Shared< testing_Pointie > create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator,
		const pointing::Weak< sensing::sensing_Pointie > &sensing_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	::jmsf::pointing::Pointer< testing_Pointie > createClone() const noexcept;

private:
	realizing_testing_Pointie( const realizing_testing_Pointie &other ) noexcept;
	const realizing_testing_Pointie &operator =( const realizing_testing_Pointie &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	 pointing::Shared< sensing::sensing_Pointie > _sensing_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace testing
} // namespace pointing
} // namespace jmsf
