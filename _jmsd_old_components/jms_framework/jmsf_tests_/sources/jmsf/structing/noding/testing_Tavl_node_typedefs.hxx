#pragma once


#include "jmsf/structing/noding/Tavl_node.hxx"

#include "jmsf/testing/Testing_object_creator.hxx"

#include "jmsf/pointing/Scoped.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/typeing/Naturals.hxx"


namespace jmsf {
namespace structing {
namespace noding {


typedef Tavl_node< typeing::Memory_natural > Mn_tavl_node;
typedef memorying::Omp< Mn_tavl_node > Mn_tavl_node_omp;
typedef pointing::Scoped< Mn_tavl_node > Mn_tavl_node_scoped;
typedef testing::Testing_object_creator< Mn_tavl_node > Mn_tavl_node_factory;


} // namespace noding
} // namespace structing
} // namespace jmsf
