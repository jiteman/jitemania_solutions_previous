#include "Debug_ui_output.h"


#include "jmsf/cule/cule_Allocators.h"

#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/Native_C_string.h"
#include "jmsf/texting/String_literal.h"

#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"

#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Amp.hin"

#include "jmsf/validating/macroses_Should.h"

#include "jmsd/platform_support/platform_detection/compiler_detection.h"


#if defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#include "jmsf/ms_windows/ms_windows_Environment.h"

#endif // #if defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )


namespace jmsf {
namespace cule {
namespace user_interfaces {


Debug_ui_output::~Debug_ui_output() noexcept {
}

Debug_ui_output::Debug_ui_output() {
}

void Debug_ui_output::print( const pointing::cShared< texting::Ansii_text > &a_string ) const {
	if ( a_string.is_empty() ) return;

	const pointing::cShared< texting::Native_C_string > native_string =
		cule_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_string );

#if defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	static ms_windows::ms_windows_Environment ms_windows_environment;
	static const ms_windows::visual_studioing::Debug_output &debug_output = ms_windows_environment.get_debug_output();
	debug_output.show( native_string->get().operator ->() );
//	::OutputDebugStringA( c_string.get() );

#endif // #if defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )

//	memorying::Destructor< typeing::internals::platform_character >::destruct( c_string );
}

void Debug_ui_output::print( const texting::String_literal &string_literal ) const {
	jmsf_Should_never_be_empty_native_pointer( string_literal.get() );

#if defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	static ms_windows::ms_windows_Environment ms_windows_environment;
	static const ms_windows::visual_studioing::Debug_output &debug_output = ms_windows_environment.get_debug_output();
	debug_output.show( string_literal.get() );
//	::OutputDebugStringA( c_string.get() );

#endif // #if defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
}


} // namespace
}
}
