#pragma once

#include "../sensing_Pointie.h"


//#include "realizing_factory_Sensing.hxx"

////#include "jmsf/Pointer.hxx"

#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/pointing_old/sensing/realizing/realizing_factory_Sensing.hxx"
//#include "jmsf/pointing/Pointer.hxx"

#include "jmsf/pointing/Shared.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace pointing {
namespace sensing {
namespace realizing {


class realizing_sensing_Pointie :
	public sensing_Pointie
{

public:
	// virtuals sensing_Pointie
	void registerDestruction() noexcept;
	void registerConstruction() noexcept;

	typeing::Memory_natural getDestrutionCounter() const noexcept;
	typeing::Memory_natural getConstructionCounter() const noexcept;
	//~virtuals sensing_Pointie

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual sensing_Pointie
	~realizing_sensing_Pointie() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< sensing_Pointie, realizing_sensing_Pointie >;
	realizing_sensing_Pointie() noexcept;

private: friend realizing_factory_Sensing;
	static pointing::Shared< sensing_Pointie > create(
		const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
		const memorying::Womp< memorying::Allocator > &sensing_pointie_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_sensing_Pointie( const realizing_sensing_Pointie &other ) noexcept;
	const realizing_sensing_Pointie &operator =( const realizing_sensing_Pointie &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _constructionCounter;
	typeing::Memory_natural _destructionCounter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace sensing
} // namespace pointing
} // namespace jmsf
