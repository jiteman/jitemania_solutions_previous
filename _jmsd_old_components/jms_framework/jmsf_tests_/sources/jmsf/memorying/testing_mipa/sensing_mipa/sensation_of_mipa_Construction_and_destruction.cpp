#include "sensation_of_mipa_Construction_and_destruction.h"


#include "jmsf/testing/testing_Allocators.h"

#include "jmsf/pointing/Shared.hin"
#include "jmsf/memorying/Constructor.hin"

#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/macroses_Should.h"


namespace jmsf {
namespace memorying {
namespace testing_mipa {
namespace sensing_mipa {


void sensation_of_mipa_Construction_and_destruction::register_diamond_destruction() noexcept {
	_the_diamond_destruction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_diamond_construction() noexcept {
	_the_diamond_construction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_interface_destruction() noexcept {
	_the_interface_destruction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_interface_construction() noexcept {
	_the_interface_construction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_mixin_destruction() noexcept {
	_the_mixin_destruction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_mixin_construction() noexcept {
	_the_mixin_construction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_template_destruction() noexcept {
	_the_template_destruction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_template_construction() noexcept {
	_the_template_construction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_virtual_destruction() noexcept {
	_the_virtual_destruction_counter += typeing::Memory_natural_one;
}

void sensation_of_mipa_Construction_and_destruction::register_virtual_construction() noexcept {
	_the_virtual_construction_counter += typeing::Memory_natural_one;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_diamond_destruction_counter() const noexcept {
	return _the_diamond_destruction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_diamond_construction_counter() const noexcept {
	return _the_diamond_construction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_interface_destruction_counter() const noexcept {
	return _the_interface_destruction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_interface_construction_counter() const noexcept {
	return _the_interface_construction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_mixin_destruction_counter() const noexcept {
	return _the_mixin_destruction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_mixin_construction_counter() const noexcept {
	return _the_mixin_construction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_template_destruction_counter() const noexcept {
	return _the_template_destruction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_template_construction_counter() const noexcept {
	return _the_template_construction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_virtual_destruction_counter() const noexcept {
	return _the_virtual_destruction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_virtual_construction_counter() const noexcept {
	return _the_virtual_construction_counter;
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_total_destruction_counter() const noexcept {
	return
		get_diamond_destruction_counter() +
		get_interface_destruction_counter() +
		get_mixin_destruction_counter() +
		get_template_destruction_counter() +
		get_virtual_destruction_counter();
}

typeing::Memory_natural sensation_of_mipa_Construction_and_destruction::get_total_construction_counter() const noexcept {
	return
		get_diamond_construction_counter() +
		get_interface_construction_counter() +
		get_mixin_construction_counter() +
		get_template_construction_counter() +
		get_virtual_construction_counter();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
sensation_of_mipa_Construction_and_destruction::~sensation_of_mipa_Construction_and_destruction() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
sensation_of_mipa_Construction_and_destruction::sensation_of_mipa_Construction_and_destruction() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//sencation_of_Construction_and_destruction::sencation_of_Construction_and_destruction() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
pointing::Shared< sensation_of_mipa_Construction_and_destruction > sensation_of_mipa_Construction_and_destruction::create() {
	jmsf_Should_never_be_empty( ::jmsf::testing::testing_Allocators::instance() );
	jmsf_Should_never_be_empty( ::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator() );
	jmsf_Should_never_be_empty( ::jmsf::testing::testing_Allocators::instance()->get_subsystem_allocator() );

	return
		pointing::Shared< sensation_of_mipa_Construction_and_destruction >::create(
			::jmsf::testing::testing_Allocators::instance()->get_reference_counters_allocator(),
			memorying::Constructor< sensation_of_mipa_Construction_and_destruction, sensation_of_mipa_Construction_and_destruction >::construct(
				::jmsf::testing::testing_Allocators::instance()->get_subsystem_allocator() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
sensation_of_mipa_Construction_and_destruction::sensation_of_mipa_Construction_and_destruction( const sensation_of_mipa_Construction_and_destruction &/*another*/ ) noexcept {
}

const sensation_of_mipa_Construction_and_destruction &sensation_of_mipa_Construction_and_destruction::operator =( const sensation_of_mipa_Construction_and_destruction &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
sensation_of_mipa_Construction_and_destruction::sensation_of_mipa_Construction_and_destruction( sensation_of_mipa_Construction_and_destruction &&/*another*/ ) noexcept {
}

sensation_of_mipa_Construction_and_destruction &sensation_of_mipa_Construction_and_destruction::operator =( sensation_of_mipa_Construction_and_destruction &&another ) noexcept {
	if ( &another == this ) return *this;

	// move
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace sensing_mipa
} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
