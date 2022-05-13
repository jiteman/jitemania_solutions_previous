#pragma once

#include "Diamond_child.hxx"


#include "Interface_parent.h"
#include "Mixin_parent.h"

#include "jmsf/pointing/Shared.hpp"

#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.hxx"


namespace jmsf {
namespace memorying {
namespace testing_mipa {


class Diamond_child :
	public Mixin_parent,
	public Interface_parent
{

public:
	// virtuals Interface_parent
	int interface_get_integer_sum() const;
	//~virtuals Interface_parent

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Mixin_parent
	int mixin_get_another_integer() const;
	//~virtuals Mixin_parent

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Interface_parent
	~Diamond_child() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Diamond_child(
		int integer,
		int another_integer,
		int template_integer,
		const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Diamond_child( const Diamond_child &another ) noexcept;
	const Diamond_child &operator =( const Diamond_child &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Diamond_child( Diamond_child &&another ) noexcept;
	Diamond_child &operator =( Diamond_child &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	int _another_integer;
	pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > _the_diamond_child_sensor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
