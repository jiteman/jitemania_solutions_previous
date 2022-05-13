#include "catch2/catch.hpp"

#include <map>

#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)
namespace {
    std::uint64_t Fibonacci(std::uint64_t number) {
        return number < 2 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
    }
}

CATCH_TEST_CASE("Benchmark Fibonacci", "[!benchmark]") {
    CATCH_CHECK(Fibonacci(0) == 1);
    // some more asserts..
    CATCH_CHECK(Fibonacci(5) == 8);
    // some more asserts..

    CATCH_BENCHMARK("Fibonacci 20") {
        return Fibonacci(20);
    };

    CATCH_BENCHMARK("Fibonacci 25") {
        return Fibonacci(25);
    };

    CATCH_BENCHMARK("Fibonacci 30") {
        return Fibonacci(30);
    };

    CATCH_BENCHMARK("Fibonacci 35") {
        return Fibonacci(35);
    };
}

CATCH_TEST_CASE("Benchmark containers", "[!benchmark]") {
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

    CATCH_SECTION("construct and destroy example") {
        CATCH_BENCHMARK_ADVANCED("construct")(Catch::Benchmark::Chronometer meter) {
            std::vector<Catch::Benchmark::storage_for<std::string>> storage(meter.runs());
            meter.measure([&](int i) { storage[i].construct("thing"); });
        };

        CATCH_BENCHMARK_ADVANCED("destroy")(Catch::Benchmark::Chronometer meter) {
            std::vector<Catch::Benchmark::destructable_object<std::string>> storage(meter.runs());
            for(auto&& o : storage)
                o.construct("thing");
            meter.measure([&](int i) { storage[i].destruct(); });
        };
    }
}
#endif // CATCH_CONFIG_ENABLE_BENCHMARKING
