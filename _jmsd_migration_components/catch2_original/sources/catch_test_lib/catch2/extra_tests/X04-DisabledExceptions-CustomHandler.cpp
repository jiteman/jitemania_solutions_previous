#define CATCH_CONFIG_DISABLE_EXCEPTIONS_CUSTOM_HANDLER

#include <catch2/catch.hpp>

namespace Catch {
     void throw_exception(std::exception const& e) {
        Catch::cerr() << "====== CUSTOM HANDLER ====== run terminates because an exception was thrown.\n"
                      << "The message was: " << e.what() << '\n';
        // Avoid abort and other exceptional exits -- there is no way
        // to tell CMake that abort is the desired outcome of a test.
        exit(1);
    }
}

CATCH_TEST_CASE("Tests that run (CustomHadler)") {
    // All of these should be run and be reported
    CATCH_CHECK(1 == 2);
    CATCH_CHECK(1 == 1);
    CATCH_CHECK(1 != 3);
    CATCH_CHECK(1 == 4);
}



CATCH_TEST_CASE("Tests that abort (CustomHadler)") {
    CATCH_REQUIRE(1 == 1);
    CATCH_REQUIRE(1 != 2);
    CATCH_REQUIRE(1 == 3);
    // We should not get here, because the test above aborts
    CATCH_REQUIRE(1 != 4);
}
