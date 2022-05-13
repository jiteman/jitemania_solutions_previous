#include "al_std_Environment.h"


#include "realizing/realization_al_std_Environment.h"

#include "jmsf/encodebuba/encodebuba_Environment.h"
#include "jmsf/encodebuba/nativing/native_Singleton.hin"
#include "jmsf/encodebuba/nativing/native_Scoped.hin"
#include "jmsf/encodebuba/nativing/native_Nonlinked.hin"

#include <iostream>


namespace jmsf {
namespace al_std {


// static
bool al_std_Environment::initialize() {
	if ( al_std_Environment::is_not_empty() ) {
		al_std::al_std_Environment::instance()->increase_instance_counter();
		return true;
	}

	if ( !encodebuba::encodebuba_Environment::initialize() ) return false;

	set_instance(
		new realizing::realization_al_std_Environment );

	if ( al_std_Environment::is_not_empty() ) {
		al_std_Environment::instance()->increase_instance_counter();
	} else {
		encodebuba::encodebuba_Environment::deinitialize();
		return false;
	}

	return al_std_Environment::instance()->is_ok();
}

// static
bool al_std_Environment::deinitialize() {
	if ( al_std_Environment::is_empty() ) return true;

	al_std_Environment::instance()->decrease_instance_counter();

	if ( al_std_Environment::instance()->no_valid_instances() ) {
		al_std_Environment::destroy_instance();
		encodebuba::encodebuba_Environment::deinitialize();
	}

	return al_std_Environment::is_empty();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//al_std_Environment::~al_std_Environment() noexcept
//{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


//// static
//bool al_std_Environment::initialize() {
//	return instance()->is_ok();
//}

//// static
//bool al_std_Environment::is_empty() noexcept {
//	return static_al_std_environment.is_empty();
//}

//// static
//bool al_std_Environment::is_not_empty() noexcept {
//	return !is_empty();
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//// static
//const al_std_Environment *al_std_Environment::instance() noexcept {
//	if ( static_al_std_environment.is_not_empty() ) return static_al_std_environment.operator ->();

//	static_al_std_environment =
//		encodebuba::nativing::native_Scoped< al_std_Environment >::create(
//			new al_std_Environment );

//	return static_al_std_environment.operator ->();
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//void al_std_Environment::initialize_status_text_messages() {

//}

//int al_std_Environment::initialize_environment() {
//	::std::cout << ::std::endl << "al_std_Environment::initialize_environment()" << ::std::endl;
//	return 0;
//}

//void al_std_Environment::terminate_environment() noexcept {
//	::std::cout << ::std::endl << "al_std_Environment::terminate_environment() - deletion" << ::std::endl;
//	static_al_std_environment = encodebuba::nativing::native_Scoped< al_std_Environment >();
//	::std::cout << ::std::endl << "al_std_Environment::terminate_environment() - after deletion" << ::std::endl;
//}

//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//al_std_Environment::~al_std_Environment() noexcept {
//	terminate_mixin_environment();
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//al_std_Environment::al_std_Environment() noexcept
//	:
//		mixin_Environment()
//{
//	initialize_mixin_environment();
//}

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//al_std_Environment::al_std_Environment( const al_std_Environment &another ) noexcept // another
//	:
//		mixin_Environment( another )
//{}

//const al_std_Environment &al_std_Environment::operator =( const al_std_Environment &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

//// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//// static
//encodebuba::nativing::native_Scoped< al_std_Environment > al_std_Environment::static_al_std_environment;

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace al_std
} // namespace jmsf
