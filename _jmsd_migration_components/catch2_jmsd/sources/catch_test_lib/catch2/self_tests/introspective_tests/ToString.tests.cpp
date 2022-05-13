#include "catch2/catch.hpp"

#include "catch2/internal/catch_enum_values_registry.h"

enum class EnumClass3 { Value1, Value2, Value3, Value4 };


CATCH_TEST_CASE( "parseEnums", "[Strings][enums]" ) {
    using namespace Catch::Matchers;
    using Catch::Detail::parseEnums;

    CATCH_SECTION( "No enums" )
        CATCH_CHECK_THAT( parseEnums( "" ), Equals( std::vector<Catch::StringRef>{} ) );

    CATCH_SECTION( "One enum value" ) {
        CATCH_CHECK_THAT( parseEnums( "ClassName::EnumName::Value1" ),
                Equals(std::vector<Catch::StringRef>{"Value1"} ) );
        CATCH_CHECK_THAT( parseEnums( "Value1" ),
                Equals( std::vector<Catch::StringRef>{"Value1"} ) );
        CATCH_CHECK_THAT( parseEnums( "EnumName::Value1" ),
                Equals(std::vector<Catch::StringRef>{"Value1"} ) );
    }

    CATCH_SECTION( "Multiple enum values" ) {
        CATCH_CHECK_THAT( parseEnums( "ClassName::EnumName::Value1, ClassName::EnumName::Value2" ),
                    Equals( std::vector<Catch::StringRef>{"Value1", "Value2"} ) );
        CATCH_CHECK_THAT( parseEnums( "ClassName::EnumName::Value1, ClassName::EnumName::Value2, ClassName::EnumName::Value3" ),
                    Equals( std::vector<Catch::StringRef>{"Value1", "Value2", "Value3"} ) );
        CATCH_CHECK_THAT( parseEnums( "ClassName::EnumName::Value1,ClassName::EnumName::Value2 , ClassName::EnumName::Value3" ),
                    Equals( std::vector<Catch::StringRef>{"Value1", "Value2", "Value3"} ) );
    }
}

CATCH_TEST_CASE( "Directly creating an EnumInfo" ) {

    using namespace Catch::Detail;
    std::unique_ptr<EnumInfo> enumInfo = makeEnumInfo( "EnumName", "EnumName::Value1, EnumName::Value2", {0, 1} );

    CATCH_CHECK( enumInfo->lookup(0) == "Value1" );
    CATCH_CHECK( enumInfo->lookup(1) == "Value2" );
    CATCH_CHECK( enumInfo->lookup(3) == "{** unexpected enum value **}" );
}
