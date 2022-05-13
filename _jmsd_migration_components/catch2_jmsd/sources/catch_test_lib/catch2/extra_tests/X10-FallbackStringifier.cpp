// X10-FallbackStringifier.cpp
// Test that defining fallbackStringifier compiles

#include <string>

// A catch-all stringifier
template <typename T>
std::string fallbackStringifier(T const&) {
    return "{ !!! }";
}

#include <catch2/catch.hpp>

struct foo {
    explicit operator bool() const {
        return true;
    }
};

CATCH_TEST_CASE("aa") {
    CATCH_REQUIRE(foo{});
}
