#include "cule_Environment.h"


#include "realizing/realization_cule_Environment.h"

#include "jmsf/encodebuba/encodebuba_Environment.h"
#include "jmsf/al_std/al_std_Environment.h"
#include "jmsf/jmsf_Environment.h"
#include "jmsf/patterning/Singleton.hin"
#include "jmsf/encodebuba/nativing/native_Singleton.hin"
#include "jmsf/encodebuba/nativing/native_Nonlinked.hin"

//#include "jmsf/jmsf_Allocators.h"


#include <iostream>


namespace jmsf {
namespace cule {


// static
typeing::Boolean cule_Environment::initialize() {
	if ( cule_Environment::is_not_empty() ) {
		cule_Environment::instance()->increase_instance_counter();
		return typeing::True;
	}

	if ( !encodebuba::encodebuba_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: cule_Environment::initialize() - can't initialize encodebuba_Environment" << ::std::endl;
		return typeing::False;
	}

	if ( !al_std::al_std_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: cule_Environment::initialize() - can't initialize al_std_Environment" << ::std::endl;
		encodebuba::encodebuba_Environment::deinitialize();
		return typeing::False;
	}

	if ( !jmsf_Environment::initialize() ) {
		::std::cout << ::std::endl << "Error: cule_Environment::initialize() - can't initialize jmsf_Environment" << ::std::endl;
		encodebuba::encodebuba_Environment::deinitialize();
		al_std::al_std_Environment::deinitialize();
		return typeing::False;
	}

	set_instance( realizing::realization_cule_Environment::create( jmsf_Environment::instance()->get_application_allocator() ) );

	if ( cule_Environment::is_not_empty() ) {
		cule_Environment::instance()->increase_instance_counter();
	} else {
		encodebuba::encodebuba_Environment::deinitialize();
		al_std::al_std_Environment::deinitialize();
		jmsf_Environment::deinitialize();
		return typeing::False;
	}

	return typeing::Boolean::create( cule_Environment::instance()->is_ok() );
}

// static
typeing::Boolean cule_Environment::deinitialize() {
	if ( cule_Environment::is_empty() ) return typeing::True;

	cule_Environment::instance()->decrease_instance_counter();

	if ( cule_Environment::instance()->no_valid_instances() ) {
		cule_Environment::destroy_instance();
		encodebuba::encodebuba_Environment::deinitialize();
		al_std::al_std_Environment::deinitialize();
		jmsf_Environment::deinitialize();
	}

	return cule_Environment::is_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//cule_Environment::~cule_Environment() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//int cule_Environment::run_all_tests() const {
//	int result = 0;

//#if !defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
//		result = cule_main_console();

//#else
//		result = cule_main_visual_studio();

//#endif

//	return result;
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
////// static
////const cule_Environment *cule_Environment::instance() noexcept {
////	static cule_Environment environment_instance;
////	return &environment_instance;
////}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//void cule_Environment::initialize_status_text_messages()
//{}

//int cule_Environment::initialize_environment() {
//	realizing::realization_cule_Allocators::create_instance( _application_allocator );

//	{
//		pointing::Shared< to_libs::system::System_time > system_time =
//			pointing::Shared< to_libs::system::System_time >::create(
//				cule_Allocators::instance()->get_reference_counters_allocator(),
//				memorying::Constructor< to_libs::system::System_time, to_libs::system::System_time >::construct(
//					cule_Allocators::instance()->_get_subsystem_allocator() ) );

//		Test_stop_watch::set_instance(
//			realizing::realization_Test_stop_watch::create(
//				cule_Allocators::instance()->_get_subsystem_allocator(),
//				system_time ) );
//	}

//	return 0;
//}

//void cule_Environment::terminate_environment() noexcept {
//	Test_stop_watch::destroy_instance();
//	cule_Allocators::destroy_instance();
//}

//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//cule_Environment::~cule_Environment() noexcept {
//	terminate_mixin_environment();
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//cule_Environment::cule_Environment( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept
//	:
//		mixin_Environment(),
//		Singleton(),
//		_application_allocator( application_allocator )
//{
//	initialize_mixin_environment();
//}

//// static
//void cule_Environment::create_instance( const memorying::Womp< memorying::Allocator > &application_allocator ) {
//	jmsf_Should_never_be_empty( application_allocator );

//	set_instance( memorying::Constructor< cule_Environment, cule_Environment >::construct( application_allocator, application_allocator ) );
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//cule_Environment::cule_Environment( const cule_Environment &another ) noexcept // another
//	:
//		mixin_Environment( another ),
//		Singleton( another )
//{
//}

//const cule_Environment &cule_Environment::operator =( const cule_Environment &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

//// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace cule
} // namespace jmsf
