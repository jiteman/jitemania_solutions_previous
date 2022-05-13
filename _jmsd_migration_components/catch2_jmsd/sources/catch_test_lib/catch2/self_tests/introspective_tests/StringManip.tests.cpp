#include "catch2/internal/catch_string_manip.h"

#include "catch2/catch.hpp"

static const char * const no_whitespace = "There is no extra whitespace here";
static const char * const leading_whitespace = " \r \t\n There is no extra whitespace here";
static const char * const trailing_whitespace = "There is no extra whitespace here \t \n \r ";
static const char * const whitespace_at_both_ends = " \r\n \t There is no extra whitespace here  \t\t\t \n";

CATCH_TEST_CASE("Trim strings", "[string-manip]") {
    using Catch::trim; using Catch::StringRef;
    static_assert(std::is_same<std::string, decltype(trim(std::string{}))>::value, "Trimming std::string should return std::string");
    static_assert(std::is_same<StringRef, decltype(trim(StringRef{}))>::value, "Trimming StringRef should return StringRef");

    CATCH_REQUIRE(trim(std::string(no_whitespace)) == no_whitespace);
    CATCH_REQUIRE(trim(std::string(leading_whitespace)) == no_whitespace);
    CATCH_REQUIRE(trim(std::string(trailing_whitespace)) == no_whitespace);
    CATCH_REQUIRE(trim(std::string(whitespace_at_both_ends)) == no_whitespace);

    CATCH_REQUIRE(trim(StringRef(no_whitespace)) == StringRef(no_whitespace));
    CATCH_REQUIRE(trim(StringRef(leading_whitespace)) == StringRef(no_whitespace));
    CATCH_REQUIRE(trim(StringRef(trailing_whitespace)) == StringRef(no_whitespace));
    CATCH_REQUIRE(trim(StringRef(whitespace_at_both_ends)) == StringRef(no_whitespace));
}

CATCH_TEST_CASE("replaceInPlace", "[string-manip]") {
    std::string letters = "abcdefcg";
    CATCH_SECTION("replace single char") {
        CATCH_CHECK(Catch::replaceInPlace(letters, "b", "z"));
        CATCH_CHECK(letters == "azcdefcg");
    }
    CATCH_SECTION("replace two chars") {
        CATCH_CHECK(Catch::replaceInPlace(letters, "c", "z"));
        CATCH_CHECK(letters == "abzdefzg");
    }
    CATCH_SECTION("replace first char") {
        CATCH_CHECK(Catch::replaceInPlace(letters, "a", "z"));
        CATCH_CHECK(letters == "zbcdefcg");
    }
    CATCH_SECTION("replace last char") {
        CATCH_CHECK(Catch::replaceInPlace(letters, "g", "z"));
        CATCH_CHECK(letters == "abcdefcz");
    }
    CATCH_SECTION("replace all chars") {
        CATCH_CHECK(Catch::replaceInPlace(letters, letters, "replaced"));
        CATCH_CHECK(letters == "replaced");
    }
    CATCH_SECTION("replace no chars") {
        CATCH_CHECK_FALSE(Catch::replaceInPlace(letters, "x", "z"));
        CATCH_CHECK(letters == letters);
    }
    CATCH_SECTION("escape '") {
        std::string s = "didn't";
        CATCH_CHECK(Catch::replaceInPlace(s, "'", "|'"));
        CATCH_CHECK(s == "didn|'t");
    }
}

CATCH_TEST_CASE("splitString", "[string-manip]") {
    using namespace Catch::Matchers;
    using Catch::splitStringRef;
    using Catch::StringRef;

    CATCH_CHECK_THAT(splitStringRef("", ','), Equals(std::vector<StringRef>()));
    CATCH_CHECK_THAT(splitStringRef("abc", ','), Equals(std::vector<StringRef>{"abc"}));
    CATCH_CHECK_THAT(splitStringRef("abc,def", ','), Equals(std::vector<StringRef>{"abc", "def"}));
}
