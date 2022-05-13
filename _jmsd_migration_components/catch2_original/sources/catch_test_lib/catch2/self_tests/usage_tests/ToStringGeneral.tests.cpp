/*
 *  Created by Martin on 17/02/2017.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#define CATCH_CONFIG_ENABLE_PAIR_STRINGMAKER
#include "catch2/catch.hpp"

#include <map>
#include <set>

CATCH_TEST_CASE( "Character pretty printing" ){
    CATCH_SECTION("Specifically escaped"){
        char tab = '\t';
        char newline = '\n';
        char carr_return = '\r';
        char form_feed = '\f';
        CATCH_CHECK(tab == '\t');
        CATCH_CHECK(newline == '\n');
        CATCH_CHECK(carr_return == '\r');
        CATCH_CHECK(form_feed == '\f');
    }
    CATCH_SECTION("General chars"){
        char space = ' ';
        CATCH_CHECK(space == ' ');
        char chars[] = {'a', 'z', 'A', 'Z'};
        for (int i = 0; i < 4; ++i){
            char c = chars[i];
            CATCH_REQUIRE(c == chars[i]);
        }
    }
    CATCH_SECTION("Low ASCII"){
        char null_terminator = '\0';
        CATCH_CHECK(null_terminator == '\0');
        for (int i = 2; i < 6; ++i){
            char c = static_cast<char>(i);
            CATCH_REQUIRE(c == i);
        }
    }
}


CATCH_TEST_CASE( "Capture and info messages" ) {
    CATCH_SECTION("Capture should stringify like assertions") {
        int i = 2;
        CATCH_CAPTURE(i);
        CATCH_REQUIRE(true);
    }
    CATCH_SECTION("Info should NOT stringify the way assertions do") {
        int i = 3;
        CATCH_INFO(i);
        CATCH_REQUIRE(true);
    }
}

CATCH_TEST_CASE( "std::map is convertible string", "[toString]" ) {

    CATCH_SECTION( "empty" ) {
        std::map<std::string, int> emptyMap;

        CATCH_REQUIRE( Catch::Detail::stringify( emptyMap ) == "{  }" );
    }

    CATCH_SECTION( "single item" ) {
        std::map<std::string, int> map = { { "one", 1 } };

        CATCH_REQUIRE( Catch::Detail::stringify( map ) == "{ { \"one\", 1 } }" );
    }

    CATCH_SECTION( "several items" ) {
        std::map<std::string, int> map = {
                { "abc", 1 },
                { "def", 2 },
                { "ghi", 3 }
            };

        CATCH_REQUIRE( Catch::Detail::stringify( map ) == "{ { \"abc\", 1 }, { \"def\", 2 }, { \"ghi\", 3 } }" );
    }
}

CATCH_TEST_CASE( "std::set is convertible string", "[toString]" ) {

    CATCH_SECTION( "empty" ) {
        std::set<std::string> emptySet;

        CATCH_REQUIRE( Catch::Detail::stringify( emptySet ) == "{  }" );
    }

    CATCH_SECTION( "single item" ) {
        std::set<std::string> set = { "one" };

        CATCH_REQUIRE( Catch::Detail::stringify( set ) == "{ \"one\" }" );
    }

    CATCH_SECTION( "several items" ) {
        std::set<std::string> set = { "abc", "def", "ghi" };

        CATCH_REQUIRE( Catch::Detail::stringify( set ) == "{ \"abc\", \"def\", \"ghi\" }" );
    }
}

CATCH_TEST_CASE("Static arrays are convertible to string", "[toString]") {
    CATCH_SECTION("Single item") {
        int singular[1] = { 1 };
        CATCH_REQUIRE(Catch::Detail::stringify(singular) == "{ 1 }");
    }
    CATCH_SECTION("Multiple") {
        int arr[3] = { 3, 2, 1 };
        CATCH_REQUIRE(Catch::Detail::stringify(arr) == "{ 3, 2, 1 }");
    }
    CATCH_SECTION("Non-trivial inner items") {
        std::vector<std::string> arr[2] = { {"1:1", "1:2", "1:3"}, {"2:1", "2:2"} };
        CATCH_REQUIRE(Catch::Detail::stringify(arr) == R"({ { "1:1", "1:2", "1:3" }, { "2:1", "2:2" } })");
    }
}

#ifdef CATCH_CONFIG_CPP17_STRING_VIEW

CATCH_TEST_CASE("String views are stringified like other strings", "[toString][approvals]") {
    std::string_view view{"abc"};
    CATCH_CHECK(Catch::Detail::stringify(view) == R"("abc")");

    std::string_view arr[] { view };
    CATCH_CHECK(Catch::Detail::stringify(arr) == R"({ "abc" })");
}

#endif

CATCH_TEST_CASE("Precision of floating point stringification can be set", "[toString][floatingPoint]") {
    CATCH_SECTION("Floats") {
        using sm = Catch::StringMaker<float>;
        const auto oldPrecision = sm::precision;

        const float testFloat = 1.12345678901234567899f;
        auto str1 = sm::convert(testFloat);
        sm::precision = 5;
        // "1." prefix = 2 chars, f suffix is another char
        CATCH_CHECK(str1.size() == 3 + 5);

        sm::precision = 10;
        auto str2 = sm::convert(testFloat);
        CATCH_REQUIRE(str2.size() == 3 + 10);
        sm::precision = oldPrecision;
    }
    CATCH_SECTION("Double") {
        using sm = Catch::StringMaker<double>;
        const auto oldPrecision = sm::precision;

        const double testDouble = 1.123456789012345678901234567899;
        sm::precision = 5;
        auto str1 = sm::convert(testDouble);
        // "1." prefix = 2 chars
        CATCH_CHECK(str1.size() == 2 + 5);

        sm::precision = 15;
        auto str2 = sm::convert(testDouble);
        CATCH_REQUIRE(str2.size() == 2 + 15);

        sm::precision = oldPrecision;
    }
}

namespace {

struct WhatException : std::exception {
    char const* what() const noexcept override {
        return "This exception has overridden what() method";
    }
    ~WhatException() override;
};

struct OperatorException : std::exception {
    ~OperatorException() override;
};

std::ostream& operator<<(std::ostream& out, OperatorException const&) {
    out << "OperatorException";
    return out;
}

struct StringMakerException : std::exception {
    ~StringMakerException() override;
};

} // end anonymous namespace

namespace Catch {
template <>
struct StringMaker<StringMakerException> {
    static std::string convert(StringMakerException const&) {
        return "StringMakerException";
    }
};
}

// Avoid -Wweak-tables
WhatException::~WhatException() = default;
OperatorException::~OperatorException() = default;
StringMakerException::~StringMakerException() = default;




CATCH_TEST_CASE("Exception as a value (e.g. in REQUIRE_THROWS_MATCHES) can be stringified", "[toString][exception]") {
    CATCH_REQUIRE(::Catch::Detail::stringify(WhatException{}) == "This exception has overridden what() method");
    CATCH_REQUIRE(::Catch::Detail::stringify(OperatorException{}) == "OperatorException");
    CATCH_REQUIRE(::Catch::Detail::stringify(StringMakerException{}) == "StringMakerException");
}
