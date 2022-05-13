/*
 *  Created by Phil on 09/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef __clang__
#pragma clang diagnostic ignored "-Wpadded"
#endif

#ifdef _MSC_VER
#pragma warning (disable : 4702) // Disable unreachable code warning for the last test
                                 // that is triggered when compiling as Win32|Release
#endif

#include "catch2/catch.hpp"

#include <cstdio>
#include <sstream>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE
(
    "Where there is more to the expression after the RHS",
    "[Tricky][failing][.]"
)
{
//    int a = 1, b = 2;
//    CATCH_REQUIRE( a == 2 || b == 2 );
    CATCH_WARN( "Uncomment the code in this test to check that it gives a sensible compiler error" );
}
///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE
(
    "Where the LHS is not a simple value",
    "[Tricky][failing][.]"
)
{
    /*
    int a = 1;
    int b = 2;

    // This only captures part of the expression, but issues a warning about the rest
    CATCH_REQUIRE( a+1 == b-1 );
    */
    CATCH_WARN( "Uncomment the code in this test to check that it gives a sensible compiler error" );
}

struct Opaque
{
    int val;
    bool operator ==( const Opaque& o ) const
    {
        return val == o.val;
    }
};

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE
(
    "A failing expression with a non streamable type is still captured",
    "[Tricky][failing][.]"
)
{

    Opaque o1, o2;
    o1.val = 7;
    o2.val = 8;

    CATCH_CHECK( &o1 == &o2 );
    CATCH_CHECK( o1 == o2 );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE
(
    "string literals of different sizes can be compared",
    "[Tricky][failing][.]"
)
{
    CATCH_REQUIRE( std::string( "first" ) == "second" );

}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE
(
    "An expression with side-effects should only be evaluated once",
    "[Tricky]"
)
{
    int i = 7;

    CATCH_REQUIRE( i++ == 7 );
    CATCH_REQUIRE( i++ == 8 );

}

namespace A {
    struct X
    {
        X() : a(4), b(2), c(7) {}
        X(int v) : a(v), b(2), c(7) {}
        int a;
        int b;
        int c;
    };
}

namespace B {
    struct Y
    {
        Y() : a(4), b(2), c(7) {}
        Y(int v) : a(v), b(2), c(7) {}
        int a;
        int b;
        int c;
    };
}

inline bool operator==(const A::X& lhs, const B::Y& rhs)
{
    return (lhs.a == rhs.a);
}

inline bool operator==(const B::Y& lhs, const A::X& rhs)
{
    return (lhs.a == rhs.a);
}


///////////////////////////////////////////////////////////////////////////////
/* This, currently, does not compile with LLVM
CATCH_TEST_CASE
(
    "Operators at different namespace levels not hijacked by Koenig lookup"
    "[Tricky]"
)
{
    A::X x;
    B::Y y;
    CATCH_REQUIRE( x == y );
}
*/

namespace ObjectWithConversions
{
    struct Object
    {
        operator unsigned int() const {return 0xc0000000;}
    };

    ///////////////////////////////////////////////////////////////////////////////
    CATCH_TEST_CASE
    (
        "Implicit conversions are supported inside assertion macros",
        "[Tricky][approvals]"
    )
    {
        Object o;
        CATCH_REQUIRE(0xc0000000 == o );
    }
}

namespace EnumBitFieldTests
{
    enum Bits : uint32_t {
        bit0 = 0x0001,
        bit1 = 0x0002,
        bit2 = 0x0004,
        bit3 = 0x0008,
        bit1and2 = bit1 | bit2,
        bit30 = 0x40000000,
        bit31 = 0x80000000,
        bit30and31 = bit30 | bit31
    };

    CATCH_TEST_CASE( "Test enum bit values", "[Tricky]" )
    {
        CATCH_REQUIRE( 0xc0000000 == bit30and31 );
    }
}

struct Obj
{
    Obj():prop(&p){}

    int p;
    int* prop;
};

CATCH_TEST_CASE("boolean member", "[Tricky]")
{
    Obj obj;
    CATCH_REQUIRE( obj.prop != nullptr );
}

// Tests for a problem submitted by Ralph McArdell
//
// The static bool value should not need to be defined outside the
// struct it is declared in - but when evaluating it in a deduced
// context it appears to require the extra definition.
// The issue was fixed by adding bool overloads to bypass the
// templates that were there to deduce it.
template <bool B>
struct is_true
{
    static const bool value = B;
};

CATCH_TEST_CASE( "(unimplemented) static bools can be evaluated", "[Tricky]" )
{
    CATCH_SECTION("compare to true")
    {
        CATCH_REQUIRE( is_true<true>::value == true );
        CATCH_REQUIRE( true == is_true<true>::value );
    }
    CATCH_SECTION("compare to false")
    {
        CATCH_REQUIRE( is_true<false>::value == false );
        CATCH_REQUIRE( false == is_true<false>::value );
    }

    CATCH_SECTION("negation")
    {
        CATCH_REQUIRE( !is_true<false>::value );
    }

    CATCH_SECTION("double negation")
    {
        CATCH_REQUIRE( !!is_true<true>::value );
    }

    CATCH_SECTION("direct")
    {
        CATCH_REQUIRE( is_true<true>::value );
        CATCH_REQUIRE_FALSE( is_true<false>::value );
    }
}

// Uncomment these tests to produce an error at test registration time
/*
CATCH_TEST_CASE( "Tests with the same name are not allowed", "[Tricky]" )
{

}
CATCH_TEST_CASE( "Tests with the same name are not allowed", "[Tricky]" )
{

}
*/

struct Boolable
{
    explicit Boolable( bool value ) : m_value( value ) {}

    explicit operator bool() const {
        return m_value;
    }

    bool m_value;
};

CATCH_TEST_CASE( "Objects that evaluated in boolean contexts can be checked", "[Tricky][SafeBool]" )
{
    Boolable True( true );
    Boolable False( false );

    CATCH_CHECK( True );
    CATCH_CHECK( !False );
    CATCH_CHECK_FALSE( False );
}

CATCH_TEST_CASE( "Assertions then sections", "[Tricky]" )
{
    // This was causing a failure due to the way the console reporter was handling
    // the current section

    CATCH_REQUIRE( true );

    CATCH_SECTION( "A section" )
    {
        CATCH_REQUIRE( true );

        CATCH_SECTION( "Another section" )
        {
            CATCH_REQUIRE( true );
        }
        CATCH_SECTION( "Another other section" )
        {
            CATCH_REQUIRE( true );
        }
    }
}

struct Awkward
{
    operator int() const { return 7; }
};

CATCH_TEST_CASE( "non streamable - with conv. op", "[Tricky]" )
{
    Awkward awkward;
    std::string s = ::Catch::Detail::stringify( awkward );
    CATCH_REQUIRE( s == "7" );
}

inline void foo() {}

typedef void (*fooptr_t)();

CATCH_TEST_CASE( "Comparing function pointers", "[Tricky][function pointer]" )
{
    // This was giving a warning in VS2010
    // #179
    fooptr_t a = foo;

    CATCH_REQUIRE( a );
    CATCH_REQUIRE( a == &foo );
}

struct S
{
    void f() {}
};


CATCH_TEST_CASE( "Comparing member function pointers", "[Tricky][member function pointer][approvals]" )
{
    typedef void (S::*MF)();
    MF m = &S::f;

    CATCH_CHECK( m == &S::f );
}

class ClassName {};

CATCH_TEST_CASE( "pointer to class", "[Tricky]" )
{
   ClassName *p = 0;
   CATCH_REQUIRE( p == 0 );
}

#include <memory>

CATCH_TEST_CASE( "null_ptr", "[Tricky]" )
{
    std::unique_ptr<int> ptr;
    CATCH_REQUIRE(ptr.get() == nullptr);
}

CATCH_TEST_CASE( "X/level/0/a", "[Tricky]" )      { CATCH_SUCCEED(""); }
CATCH_TEST_CASE( "X/level/0/b", "[Tricky][fizz]" ){ CATCH_SUCCEED(""); }
CATCH_TEST_CASE( "X/level/1/a", "[Tricky]" )      { CATCH_SUCCEED(""); }
CATCH_TEST_CASE( "X/level/1/b", "[Tricky]" )      { CATCH_SUCCEED(""); }

CATCH_TEST_CASE( "has printf" ) {

    // This can cause problems as, currently, stdout itself is not redirected - only the cout (and cerr) buffer
    printf( "loose text artifact\n" );
}

namespace {
    struct constructor_throws {
        [[noreturn]] constructor_throws() {
            throw 1;
        }
    };
}

CATCH_TEST_CASE("Commas in various macros are allowed") {
    CATCH_REQUIRE_THROWS( std::vector<constructor_throws>{constructor_throws{}, constructor_throws{}} );
    CATCH_CHECK_THROWS( std::vector<constructor_throws>{constructor_throws{}, constructor_throws{}} );
    CATCH_REQUIRE_NOTHROW( std::vector<int>{1, 2, 3} == std::vector<int>{1, 2, 3} );
    CATCH_CHECK_NOTHROW( std::vector<int>{1, 2, 3} == std::vector<int>{1, 2, 3} );

    CATCH_REQUIRE(std::vector<int>{1, 2} == std::vector<int>{1, 2});
    CATCH_CHECK( std::vector<int>{1, 2} == std::vector<int>{1, 2} );
    CATCH_REQUIRE_FALSE(std::vector<int>{1, 2} == std::vector<int>{1, 2, 3});
    CATCH_CHECK_FALSE( std::vector<int>{1, 2} == std::vector<int>{1, 2, 3} );

    CATCH_CHECK_NOFAIL( std::vector<int>{1, 2} == std::vector<int>{1, 2} );
    CATCH_CHECKED_IF( std::vector<int>{1, 2} == std::vector<int>{1, 2} ) {
        CATCH_REQUIRE(true);
    } CATCH_CHECKED_ELSE( std::vector<int>{1, 2} == std::vector<int>{1, 2} ) {
        CATCH_CHECK(true);
    }
}

CATCH_TEST_CASE( "non-copyable objects", "[.][failing]" ) {
    // Thanks to Agustin Bergé (@k-ballo on the cpplang Slack) for raising this
    std::type_info const& ti = typeid(int);
    CATCH_CHECK( ti == typeid(int) );
}

CATCH_TEST_CASE("#1514: stderr/stdout is not captured in tests aborted by an exception", "[output-capture][regression][.]") {
    std::cout << "This would not be caught previously\n" << std::flush;
    std::clog << "Nor would this\n" << std::flush;
    // FAIL aborts the test by throwing a Catch exception
    CATCH_FAIL("1514");
}
