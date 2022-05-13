#include "factory_Sensing.h"


//#include "realizing/realization_factory_Sensing.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"


#include "jmsf/patterning/Singleton.hin"


namespace jmsf {
namespace pointing {
namespace sensing {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_Sensing::~factory_Sensing() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
//factory_Sensing *factory_Sensing::create_singleton_instance() noexcept {
//factory_Sensing *factory_Sensing::createInstance() noexcept {
//	factory_Sensing *factorySensing = new realizing::realization_factory_Sensing;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factorySensing, MACROS_FILE_AND_LINE ) );
//	return factorySensing;
//}

factory_Sensing::factory_Sensing() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//factory_Sensing::factory_Sensing( const factory_Sensing &other ) noexcept
//	:
//		Singleton( other )
//{}

//const factory_Sensing &factory_Sensing::operator =( const factory_Sensing &other ) noexcept {
//	if ( this == &other ) return *this;

//	// copy
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace sensing
} // namespace pointing
} // namespace jmsf
