/*
 *  Created by Phil on 09/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"

#include <string>
#include <stdexcept>

#ifdef _MSC_VER
#pragma warning(disable:4702) // Unreachable code -- unconditional throws and so on
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wunreachable-code"
#endif

namespace { namespace ExceptionTests {

#ifndef EXCEPTION_TEST_HELPERS_INCLUDED // Don't compile this more than once per TU
#define EXCEPTION_TEST_HELPERS_INCLUDED

int thisThrows() {
    throw std::domain_error( "expected exception" );
    return 1;
}

int thisDoesntThrow() {
    return 0;
}

class CustomException {
public:
    explicit CustomException( const std::string& msg )
    : m_msg( msg )
    {}

    std::string getMessage() const {
        return m_msg;
    }

private:
    std::string m_msg;
};

class CustomStdException : public std::exception {
public:
    explicit CustomStdException( const std::string& msg )
    : m_msg( msg )
    {}
    ~CustomStdException() noexcept override {}

    std::string getMessage() const {
        return m_msg;
    }

private:
    std::string m_msg;
};

[[noreturn]] void throwCustom() {
    throw CustomException( "custom exception - not std" );
}

#endif

CATCH_TEST_CASE( "When checked exceptions are thrown they can be expected or unexpected", "[!throws]" ) {
    CATCH_REQUIRE_THROWS_AS( thisThrows(), std::domain_error );
    CATCH_REQUIRE_NOTHROW( thisDoesntThrow() );
    CATCH_REQUIRE_THROWS( thisThrows() );
}

CATCH_TEST_CASE( "Expected exceptions that don't throw or unexpected exceptions fail the test", "[.][failing][!throws]" ) {
    CATCH_CHECK_THROWS_AS( thisThrows(), std::string );
    CATCH_CHECK_THROWS_AS( thisDoesntThrow(), std::domain_error );
    CATCH_CHECK_NOTHROW( thisThrows() );
}

CATCH_TEST_CASE( "When unchecked exceptions are thrown directly they are always failures", "[.][failing][!throws]" ) {
    throw std::domain_error( "unexpected exception" );
}

CATCH_TEST_CASE( "An unchecked exception reports the line of the last assertion", "[.][failing][!throws]" ) {
    CATCH_CHECK( 1 == 1 );
    throw std::domain_error( "unexpected exception" );
}

CATCH_TEST_CASE( "When unchecked exceptions are thrown from sections they are always failures", "[.][failing][!throws]" ) {
    CATCH_SECTION( "section name" ) {
        throw std::domain_error("unexpected exception");
    }
}

CATCH_TEST_CASE( "When unchecked exceptions are thrown from functions they are always failures", "[.][failing][!throws]" ) {
    CATCH_CHECK( thisThrows() == 0 );
}

CATCH_TEST_CASE( "When unchecked exceptions are thrown during a REQUIRE the test should abort fail", "[.][failing][!throws]" ) {
    CATCH_REQUIRE( thisThrows() == 0 );
    CATCH_FAIL( "This should never happen" );
}

CATCH_TEST_CASE( "When unchecked exceptions are thrown during a CATCH_CHECK the test should continue", "[.][failing][!throws]" ) {
    try {
        CATCH_CHECK(thisThrows() == 0);
    }
    catch(...) {
        CATCH_FAIL( "This should never happen" );
    }
}

CATCH_TEST_CASE( "When unchecked exceptions are thrown, but caught, they do not affect the test", "[!throws]" ) {
    try {
        throw std::domain_error( "unexpected exception" );
    }
    catch(...) {}
}


CATCH_TRANSLATE_EXCEPTION( CustomException& ex ) {
    return ex.getMessage();
}

CATCH_TRANSLATE_EXCEPTION( CustomStdException& ex ) {
    return ex.getMessage();
}

CATCH_TRANSLATE_EXCEPTION( double& ex ) {
    return Catch::Detail::stringify( ex );
}

CATCH_TEST_CASE("Non-std exceptions can be translated", "[.][failing][!throws]" ) {
    throw CustomException( "custom exception" );
}

CATCH_TEST_CASE("Custom std-exceptions can be custom translated", "[.][failing][!throws]" ) {
    throw CustomException( "custom std exception" );
}

CATCH_TEST_CASE( "Custom exceptions can be translated when testing for nothrow", "[.][failing][!throws]" ) {
    CATCH_REQUIRE_NOTHROW( throwCustom() );
}

CATCH_TEST_CASE( "Custom exceptions can be translated when testing for throwing as something else", "[.][failing][!throws]" ) {
    CATCH_REQUIRE_THROWS_AS( throwCustom(), std::exception );
}

CATCH_TEST_CASE( "Unexpected exceptions can be translated", "[.][failing][!throws]"  ) {
    throw double( 3.14 );
}

CATCH_TEST_CASE("Thrown string literals are translated", "[.][failing][!throws]") {
    throw "For some reason someone is throwing a string literal!";
}

CATCH_TEST_CASE("thrown std::strings are translated", "[.][failing][!throws]") {
    throw std::string{ "Why would you throw a std::string?" };
}


#ifndef CATCH_CONFIG_DISABLE_MATCHERS

CATCH_TEST_CASE( "Exception messages can be tested for", "[!throws]" ) {
    using namespace Catch::Matchers;
    CATCH_SECTION( "exact match" )
        CATCH_REQUIRE_THROWS_WITH( thisThrows(), "expected exception" );
    CATCH_SECTION( "different case" )
    CATCH_REQUIRE_THROWS_WITH( thisThrows(), Equals( "expecteD Exception", Catch::CaseSensitive::No ) );
    CATCH_SECTION( "wildcarded" ) {
        CATCH_REQUIRE_THROWS_WITH( thisThrows(), StartsWith( "expected" ) );
        CATCH_REQUIRE_THROWS_WITH( thisThrows(), EndsWith( "exception" ) );
        CATCH_REQUIRE_THROWS_WITH( thisThrows(), Contains( "except" ) );
        CATCH_REQUIRE_THROWS_WITH( thisThrows(), Contains( "exCept", Catch::CaseSensitive::No ) );
    }
}

#endif

CATCH_TEST_CASE( "Mismatching exception messages failing the test", "[.][failing][!throws]" ) {
    CATCH_REQUIRE_THROWS_WITH( thisThrows(), "expected exception" );
    CATCH_REQUIRE_THROWS_WITH( thisThrows(), "should fail" );
    CATCH_REQUIRE_THROWS_WITH( thisThrows(), "expected exception" );
}

CATCH_TEST_CASE( "#748 - captures with unexpected exceptions", "[.][failing][!throws][!shouldfail]" ) {
    int answer = 42;
    CATCH_CAPTURE( answer );
    // the message should be printed on the first two sections but not on the third
    CATCH_SECTION( "outside assertions" ) {
        thisThrows();
    }
    CATCH_SECTION( "inside CATCH_REQUIRE_NOTHROW" ) {
        CATCH_REQUIRE_NOTHROW( thisThrows() );
    }
    CATCH_SECTION( "inside CATCH_REQUIRE_THROWS" ) {
        CATCH_REQUIRE_THROWS( thisThrows() );
    }
}

}} // namespace ExceptionTests

#ifdef __clang__
#pragma clang diagnostic pop
#endif
