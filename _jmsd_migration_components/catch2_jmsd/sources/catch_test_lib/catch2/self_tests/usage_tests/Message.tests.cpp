/*
 *  Created by Phil on 09/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"
#include <iostream>

CATCH_TEST_CASE( "CATCH_INFO and CATCH_WARN do not abort tests", "[messages][.]" ) {
    CATCH_INFO( "this is a " << "message" );    // This should output the message if a failure occurs
    CATCH_WARN( "this is a " << "warning" );    // This should always output the message but then continue
}

CATCH_TEST_CASE( "#1455 - CATCH_INFO and CATCH_WARN can start with a linebreak", "[messages][.]" ) {
    // Previously these would be hidden from the console reporter output,
    // because it would fail at properly reflowing the text
    CATCH_INFO( "\nThis info message starts with a linebreak" );
    CATCH_WARN( "\nThis warning message starts with a linebreak" );
}

CATCH_TEST_CASE( "SUCCEED counts as a test pass", "[messages]" ) {
    CATCH_SUCCEED( "this is a " << "success" );
}

CATCH_TEST_CASE( "CATCH_INFO gets logged on failure", "[failing][messages][.]" ) {
    CATCH_INFO( "this message should be logged" );
    CATCH_INFO( "so should this" );
    int a = 2;
    CATCH_REQUIRE( a == 1 );
}

CATCH_TEST_CASE( "CATCH_INFO gets logged on failure, even if captured before successful assertions", "[failing][messages][.]" ) {
    CATCH_INFO( "this message may be logged later" );
    int a = 2;
    CATCH_CHECK( a == 2 );

    CATCH_INFO( "this message should be logged" );

    CATCH_CHECK( a == 1 );

    CATCH_INFO( "and this, but later" );

    CATCH_CHECK( a == 0 );

    CATCH_INFO( "but not this" );

    CATCH_CHECK( a == 2 );
}

CATCH_TEST_CASE( "CATCH_FAIL aborts the test", "[failing][messages][.]" ) {
    CATCH_FAIL( "This is a " << "failure" );    // This should output the message and abort
    CATCH_WARN( "We should never see this");
}

CATCH_TEST_CASE( "CATCH_FAIL_CATCH_CHECK does not abort the test", "[failing][messages][.]" ) {
    CATCH_FAIL_CHECK( "This is a " << "failure" );    // This should output the message then continue
    CATCH_WARN( "This message appears in the output");
}

CATCH_TEST_CASE( "CATCH_FAIL does not require an argument", "[failing][messages][.]" ) {
    CATCH_FAIL();
}

CATCH_TEST_CASE( "SUCCEED does not require an argument", "[messages][.]" ) {
   CATCH_SUCCEED();
}

CATCH_TEST_CASE( "Output from all sections is reported", "[failing][messages][.]" ) {
    CATCH_SECTION( "one" ) {
        CATCH_FAIL( "Message from section one" );
    }

    CATCH_SECTION( "two" ) {
        CATCH_FAIL( "Message from section two" );
    }
}

CATCH_TEST_CASE( "Standard output from all sections is reported", "[messages][.]" ) {
    CATCH_SECTION( "one" ) {
        std::cout << "Message from section one" << std::endl;
    }

    CATCH_SECTION( "two" ) {
        std::cout << "Message from section two" << std::endl;
    }
}

CATCH_TEST_CASE( "Standard error is reported and redirected", "[messages][.][approvals]" ) {
    CATCH_SECTION( "std::cerr" ) {
        std::cerr << "Write to std::cerr" << std::endl;
    }
    CATCH_SECTION( "std::clog" ) {
        std::clog << "Write to std::clog" << std::endl;
    }
    CATCH_SECTION( "Interleaved writes to cerr and clog" ) {
        std::cerr << "Inter";
        std::clog << "leaved";
        std::cerr << ' ';
        std::clog << "writes";
        std::cerr << " to error";
        std::clog << " streams" << std::endl;
    }
}

CATCH_TEST_CASE( "CATCH_INFO is reset for each loop", "[messages][failing][.]" ) {
    for( int i=0; i<100; i++ )
    {
        CATCH_INFO( "current counter " << i );
        CATCH_CAPTURE( i );
        CATCH_REQUIRE( i < 10 );
    }
}

CATCH_TEST_CASE( "The NO_CATCH_FAIL macro reports a failure but does not fail the test", "[messages]" ) {
    CATCH_CHECK_NOFAIL( 1 == 2 );
}

CATCH_TEST_CASE( "just info", "[info][isolated info][messages]" ) {
    CATCH_INFO( "this should never be seen" );
}
CATCH_TEST_CASE( "just failure", "[fail][isolated info][.][messages]" ) {
    CATCH_FAIL( "Previous info should not be seen" );
}


CATCH_TEST_CASE( "sends information to CATCH_INFO", "[.][failing]" ) {
    CATCH_INFO( "hi" );
    int i = 7;
    CATCH_CAPTURE( i );
    CATCH_REQUIRE( false );
}

CATCH_TEST_CASE( "Pointers can be converted to strings", "[messages][.][approvals]" ) {
    int p;
    CATCH_WARN( "actual address of p: " << &p );
    CATCH_WARN( "toString(p): " << ::Catch::Detail::stringify( &p ) );
}

template <typename T>
static void unscoped_info( T msg ) {
    CATCH_UNSCOPED_INFO( msg );
}

CATCH_TEST_CASE( "just unscoped info", "[unscoped][info]" ) {
    unscoped_info( "this should NOT be seen" );
    unscoped_info( "this also should NOT be seen" );
}

CATCH_TEST_CASE( "just failure after unscoped info", "[failing][.][unscoped][info]" ) {
    CATCH_FAIL( "previous unscoped info SHOULD not be seen" );
}

CATCH_TEST_CASE( "print unscoped info if passing unscoped info is printed", "[unscoped][info]" ) {
    unscoped_info( "this MAY be seen IF info is printed for passing assertions" );
    CATCH_REQUIRE( true );
}

CATCH_TEST_CASE( "prints unscoped info on failure", "[failing][.][unscoped][info]" ) {
    unscoped_info( "this SHOULD be seen" );
    unscoped_info( "this SHOULD also be seen" );
    CATCH_REQUIRE( false );
    unscoped_info( "but this should NOT be seen" );
}

CATCH_TEST_CASE( "not prints unscoped info from previous failures", "[failing][.][unscoped][info]" ) {
    unscoped_info( "this MAY be seen only for the FIRST assertion IF info is printed for passing assertions" );
    CATCH_REQUIRE( true );
    unscoped_info( "this MAY be seen only for the SECOND assertion IF info is printed for passing assertions" );
    CATCH_REQUIRE( true );
    unscoped_info( "this SHOULD be seen" );
    CATCH_REQUIRE( false );
}

CATCH_TEST_CASE( "prints unscoped info only for the first assertion", "[failing][.][unscoped][info]" ) {
    unscoped_info( "this SHOULD be seen only ONCE" );
    CATCH_CHECK( false );
    CATCH_CHECK( true );
    unscoped_info( "this MAY also be seen only ONCE IF info is printed for passing assertions" );
    CATCH_CHECK( true );
    CATCH_CHECK( true );
}

CATCH_TEST_CASE( "stacks unscoped info in loops", "[failing][.][unscoped][info]" ) {
    CATCH_UNSCOPED_INFO("Count 1 to 3...");
    for (int i = 1; i <= 3; i++) {
        unscoped_info(i);
    }
    CATCH_CHECK( false );

    CATCH_UNSCOPED_INFO("Count 4 to 6...");
    for (int i = 4; i <= 6; i++) {
        unscoped_info(i);
    }
    CATCH_CHECK( false );
}

CATCH_TEST_CASE( "mix info, unscoped info and warning", "[unscoped][info]" ) {
    CATCH_INFO("info");
    unscoped_info("unscoped info");
    CATCH_WARN("and warn may mix");
    CATCH_WARN("they are not cleared after warnings");
}

CATCH_TEST_CASE( "CATCH_CAPTURE can deal with complex expressions", "[messages][capture]" ) {
    int a = 1;
    int b = 2;
    int c = 3;
    CATCH_CAPTURE( a, b, c, a + b, a+b, c > b, a == 1 );
    CATCH_SUCCEED();
}

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value" // In (1, 2), the "1" is unused ...
#endif
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value" // All the comma operators are side-effect free
#endif
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4709) // comma in indexing operator
#pragma warning( disable: 5061 ) // the use of a comma operator as a subscript expression has been deprecated
#endif

template <typename T1, typename T2>
struct helper_1436 {
    helper_1436(T1 t1_, T2 t2_):
        t1{ t1_ },
        t2{ t2_ }
    {}
    T1 t1;
    T2 t2;
};

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, helper_1436<T1, T2> const& helper) {
    out << "{ " << helper.t1 << ", " << helper.t2 << " }";
    return out;
}

CATCH_TEST_CASE("CATCH_CAPTURE can deal with complex expressions involving commas", "[messages][capture]") {
    CATCH_CAPTURE(std::vector<int>{1, 2, 3}[0, 1, 2],
            std::vector<int>{1, 2, 3}[(0, 1)],
            std::vector<int>{1, 2, 3}[0]);
    CATCH_CAPTURE((helper_1436<int, int>{12, -12}),
            (helper_1436<int, int>(-12, 12)));
    CATCH_CAPTURE( (1, 2), (2, 3) );
    CATCH_SUCCEED();
}

CATCH_TEST_CASE("CATCH_CAPTURE parses string and character constants", "[messages][capture]") {
    CATCH_CAPTURE(("comma, in string", "escaped, \", "), "single quote in string,',", "some escapes, \\,\\\\");
    CATCH_CAPTURE("some, ), unmatched, } prenheses {[<");
    CATCH_CAPTURE('"', '\'', ',', '}', ')', '(', '{');
    CATCH_SUCCEED();
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif
