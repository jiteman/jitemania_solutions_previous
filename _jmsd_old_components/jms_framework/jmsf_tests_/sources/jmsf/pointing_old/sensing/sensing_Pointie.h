#pragma once


#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/typeing/Naturals.hxx"


namespace jmsf {
namespace pointing {
namespace sensing {


class sensing_Pointie {

public:
	virtual void registerDestruction() noexcept = 0;
	virtual void registerConstruction() noexcept = 0;

	virtual typeing::Memory_natural getDestrutionCounter() const noexcept = 0;
	virtual typeing::Memory_natural getConstructionCounter() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< sensing_Pointie >;
	virtual ~sensing_Pointie() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace sensing
} // namespace pointing
} // namespace jmsf
