#include "mixin_null_Object.h"


//#include "jmsf/memorying/temporary_Allocator.h"

#include "jmsf/typeing/Boolean.h"


namespace jmsf {
namespace patterning {
namespace mixing {


typeing::Boolean mixin_null_Object::is_null() const noexcept {
	return typeing::True;
}

typeing::Boolean mixin_null_Object::is_exception() const noexcept {
	return typeing::False;
}

void mixin_null_Object::throw_if_exception() const
{}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_null_Object::~mixin_null_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Object::mixin_null_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mixing
} // namespace patterning
} // namespace jmsf
