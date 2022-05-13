#pragma once

#include "catch_test_registry.h"
#include "catch_test_spec.h"
#include "catch_interfaces_config.h"

#include <vector>
#include <set>
#include <algorithm>
#include <ios>

namespace Catch {

    class TestCase;
    struct IConfig;

    std::vector<TestCase> sortTests( IConfig const& config, std::vector<TestCase> const& unsortedTestCases );

    bool isThrowSafe( TestCase const& testCase, IConfig const& config );
    bool matchTest( TestCase const& testCase, TestSpec const& testSpec, IConfig const& config );

    void enforceNoDuplicateTestCases( std::vector<TestCase> const& functions );

    std::vector<TestCase> filterTests( std::vector<TestCase> const& testCases, TestSpec const& testSpec, IConfig const& config );
    std::vector<TestCase> const& getAllTestCasesSorted( IConfig const& config );

    class TestRegistry : public ITestCaseRegistry {
    public:
        virtual ~TestRegistry() = default;

        virtual void registerTest( TestCase const& testCase );

        std::vector<TestCase> const& getAllTests() const override;
        std::vector<TestCase> const& getAllTestsSorted( IConfig const& config ) const override;

    private:
        std::vector<TestCase> m_functions;
        mutable RunTests::InWhatOrder m_currentSortOrder = RunTests::InDeclarationOrder;
        mutable std::vector<TestCase> m_sortedFunctions;
        std::size_t m_unnamedCount = 0;
        std::ios_base::Init m_ostreamInit; // Forces cout/ cerr to be initialised
    };

    ///////////////////////////////////////////////////////////////////////////

    class TestInvokerAsFunction : public ITestInvoker {
        void(*m_testAsFunction)();
    public:
        TestInvokerAsFunction( void(*testAsFunction)() ) noexcept;

        void invoke() const override;
    };


    std::string extractClassName( StringRef const& classOrQualifiedMethodName );

    ///////////////////////////////////////////////////////////////////////////


} // end namespace Catch
