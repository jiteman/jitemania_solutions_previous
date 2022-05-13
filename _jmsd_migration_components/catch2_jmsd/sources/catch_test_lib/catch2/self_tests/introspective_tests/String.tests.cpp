#include "catch2/internal/catch_stringref.h"

#include "catch2/catch.hpp"

#include <cstring>

CATCH_TEST_CASE( "StringRef", "[Strings][StringRef]" ) {

    using Catch::StringRef;

    CATCH_SECTION( "Empty string" ) {
        StringRef empty;
        CATCH_REQUIRE( empty.empty() );
        CATCH_REQUIRE( empty.size() == 0 );
        CATCH_REQUIRE( empty.isNullTerminated() );
        CATCH_REQUIRE( std::strcmp( empty.c_str(), "" ) == 0 );
    }

    CATCH_SECTION( "From string literal" ) {
        StringRef s = "hello";
        CATCH_REQUIRE( s.empty() == false );
        CATCH_REQUIRE( s.size() == 5 );
        CATCH_REQUIRE( s.isNullTerminated() );

        auto rawChars = s.data();
        CATCH_REQUIRE( std::strcmp( rawChars, "hello" ) == 0 );

        CATCH_REQUIRE_NOTHROW(s.c_str());
        CATCH_REQUIRE(s.c_str() == rawChars);
        CATCH_REQUIRE(s.data() == rawChars);
    }
    CATCH_SECTION( "From sub-string" ) {
        StringRef original = StringRef( "original string" ).substr(0, 8);
        CATCH_REQUIRE( original == "original" );

        CATCH_REQUIRE_FALSE(original.isNullTerminated());
        CATCH_REQUIRE_THROWS(original.c_str());
        CATCH_REQUIRE_NOTHROW(original.data());
    }


    CATCH_SECTION( "Substrings" ) {
        StringRef s = "hello world!";
        StringRef ss = s.substr(0, 5);

        CATCH_SECTION( "zero-based substring" ) {
            CATCH_REQUIRE( ss.empty() == false );
            CATCH_REQUIRE( ss.size() == 5 );
            CATCH_REQUIRE( std::strncmp( ss.data(), "hello", 5 ) == 0 );
            CATCH_REQUIRE( ss == "hello" );
        }

        CATCH_SECTION( "non-zero-based substring") {
            ss = s.substr( 6, 6 );
            CATCH_REQUIRE( ss.size() == 6 );
            CATCH_REQUIRE( std::strcmp( ss.c_str(), "world!" ) == 0 );
        }

        CATCH_SECTION( "Pointer values of full refs should match" ) {
            StringRef s2 = s;
            CATCH_REQUIRE( s.data() == s2.data() );
        }

        CATCH_SECTION( "Pointer values of substring refs should also match" ) {
            CATCH_REQUIRE( s.data() == ss.data() );
        }

        CATCH_SECTION("Past the end substring") {
            CATCH_REQUIRE(s.substr(s.size() + 1, 123).empty());
        }

        CATCH_SECTION("Substring off the end are trimmed") {
            ss = s.substr(6, 123);
            CATCH_REQUIRE(std::strcmp(ss.c_str(), "world!") == 0);
        }
        // TODO: substring into string + size is longer than end
    }

    CATCH_SECTION( "Comparisons are deep" ) {
        char buffer1[] = "Hello";
        char buffer2[] = "Hello";
        CATCH_CHECK((char*)buffer1 != (char*)buffer2);

        StringRef left(buffer1), right(buffer2);
        CATCH_REQUIRE( left == right );
        CATCH_REQUIRE(left != left.substr(0, 3));
    }

    CATCH_SECTION( "from std::string" ) {
        std::string stdStr = "a standard string";

        CATCH_SECTION( "implicitly constructed" ) {
            StringRef sr = stdStr;
            CATCH_REQUIRE( sr == "a standard string" );
            CATCH_REQUIRE( sr.size() == stdStr.size() );
        }
        CATCH_SECTION( "explicitly constructed" ) {
            StringRef sr( stdStr );
            CATCH_REQUIRE( sr == "a standard string" );
            CATCH_REQUIRE( sr.size() == stdStr.size() );
        }
        CATCH_SECTION( "assigned" ) {
            StringRef sr;
            sr = stdStr;
            CATCH_REQUIRE( sr == "a standard string" );
            CATCH_REQUIRE( sr.size() == stdStr.size() );
        }
    }

    CATCH_SECTION( "to std::string" ) {
        StringRef sr = "a stringref";

        CATCH_SECTION( "explicitly constructed" ) {
            std::string stdStr( sr );
            CATCH_REQUIRE( stdStr == "a stringref" );
            CATCH_REQUIRE( stdStr.size() == sr.size() );
        }
        CATCH_SECTION( "assigned" ) {
            std::string stdStr;
            stdStr = static_cast<std::string>(sr);
            CATCH_REQUIRE( stdStr == "a stringref" );
            CATCH_REQUIRE( stdStr.size() == sr.size() );
        }
    }
}

CATCH_TEST_CASE("StringRef at compilation time", "[Strings][StringRef][constexpr]") {
    using Catch::StringRef;
    CATCH_SECTION("Simple constructors") {
        CATCH_STATIC_REQUIRE(StringRef{}.size() == 0);

        CATCH_STATIC_REQUIRE(StringRef{ "abc", 3 }.size() == 3);
        CATCH_STATIC_REQUIRE(StringRef{ "abc", 3 }.isNullTerminated());

        CATCH_STATIC_REQUIRE(StringRef{ "abc", 2 }.size() == 2);
        CATCH_STATIC_REQUIRE_FALSE(StringRef{ "abc", 2 }.isNullTerminated());
    }
    CATCH_SECTION("UDL construction") {
        constexpr auto sr1 = "abc"_catch_sr;
        CATCH_STATIC_REQUIRE_FALSE(sr1.empty());
        CATCH_STATIC_REQUIRE(sr1.size() == 3);
        CATCH_STATIC_REQUIRE(sr1.isNullTerminated());

        using Catch::operator"" _sr;
        constexpr auto sr2 = ""_sr;
        CATCH_STATIC_REQUIRE(sr2.empty());
        CATCH_STATIC_REQUIRE(sr2.size() == 0);
        CATCH_STATIC_REQUIRE(sr2.isNullTerminated());
    }
}
