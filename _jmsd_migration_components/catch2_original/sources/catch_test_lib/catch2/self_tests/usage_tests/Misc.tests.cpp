/*
 *  Created by Phil on 29/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"

#ifdef __clang__
#   pragma clang diagnostic ignored "-Wc++98-compat"
#   pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif


#include <iostream>
#include <cerrno>
#include <limits>
#include <sstream>
#include <array>

namespace { namespace MiscTests {

#ifndef MISC_TEST_HELPERS_INCLUDED // Don't compile this more than once per TU
#define MISC_TEST_HELPERS_INCLUDED

inline const char* makeString( bool makeNull ) {
    return makeNull ? nullptr : "valid string";
}
inline bool testCheckedIf( bool flag )  {
    CATCH_CHECKED_IF( flag )
        return true;
    else
        return false;
}
inline bool testCheckedElse( bool flag ) {
    CATCH_CHECKED_ELSE( flag )
        return false;

    return true;
}

inline unsigned int Factorial( unsigned int number )  {
    return number > 1 ? Factorial(number-1)*number : 1;
}

static int f() {
    return 1;
}

inline void manuallyRegisteredTestFunction() {
    CATCH_SUCCEED( "was called" );
}

struct AutoTestReg {
    AutoTestReg() {
        CATCH_REGISTER_TEST_CASE( manuallyRegisteredTestFunction, "ManuallyRegistered" );
    }
};

CATCH_INTERNAL_START_WARNINGS_SUPPRESSION
CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS
static AutoTestReg autoTestReg;
CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION

template<typename T>
struct Foo {
    size_t size() { return 0; }
};

template<typename T, size_t S>
struct Bar {
    size_t size() { return S; }
};
#endif

CATCH_TEST_CASE( "random CATCH_SECTION tests", "[.][sections][failing]" ) {
    int a = 1;
    int b = 2;

    CATCH_SECTION( "doesn't equal" ) {
        CATCH_REQUIRE( a != b );
        CATCH_REQUIRE( b != a );
    }

    CATCH_SECTION( "not equal" ) {
        CATCH_REQUIRE( a != b);
    }
}

CATCH_TEST_CASE( "nested CATCH_SECTION tests", "[.][sections][failing]" ) {
    int a = 1;
    int b = 2;

    CATCH_SECTION( "doesn't equal" ) {
        CATCH_REQUIRE( a != b );
        CATCH_REQUIRE( b != a );

        CATCH_SECTION( "not equal" ) {
            CATCH_REQUIRE( a != b);
        }
    }
}

CATCH_TEST_CASE( "more nested CATCH_SECTION tests", "[sections][failing][.]" ) {
    int a = 1;
    int b = 2;

    CATCH_SECTION( "doesn't equal" ) {
        CATCH_SECTION( "equal" ) {
            CATCH_REQUIRE( a == b );
        }

        CATCH_SECTION( "not equal" ) {
            CATCH_REQUIRE( a != b );
        }
        CATCH_SECTION( "less than" ) {
            CATCH_REQUIRE( a < b );
        }
    }
}

CATCH_TEST_CASE( "even more nested CATCH_SECTION tests", "[sections]" ) {
    CATCH_SECTION( "c" ) {
        CATCH_SECTION( "d (leaf)" ) {
            CATCH_SUCCEED(); // avoid failing due to no tests
        }

        CATCH_SECTION( "e (leaf)" ) {
            CATCH_SUCCEED(); // avoid failing due to no tests
        }
    }

    CATCH_SECTION( "f (leaf)" ) {
        CATCH_SUCCEED(); // avoid failing due to no tests
    }
}

CATCH_TEST_CASE( "looped CATCH_SECTION tests", "[.][failing][sections]" ) {
    int a = 1;

    for( int b = 0; b < 10; ++b ) {
        CATCH_DYNAMIC_SECTION( "b is currently: " << b ) {
            CATCH_CHECK( b > a );
        }
    }
}

CATCH_TEST_CASE( "looped tests", "[.][failing]" ) {
    static const int fib[]  = { 1, 1, 2, 3, 5, 8, 13, 21 };

    for( std::size_t i=0; i < sizeof(fib)/sizeof(int); ++i ) {
        CATCH_INFO( "Testing if fib[" << i << "] (" << fib[i] << ") is even" );
        CATCH_CHECK( ( fib[i] % 2 ) == 0 );
    }
}

CATCH_TEST_CASE( "Sends stuff to stdout and stderr", "[.]" ) {
    std::cout << "A string sent directly to stdout" << std::endl;
    std::cerr << "A string sent directly to stderr" << std::endl;
    std::clog << "A string sent to stderr via clog" << std::endl;
}

CATCH_TEST_CASE( "null strings" ) {
    CATCH_REQUIRE( makeString( false ) != static_cast<char*>(nullptr));
    CATCH_REQUIRE( makeString( true ) == static_cast<char*>(nullptr));
}

CATCH_TEST_CASE( "checkedIf" ) {
    CATCH_REQUIRE( testCheckedIf( true ) );
}

CATCH_TEST_CASE( "checkedIf, failing", "[failing][.]" ) {
    CATCH_REQUIRE( testCheckedIf( false ) );
}

CATCH_TEST_CASE( "checkedElse" ) {
    CATCH_REQUIRE( testCheckedElse( true ) );
}

CATCH_TEST_CASE( "checkedElse, failing", "[failing][.]" ) {
    CATCH_REQUIRE( testCheckedElse( false ) );
}

CATCH_TEST_CASE( "xmlentitycheck" ) {
    CATCH_SECTION( "embedded xml: <test>it should be possible to embed xml characters, such as <, \" or &, or even whole <xml>documents</xml> within an attribute</test>" ) {
        CATCH_SUCCEED(); // We need this here to stop it failing due to no tests
    }
    CATCH_SECTION( "encoded chars: these should all be encoded: &&&\"\"\"<<<&\"<<&\"" ) {
        CATCH_SUCCEED(); // We need this here to stop it failing due to no tests
    }
}

CATCH_TEST_CASE( "send a single char to CATCH_INFO", "[failing][.]" ) {
    CATCH_INFO(3);
    CATCH_REQUIRE(false);
}

CATCH_TEST_CASE( "atomic if", "[failing][0]") {
    std::size_t x = 0;

    if( x )
        CATCH_REQUIRE(x > 0);
    else
        CATCH_REQUIRE(x == 0);
}


CATCH_TEST_CASE( "Factorials are computed", "[factorial]" ) {
  CATCH_REQUIRE( Factorial(0) == 1 );
  CATCH_REQUIRE( Factorial(1) == 1 );
  CATCH_REQUIRE( Factorial(2) == 2 );
  CATCH_REQUIRE( Factorial(3) == 6 );
  CATCH_REQUIRE( Factorial(10) == 3628800 );
}

CATCH_TEST_CASE( "An empty test with no assertions", "[empty]" ) {}

CATCH_TEST_CASE( "Nice descriptive name", "[tag1][tag2][tag3][.]" ) {
    CATCH_WARN( "This one ran" );
}
CATCH_TEST_CASE( "first tag", "[tag1]" ) {}
CATCH_TEST_CASE( "second tag", "[tag2]" ) {}

//
//CATCH_TEST_CASE( "spawn a new process", "[.]" )
//{
//    // !TBD Work in progress
//    char line[200];
//    FILE* output = popen("./CatchSelfTest ./failing/matchers/StartsWith", "r");
//    while ( fgets(line, 199, output) )
//        std::cout << line;
//}

CATCH_TEST_CASE( "vectors can be sized and resized", "[vector]" ) {

    std::vector<int> v( 5 );

    CATCH_REQUIRE( v.size() == 5 );
    CATCH_REQUIRE( v.capacity() >= 5 );

    CATCH_SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        CATCH_REQUIRE( v.size() == 10 );
        CATCH_REQUIRE( v.capacity() >= 10 );
    }
    CATCH_SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        CATCH_REQUIRE( v.size() == 0 );
        CATCH_REQUIRE( v.capacity() >= 5 );

        CATCH_SECTION( "We can use the 'swap trick' to reset the capacity" ) {
            std::vector<int> empty;
            empty.swap( v );

            CATCH_REQUIRE( v.capacity() == 0 );
        }
    }
    CATCH_SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );

        CATCH_REQUIRE( v.size() == 5 );
        CATCH_REQUIRE( v.capacity() >= 10 );
    }
    CATCH_SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        CATCH_REQUIRE( v.size() == 5 );
        CATCH_REQUIRE( v.capacity() >= 5 );
    }
}

CATCH_TEMPLATE_TEST_CASE( "TemplateTest: vectors can be sized and resized", "[vector][template]", int, float, std::string, (std::tuple<int,float>) ) {

    std::vector<TestType> v( 5 );

    CATCH_REQUIRE( v.size() == 5 );
    CATCH_REQUIRE( v.capacity() >= 5 );

    CATCH_SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        CATCH_REQUIRE( v.size() == 10 );
        CATCH_REQUIRE( v.capacity() >= 10 );
    }
    CATCH_SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        CATCH_REQUIRE( v.size() == 0 );
        CATCH_REQUIRE( v.capacity() >= 5 );

        CATCH_SECTION( "We can use the 'swap trick' to reset the capacity" ) {
            std::vector<TestType> empty;
            empty.swap( v );

            CATCH_REQUIRE( v.capacity() == 0 );
        }
    }
    CATCH_SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );

        CATCH_REQUIRE( v.size() == 5 );
        CATCH_REQUIRE( v.capacity() >= 10 );
    }
    CATCH_SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        CATCH_REQUIRE( v.size() == 5 );
        CATCH_REQUIRE( v.capacity() >= 5 );
    }
}

CATCH_TEMPLATE_TEST_CASE_SIG("TemplateTestSig: vectors can be sized and resized", "[vector][template][nttp]", ((typename TestType, int V), TestType, V), (int,5), (float,4), (std::string,15), ((std::tuple<int, float>), 6)) {

    std::vector<TestType> v(V);

    CATCH_REQUIRE(v.size() == V);
    CATCH_REQUIRE(v.capacity() >= V);

    CATCH_SECTION("resizing bigger changes size and capacity") {
        v.resize(2 * V);

        CATCH_REQUIRE(v.size() == 2 * V);
        CATCH_REQUIRE(v.capacity() >= 2 * V);
    }
    CATCH_SECTION("resizing smaller changes size but not capacity") {
        v.resize(0);

        CATCH_REQUIRE(v.size() == 0);
        CATCH_REQUIRE(v.capacity() >= V);

        CATCH_SECTION("We can use the 'swap trick' to reset the capacity") {
            std::vector<TestType> empty;
            empty.swap(v);

            CATCH_REQUIRE(v.capacity() == 0);
        }
    }
    CATCH_SECTION("reserving bigger changes capacity but not size") {
        v.reserve(2 * V);

        CATCH_REQUIRE(v.size() == V);
        CATCH_REQUIRE(v.capacity() >= 2 * V);
    }
    CATCH_SECTION("reserving smaller does not change size or capacity") {
        v.reserve(0);

        CATCH_REQUIRE(v.size() == V);
        CATCH_REQUIRE(v.capacity() >= V);
    }
}

CATCH_TEMPLATE_PRODUCT_TEST_CASE("A Template product test case", "[template][product]", (std::vector, Foo), (int, float)) {
    TestType x;
    CATCH_REQUIRE(x.size() == 0);
}

CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG("A Template product test case with array signature", "[template][product][nttp]", ((typename T, size_t S), T, S), (std::array, Bar), ((int, 9), (float, 42))) {
    TestType x;
    CATCH_REQUIRE(x.size() > 0);
}

CATCH_TEMPLATE_PRODUCT_TEST_CASE("Product with differing arities", "[template][product]", std::tuple, (int, (int, double), (int, double, float))) {
    CATCH_REQUIRE(std::tuple_size<TestType>::value >= 1);
}

using MyTypes = std::tuple<int, char, float>;
CATCH_TEMPLATE_LIST_TEST_CASE("Template test case with test types specified inside std::tuple", "[template][list]", MyTypes)
{
    CATCH_REQUIRE(sizeof(TestType) > 0);
}

struct NonDefaultConstructibleType {
    NonDefaultConstructibleType() = delete;
};

using MyNonDefaultConstructibleTypes = std::tuple<NonDefaultConstructibleType, float>;
CATCH_TEMPLATE_LIST_TEST_CASE("Template test case with test types specified inside non-default-constructible std::tuple", "[template][list]", MyNonDefaultConstructibleTypes)
{
    CATCH_REQUIRE(sizeof(TestType) > 0);
}

struct NonCopyableAndNonMovableType {
    NonCopyableAndNonMovableType() = default;

    NonCopyableAndNonMovableType(NonCopyableAndNonMovableType const &) = delete;
    NonCopyableAndNonMovableType(NonCopyableAndNonMovableType &&) = delete;
    auto operator=(NonCopyableAndNonMovableType const &) -> NonCopyableAndNonMovableType & = delete;
    auto operator=(NonCopyableAndNonMovableType &&) -> NonCopyableAndNonMovableType & = delete;
};

using NonCopyableAndNonMovableTypes = std::tuple<NonCopyableAndNonMovableType, float>;
CATCH_TEMPLATE_LIST_TEST_CASE("Template test case with test types specified inside non-copyable and non-movable std::tuple", "[template][list]", NonCopyableAndNonMovableTypes)
{
    CATCH_REQUIRE(sizeof(TestType) > 0);
}

// https://github.com/philsquared/Catch/issues/166
CATCH_TEST_CASE("A couple of nested sections followed by a failure", "[failing][.]") {
    CATCH_SECTION("Outer")
        CATCH_SECTION("Inner")
            CATCH_SUCCEED("that's not flying - that's failing in style");

    CATCH_FAIL("to infinity and beyond");
}

CATCH_TEST_CASE("not allowed", "[!throws]") {
    // This test case should not be included if you run with -e on the command line
    CATCH_SUCCEED();
}

//CATCH_TEST_CASE( "Is big endian" ) {
//    CATCH_CHECK( Catch::Detail::Endianness::which() == Catch::Detail::Endianness::Little );
//}

CATCH_TEST_CASE( "Tabs and newlines show in output", "[.][whitespace][failing]" ) {

    // Based on issue #242
    std::string s1 = "if ($b == 10) {\n\t\t$a\t= 20;\n}";
    std::string s2 = "if ($b == 10) {\n\t$a = 20;\n}\n";
    CATCH_CHECK( s1 == s2 );
}


#ifdef CATCH_CONFIG_WCHAR
CATCH_TEST_CASE( "toString on const wchar_t const pointer returns the string contents", "[toString]" ) {
        const wchar_t * const s = L"wide load";
        std::string result = ::Catch::Detail::stringify( s );
        CATCH_CHECK( result == "\"wide load\"" );
}

CATCH_TEST_CASE( "toString on const wchar_t pointer returns the string contents", "[toString]" ) {
        const wchar_t * s = L"wide load";
        std::string result = ::Catch::Detail::stringify( s );
        CATCH_CHECK( result == "\"wide load\"" );
}

CATCH_TEST_CASE( "toString on wchar_t const pointer returns the string contents", "[toString]" ) {
        auto const s = const_cast<wchar_t*>( L"wide load" );
        std::string result = ::Catch::Detail::stringify( s );
        CATCH_CHECK( result == "\"wide load\"" );
}

CATCH_TEST_CASE( "toString on wchar_t returns the string contents", "[toString]" ) {
        auto s = const_cast<wchar_t*>( L"wide load" );
        std::string result = ::Catch::Detail::stringify( s );
        CATCH_CHECK( result == "\"wide load\"" );
}
#endif

CATCH_TEST_CASE( "long long" ) {
    long long l = std::numeric_limits<long long>::max();

    CATCH_REQUIRE( l == std::numeric_limits<long long>::max() );
}

CATCH_TEST_CASE( "This test 'should' fail but doesn't", "[.][failing][!shouldfail]" ) {
    CATCH_SUCCEED( "oops!" );
}

CATCH_TEST_CASE( "# A test name that starts with a #" ) {
    CATCH_SUCCEED( "yay" );
}

CATCH_TEST_CASE( "#835 -- errno should not be touched by Catch", "[.][failing][!shouldfail]" ) {
    errno = 1;
    CATCH_CHECK(f() == 0);
    CATCH_REQUIRE(errno == 1); // Check that f() doesn't touch errno.
}

CATCH_TEST_CASE( "#961 -- Dynamically created sections should all be reported", "[.]" ) {
    for (char i = '0'; i < '5'; ++i) {
        CATCH_SECTION(std::string("Looped section ") + i) {
            CATCH_SUCCEED( "Everything is OK" );
        }
    }
}

CATCH_TEST_CASE( "#1175 - Hidden Test", "[.]" ) {
  // Just for checking that hidden test is not listed by default
  CATCH_SUCCEED();
}

}} // namespace MiscTests
