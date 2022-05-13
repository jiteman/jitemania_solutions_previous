#pragma once

#include "Mixin_parent.hxx"


#include "Virtual_parent.h"

#include "jmsf/pointing/Shared.hpp"

#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.hxx"


namespace jmsf {
namespace memorying {
namespace testing_mipa {


class Mixin_parent :
	virtual public Virtual_parent
{

public:
	// virtuals Virtual_parent
	int virtual_get_integer() const;
	//~virtuals Virtual_parent

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual int mixin_get_another_integer() const = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Virtual_parent
	~Mixin_parent() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mixin_parent(
		int integer,
		const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Mixin_parent( const Mixin_parent &another ) noexcept;
	const Mixin_parent &operator =( const Mixin_parent &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Mixin_parent( Mixin_parent &&another ) noexcept;
	Mixin_parent &operator =( Mixin_parent &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	int _integer;
	pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > _the_mixin_parent_sensor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf


