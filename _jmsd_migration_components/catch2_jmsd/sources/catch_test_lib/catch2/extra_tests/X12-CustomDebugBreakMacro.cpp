// X12-CustomDebugBreakMacro.cpp
// Test that user-defined `CATCH_BREAK_INTO_DEBUGGER` is respected and used.

#include <iostream>

void custom_debug_break() {
    std::cerr << "Pretty please, break into debugger\n";
}

#define CATCH_BREAK_INTO_DEBUGGER() custom_debug_break()

#include <catch2/catch.hpp>

CATCH_TEST_CASE("Failing test that breaks into debugger", "[macros]") {
    CATCH_REQUIRE(1 == 2);
}
