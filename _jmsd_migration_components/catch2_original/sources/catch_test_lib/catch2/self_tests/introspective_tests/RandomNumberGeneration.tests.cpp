/*
 *  Created by Martin on 06/10/2019.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"

#include "catch2/internal/catch_random_number_generator.h"

CATCH_TEST_CASE("Our PCG implementation provides expected results for known seeds", "[rng]") {
    Catch::SimplePcg32 rng;
    CATCH_SECTION("Default seeded") {
        CATCH_REQUIRE(rng() == 0xfcdb943b);
        CATCH_REQUIRE(rng() == 0x6f55b921);
        CATCH_REQUIRE(rng() == 0x4c17a916);
        CATCH_REQUIRE(rng() == 0x71eae25f);
        CATCH_REQUIRE(rng() == 0x6ce7909c);
    }
    CATCH_SECTION("Specific seed") {
        rng.seed(0xabcd1234);
        CATCH_REQUIRE(rng() == 0x57c08495);
        CATCH_REQUIRE(rng() == 0x33c956ac);
        CATCH_REQUIRE(rng() == 0x2206fd76);
        CATCH_REQUIRE(rng() == 0x3501a35b);
        CATCH_REQUIRE(rng() == 0xfdffb30f);

        // Also check repeated output after reseeding
        rng.seed(0xabcd1234);
        CATCH_REQUIRE(rng() == 0x57c08495);
        CATCH_REQUIRE(rng() == 0x33c956ac);
        CATCH_REQUIRE(rng() == 0x2206fd76);
        CATCH_REQUIRE(rng() == 0x3501a35b);
        CATCH_REQUIRE(rng() == 0xfdffb30f);
    }
}

CATCH_TEST_CASE("Comparison ops", "[rng]") {
    using Catch::SimplePcg32;
    CATCH_REQUIRE(SimplePcg32{} == SimplePcg32{});
    CATCH_REQUIRE(SimplePcg32{ 0 } != SimplePcg32{});
    CATCH_REQUIRE_FALSE(SimplePcg32{ 1 } == SimplePcg32{ 2 });
    CATCH_REQUIRE_FALSE(SimplePcg32{ 1 } != SimplePcg32{ 1 });
}
