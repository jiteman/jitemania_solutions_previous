/*
 *  Created by Phil on 27/06/2014.
 *  Copyright 2014 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"
#include "catch2/internal/catch_tag_alias_registry.h"

CATCH_TEST_CASE( "Tag alias can be registered against tag patterns" ) {

    Catch::TagAliasRegistry registry;

    registry.add( "[@zzz]", "[one][two]", Catch::SourceLineInfo( "file", 2 ) );

    CATCH_SECTION( "The same tag alias can only be registered once" ) {

        try {
            registry.add( "[@zzz]", "[one][two]", Catch::SourceLineInfo( "file", 10 ) );
            CATCH_FAIL( "expected exception" );
        }
        catch( std::exception& ex ) {
#ifndef CATCH_CONFIG_DISABLE_MATCHERS
            std::string what = ex.what();
            using namespace Catch::Matchers;
            CATCH_CHECK_THAT( what, Contains( "[@zzz]" ) );
            CATCH_CHECK_THAT( what, Contains( "file" ) );
            CATCH_CHECK_THAT( what, Contains( "2" ) );
            CATCH_CHECK_THAT( what, Contains( "10" ) );
#endif
        }
    }

    CATCH_SECTION( "Tag aliases must be of the form [@name]" ) {
        CATCH_CHECK_THROWS( registry.add( "[no ampersat]", "", Catch::SourceLineInfo( "file", 3 ) ) );
        CATCH_CHECK_THROWS( registry.add( "[the @ is not at the start]", "", Catch::SourceLineInfo( "file", 3 ) ) );
        CATCH_CHECK_THROWS( registry.add( "@no square bracket at start]", "", Catch::SourceLineInfo( "file", 3 ) ) );
        CATCH_CHECK_THROWS( registry.add( "[@no square bracket at end", "", Catch::SourceLineInfo( "file", 3 ) ) );
    }
}

CATCH_TEST_CASE("shortened hide tags are split apart") {
    auto testcase = Catch::makeTestCase(nullptr, "", {"fake test name", "[.magic-tag]"}, CATCH_INTERNAL_LINEINFO);
    CATCH_REQUIRE_THAT(testcase.tags, Catch::VectorContains(std::string("magic-tag")) && Catch::VectorContains(std::string(".")));
}

CATCH_TEST_CASE("adding a hide tag implicitly enables all others", "[tags]") {
    using Catch::VectorContains;
    auto tag = GENERATE(as<char const*>{}, "[!hide]", "[.]", "[.foo]");
    auto testcase = Catch::makeTestCase(nullptr, "", {"fake test name", tag}, CATCH_INTERNAL_LINEINFO);
    CATCH_REQUIRE_THAT(testcase.tags, VectorContains(std::string(".")) && VectorContains(std::string("!hide")));
}
