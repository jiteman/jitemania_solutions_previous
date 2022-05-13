#include "catch2/catch.hpp"
#include "catch2/internal/catch_xmlwriter.h"

#include <sstream>

inline std::string encode( std::string const& str, Catch::XmlEncode::ForWhat forWhat = Catch::XmlEncode::ForTextNodes ) {
    std::ostringstream oss;
    oss << Catch::XmlEncode( str, forWhat );
    return oss.str();
}

CATCH_TEST_CASE( "XmlEncode", "[XML]" ) {
    CATCH_SECTION( "normal string" ) {
        CATCH_REQUIRE( encode( "normal string" ) == "normal string" );
    }
    CATCH_SECTION( "empty string" ) {
        CATCH_REQUIRE( encode( "" ) == "" );
    }
    CATCH_SECTION( "string with ampersand" ) {
        CATCH_REQUIRE( encode( "smith & jones" ) == "smith &amp; jones" );
    }
    CATCH_SECTION( "string with less-than" ) {
        CATCH_REQUIRE( encode( "smith < jones" ) == "smith &lt; jones" );
    }
    CATCH_SECTION( "string with greater-than" ) {
        CATCH_REQUIRE( encode( "smith > jones" ) == "smith > jones" );
        CATCH_REQUIRE( encode( "smith ]]> jones" ) == "smith ]]&gt; jones" );
    }
    CATCH_SECTION( "string with quotes" ) {
        std::string stringWithQuotes = "don't \"quote\" me on that";
        CATCH_REQUIRE( encode( stringWithQuotes ) == stringWithQuotes );
        CATCH_REQUIRE( encode( stringWithQuotes, Catch::XmlEncode::ForAttributes ) == "don't &quot;quote&quot; me on that" );
    }
    CATCH_SECTION( "string with control char (1)" ) {
        CATCH_REQUIRE( encode( "[\x01]" ) == "[\\x01]" );
    }
    CATCH_SECTION( "string with control char (x7F)" ) {
        CATCH_REQUIRE( encode( "[\x7F]" ) == "[\\x7F]" );
    }
}

// Thanks to Peter Bindels (dascandy) for some of the tests
CATCH_TEST_CASE("XmlEncode: UTF-8", "[XML][UTF-8][approvals]") {
#define ESC(lit) (char*)(lit)
    CATCH_SECTION("Valid utf-8 strings") {
        CATCH_CHECK(encode(ESC(u8"Here be 👾")) == ESC(u8"Here be 👾"));
        CATCH_CHECK(encode(ESC(u8"šš")) == ESC(u8"šš"));

        CATCH_CHECK(encode("\xDF\xBF")         == "\xDF\xBF"); // 0x7FF
        CATCH_CHECK(encode("\xE0\xA0\x80")     == "\xE0\xA0\x80"); // 0x800
        CATCH_CHECK(encode("\xED\x9F\xBF")     == "\xED\x9F\xBF"); // 0xD7FF
        CATCH_CHECK(encode("\xEE\x80\x80")     == "\xEE\x80\x80"); // 0xE000
        CATCH_CHECK(encode("\xEF\xBF\xBF")     == "\xEF\xBF\xBF"); // 0xFFFF
        CATCH_CHECK(encode("\xF0\x90\x80\x80") == "\xF0\x90\x80\x80"); // 0x10000
        CATCH_CHECK(encode("\xF4\x8F\xBF\xBF") == "\xF4\x8F\xBF\xBF"); // 0x10FFFF
    }
    CATCH_SECTION("Invalid utf-8 strings") {
        CATCH_SECTION("Various broken strings") {
//            CATCH_CHECK(encode(ESC("Here \xFF be \xF0\x9F\x91\xBE")) == ESC(u8"Here \\xFF be 👾"));
            CATCH_CHECK(encode("\xFF") == "\\xFF");
//            CATCH_CHECK(encode("\xC5\xC5\xA0") == ESC(u8"\\xC5Š"));
            CATCH_CHECK(encode("\xF4\x90\x80\x80") == ESC(u8"\\xF4\\x90\\x80\\x80")); // 0x110000 -- out of unicode range
        }

        CATCH_SECTION("Overlong encodings") {
            CATCH_CHECK(encode("\xC0\x80") == "\\xC0\\x80"); // \0
            CATCH_CHECK(encode("\xF0\x80\x80\x80") == "\\xF0\\x80\\x80\\x80"); // Super-over-long \0
            CATCH_CHECK(encode("\xC1\xBF") == "\\xC1\\xBF"); // ASCII char as UTF-8 (0x7F)
            CATCH_CHECK(encode("\xE0\x9F\xBF") == "\\xE0\\x9F\\xBF"); // 0x7FF
            CATCH_CHECK(encode("\xF0\x8F\xBF\xBF") == "\\xF0\\x8F\\xBF\\xBF"); // 0xFFFF
        }

        // Note that we actually don't modify surrogate pairs, as we do not do strict checking
        CATCH_SECTION("Surrogate pairs") {
            CATCH_CHECK(encode("\xED\xA0\x80") == "\xED\xA0\x80"); // Invalid surrogate half 0xD800
            CATCH_CHECK(encode("\xED\xAF\xBF") == "\xED\xAF\xBF"); // Invalid surrogate half 0xDBFF
            CATCH_CHECK(encode("\xED\xB0\x80") == "\xED\xB0\x80"); // Invalid surrogate half 0xDC00
            CATCH_CHECK(encode("\xED\xBF\xBF") == "\xED\xBF\xBF"); // Invalid surrogate half 0xDFFF
        }

        CATCH_SECTION("Invalid start byte") {
            CATCH_CHECK(encode("\x80") == "\\x80");
            CATCH_CHECK(encode("\x81") == "\\x81");
            CATCH_CHECK(encode("\xBC") == "\\xBC");
            CATCH_CHECK(encode("\xBF") == "\\xBF");
            // Out of range
            CATCH_CHECK(encode("\xF5\x80\x80\x80") == "\\xF5\\x80\\x80\\x80");
            CATCH_CHECK(encode("\xF6\x80\x80\x80") == "\\xF6\\x80\\x80\\x80");
            CATCH_CHECK(encode("\xF7\x80\x80\x80") == "\\xF7\\x80\\x80\\x80");
        }

        CATCH_SECTION("Missing continuation byte(s)") {
            // Missing first continuation byte
            CATCH_CHECK(encode("\xDE") == "\\xDE");
            CATCH_CHECK(encode("\xDF") == "\\xDF");
            CATCH_CHECK(encode("\xE0") == "\\xE0");
            CATCH_CHECK(encode("\xEF") == "\\xEF");
            CATCH_CHECK(encode("\xF0") == "\\xF0");
            CATCH_CHECK(encode("\xF4") == "\\xF4");

            // Missing second continuation byte
            CATCH_CHECK(encode("\xE0\x80") == "\\xE0\\x80");
            CATCH_CHECK(encode("\xE0\xBF") == "\\xE0\\xBF");
            CATCH_CHECK(encode("\xE1\x80") == "\\xE1\\x80");
            CATCH_CHECK(encode("\xF0\x80") == "\\xF0\\x80");
            CATCH_CHECK(encode("\xF4\x80") == "\\xF4\\x80");

            // Missing third continuation byte
            CATCH_CHECK(encode("\xF0\x80\x80") == "\\xF0\\x80\\x80");
            CATCH_CHECK(encode("\xF4\x80\x80") == "\\xF4\\x80\\x80");
        }
    }
#undef ESC
}
