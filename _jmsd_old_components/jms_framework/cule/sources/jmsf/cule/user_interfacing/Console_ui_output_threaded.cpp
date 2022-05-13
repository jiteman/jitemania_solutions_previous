#include "Console_ui_output_threaded.h"


#include "jmsf/cule/cule_Allocators.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/Native_C_string.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Amp.hin"
#include "jmsf/memorying/Awa_iterator.hin"


#include "jmsf/al_std/stl_hin/iostream_al_std.hin"

#include "jmsf/synchronizing/Event.h"

#include <functional>


namespace jmsf {
namespace cule {
namespace user_interfaces {


void Console_ui_output_threaded::printing_thread() {
	for ( ;; ) {
		if ( !_resume_event->wait() ) return;

		_resume_event->reset();

		if ( !_remote_string->str().empty() ) {
			::std::cout << _remote_string->str();
		}

		_is_ready_event->signal();
	}
}

Console_ui_output_threaded::~Console_ui_output_threaded() noexcept {
	_resume_event->signal_to_cancel();

	if ( _remote_thread->joinable() ) {
		_remote_thread->join();
	}

	if ( !_local_string->str().empty() ) {
		::std::cout << _local_string->str();
	}
}

Console_ui_output_threaded::Console_ui_output_threaded()
	:
		_resume_event( ::std::make_unique< synchronizing::Event >() ),
		_is_ready_event( ::std::make_unique< synchronizing::Event >() ),
		_local_string( ::std::make_unique< ::std::stringstream >() ),
		_remote_string( ::std::make_unique< ::std::stringstream >() )
{
	//_remote_thread = ::std::unique_ptr< ::std::thread >( new ::std::thread( ::std::ref( *this ) ) );
	_remote_thread = ::std::make_unique< ::std::thread >( ::std::bind( &Console_ui_output_threaded::printing_thread, this ) );
	_is_ready_event->signal();
}

void Console_ui_output_threaded::print( const pointing::cShared< texting::Ansii_text > &a_string ) const {
	if ( a_string.is_empty() ) return;

	const pointing::cShared< texting::Native_C_string > native_string =
		cule_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_string );

	*_local_string << native_string->get().operator ->();

	this->switch_buffers_if_ready();
}

void Console_ui_output_threaded::print( const texting::String_literal &string_literal ) const {
	*_local_string << string_literal.get();

	this->switch_buffers_if_ready();
}

void Console_ui_output_threaded::switch_buffers_if_ready() const {
	if ( !_is_ready_event->is_set() ) return;

	_is_ready_event->reset();

	_local_string.swap( _remote_string );

	_local_string->str( ::std::string() );

	_resume_event->signal();
}


} // namespace
}
}
