// X02-DisabledMacros.cpp
// Test that CATCH_CONFIG_DISABLE turns off TEST_CASE autoregistration
// and expressions in assertion macros are not run.

#include <catch2/catch.hpp>


// CATCH_CONFIG_DISABLE also prevents reporter registration.
// We need to manually register at least one reporter for our tests
static Catch::ReporterRegistrar<Catch::ConsoleReporter> temporary( "console" );

#include <iostream>

struct foo {
    foo(){
        CATCH_REQUIRE_NOTHROW( print() );
    }
    void print() const {
        std::cout << "This should not happen\n";
    }
};

// Construct foo, but `foo::print` should not be run
foo f;

// This test should not be run, because it won't be registered
CATCH_TEST_CASE( "Disabled Macros" ) {
    std::cout << "This should not happen\n";
    CATCH_FAIL();
}
