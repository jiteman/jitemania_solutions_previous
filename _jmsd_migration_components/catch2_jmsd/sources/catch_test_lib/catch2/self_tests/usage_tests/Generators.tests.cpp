#include "catch2/catch.hpp"

#include <cstring>


// Generators and sections can be nested freely
CATCH_TEST_CASE("Generators -- simple", "[generators]") {
    auto i = GENERATE(1, 2, 3);
    CATCH_SECTION("one") {
        auto j = GENERATE(values({ -3, -2, -1 }));
        CATCH_REQUIRE(j < i);
    }

    CATCH_SECTION("two") {
        // You can also explicitly set type for generators via Catch::Generators::as
        auto str = GENERATE(as<std::string>{}, "a", "bb", "ccc");
        CATCH_REQUIRE(4u * i > str.size());
    }
}

// You can create a cartesian-product of generators by creating multiple ones
CATCH_TEST_CASE("3x3x3 ints", "[generators]") {
    auto x = GENERATE(1, 2, 3);
    auto y = GENERATE(4, 5, 6);
    auto z = GENERATE(7, 8, 9);
    // These assertions will be run 27 times (3x3x3)
    CATCH_CHECK(x < y);
    CATCH_CHECK(y < z);
    CATCH_REQUIRE(x < z);
}

// You can also create data tuples
CATCH_TEST_CASE("tables", "[generators]") {
    // Note that this will not compile with libstdc++ older than libstdc++6
    // See https://stackoverflow.com/questions/12436586/tuple-vector-and-initializer-list
    // for possible workarounds
    //    auto data = GENERATE(table<char const*, int>({
    //        {"first", 5},
    //        {"second", 6},
    //        {"third", 5},
    //        {"etc...", 6}
    //    }));

    // Workaround for the libstdc++ bug mentioned above
    using tuple_type = std::tuple<char const*, int>;
    auto data = GENERATE(table<char const*, int>({
        tuple_type{"first", 5},
        tuple_type{"second", 6},
        tuple_type{"third", 5},
        tuple_type{"etc...", 6}
    }));

    CATCH_REQUIRE(strlen(std::get<0>(data)) == static_cast<size_t>(std::get<1>(data)));
}


#ifdef __cpp_structured_bindings

// Structured bindings make the table utility much nicer to use
CATCH_TEST_CASE( "strlen2", "[approvals][generators]" ) {
    auto [test_input, expected] = GENERATE( table<std::string, size_t>({
            {"one", 3},
            {"two", 3},
            {"three", 5},
            {"four", 4}
        }));

    CATCH_REQUIRE( test_input.size() == expected );
}
#endif


// An alternate way of doing data tables without structured bindings
struct Data { std::string str; size_t len; };

CATCH_TEST_CASE( "strlen3", "[generators]" ) {
    auto data = GENERATE( values<Data>({
            {"one", 3},
            {"two", 3},
            {"three", 5},
            {"four", 4}
        }));

    CATCH_REQUIRE( data.str.size() == data.len );
}



#ifdef __cpp_structured_bindings

// Based on example from https://docs.cucumber.io/gherkin/reference/#scenario-outline
// (thanks to https://github.com/catchorg/Catch2/issues/850#issuecomment-399504851)

// Note that GIVEN, WHEN, and THEN now forward onto DYNAMIC_CATCH_SECTION instead of CATCH_SECTION.
// DYNAMIC_CATCH_SECTION takes its name as a stringstream-style expression, so can be formatted using
// variables in scope - such as the generated variables here. This reads quite nicely in the
// test name output (the full scenario description).

static auto eatCucumbers( int start, int eat ) -> int { return start-eat; }

CATCH_SCENARIO("Eating cucumbers", "[generators][approvals]") {

    auto [start, eat, left] = GENERATE( table<int,int,int> ({
            { 12, 5, 7 },
            { 20, 5, 15 }
        }));

    CATCH_GIVEN( "there are " << start << " cucumbers" )
    CATCH_WHEN( "I eat " << eat << " cucumbers" )
    CATCH_THEN( "I should have " << left << " cucumbers" ) {
        CATCH_REQUIRE( eatCucumbers( start, eat ) == left );
    }
}
#endif

// There are also some generic generator manipulators
CATCH_TEST_CASE("Generators -- adapters", "[generators][generic]") {
    // TODO: This won't work yet, introduce GENERATE_VAR?
    //auto numbers = Catch::Generators::values({ 1, 2, 3, 4, 5, 6 });
    CATCH_SECTION("Filtering by predicate") {
        CATCH_SECTION("Basic usage") {
            // This filters out all odd (false) numbers, giving [2, 4, 6]
            auto i = GENERATE(filter([] (int val) { return val % 2 == 0; }, values({ 1, 2, 3, 4, 5, 6 })));
            CATCH_REQUIRE(i % 2 == 0);
        }
        CATCH_SECTION("Throws if there are no matching values") {
            using namespace Catch::Generators;
            CATCH_REQUIRE_THROWS_AS(filter([] (int) {return false; }, value(1)), Catch::GeneratorException);
        }
    }
    CATCH_SECTION("Shortening a range") {
        // This takes the first 3 elements from the values, giving back [1, 2, 3]
        auto i = GENERATE(take(3, values({ 1, 2, 3, 4, 5, 6 })));
        CATCH_REQUIRE(i < 4);
    }
    CATCH_SECTION("Transforming elements") {
        CATCH_SECTION("Same type") {
            // This doubles values [1, 2, 3] into [2, 4, 6]
            auto i = GENERATE(map([] (int val) { return val * 2; }, values({ 1, 2, 3 })));
            CATCH_REQUIRE(i % 2 == 0);
        }
        CATCH_SECTION("Different type") {
            // This takes a generator that returns ints and maps them into strings
            auto i = GENERATE(map<std::string>([] (int val) { return std::to_string(val); }, values({ 1, 2, 3 })));
            CATCH_REQUIRE(i.size() == 1);
        }
        CATCH_SECTION("Different deduced type") {
            // This takes a generator that returns ints and maps them into strings
            auto i = GENERATE(map([] (int val) { return std::to_string(val); }, values({ 1, 2, 3 })));
            CATCH_REQUIRE(i.size() == 1);
        }
    }
    CATCH_SECTION("Repeating a generator") {
        // This will return values [1, 2, 3, 1, 2, 3]
        auto j = GENERATE(repeat(2, values({ 1, 2, 3 })));
        CATCH_REQUIRE(j > 0);
    }
    CATCH_SECTION("Chunking a generator into sized pieces") {
        CATCH_SECTION("Number of elements in source is divisible by chunk size") {
            auto chunk2 = GENERATE(chunk(2, values({ 1, 1, 2, 2, 3, 3 })));
            CATCH_REQUIRE(chunk2.size() == 2);
            CATCH_REQUIRE(chunk2.front() == chunk2.back());
        }
        CATCH_SECTION("Number of elements in source is not divisible by chunk size") {
            auto chunk2 = GENERATE(chunk(2, values({ 1, 1, 2, 2, 3 })));
            CATCH_REQUIRE(chunk2.size() == 2);
            CATCH_REQUIRE(chunk2.front() == chunk2.back());
            CATCH_REQUIRE(chunk2.front() < 3);
        }
        CATCH_SECTION("Chunk size of zero") {
            auto chunk2 = GENERATE(take(3, chunk(0, value(1))));
            CATCH_REQUIRE(chunk2.size() == 0);
        }
        CATCH_SECTION("Throws on too small generators") {
            using namespace Catch::Generators;
            CATCH_REQUIRE_THROWS_AS(chunk(2, value(1)), Catch::GeneratorException);
        }
    }
}

// Note that because of the non-reproducibility of distributions,
// anything involving the random generators cannot be part of approvals
CATCH_TEST_CASE("Random generator", "[generators][approvals]") {
    CATCH_SECTION("Infer int from integral arguments") {
        auto val = GENERATE(take(4, random(0, 1)));
        CATCH_STATIC_REQUIRE(std::is_same<decltype(val), int>::value);
        CATCH_REQUIRE(0 <= val);
        CATCH_REQUIRE(val <= 1);
    }
    CATCH_SECTION("Infer double from double arguments") {
        auto val = GENERATE(take(4, random(0., 1.)));
        CATCH_STATIC_REQUIRE(std::is_same<decltype(val), double>::value);
        CATCH_REQUIRE(0. <= val);
        CATCH_REQUIRE(val < 1);
    }
}


CATCH_TEST_CASE("Nested generators and captured variables", "[generators]") {
    // Workaround for old libstdc++
    using record = std::tuple<int, int>;
    // Set up 3 ranges to generate numbers from
    auto extent = GENERATE(table<int, int>({
        record{3, 7},
        record{-5, -3},
        record{90, 100}
    }));

    auto from = std::get<0>(extent);
    auto to = std::get<1>(extent);

    auto values = GENERATE_COPY(range(from, to));
    CATCH_REQUIRE(values > -6);
}

namespace {
    size_t call_count = 0;
    size_t test_count = 0;
    std::vector<int> make_data() {
        return { 1, 3, 5, 7, 9, 11 };
    }
    std::vector<int> make_data_counted() {
        ++call_count;
        return make_data();
    }
}

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

CATCH_TEST_CASE("Copy and then generate a range", "[generators]") {
    CATCH_SECTION("from var and iterators") {
        static auto data = make_data();

        // It is important to notice that a generator is only initialized
        // **once** per run. What this means is that modifying data will not
        // modify the underlying generator.
        auto elem = GENERATE_REF(from_range(data.begin(), data.end()));
        CATCH_REQUIRE(elem % 2 == 1);
    }
    CATCH_SECTION("From a temporary container") {
        auto elem = GENERATE(from_range(make_data_counted()));
        ++test_count;
        CATCH_REQUIRE(elem % 2 == 1);
    }
    CATCH_SECTION("Final validation") {
        CATCH_REQUIRE(call_count == 1);
        CATCH_REQUIRE(make_data().size() == test_count);
    }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif
