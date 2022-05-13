#define CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER
#include "catch2/catch.hpp"

#include <tuple>

CATCH_TEST_CASE( "tuple<>", "[toString][tuple]" )
{
    typedef std::tuple<> type;
    CATCH_CHECK( "{ }" == ::Catch::Detail::stringify(type{}) );
    type value {};
    CATCH_CHECK( "{ }" == ::Catch::Detail::stringify(value) );
}

CATCH_TEST_CASE( "tuple<int>", "[toString][tuple]" )
{
    typedef std::tuple<int> type;
    CATCH_CHECK( "{ 0 }" == ::Catch::Detail::stringify(type{0}) );
}


CATCH_TEST_CASE( "tuple<float,int>", "[toString][tuple]" )
{
    typedef std::tuple<float,int> type;
    CATCH_CHECK( "1.2f" == ::Catch::Detail::stringify(float(1.2)) );
    CATCH_CHECK( "{ 1.2f, 0 }" == ::Catch::Detail::stringify(type{1.2f,0}) );
}

CATCH_TEST_CASE( "tuple<string,string>", "[toString][tuple]" )
{
    typedef std::tuple<std::string,std::string> type;
    CATCH_CHECK( "{ \"hello\", \"world\" }" == ::Catch::Detail::stringify(type{"hello","world"}) );
}

CATCH_TEST_CASE( "tuple<tuple<int>,tuple<>,float>", "[toString][tuple]" )
{
    typedef std::tuple<std::tuple<int>,std::tuple<>,float> type;
    type value { std::tuple<int>{42}, {}, 1.2f };
    CATCH_CHECK( "{ { 42 }, { }, 1.2f }" == ::Catch::Detail::stringify(value) );
}

CATCH_TEST_CASE( "tuple<nullptr,int,const char *>", "[toString][tuple]" )
{
    typedef std::tuple<std::nullptr_t,int,const char *> type;
    type value { nullptr, 42, "Catch me" };
    CATCH_CHECK( "{ nullptr, 42, \"Catch me\" }" == ::Catch::Detail::stringify(value) );
}

