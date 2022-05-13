#pragma once


namespace jmsf {
namespace validating {
namespace basing {


// Seinsei: system or framework inability (network connection lost, out of memory, resource is locked, etc.)
// One has to wait or use another resource
// It's is common to have these exceptions throw from time to time.
class exception_Inability;


} // namespace basing
} // namespace validating
} // namespace jmsf
