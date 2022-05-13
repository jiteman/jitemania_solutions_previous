#pragma once

#include "jmsf/patterning/Singleton.hpp"

#include "sensing_Pointie.hxx"

//#include "jmsf/pointing/Pointer.hxx"
//#include "jmsf/memorying/Womp.hxx"
#include "jmsf/pointing/Shared.hxx"

#include "jmsf/memorying/Destructor.hxx"
//#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace pointing {
namespace sensing {


class factory_Sensing :
	public ::jmsf::patterning::Singleton< factory_Sensing >
{

public:
	virtual pointing::Shared< sensing_Pointie > create_pointie() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< factory_Sensing >;
	// virtual
	~factory_Sensing() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: // friend ::jmsf::patterning::Singleton< factory_Sensing >;
//	static factory_Sensing *create_singleton_instance() noexcept;
//	static factory_Sensing *createInstance() noexcept;

protected:
	factory_Sensing() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_Sensing( const factory_Sensing &other ) noexcept = delete;
	factory_Sensing &operator =( const factory_Sensing &other ) noexcept = delete;
	factory_Sensing( factory_Sensing &&other ) noexcept = delete;
	factory_Sensing &operator =( factory_Sensing &&other ) noexcept = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace sensing
} // namespace pointing
} // namespace jmsf
