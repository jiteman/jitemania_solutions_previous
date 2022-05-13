#pragma once

#include "Interface_parent.hxx"


#include "Virtual_parent.h"

#include "Template_parent.hpp"

#include "jmsf/pointing/Shared.hpp"

#include "sensing_mipa/sensation_of_mipa_Construction_and_destruction.hxx"


namespace jmsf {
namespace memorying {
namespace testing_mipa {


class Interface_parent :
	public Template_parent< Interface_parent >,
	virtual public Virtual_parent
{

public:
	virtual int interface_get_integer_sum() const = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Interface_parent() noexcept;

	Interface_parent(
		int template_integer,
		const pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > &a_sensor );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Shared< sensing_mipa::sensation_of_mipa_Construction_and_destruction > _the_interface_parent_sensor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
