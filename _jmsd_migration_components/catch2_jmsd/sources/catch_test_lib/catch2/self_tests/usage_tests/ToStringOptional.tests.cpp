#define CATCH_CONFIG_ENABLE_OPTIONAL_STRINGMAKER
#include "catch2/catch.hpp"

#if defined(CATCH_CONFIG_CPP17_OPTIONAL)

CATCH_TEST_CASE( "std::optional<int> -> toString", "[toString][optional][approvals]" ) {
    using type = std::optional<int>;
    CATCH_REQUIRE( "{ }" == ::Catch::Detail::stringify( type{} ) );
    CATCH_REQUIRE( "0" == ::Catch::Detail::stringify( type{ 0 } ) );
}

CATCH_TEST_CASE( "std::optional<std::string> -> toString", "[toString][optional][approvals]" ) {
    using type = std::optional<std::string>;
    CATCH_REQUIRE( "{ }" == ::Catch::Detail::stringify( type{} ) );
    CATCH_REQUIRE( "\"abc\"" == ::Catch::Detail::stringify( type{ "abc" } ) );
}

CATCH_TEST_CASE( "std::vector<std::optional<int> > -> toString", "[toString][optional][approvals]" ) {
    using type = std::vector<std::optional<int> >;
    CATCH_REQUIRE( "{ 0, { }, 2 }" == ::Catch::Detail::stringify( type{ 0, {}, 2 } ) );
}

#endif // CATCH_INTERNAL_CONFIG_CPP17_OPTIONAL
