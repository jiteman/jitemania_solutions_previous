/*
 *  Created by Phil on 13/5/2013.
 *  Copyright 2014 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"
#include "catch2/internal/catch_test_spec_parser.h"
#include "catch2/internal/catch_config.hpp"
#include "catch2/internal/catch_commandline.h"

#ifdef __clang__
#   pragma clang diagnostic ignored "-Wc++98-compat"
#endif

inline Catch::TestCase fakeTestCase(const char* name, const char* desc = "") { return Catch::makeTestCase(nullptr, "", { name, desc }, CATCH_INTERNAL_LINEINFO); }

CATCH_TEST_CASE( "Parse test names and tags", "[command-line][test-spec]" ) {

    using Catch::parseTestSpec;
    using Catch::TestSpec;

    Catch::TestCase tcA = fakeTestCase( "a" );
    Catch::TestCase tcB = fakeTestCase( "b", "[one][x]" );
    Catch::TestCase tcC = fakeTestCase( "longer name with spaces", "[two][three][.][x]" );
    Catch::TestCase tcD = fakeTestCase( "zlonger name with spacesz" );

    CATCH_SECTION( "Empty test spec should have no filters" ) {
        TestSpec spec;
        CATCH_CHECK( spec.hasFilters() == false );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
    }

    CATCH_SECTION( "Test spec from empty string should have no filters" ) {
        TestSpec spec = parseTestSpec( "" );
        CATCH_CHECK( spec.hasFilters() == false );
        CATCH_CHECK( spec.matches(tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
    }

    CATCH_SECTION( "Test spec from just a comma should have no filters" ) {
        TestSpec spec = parseTestSpec( "," );
        CATCH_CHECK( spec.hasFilters() == false );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
    }

    CATCH_SECTION( "Test spec from name should have one filter" ) {
        TestSpec spec = parseTestSpec( "b" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == true );
    }

    CATCH_SECTION( "Test spec from quoted name should have one filter" ) {
        TestSpec spec = parseTestSpec( "\"b\"" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == true );
    }

    CATCH_SECTION( "Test spec from name should have one filter" ) {
        TestSpec spec = parseTestSpec( "b" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == false );
    }

    CATCH_SECTION( "Wildcard at the start" ) {
        TestSpec spec = parseTestSpec( "*spaces" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == false );
        CATCH_CHECK( parseTestSpec( "*a" ).matches( tcA ) == true );
    }
    CATCH_SECTION( "Wildcard at the end" ) {
        TestSpec spec = parseTestSpec( "long*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == false );
        CATCH_CHECK( parseTestSpec( "a*" ).matches( tcA ) == true );
    }
    CATCH_SECTION( "Wildcard at both ends" ) {
        TestSpec spec = parseTestSpec( "*name*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == true );
        CATCH_CHECK( parseTestSpec( "*a*" ).matches( tcA ) == true );
    }
    CATCH_SECTION( "Redundant wildcard at the start" ) {
        TestSpec spec = parseTestSpec( "*a" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == false );
    }
    CATCH_SECTION( "Redundant wildcard at the end" ) {
        TestSpec spec = parseTestSpec( "a*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == false );
    }
    CATCH_SECTION( "Redundant wildcard at both ends" ) {
        TestSpec spec = parseTestSpec( "*a*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == false );
    }
    CATCH_SECTION( "Wildcard at both ends, redundant at start" ) {
        TestSpec spec = parseTestSpec( "*longer*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == true );
    }
    CATCH_SECTION( "Just wildcard" ) {
        TestSpec spec = parseTestSpec( "*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == true );
    }

    CATCH_SECTION( "Single tag" ) {
        TestSpec spec = parseTestSpec( "[one]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == false );
    }
    CATCH_SECTION( "Single tag, two matches" ) {
        TestSpec spec = parseTestSpec( "[x]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == true );
    }
    CATCH_SECTION( "Two tags" ) {
        TestSpec spec = parseTestSpec( "[two][x]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
    }
    CATCH_SECTION( "Two tags, spare separated" ) {
        TestSpec spec = parseTestSpec( "[two] [x]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
    }
    CATCH_SECTION( "Wildcarded name and tag" ) {
        TestSpec spec = parseTestSpec( "*name*[x]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "Single tag exclusion" ) {
        TestSpec spec = parseTestSpec( "~[one]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
    }
    CATCH_SECTION( "One tag exclusion and one tag inclusion" ) {
        TestSpec spec = parseTestSpec( "~[two][x]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == false );
    }
    CATCH_SECTION( "One tag exclusion and one wldcarded name inclusion" ) {
        TestSpec spec = parseTestSpec( "~[two]*name*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == false );
        CATCH_CHECK( spec.matches( tcD ) == true );
    }
    CATCH_SECTION( "One tag exclusion, using exclude:, and one wldcarded name inclusion" ) {
        TestSpec spec = parseTestSpec( "exclude:[two]*name*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == false );
        CATCH_CHECK( spec.matches( tcD ) == true );
    }
    CATCH_SECTION( "name exclusion" ) {
        TestSpec spec = parseTestSpec( "~b" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == true );
    }
    CATCH_SECTION( "wildcarded name exclusion" ) {
        TestSpec spec = parseTestSpec( "~*name*" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == false );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "wildcarded name exclusion with tag inclusion" ) {
        TestSpec spec = parseTestSpec( "~*name*,[three]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "wildcarded name exclusion, using exclude:, with tag inclusion" ) {
        TestSpec spec = parseTestSpec( "exclude:*name*,[three]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == true );
        CATCH_CHECK( spec.matches( tcB ) == true );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "two wildcarded names" ) {
        TestSpec spec = parseTestSpec( "\"longer*\"\"*spaces\"" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == true );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "empty tag" ) {
        TestSpec spec = parseTestSpec( "[]" );
        CATCH_CHECK( spec.hasFilters() == false );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == false );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "empty quoted name" ) {
        TestSpec spec = parseTestSpec( "\"\"" );
        CATCH_CHECK( spec.hasFilters() == false );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == false );
        CATCH_CHECK( spec.matches( tcD ) == false );
    }
    CATCH_SECTION( "quoted string followed by tag exclusion" ) {
        TestSpec spec = parseTestSpec( "\"*name*\"~[.]" );
        CATCH_CHECK( spec.hasFilters() == true );
        CATCH_CHECK( spec.matches( tcA ) == false );
        CATCH_CHECK( spec.matches( tcB ) == false );
        CATCH_CHECK( spec.matches( tcC ) == false );
        CATCH_CHECK( spec.matches( tcD ) == true );
    }
    CATCH_SECTION( "Leading and trailing spaces in test spec" ) {
        TestSpec spec = parseTestSpec( "\"  aardvark \"" );
        CATCH_CHECK( spec.matches( fakeTestCase( "  aardvark " ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( "  aardvark" ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( " aardvark " ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( "aardvark " ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( "aardvark" ) ) );
    }
    CATCH_SECTION( "Leading and trailing spaces in test name" ) {
        TestSpec spec = parseTestSpec( "aardvark" );
        CATCH_CHECK( spec.matches( fakeTestCase( "  aardvark " ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( "  aardvark" ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( " aardvark " ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( "aardvark " ) ) );
        CATCH_CHECK( spec.matches( fakeTestCase( "aardvark" ) ) );
    }
    CATCH_SECTION("Shortened hide tags are split apart when parsing") {
        TestSpec spec = parseTestSpec("[.foo]");
        CATCH_CHECK(spec.matches(fakeTestCase("hidden and foo", "[.][foo]")));
        CATCH_CHECK_FALSE(spec.matches(fakeTestCase("only foo", "[foo]")));
    }
    CATCH_SECTION("Shortened hide tags also properly handle exclusion") {
        TestSpec spec = parseTestSpec("~[.foo]");
        CATCH_CHECK_FALSE(spec.matches(fakeTestCase("hidden and foo", "[.][foo]")));
        CATCH_CHECK_FALSE(spec.matches(fakeTestCase("only foo", "[foo]")));
        CATCH_CHECK_FALSE(spec.matches(fakeTestCase("only hidden", "[.]")));
        CATCH_CHECK(spec.matches(fakeTestCase("neither foo nor hidden", "[bar]")));
    }
}

CATCH_TEST_CASE( "Process can be configured on command line", "[config][command-line]" ) {

#ifndef CATCH_CONFIG_DISABLE_MATCHERS
    using namespace Catch::Matchers;
#endif

    Catch::ConfigData config;
    auto cli = Catch::makeCommandLineParser(config);

    CATCH_SECTION("empty args don't cause a crash") {
        auto result = cli.parse({""});
        CATCH_CHECK(result);
        CATCH_CHECK(config.processName == "");
    }

    CATCH_SECTION("default - no arguments") {
        auto result = cli.parse({"test"});
        CATCH_CHECK(result);
        CATCH_CHECK(config.processName == "test");
        CATCH_CHECK(config.shouldDebugBreak == false);
        CATCH_CHECK(config.abortAfter == -1);
        CATCH_CHECK(config.noThrow == false);
        CATCH_CHECK(config.reporterName == "console");

        Catch::Config cfg(config);
        CATCH_CHECK_FALSE(cfg.hasTestFilters());
    }

    CATCH_SECTION("test lists") {
        CATCH_SECTION("Specify one test case using") {
            auto result = cli.parse({"test", "test1"});
            CATCH_CHECK(result);

            Catch::Config cfg(config);
            CATCH_REQUIRE(cfg.hasTestFilters());
            CATCH_REQUIRE(cfg.testSpec().matches(fakeTestCase("notIncluded")) == false);
            CATCH_REQUIRE(cfg.testSpec().matches(fakeTestCase("test1")));
        }
        CATCH_SECTION("Specify one test case exclusion using exclude:") {
            auto result = cli.parse({"test", "exclude:test1"});
            CATCH_CHECK(result);

            Catch::Config cfg(config);
            CATCH_REQUIRE(cfg.hasTestFilters());
            CATCH_REQUIRE(cfg.testSpec().matches(fakeTestCase("test1")) == false);
            CATCH_REQUIRE(cfg.testSpec().matches(fakeTestCase("alwaysIncluded")));
        }

        CATCH_SECTION("Specify one test case exclusion using ~") {
            auto result = cli.parse({"test", "~test1"});
            CATCH_CHECK(result);

            Catch::Config cfg(config);
            CATCH_REQUIRE(cfg.hasTestFilters());
            CATCH_REQUIRE(cfg.testSpec().matches(fakeTestCase("test1")) == false);
            CATCH_REQUIRE(cfg.testSpec().matches(fakeTestCase("alwaysIncluded")));
        }

    }

    CATCH_SECTION("reporter") {
        CATCH_SECTION("-r/console") {
            CATCH_CHECK(cli.parse({"test", "-r", "console"}));

            CATCH_REQUIRE(config.reporterName == "console");
        }
        CATCH_SECTION("-r/xml") {
            CATCH_CHECK(cli.parse({"test", "-r", "xml"}));

            CATCH_REQUIRE(config.reporterName == "xml");
        }
        CATCH_SECTION("--reporter/junit") {
            CATCH_CHECK(cli.parse({"test", "--reporter", "junit"}));

            CATCH_REQUIRE(config.reporterName == "junit");
        }
        CATCH_SECTION("Only one reporter is accepted") {
            CATCH_REQUIRE_FALSE(cli.parse({ "test", "-r", "xml", "-r", "junit" }));
        }
        CATCH_SECTION("must match one of the available ones") {
            auto result = cli.parse({"test", "--reporter", "unsupported"});
            CATCH_CHECK(!result);

#ifndef CATCH_CONFIG_DISABLE_MATCHERS
            CATCH_REQUIRE_THAT(result.errorMessage(), Contains("Unrecognized reporter"));
#endif
        }
    }

    CATCH_SECTION("debugger") {
        CATCH_SECTION("-b") {
            CATCH_CHECK(cli.parse({"test", "-b"}));

            CATCH_REQUIRE(config.shouldDebugBreak == true);
        }
        CATCH_SECTION("--break") {
            CATCH_CHECK(cli.parse({"test", "--break"}));

            CATCH_REQUIRE(config.shouldDebugBreak);
        }
    }


    CATCH_SECTION("abort") {
        CATCH_SECTION("-a aborts after first failure") {
            CATCH_CHECK(cli.parse({"test", "-a"}));

            CATCH_REQUIRE(config.abortAfter == 1);
        }
        CATCH_SECTION("-x 2 aborts after two failures") {
            CATCH_CHECK(cli.parse({"test", "-x", "2"}));

            CATCH_REQUIRE(config.abortAfter == 2);
        }
        CATCH_SECTION("-x must be numeric") {
            auto result = cli.parse({"test", "-x", "oops"});
            CATCH_CHECK(!result);

#ifndef CATCH_CONFIG_DISABLE_MATCHERS
            CATCH_REQUIRE_THAT(result.errorMessage(), Contains("convert") && Contains("oops"));
#endif
        }

     CATCH_SECTION("wait-for-keypress") {
        CATCH_SECTION("Accepted options") {
            using tuple_type = std::tuple<char const*, Catch::WaitForKeypress::When>;
            auto input = GENERATE(table<char const*, Catch::WaitForKeypress::When>({
                tuple_type{"never", Catch::WaitForKeypress::Never},
                tuple_type{"start", Catch::WaitForKeypress::BeforeStart},
                tuple_type{"exit",  Catch::WaitForKeypress::BeforeExit},
                tuple_type{"both",  Catch::WaitForKeypress::BeforeStartAndExit},
            }));
            CATCH_CHECK(cli.parse({"test", "--wait-for-keypress", std::get<0>(input)}));

            CATCH_REQUIRE(config.waitForKeypress == std::get<1>(input));
        }

        CATCH_SECTION("invalid options are reported") {
            auto result = cli.parse({"test", "--wait-for-keypress", "sometimes"});
            CATCH_CHECK(!result);

#ifndef CATCH_CONFIG_DISABLE_MATCHERS
            CATCH_REQUIRE_THAT(result.errorMessage(), Contains("never") && Contains("both"));
#endif
        }
    }
   }

    CATCH_SECTION("nothrow") {
        CATCH_SECTION("-e") {
            CATCH_CHECK(cli.parse({"test", "-e"}));

            CATCH_REQUIRE(config.noThrow);
        }
        CATCH_SECTION("--nothrow") {
            CATCH_CHECK(cli.parse({"test", "--nothrow"}));

            CATCH_REQUIRE(config.noThrow);
        }
    }

    CATCH_SECTION("output filename") {
        CATCH_SECTION("-o filename") {
            CATCH_CHECK(cli.parse({"test", "-o", "filename.ext"}));

            CATCH_REQUIRE(config.outputFilename == "filename.ext");
        }
        CATCH_SECTION("--out") {
            CATCH_CHECK(cli.parse({"test", "--out", "filename.ext"}));

            CATCH_REQUIRE(config.outputFilename == "filename.ext");
        }
    }

    CATCH_SECTION("combinations") {
        CATCH_SECTION("Single character flags can be combined") {
            CATCH_CHECK(cli.parse({"test", "-abe"}));

            CATCH_CHECK(config.abortAfter == 1);
            CATCH_CHECK(config.shouldDebugBreak);
            CATCH_CHECK(config.noThrow == true);
        }
    }


    CATCH_SECTION( "use-colour") {

        using Catch::UseColour;

        CATCH_SECTION( "without option" ) {
            CATCH_CHECK(cli.parse({"test"}));

            CATCH_REQUIRE( config.useColour == UseColour::Auto );
        }

        CATCH_SECTION( "auto" ) {
            CATCH_CHECK(cli.parse({"test", "--use-colour", "auto"}));

            CATCH_REQUIRE( config.useColour == UseColour::Auto );
        }

        CATCH_SECTION( "yes" ) {
            CATCH_CHECK(cli.parse({"test", "--use-colour", "yes"}));

            CATCH_REQUIRE( config.useColour == UseColour::Yes );
        }

        CATCH_SECTION( "no" ) {
            CATCH_CHECK(cli.parse({"test", "--use-colour", "no"}));

            CATCH_REQUIRE( config.useColour == UseColour::No );
        }

        CATCH_SECTION( "error" ) {
            auto result = cli.parse({"test", "--use-colour", "wrong"});
            CATCH_CHECK( !result );
#ifndef CATCH_CONFIG_DISABLE_MATCHERS
            CATCH_CHECK_THAT( result.errorMessage(), Contains( "colour mode must be one of" ) );
#endif
        }
    }

    CATCH_SECTION("Benchmark options") {
        CATCH_SECTION("samples") {
            CATCH_CHECK(cli.parse({ "test", "--benchmark-samples=200" }));

            CATCH_REQUIRE(config.benchmarkSamples == 200);
        }

        CATCH_SECTION("resamples") {
            CATCH_CHECK(cli.parse({ "test", "--benchmark-resamples=20000" }));

            CATCH_REQUIRE(config.benchmarkResamples == 20000);
        }

        CATCH_SECTION("confidence-interval") {
            CATCH_CHECK(cli.parse({ "test", "--benchmark-confidence-interval=0.99" }));

            CATCH_REQUIRE(config.benchmarkConfidenceInterval == Catch::Detail::Approx(0.99));
        }

        CATCH_SECTION("no-analysis") {
            CATCH_CHECK(cli.parse({ "test", "--benchmark-no-analysis" }));

            CATCH_REQUIRE(config.benchmarkNoAnalysis);
        }

        CATCH_SECTION("warmup-time") {
            CATCH_CHECK(cli.parse({ "test", "--benchmark-warmup-time=10" }));

            CATCH_REQUIRE(config.benchmarkWarmupTime == 10);
        }
    }
}

CATCH_TEST_CASE("Test with special, characters \"in name", "[cli][regression]") {
    // This test case succeeds if we can invoke it from the CLI
    CATCH_SUCCEED();
}
