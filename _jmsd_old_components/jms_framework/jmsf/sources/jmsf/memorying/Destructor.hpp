#pragma once


#include "Destructor.hxx"

#include "Omp.hxx"
#include "Amp.hxx"


namespace jmsf {
namespace memorying {


// Seinsei: todonext - figure out destruction and deallocation politics - without exceptions, but with error logging
// then create corresponding infrastructure
template< class A_type >
class Destructor {

public:
	static void destruct( const Omp< A_type > &an_object_memory_pointer );
	static void destruct( const Amp< A_type > &an_array_memory_pointer );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
