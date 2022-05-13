/*
 *  Created by Phil on 15/03/2013.
 *  Copyright 2013 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"


CATCH_TEST_CASE()
{
    CATCH_SUCCEED( "anonymous test case" );
}

CATCH_TEST_CASE( "Test case with one argument" )
{
    CATCH_SUCCEED( "no assertions" );
}

CATCH_TEST_CASE( "Variadic macros", "[variadic][sections]" )
{
    CATCH_SECTION( "Section with one argument" )
    {
        CATCH_SUCCEED( "no assertions" );
    }
}

