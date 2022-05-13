// X20-BenchmarkingMacros.cpp
// Test that the benchmarking support macros compile properly with the single header

#include <catch2/catch.hpp>

namespace {
std::uint64_t factorial(std::uint64_t number) {
    if (number < 2) {
        return 1;
    }
    return number * factorial(number - 1);
}
}

CATCH_TEST_CASE("Benchmark factorial", "[benchmark]") {
    CATCH_CHECK(factorial(0) == 1);
    // some more asserts..
    CATCH_CHECK(factorial(10) == 3628800);

    CATCH_BENCHMARK("factorial 10") {
        return factorial(10);
    };

    CATCH_CHECK(factorial(14) == 87178291200ull);
    CATCH_BENCHMARK("factorial 14") {
        return factorial(14);
    };
}

CATCH_TEST_CASE("Benchmark containers (BenchmarkingMacros)", "[.][benchmark]") {
    static const int size = 100;

    std::vector<int> v;
    std::map<int, int> m;

    CATCH_SECTION("without generator") {
        CATCH_BENCHMARK("Load up a vector") {
            v = std::vector<int>();
            for (int i = 0; i < size; ++i)
                v.push_back(i);
        };
        CATCH_REQUIRE(v.size() == size);

        // test optimizer control
        CATCH_BENCHMARK("Add up a vector's content") {
            uint64_t add = 0;
            for (int i = 0; i < size; ++i)
                add += v[i];
            return add;
        };

        CATCH_BENCHMARK("Load up a map") {
            m = std::map<int, int>();
            for (int i = 0; i < size; ++i)
                m.insert({ i, i + 1 });
        };
        CATCH_REQUIRE(m.size() == size);

        CATCH_BENCHMARK("Reserved vector") {
            v = std::vector<int>();
            v.reserve(size);
            for (int i = 0; i < size; ++i)
                v.push_back(i);
        };
        CATCH_REQUIRE(v.size() == size);

        CATCH_BENCHMARK("Resized vector") {
            v = std::vector<int>();
            v.resize(size);
            for (int i = 0; i < size; ++i)
                v[i] = i;
        };
        CATCH_REQUIRE(v.size() == size);

        int array[size];
        CATCH_BENCHMARK("A fixed size array that should require no allocations") {
            for (int i = 0; i < size; ++i)
                array[i] = i;
        };
        int sum = 0;
        for (int i = 0; i < size; ++i)
            sum += array[i];
        CATCH_REQUIRE(sum > size);

        CATCH_SECTION("XYZ") {

            CATCH_BENCHMARK_ADVANCED("Load up vector with chronometer")(Catch::Benchmark::Chronometer meter) {
                std::vector<int> k;
                meter.measure([&](int idx) {
                    k = std::vector<int>();
                    for (int i = 0; i < size; ++i)
                        k.push_back(idx);
                });
                CATCH_REQUIRE(k.size() == size);
            };

            int runs = 0;
            CATCH_BENCHMARK("Fill vector indexed", benchmarkIndex) {
                v = std::vector<int>();
                v.resize(size);
                for (int i = 0; i < size; ++i)
                    v[i] = benchmarkIndex;
                runs = benchmarkIndex;
            };

            for (size_t i = 0; i < v.size(); ++i) {
                CATCH_REQUIRE(v[i] == runs);
            }
        }
    }

    CATCH_SECTION("with generator") {
        auto generated = GENERATE(range(0, 10));
        CATCH_BENCHMARK("Fill vector generated") {
            v = std::vector<int>();
            v.resize(size);
            for (int i = 0; i < size; ++i)
                v[i] = generated;
        };
        for (size_t i = 0; i < v.size(); ++i) {
            CATCH_REQUIRE(v[i] == generated);
        }
    }
}
