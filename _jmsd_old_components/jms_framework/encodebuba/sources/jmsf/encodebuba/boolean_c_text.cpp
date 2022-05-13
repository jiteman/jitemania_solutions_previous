#include "boolean_c_text.h"


namespace jmsf {
namespace encodebuba {


const char *boolean_to_c_text( const bool a_boolean ) noexcept {
	return a_boolean ? "true" : "false";
}


} // namespace encodebuba
} // namespace jmsf
