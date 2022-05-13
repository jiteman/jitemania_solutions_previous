/*
 *  Created by Phil on 29/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"

namespace { namespace BDDTests {

#ifndef BDD_TEST_HELPERS_INCLUDED // Don't compile this more than once per TU
#define BDD_TEST_HELPERS_INCLUDED

    inline bool itDoesThis() { return true; }

    inline bool itDoesThat() { return true; }

    namespace {

// a trivial fixture example to support SCENARIO_METHOD tests
        struct Fixture {
            Fixture()
                    : d_counter(0) {
            }

            int counter() {
                return d_counter++;
            }

            int d_counter;
        };

    }
#endif

    CATCH_SCENARIO("Do that thing with the thing", "[Tags]") {
        CATCH_GIVEN("This stuff exists") {
            // make stuff exist
            CATCH_AND_GIVEN("And some assumption") {
                // Validate assumption
                CATCH_WHEN("I do this") {
                    // do this
                    CATCH_THEN("it should do this") {
                        CATCH_REQUIRE(itDoesThis());
                        CATCH_AND_THEN("do that")
                        CATCH_REQUIRE(itDoesThat());
                    }
                }
            }
        }
    }

    CATCH_SCENARIO("Vector resizing affects size and capacity", "[vector][bdd][size][capacity]") {
        CATCH_GIVEN("an empty vector") {
            std::vector<int> v;
            CATCH_REQUIRE(v.size() == 0);

            CATCH_WHEN("it is made larger") {
                v.resize(10);
                CATCH_THEN("the size and capacity go up") {
                    CATCH_REQUIRE(v.size() == 10);
                    CATCH_REQUIRE(v.capacity() >= 10);

                    CATCH_AND_WHEN("it is made smaller again") {
                        v.resize(5);
                        CATCH_THEN("the size goes down but the capacity stays the same") {
                            CATCH_REQUIRE(v.size() == 5);
                            CATCH_REQUIRE(v.capacity() >= 10);
                        }
                    }
                }
            }

            CATCH_WHEN("we reserve more space") {
                v.reserve(10);
                CATCH_THEN("The capacity is increased but the size remains the same") {
                    CATCH_REQUIRE(v.capacity() >= 10);
                    CATCH_REQUIRE(v.size() == 0);
                }
            }
        }
    }

    CATCH_SCENARIO("This is a really long scenario name to see how the list command deals with wrapping",
             "[very long tags][lots][long][tags][verbose]"
                     "[one very long tag name that should cause line wrapping writing out using the list command]"
                     "[anotherReallyLongTagNameButThisOneHasNoObviousWrapPointsSoShouldSplitWithinAWordUsingADashCharacter]") {
		CATCH_GIVEN("A section name that is so long that it cannot fit in a single console width")
		CATCH_WHEN( "The test headers are printed as part of the normal running of the scenario")
		CATCH_THEN( "The, deliberately very long and overly verbose (you see what I did there?) section names must wrap, along with an indent")
		CATCH_SUCCEED( "boo!");
    }

    CATCH_SCENARIO_METHOD(Fixture,
                    "BDD tests requiring Fixtures to provide commonly-accessed data or methods",
                    "[bdd][fixtures]") {
        const int before(counter());
        CATCH_GIVEN("No operations precede me") {
            CATCH_REQUIRE(before == 0);
            CATCH_WHEN("We get the count") {
                const int after(counter());
                CATCH_THEN("Subsequently values are higher") {
                    CATCH_REQUIRE(after > before);
                }
            }
        }
    }

}} // namespace BDDtests
