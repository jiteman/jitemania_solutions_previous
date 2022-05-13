#include "catch_chronometer.hpp"


namespace Catch {
namespace Benchmark {


int Chronometer::runs() const {
	return k;
}

Chronometer::Chronometer( Detail::ChronometerConcept &meter, int const k )
	:
		impl( &meter ),
		k( k )
{}


} // namespace Benchmark
} // namespace Catch
