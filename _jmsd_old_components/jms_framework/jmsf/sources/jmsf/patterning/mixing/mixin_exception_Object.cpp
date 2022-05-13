#include "mixin_exception_Object.h"


#include "jmsf/patterning/mixing/excepting/exception_exception_Object.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/texting/Ansii_allocating_assistor.h"
#include "jmsf/texting/Ansii_text.h"
#include "jmsf/texting/String_literal.h"
#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/File_and_line.h"

//#include "jmsf/memorying/temporary_Allocator.h"
//#include "jmsf/memorying/Wamp.inl"


namespace jmsf {
namespace patterning {
namespace mixing {


typeing::Boolean mixin_exception_Object::is_null() const noexcept {
	return typeing::False;
}

typeing::Boolean mixin_exception_Object::is_exception() const noexcept {
	return typeing::True;
}

void mixin_exception_Object::throw_if_exception() const {
	memorying::Womp< texting::Ansii_allocating_assistor > allocating_assistor =
		jmsf_Allocators::instance()->get_ansii_allocating_assistor();

	throw
		exceptions::exception_exception_Object(
			texting::Aaa_sl(
				jmsf_Allocators::instance()->get_ansii_allocating_assistor(),
				JMSF_SL( "mixin_exception_Object::throw_if_exception() - undefined class" ) ),
			JMSF_FILE_AND_LINE );
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_exception_Object::~mixin_exception_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_exception_Object::mixin_exception_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace patterning
} // namespace jmsf
