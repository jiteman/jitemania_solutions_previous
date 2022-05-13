#include "Naturals.hin"


namespace jmsf {
namespace typeing {


const Memory_natural Memory_natural_nil = Memory_natural::GET_NATURALS_NIL();
//const Memory_natural Memory_natural_one = Memory_natural::NATURALS_ONE;
const Memory_natural Memory_natural_one = Memory_natural::GET_NATURALS_ONE();
//const Memory_natural Memory_natural_max = Memory_natural::NATURALS_MAX;
const Memory_natural Memory_natural_max = Memory_natural::GET_NATURALS_MAX();
//const Memory_natural Memory_natural_badmax = Memory_natural::NATURALS_BADMAX;

const File_natural File_natural_nil = File_natural::GET_NATURALS_NIL();
const File_natural File_natural_one = File_natural::GET_NATURALS_ONE();
const File_natural File_natural_max = File_natural::GET_NATURALS_MAX();
//const File_natural File_natural_badmax = File_natural::NATURALS_BADMAX;

const Shortest_natural Shortest_natural_nil = Shortest_natural::GET_NATURALS_NIL();
const Shortest_natural Shortest_natural_one = Shortest_natural::GET_NATURALS_ONE();
const Shortest_natural Shortest_natural_max = Shortest_natural::GET_NATURALS_MAX();
//const Shortest_natural Shortest_natural_badmax = Shortest_natural::NATURALS_BADMAX;

const Shortest_natural_small Shortest_natural_small_nil = Shortest_natural_small::GET_NATURALS_NIL();
const Shortest_natural_small Shortest_natural_small_one = Shortest_natural_small::GET_NATURALS_ONE();
const Shortest_natural_small Shortest_natural_small_max = Shortest_natural_small::GET_NATURALS_MAX();
//const Shortest_natural_small Shortest_natural_small_badmax = Shortest_natural_small::NATURALS_BADMAX;

const Short_natural Short_natural_nil = Short_natural::GET_NATURALS_NIL();
const Short_natural Short_natural_one = Short_natural::GET_NATURALS_ONE();
const Short_natural Short_natural_max = Short_natural::GET_NATURALS_MAX();
//const Short_natural Short_natural_badmax = Short_natural::NATURALS_BADMAX;

const Short_natural_small Short_natural_small_nil = Short_natural_small::GET_NATURALS_NIL();
const Short_natural_small Short_natural_small_one = Short_natural_small::GET_NATURALS_ONE();
const Short_natural_small Short_natural_small_max = Short_natural_small::GET_NATURALS_MAX();
//const Short_natural_small Short_natural_small_badmax = Short_natural_small::NATURALS_BADMAX;

const Natural Natural_nil = Natural::GET_NATURALS_NIL();
const Natural Natural_one = Natural::GET_NATURALS_ONE();
const Natural Natural_max = Natural::GET_NATURALS_MAX();
//const Natural Natural_badmax = Natural::NATURALS_BADMAX;

const Natural_small Natural_small_nil = Natural_small::GET_NATURALS_NIL();
const Natural_small Natural_small_one = Natural_small::GET_NATURALS_ONE();
const Natural_small Natural_small_max = Natural_small::GET_NATURALS_MAX();
//const Natural_small Natural_small_badmax = Natural_small::NATURALS_BADMAX;

const Long_natural Long_natural_nil = Long_natural::GET_NATURALS_NIL();
const Long_natural Long_natural_one = Long_natural::GET_NATURALS_ONE();
const Long_natural Long_natural_max = Long_natural::GET_NATURALS_MAX();
//const Long_natural Long_natural_badmax = Long_natural::NATURALS_BADMAX;

const Long_natural_small Long_natural_small_nil = Long_natural_small::GET_NATURALS_NIL();
const Long_natural_small Long_natural_small_one = Long_natural_small::GET_NATURALS_ONE();
const Long_natural_small Long_natural_small_max = Long_natural_small::GET_NATURALS_MAX();
//const Long_natural_small Long_natural_small_badmax = Long_natural_small::NATURALS_BADMAX;


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


Memory_natural create_address_from_pointer( const void *const memory_pointer ) noexcept {
	return typeing::Memory_natural::create( reinterpret_cast< typeing::memory_natural_value_type >( memory_pointer ) );
}


} // namespace typeing
} // namespace jmsf
