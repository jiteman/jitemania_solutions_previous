/*
 *  Created by Phil on 08/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wpadded"
// Wdouble-promotion is not supported until 3.8
#   if (__clang_major__ > 3) || (__clang_major__ == 3 && __clang_minor__ > 7)
#       pragma clang diagnostic ignored "-Wdouble-promotion"
#   endif
#endif

#include "catch2/catch.hpp"

#include <string>
#include <limits>
#include <cstdint>

namespace { namespace ConditionTests {

#ifndef CONDITION_TEST_HELPERS_INCLUDED // Don't compile this more than once per TU
#define CONDITION_TEST_HELPERS_INCLUDED

struct TestData {
    int int_seven = 7;
    std::string str_hello = "hello";
    float float_nine_point_one = 9.1f;
    double double_pi = 3.1415926535;
};

struct TestDef {
    TestDef& operator + ( const std::string& ) {
        return *this;
    }
    TestDef& operator[]( const std::string& ) {
        return *this;
    }
};

inline const char* returnsConstNull(){ return nullptr; }
inline char* returnsNull(){ return nullptr; }

#endif

// The "failing" tests all use the CATCH_CHECK macro, which continues if the specific test fails.
// This allows us to see all results, even if an earlier check fails

// Equality tests
CATCH_TEST_CASE( "Equality checks that should succeed" )
{
    TestDef td;
    td + "hello" + "hello";

    TestData data;

    CATCH_REQUIRE( data.int_seven == 7 );
    CATCH_REQUIRE( data.float_nine_point_one == Approx( 9.1f ) );
    CATCH_REQUIRE( data.double_pi == Approx( 3.1415926535 ) );
    CATCH_REQUIRE( data.str_hello == "hello" );
    CATCH_REQUIRE( "hello" == data.str_hello );
    CATCH_REQUIRE( data.str_hello.size() == 5 );

    double x = 1.1 + 0.1 + 0.1;
    CATCH_REQUIRE( x == Approx( 1.3 ) );
}

CATCH_TEST_CASE( "Equality checks that should fail", "[.][failing][!mayfail]" )
{
    TestData data;

    CATCH_CHECK( data.int_seven == 6 );
    CATCH_CHECK( data.int_seven == 8 );
    CATCH_CHECK( data.int_seven == 0 );
    CATCH_CHECK( data.float_nine_point_one == Approx( 9.11f ) );
    CATCH_CHECK( data.float_nine_point_one == Approx( 9.0f ) );
    CATCH_CHECK( data.float_nine_point_one == Approx( 1 ) );
    CATCH_CHECK( data.float_nine_point_one == Approx( 0 ) );
    CATCH_CHECK( data.double_pi == Approx( 3.1415 ) );
    CATCH_CHECK( data.str_hello == "goodbye" );
    CATCH_CHECK( data.str_hello == "hell" );
    CATCH_CHECK( data.str_hello == "hello1" );
    CATCH_CHECK( data.str_hello.size() == 6 );

    double x = 1.1 + 0.1 + 0.1;
    CATCH_CHECK( x == Approx( 1.301 ) );
}

CATCH_TEST_CASE( "Inequality checks that should succeed" )
{
    TestData data;

    CATCH_REQUIRE( data.int_seven != 6 );
    CATCH_REQUIRE( data.int_seven != 8 );
    CATCH_REQUIRE( data.float_nine_point_one != Approx( 9.11f ) );
    CATCH_REQUIRE( data.float_nine_point_one != Approx( 9.0f ) );
    CATCH_REQUIRE( data.float_nine_point_one != Approx( 1 ) );
    CATCH_REQUIRE( data.float_nine_point_one != Approx( 0 ) );
    CATCH_REQUIRE( data.double_pi != Approx( 3.1415 ) );
    CATCH_REQUIRE( data.str_hello != "goodbye" );
    CATCH_REQUIRE( data.str_hello != "hell" );
    CATCH_REQUIRE( data.str_hello != "hello1" );
    CATCH_REQUIRE( data.str_hello.size() != 6 );
}

CATCH_TEST_CASE( "Inequality checks that should fail", "[.][failing][!shouldfail]" )
{
    TestData data;

    CATCH_CHECK( data.int_seven != 7 );
    CATCH_CHECK( data.float_nine_point_one != Approx( 9.1f ) );
    CATCH_CHECK( data.double_pi != Approx( 3.1415926535 ) );
    CATCH_CHECK( data.str_hello != "hello" );
    CATCH_CHECK( data.str_hello.size() != 5 );
}

// Ordering comparison tests
CATCH_TEST_CASE( "Ordering comparison checks that should succeed" )
{
    TestData data;

    CATCH_REQUIRE( data.int_seven < 8 );
    CATCH_REQUIRE( data.int_seven > 6 );
    CATCH_REQUIRE( data.int_seven > 0 );
    CATCH_REQUIRE( data.int_seven > -1 );

    CATCH_REQUIRE( data.int_seven >= 7 );
    CATCH_REQUIRE( data.int_seven >= 6 );
    CATCH_REQUIRE( data.int_seven <= 7 );
    CATCH_REQUIRE( data.int_seven <= 8 );

    CATCH_REQUIRE( data.float_nine_point_one > 9 );
    CATCH_REQUIRE( data.float_nine_point_one < 10 );
    CATCH_REQUIRE( data.float_nine_point_one < 9.2 );

    CATCH_REQUIRE( data.str_hello <= "hello" );
    CATCH_REQUIRE( data.str_hello >= "hello" );

    CATCH_REQUIRE( data.str_hello < "hellp" );
    CATCH_REQUIRE( data.str_hello < "zebra" );
    CATCH_REQUIRE( data.str_hello > "hellm" );
    CATCH_REQUIRE( data.str_hello > "a" );
}

CATCH_TEST_CASE( "Ordering comparison checks that should fail", "[.][failing]" )
{
    TestData data;

    CATCH_CHECK( data.int_seven > 7 );
    CATCH_CHECK( data.int_seven < 7 );
    CATCH_CHECK( data.int_seven > 8 );
    CATCH_CHECK( data.int_seven < 6 );
    CATCH_CHECK( data.int_seven < 0 );
    CATCH_CHECK( data.int_seven < -1 );

    CATCH_CHECK( data.int_seven >= 8 );
    CATCH_CHECK( data.int_seven <= 6 );

    CATCH_CHECK( data.float_nine_point_one < 9 );
    CATCH_CHECK( data.float_nine_point_one > 10 );
    CATCH_CHECK( data.float_nine_point_one > 9.2 );

    CATCH_CHECK( data.str_hello > "hello" );
    CATCH_CHECK( data.str_hello < "hello" );
    CATCH_CHECK( data.str_hello > "hellp" );
    CATCH_CHECK( data.str_hello > "z" );
    CATCH_CHECK( data.str_hello < "hellm" );
    CATCH_CHECK( data.str_hello < "a" );

    CATCH_CHECK( data.str_hello >= "z" );
    CATCH_CHECK( data.str_hello <= "a" );
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif


// Comparisons with int literals
CATCH_TEST_CASE( "Comparisons with int literals don't warn when mixing signed/ unsigned" )
{
    int i = 1;
    unsigned int ui = 2;
    long l = 3;
    unsigned long ul = 4;
    char c = 5;
    unsigned char uc = 6;

    CATCH_REQUIRE( i == 1 );
    CATCH_REQUIRE( ui == 2 );
    CATCH_REQUIRE( l == 3 );
    CATCH_REQUIRE( ul == 4 );
    CATCH_REQUIRE( c == 5 );
    CATCH_REQUIRE( uc == 6 );

    CATCH_REQUIRE( 1 == i );
    CATCH_REQUIRE( 2 == ui );
    CATCH_REQUIRE( 3 == l );
    CATCH_REQUIRE( 4 == ul );
    CATCH_REQUIRE( 5 == c );
    CATCH_REQUIRE( 6 == uc );

    CATCH_REQUIRE( (std::numeric_limits<uint32_t>::max)() > ul );
}

// Disable warnings about sign conversions for the next two tests
// (as we are deliberately invoking them)
// - Currently only disabled for GCC/ LLVM. Should add VC++ too
#ifdef  __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif
#ifdef _MSC_VER
#pragma warning(disable:4389) // '==' : signed/unsigned mismatch
#endif

CATCH_TEST_CASE( "comparisons between int variables" )
{
    long            long_var = 1L;
    unsigned char    unsigned_char_var = 1;
    unsigned short    unsigned_short_var = 1;
    unsigned int    unsigned_int_var = 1;
    unsigned long    unsigned_long_var = 1L;

    CATCH_REQUIRE( long_var == unsigned_char_var );
    CATCH_REQUIRE( long_var == unsigned_short_var );
    CATCH_REQUIRE( long_var == unsigned_int_var );
    CATCH_REQUIRE( long_var == unsigned_long_var );
}

CATCH_TEST_CASE( "comparisons between const int variables" )
{
    const unsigned char     unsigned_char_var = 1;
    const unsigned short    unsigned_short_var = 1;
    const unsigned int      unsigned_int_var = 1;
    const unsigned long     unsigned_long_var = 1L;

    CATCH_REQUIRE( unsigned_char_var == 1 );
    CATCH_REQUIRE( unsigned_short_var == 1 );
    CATCH_REQUIRE( unsigned_int_var == 1 );
    CATCH_REQUIRE( unsigned_long_var == 1 );
}

CATCH_TEST_CASE( "Comparisons between unsigned ints and negative signed ints match c++ standard behaviour" )
{
    CATCH_CHECK( ( -1 > 2u ) );
    CATCH_CHECK( -1 > 2u );

    CATCH_CHECK( ( 2u < -1 ) );
    CATCH_CHECK( 2u < -1 );

    const int minInt = (std::numeric_limits<int>::min)();
    CATCH_CHECK( ( minInt > 2u ) );
    CATCH_CHECK( minInt > 2u );
}

CATCH_TEST_CASE( "Comparisons between ints where one side is computed" )
{
     CATCH_CHECK( 54 == 6*9 );
}

#ifdef  __GNUC__
#pragma GCC diagnostic pop
#endif

CATCH_TEST_CASE( "Pointers can be compared to null" )
{
    TestData* p = nullptr;
    TestData* pNULL = nullptr;

    CATCH_REQUIRE( p == nullptr );
    CATCH_REQUIRE( p == pNULL );

    TestData data;
    p = &data;

    CATCH_REQUIRE( p != nullptr );

    const TestData* cp = p;
    CATCH_REQUIRE( cp != nullptr );

    const TestData* const cpc = p;
    CATCH_REQUIRE( cpc != nullptr );

    CATCH_REQUIRE( returnsNull() == nullptr );
    CATCH_REQUIRE( returnsConstNull() == nullptr );

    CATCH_REQUIRE( nullptr != p );
}

// Not (!) tests
// The problem with the ! operator is that it has right-to-left associativity.
// This means we can't isolate it when we decompose. The simple CATCH_REQUIRE( !false ) form, therefore,
// cannot have the operand value extracted. The test will work correctly, and the situation
// is detected and a warning issued.
// An alternative form of the macros (CATCH_CHECK_FALSE and CATCH_REQUIRE_FALSE) can be used instead to capture
// the operand value.
CATCH_TEST_CASE( "'Not' checks that should succeed" )
{
    bool falseValue = false;

    CATCH_REQUIRE( false == false );
    CATCH_REQUIRE( true == true );
    CATCH_REQUIRE( !false );
    CATCH_REQUIRE_FALSE( false );

    CATCH_REQUIRE( !falseValue );
    CATCH_REQUIRE_FALSE( falseValue );

    CATCH_REQUIRE( !(1 == 2) );
    CATCH_REQUIRE_FALSE( 1 == 2 );
}

CATCH_TEST_CASE( "'Not' checks that should fail", "[.][failing]" )
{
    bool trueValue = true;

    CATCH_CHECK( false != false );
    CATCH_CHECK( true != true );
    CATCH_CHECK( !true );
    CATCH_CHECK_FALSE( true );

    CATCH_CHECK( !trueValue );
    CATCH_CHECK_FALSE( trueValue );

    CATCH_CHECK( !(1 == 1) );
    CATCH_CHECK_FALSE( 1 == 1 );
}

}} // namespace ConditionTests
