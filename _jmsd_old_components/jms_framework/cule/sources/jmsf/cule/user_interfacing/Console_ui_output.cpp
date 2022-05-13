#include "Console_ui_output.h"


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


namespace jmsf {
namespace cule {
namespace user_interfaces {


Console_ui_output::~Console_ui_output() noexcept {
}

Console_ui_output::Console_ui_output() {
}

void Console_ui_output::print( const pointing::cShared< texting::Ansii_text > &a_string ) const {
	if ( a_string.is_empty() ) return;

	const pointing::cShared< texting::Native_C_string > native_string =
		cule_Allocators::instance()->get_ansii_allocating_assistor()->create_native_from_ansii_text( a_string );

	::std::cout << native_string->get().operator ->();
}

void Console_ui_output::print( const texting::String_literal &string_literal ) const {
	::std::cout << string_literal.get();
}


} // namespace
}
}
