/*
 *  Created by Phil on 1/10/2015.
 *  Copyright 2015 Two Blue Cubes Ltd
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#include "catch2/internal/catch_suppress_warnings.h"
#include "catch2/internal/catch_test_case_tracker.h"

#include "catch2/catch.hpp"

using namespace Catch;

namespace {
Catch::TestCaseTracking::NameAndLocation makeNAL( std::string const& name ) {
    return Catch::TestCaseTracking::NameAndLocation( name, Catch::SourceLineInfo("",0) );
}
}

CATCH_TEST_CASE( "Tracker" ) {

    TrackerContext ctx;
    ctx.startRun();
    ctx.startCycle();


    ITracker& testCase = SectionTracker::acquire( ctx, makeNAL( "Testcase" ) );
    CATCH_REQUIRE( testCase.isOpen() );

    ITracker& s1 = SectionTracker::acquire( ctx, makeNAL( "S1" ) );
    CATCH_REQUIRE( s1.isOpen() );

    CATCH_SECTION( "successfully close one section" ) {
        s1.close();
        CATCH_REQUIRE( s1.isSuccessfullyCompleted() );
        CATCH_REQUIRE( testCase.isComplete() == false );

        testCase.close();
        CATCH_REQUIRE( ctx.completedCycle() );
        CATCH_REQUIRE( testCase.isSuccessfullyCompleted() );
    }

    CATCH_SECTION( "fail one section" ) {
        s1.fail();
        CATCH_REQUIRE( s1.isComplete() );
        CATCH_REQUIRE( s1.isSuccessfullyCompleted() == false );
        CATCH_REQUIRE( testCase.isComplete() == false );

        testCase.close();
        CATCH_REQUIRE( ctx.completedCycle() );
        CATCH_REQUIRE( testCase.isSuccessfullyCompleted() == false );

        CATCH_SECTION( "re-enter after failed section" ) {
            ctx.startCycle();
            ITracker& testCase2 = SectionTracker::acquire( ctx, makeNAL( "Testcase" ) );
            CATCH_REQUIRE( testCase2.isOpen() );

            ITracker& s1b = SectionTracker::acquire( ctx, makeNAL( "S1" ) );
            CATCH_REQUIRE( s1b.isOpen() == false );

            testCase2.close();
            CATCH_REQUIRE( ctx.completedCycle() );
            CATCH_REQUIRE( testCase.isComplete() );
            CATCH_REQUIRE( testCase.isSuccessfullyCompleted() );
        }
        CATCH_SECTION( "re-enter after failed section and find next section" ) {
            ctx.startCycle();
            ITracker& testCase2 = SectionTracker::acquire( ctx, makeNAL( "Testcase" ) );
            CATCH_REQUIRE( testCase2.isOpen() );

            ITracker& s1b = SectionTracker::acquire( ctx, makeNAL( "S1" ) );
            CATCH_REQUIRE( s1b.isOpen() == false );

            ITracker& s2 = SectionTracker::acquire( ctx, makeNAL( "S2" ) );
            CATCH_REQUIRE( s2.isOpen() );

            s2.close();
            CATCH_REQUIRE( ctx.completedCycle() );

            testCase2.close();
            CATCH_REQUIRE( testCase.isComplete() );
            CATCH_REQUIRE( testCase.isSuccessfullyCompleted() );
        }
    }

    CATCH_SECTION( "successfully close one section, then find another" ) {
        s1.close();

        ITracker& s2 = SectionTracker::acquire( ctx, makeNAL( "S2" ) );
        CATCH_REQUIRE( s2.isOpen() == false );

        testCase.close();
        CATCH_REQUIRE( testCase.isComplete() == false );

        CATCH_SECTION( "Re-enter - skips S1 and enters S2" ) {
            ctx.startCycle();
            ITracker& testCase2 = SectionTracker::acquire( ctx, makeNAL( "Testcase" ) );
            CATCH_REQUIRE( testCase2.isOpen() );

            ITracker& s1b = SectionTracker::acquire( ctx, makeNAL( "S1" ) );
            CATCH_REQUIRE( s1b.isOpen() == false );

            ITracker& s2b = SectionTracker::acquire( ctx, makeNAL( "S2" ) );
            CATCH_REQUIRE( s2b.isOpen() );

            CATCH_REQUIRE( ctx.completedCycle() == false );

            CATCH_SECTION ("Successfully close S2") {
                s2b.close();
                CATCH_REQUIRE( ctx.completedCycle() );

                CATCH_REQUIRE( s2b.isSuccessfullyCompleted() );
                CATCH_REQUIRE( testCase2.isComplete() == false );

                testCase2.close();
                CATCH_REQUIRE( testCase2.isSuccessfullyCompleted() );
            }
            CATCH_SECTION ("fail S2") {
                s2b.fail();
                CATCH_REQUIRE( ctx.completedCycle() );

                CATCH_REQUIRE( s2b.isComplete() );
                CATCH_REQUIRE( s2b.isSuccessfullyCompleted() == false );

                testCase2.close();
                CATCH_REQUIRE( testCase2.isSuccessfullyCompleted() == false );

                // Need a final cycle
                ctx.startCycle();
                ITracker& testCase3 = SectionTracker::acquire( ctx, makeNAL( "Testcase" ) );
                CATCH_REQUIRE( testCase3.isOpen() );

                ITracker& s1c = SectionTracker::acquire( ctx, makeNAL( "S1" ) );
                CATCH_REQUIRE( s1c.isOpen() == false );

                ITracker& s2c = SectionTracker::acquire( ctx, makeNAL( "S2" ) );
                CATCH_REQUIRE( s2c.isOpen() == false );

                testCase3.close();
                CATCH_REQUIRE( testCase3.isSuccessfullyCompleted() );
            }
        }
    }

    CATCH_SECTION( "open a nested section" ) {
        ITracker& s2 = SectionTracker::acquire( ctx, makeNAL( "S2" ) );
        CATCH_REQUIRE( s2.isOpen() );

        s2.close();
        CATCH_REQUIRE( s2.isComplete() );
        CATCH_REQUIRE( s1.isComplete() == false );

        s1.close();
        CATCH_REQUIRE( s1.isComplete() );
        CATCH_REQUIRE( testCase.isComplete() == false );

        testCase.close();
        CATCH_REQUIRE( testCase.isComplete() );
    }
}

static bool previouslyRun = false;
static bool previouslyRunNested = false;

CATCH_TEST_CASE( "#1394", "[.][approvals][tracker]" ) {
    // -- Don't re-run after specified section is done
    CATCH_REQUIRE(previouslyRun == false);

    CATCH_SECTION( "RunSection" ) {
        previouslyRun = true;
    }
    CATCH_SECTION( "SkipSection" ) {
        // cause an error if this section is called because it shouldn't be
        CATCH_REQUIRE(1 == 0);
    }
}

CATCH_TEST_CASE( "#1394 nested", "[.][approvals][tracker]" ) {
    CATCH_REQUIRE(previouslyRunNested == false);

    CATCH_SECTION( "NestedRunSection" ) {
        CATCH_SECTION( "s1" ) {
            previouslyRunNested = true;
        }
    }
    CATCH_SECTION( "NestedSkipSection" ) {
        // cause an error if this section is called because it shouldn't be
        CATCH_REQUIRE(1 == 0);
    }
}

// Selecting a "not last" section inside a test case via -c "section" would
// previously only run the first subsection, instead of running all of them.
// This allows us to check that `"#1670 regression check" -c A` leads to
// 2 successful assertions.
CATCH_TEST_CASE("#1670 regression check", "[.approvals][tracker]") {
    CATCH_SECTION("A") {
        CATCH_SECTION("1") CATCH_SUCCEED();
        CATCH_SECTION("2") CATCH_SUCCEED();
    }
    CATCH_SECTION("B") {
        CATCH_SECTION("1") CATCH_SUCCEED();
        CATCH_SECTION("2") CATCH_SUCCEED();
    }
}
