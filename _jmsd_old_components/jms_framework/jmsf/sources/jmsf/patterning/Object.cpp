#include "Object.h"


//#include "jmsf/typeing/Boolean.h"
//#include "jmsf/memorying/temporary_Allocator.h"
//#include "jmsf/memorying/Destructor.hin"


namespace jmsf {
namespace patterning {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// typeing::Boolean Object::isReal() const noexcept {
// 	return isNull().not().and( isException().not() );
// }
//
// void Object::_deleteThisIfReal() const noexcept {
// 	if ( isReal() ) {
// 		memorying::temporary_Allocator allocator;
// 		memorying::Destruct( *this, allocator );
// 	}
// }

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Object::~Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace patterning
} // namespace jmsf
