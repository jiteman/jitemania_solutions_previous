// X11-DisableStringification.cpp
// Test that stringification of original expression can be disabled
// this is a workaround for VS 2017 issue with Raw String literal
// and preprocessor token pasting. In other words, hopefully this test
// will be deleted soon :-)

#include <catch2/catch.hpp>

struct Hidden {};

bool operator==(Hidden, Hidden);
bool operator==(Hidden, Hidden) { return true; }

CATCH_TEST_CASE("DisableStringification") {
    CATCH_REQUIRE( Hidden{} == Hidden{} );
}
