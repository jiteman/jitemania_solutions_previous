#pragma once


#include "List_agent.hxx"

#include "../traversing/List_traverser.hxx"

#include "jmsf/memorying/Omp.hxx"
#include "jmsf/structing/noding/Doubly_linked_node.hxx"
#include "jmsf/typeing/Naturals.hxx"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
class List_agent {

private: friend traversing::List_traverser< A_type >;
	virtual memorying::Omp< noding::Doubly_linked_node< A_type > > &take_begin() noexcept = 0;
	virtual memorying::Omp< noding::Doubly_linked_node< A_type > > &take_end() noexcept = 0;
	virtual typeing::Memory_natural &take_quantity() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ~List_agent() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};




} // namespace containing
} // namespace structing
} // namespace jmsf
