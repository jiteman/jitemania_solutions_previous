#pragma once
// Outlier information

#include "catch_lib.h"


namespace Catch {
    namespace Benchmark {
        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE OutlierClassification {
            int samples_seen = 0;
            int low_severe = 0;     // more than 3 times IQR below Q1
            int low_mild = 0;       // 1.5 to 3 times IQR below Q1
            int high_mild = 0;      // 1.5 to 3 times IQR above Q3
            int high_severe = 0;    // more than 3 times IQR above Q3

            int total() const;
        };
    } // namespace Benchmark
} // namespace Catch
