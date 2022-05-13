#pragma once

#include "sensation_of_mipa_Construction_and_destruction.hxx"


#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/pointing/Shared.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace memorying {
namespace testing_mipa {
namespace sensing_mipa {


class sensation_of_mipa_Construction_and_destruction {

public:
	void register_diamond_destruction() noexcept;
	void register_diamond_construction() noexcept;

	void register_interface_destruction() noexcept;
	void register_interface_construction() noexcept;

	void register_mixin_destruction() noexcept;
	void register_mixin_construction() noexcept;

	void register_template_destruction() noexcept;
	void register_template_construction() noexcept;

	void register_virtual_destruction() noexcept;
	void register_virtual_construction() noexcept;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Memory_natural get_diamond_destruction_counter() const noexcept;
	typeing::Memory_natural get_diamond_construction_counter() const noexcept;

	typeing::Memory_natural get_interface_destruction_counter() const noexcept;
	typeing::Memory_natural get_interface_construction_counter() const noexcept;

	typeing::Memory_natural get_mixin_destruction_counter() const noexcept;
	typeing::Memory_natural get_mixin_construction_counter() const noexcept;

	typeing::Memory_natural get_template_destruction_counter() const noexcept;
	typeing::Memory_natural get_template_construction_counter() const noexcept;

	typeing::Memory_natural get_virtual_destruction_counter() const noexcept;
	typeing::Memory_natural get_virtual_construction_counter() const noexcept;

	typeing::Memory_natural get_total_destruction_counter() const noexcept;
	typeing::Memory_natural get_total_construction_counter() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< sensation_of_mipa_Construction_and_destruction >;
	~sensation_of_mipa_Construction_and_destruction() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	sensation_of_mipa_Construction_and_destruction() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	//	sencation_of_Construction_and_destruction() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static pointing::Shared< sensation_of_mipa_Construction_and_destruction > create();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	sensation_of_mipa_Construction_and_destruction( const sensation_of_mipa_Construction_and_destruction &another ) noexcept;
	const sensation_of_mipa_Construction_and_destruction &operator =( const sensation_of_mipa_Construction_and_destruction &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	sensation_of_mipa_Construction_and_destruction( sensation_of_mipa_Construction_and_destruction &&another ) noexcept;
	sensation_of_mipa_Construction_and_destruction &operator =( sensation_of_mipa_Construction_and_destruction &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Memory_natural _the_diamond_construction_counter;
	typeing::Memory_natural _the_diamond_destruction_counter;

	typeing::Memory_natural _the_interface_construction_counter;
	typeing::Memory_natural _the_interface_destruction_counter;

	typeing::Memory_natural _the_mixin_construction_counter;
	typeing::Memory_natural _the_mixin_destruction_counter;

	typeing::Memory_natural _the_template_construction_counter;
	typeing::Memory_natural _the_template_destruction_counter;

	typeing::Memory_natural _the_virtual_construction_counter;
	typeing::Memory_natural _the_virtual_destruction_counter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace sensing_mipa
} // namespace testing_mipa
} // namespace memorying
} // namespace jmsf
