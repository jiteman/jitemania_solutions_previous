#pragma once


#include "../factory_Pointie_and_Proxie.h"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace pointing {
namespace testing {
namespace realizing {


class realizing_factory_Pointie_and_Proxie :
	public factory_Pointie_and_Proxie
{

public:
	// virtuals factory_Testing
	pointing::Shared< testing_Pointie > create_pointie( const pointing::Weak< sensing::sensing_Pointie > &sensing_pointer ) const noexcept;
//	pointing::xShared< testing_Proxie > create_proxie( const pointing::xWeak< sensing::sensing_Pointie > &sensing_pointer ) const noexcept;
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< factory_Pointie_and_Proxie >;
	// virtual
	~realizing_factory_Pointie_and_Proxie() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< factory_Pointie_and_Proxie, realizing_factory_Pointie_and_Proxie >;
	realizing_factory_Pointie_and_Proxie(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &testing_pointie_allocator,
		const memorying::Womp< memorying::Allocator > &testing_proxie_allocator ) noexcept;

private:
	static void create_instance(
		const memorying::Womp< memorying::Allocator > &factory_pointie_and_proxie_allocator,
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &testing_pointie_allocator,
		const memorying::Womp< memorying::Allocator > &testing_proxie_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_factory_Pointie_and_Proxie( const realizing_factory_Pointie_and_Proxie &other ) noexcept = delete;
	realizing_factory_Pointie_and_Proxie &operator =( const realizing_factory_Pointie_and_Proxie &other ) noexcept = delete;
	realizing_factory_Pointie_and_Proxie( realizing_factory_Pointie_and_Proxie &&other ) noexcept = delete;
	realizing_factory_Pointie_and_Proxie &operator =( realizing_factory_Pointie_and_Proxie &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _reference_counters_allocator;
	memorying::Womp< memorying::Allocator > _testing_pointie_allocator;
	memorying::Womp< memorying::Allocator > _testing_proxie_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace testing
} // namespace pointing
} // namespace jmsf
