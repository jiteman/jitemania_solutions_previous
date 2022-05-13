#include "catch_outlier_classification.hpp"


namespace Catch {
namespace Benchmark {


int OutlierClassification::total() const {
	return low_severe + low_mild + high_mild + high_severe;
}


} // namespace Benchmark
} // namespace Catch
