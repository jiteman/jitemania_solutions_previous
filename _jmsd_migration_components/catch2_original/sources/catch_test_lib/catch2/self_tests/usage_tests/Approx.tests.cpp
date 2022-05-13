/*
 *  Created by Phil on 28/04/2011.
 *  Copyright 2011 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"

#include <cmath>

namespace { namespace ApproxTests {

#ifndef APPROX_TEST_HELPERS_INCLUDED // Don't compile this more than once per TU
#define APPROX_TEST_HELPERS_INCLUDED

    inline double divide( double a, double b ) {
        return a/b;
    }

    class StrongDoubleTypedef {
        double d_ = 0.0;

    public:
        explicit StrongDoubleTypedef(double d) : d_(d) {}
        explicit operator double() const { return d_; }
    };

    inline std::ostream& operator<<( std::ostream& os, StrongDoubleTypedef td ) {
        return os << "StrongDoubleTypedef(" << static_cast<double>(td) << ")";
    }

#endif

using namespace Catch::literals;

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "A comparison that uses literals instead of the normal constructor", "[Approx]" ) {
    double d = 1.23;

    CATCH_REQUIRE( d == 1.23_a );
    CATCH_REQUIRE( d != 1.22_a );
    CATCH_REQUIRE( -d == -1.23_a );

    CATCH_REQUIRE( d == 1.2_a .epsilon(.1) );
    CATCH_REQUIRE( d != 1.2_a .epsilon(.001) );
    CATCH_REQUIRE( d == 1_a .epsilon(.3) );
}

CATCH_TEST_CASE( "Some simple comparisons between doubles", "[Approx]" ) {
    double d = 1.23;

    CATCH_REQUIRE( d == Approx( 1.23 ) );
    CATCH_REQUIRE( d != Approx( 1.22 ) );
    CATCH_REQUIRE( d != Approx( 1.24 ) );

    CATCH_REQUIRE( d == 1.23_a );
    CATCH_REQUIRE( d != 1.22_a );

    CATCH_REQUIRE( Approx( d ) == 1.23 );
    CATCH_REQUIRE( Approx( d ) != 1.22 );
    CATCH_REQUIRE( Approx( d ) != 1.24 );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Approximate comparisons with different epsilons", "[Approx]" ) {
    double d = 1.23;

    CATCH_REQUIRE( d != Approx( 1.231 ) );
    CATCH_REQUIRE( d == Approx( 1.231 ).epsilon( 0.1 ) );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Less-than inequalities with different epsilons", "[Approx]" ) {
  double d = 1.23;

  CATCH_REQUIRE( d <= Approx( 1.24 ) );
  CATCH_REQUIRE( d <= Approx( 1.23 ) );
  CATCH_REQUIRE_FALSE( d <= Approx( 1.22 ) );
  CATCH_REQUIRE( d <= Approx( 1.22 ).epsilon(0.1) );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Greater-than inequalities with different epsilons", "[Approx]" ) {
  double d = 1.23;

  CATCH_REQUIRE( d >= Approx( 1.22 ) );
  CATCH_REQUIRE( d >= Approx( 1.23 ) );
  CATCH_REQUIRE_FALSE( d >= Approx( 1.24 ) );
  CATCH_REQUIRE( d >= Approx( 1.24 ).epsilon(0.1) );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Approximate comparisons with floats", "[Approx]" ) {
    CATCH_REQUIRE( 1.23f == Approx( 1.23f ) );
    CATCH_REQUIRE( 0.0f == Approx( 0.0f ) );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Approximate comparisons with ints", "[Approx]" ) {
    CATCH_REQUIRE( 1 == Approx( 1 ) );
    CATCH_REQUIRE( 0 == Approx( 0 ) );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Approximate comparisons with mixed numeric types", "[Approx]" ) {
    const double dZero = 0;
    const double dSmall = 0.00001;
    const double dMedium = 1.234;

    CATCH_REQUIRE( 1.0f == Approx( 1 ) );
    CATCH_REQUIRE( 0 == Approx( dZero) );
    CATCH_REQUIRE( 0 == Approx( dSmall ).margin( 0.001 ) );
    CATCH_REQUIRE( 1.234f == Approx( dMedium ) );
    CATCH_REQUIRE( dMedium == Approx( 1.234f ) );
}

///////////////////////////////////////////////////////////////////////////////
CATCH_TEST_CASE( "Use a custom approx", "[Approx][custom]" ) {
    double d = 1.23;

    Approx approx = Approx::custom().epsilon( 0.01 );

    CATCH_REQUIRE( d == approx( 1.23 ) );
    CATCH_REQUIRE( d == approx( 1.22 ) );
    CATCH_REQUIRE( d == approx( 1.24 ) );
    CATCH_REQUIRE( d != approx( 1.25 ) );

    CATCH_REQUIRE( approx( d ) == 1.23 );
    CATCH_REQUIRE( approx( d ) == 1.22 );
    CATCH_REQUIRE( approx( d ) == 1.24 );
    CATCH_REQUIRE( approx( d ) != 1.25 );
}

CATCH_TEST_CASE( "Approximate PI", "[Approx][PI]" ) {
    CATCH_REQUIRE( divide( 22, 7 ) == Approx( 3.141 ).epsilon( 0.001 ) );
    CATCH_REQUIRE( divide( 22, 7 ) != Approx( 3.141 ).epsilon( 0.0001 ) );
}

///////////////////////////////////////////////////////////////////////////////

CATCH_TEST_CASE( "Absolute margin", "[Approx]" ) {
    CATCH_REQUIRE( 104.0 != Approx(100.0) );
    CATCH_REQUIRE( 104.0 == Approx(100.0).margin(5) );
    CATCH_REQUIRE( 104.0 == Approx(100.0).margin(4) );
    CATCH_REQUIRE( 104.0 != Approx(100.0).margin(3) );
    CATCH_REQUIRE( 100.3 != Approx(100.0) );
    CATCH_REQUIRE( 100.3 == Approx(100.0).margin(0.5) );
}

CATCH_TEST_CASE("Approx with exactly-representable margin", "[Approx]") {
    CATCH_CHECK( 0.25f == Approx(0.0f).margin(0.25f) );

    CATCH_CHECK( 0.0f == Approx(0.25f).margin(0.25f) );
    CATCH_CHECK( 0.5f == Approx(0.25f).margin(0.25f) );

    CATCH_CHECK( 245.0f == Approx(245.25f).margin(0.25f) );
    CATCH_CHECK( 245.5f == Approx(245.25f).margin(0.25f) );
}

CATCH_TEST_CASE("Approx setters validate their arguments", "[Approx]") {
    CATCH_REQUIRE_NOTHROW(Approx(0).margin(0));
    CATCH_REQUIRE_NOTHROW(Approx(0).margin(1234656));

    CATCH_REQUIRE_THROWS_AS(Approx(0).margin(-2), std::domain_error);

    CATCH_REQUIRE_NOTHROW(Approx(0).epsilon(0));
    CATCH_REQUIRE_NOTHROW(Approx(0).epsilon(1));

    CATCH_REQUIRE_THROWS_AS(Approx(0).epsilon(-0.001), std::domain_error);
    CATCH_REQUIRE_THROWS_AS(Approx(0).epsilon(1.0001), std::domain_error);
}

CATCH_TEST_CASE("Default scale is invisible to comparison", "[Approx]") {
    CATCH_REQUIRE(101.000001 != Approx(100).epsilon(0.01));
    CATCH_REQUIRE(std::pow(10, -5) != Approx(std::pow(10, -7)));
}

CATCH_TEST_CASE("Epsilon only applies to Approx's value", "[Approx]") {
    CATCH_REQUIRE(101.01 != Approx(100).epsilon(0.01));
}

CATCH_TEST_CASE("Assorted miscellaneous tests", "[Approx][approvals]") {
    CATCH_REQUIRE(INFINITY == Approx(INFINITY));
    CATCH_REQUIRE(-INFINITY != Approx(INFINITY));
    CATCH_REQUIRE(1 != Approx(INFINITY));
    CATCH_REQUIRE(INFINITY != Approx(1));
    CATCH_REQUIRE(NAN != Approx(NAN));
    CATCH_REQUIRE_FALSE(NAN == Approx(NAN));
}

CATCH_TEST_CASE( "Comparison with explicitly convertible types", "[Approx]" )
{
  StrongDoubleTypedef td(10.0);

  CATCH_REQUIRE(td == Approx(10.0));
  CATCH_REQUIRE(Approx(10.0) == td);

  CATCH_REQUIRE(td != Approx(11.0));
  CATCH_REQUIRE(Approx(11.0) != td);

  CATCH_REQUIRE(td <= Approx(10.0));
  CATCH_REQUIRE(td <= Approx(11.0));
  CATCH_REQUIRE(Approx(10.0) <= td);
  CATCH_REQUIRE(Approx(9.0) <= td);

  CATCH_REQUIRE(td >= Approx(9.0));
  CATCH_REQUIRE(td >= Approx(td));
  CATCH_REQUIRE(Approx(td) >= td);
  CATCH_REQUIRE(Approx(11.0) >= td);

}

}} // namespace ApproxTests
