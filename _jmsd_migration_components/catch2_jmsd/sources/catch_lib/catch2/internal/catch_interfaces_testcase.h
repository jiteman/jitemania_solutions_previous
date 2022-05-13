#pragma once

#include <vector>

#include "catch_lib.h"


namespace Catch {

    class TestSpec;

    struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE ITestInvoker {
        virtual void invoke () const = 0;
        virtual ~ITestInvoker();
    };

    class TestCase;
    struct IConfig;

    struct ITestCaseRegistry {
        virtual ~ITestCaseRegistry();
        virtual std::vector<TestCase> const& getAllTests() const = 0;
        virtual std::vector<TestCase> const& getAllTestsSorted( IConfig const& config ) const = 0;
    };

//	bool isThrowSafe( TestCase const& testCase, IConfig const& config );
//	bool matchTest( TestCase const& testCase, TestSpec const& testSpec, IConfig const& config );
//	std::vector<TestCase> filterTests( std::vector<TestCase> const& testCases, TestSpec const& testSpec, IConfig const& config );
//	std::vector<TestCase> const& getAllTestCasesSorted( IConfig const& config );

}
