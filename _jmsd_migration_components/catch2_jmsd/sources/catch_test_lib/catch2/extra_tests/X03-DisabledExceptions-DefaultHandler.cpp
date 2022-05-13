#include <catch2/catch.hpp>

CATCH_TEST_CASE("Tests that run (DefaultHadler)") {
    // All of these should be run and be reported
    CATCH_CHECK(1 == 2);
    CATCH_CHECK(1 == 1);
    CATCH_CHECK(1 != 3);
    CATCH_CHECK(1 == 4);
}



CATCH_TEST_CASE("Tests that abort (DefaultHadler)") {
    // Avoid abort and other exceptional exits -- there is no way
    // to tell CMake that abort is the desired outcome of a test.
    std::set_terminate([](){exit(1);});
    CATCH_REQUIRE(1 == 1);
    CATCH_REQUIRE(1 != 2);
    CATCH_REQUIRE(1 == 3);
    // We should not get here, because the test above aborts
    CATCH_REQUIRE(1 != 4);
}
