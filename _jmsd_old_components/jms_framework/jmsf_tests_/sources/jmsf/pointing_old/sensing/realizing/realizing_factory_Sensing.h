#pragma once


#include "../factory_Sensing.h"

#include "jmsf/testing/testing_Factory_maintainer.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace pointing {
namespace sensing {
namespace realizing {


class realizing_factory_Sensing :
	public factory_Sensing
{

public:
	// virtuals factory_Sensing
	pointing::Shared< sensing_Pointie > create_pointie() const noexcept;
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realizing_factory_Sensing() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< factory_Sensing, realizing_factory_Sensing >;
	realizing_factory_Sensing(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator ) noexcept;

private: friend ::jmsf::testing::testing_Factory_maintainer;
	static void create_instance(
		const memorying::Womp< memorying::Allocator > &sensing_factory_allocator,
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_factory_Sensing( const realizing_factory_Sensing &other ) noexcept = delete;
	realizing_factory_Sensing &operator =( const realizing_factory_Sensing &other ) noexcept = delete;
	realizing_factory_Sensing( realizing_factory_Sensing &&other ) noexcept = delete;
	realizing_factory_Sensing &operator =( realizing_factory_Sensing &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _reference_counters_allocator;
	memorying::Womp< memorying::Allocator > _sensing_pointie_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace sensing
} // namespace pointing
} // jmsf
