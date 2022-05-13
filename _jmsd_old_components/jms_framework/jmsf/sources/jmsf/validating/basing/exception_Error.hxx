#pragma once


namespace jmsf {
namespace validating {
namespace basing {


// Seinsei: programmer error catch (nill pointer dereferencing, division by zero, etc.)
// One has to change the codebase (make some significant fix, add some significant code).
// No such exceptions throw from correct code.
class exception_Error;


} // namespace basing
} // namespace validating
} // namespace jmsf
