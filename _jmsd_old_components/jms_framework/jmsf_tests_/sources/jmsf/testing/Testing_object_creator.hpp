#pragma once

#include "Testing_object_creator.hxx"


#include "jmsf/pointing/Scoped.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace testing {


template< class A_type >
class Testing_object_creator {

public:
	static memorying::Omp< A_type > create_omp();

	template< class A_first_parameter >
	static memorying::Omp< A_type > create_omp( const A_first_parameter &an_object );

	static pointing::Scoped< A_type > create_scoped();
};


} // namespace testing
} // namespace jmsf
