#include "catch2/catch.hpp"

// Tests of generator implementation details
CATCH_TEST_CASE("Generators internals", "[generators][internals]") {
    using namespace Catch::Generators;

    CATCH_SECTION("Single value") {
        auto gen = value(123);
        CATCH_REQUIRE(gen.get() == 123);
        CATCH_REQUIRE_FALSE(gen.next());
    }
    CATCH_SECTION("Preset values") {
        auto gen = values({ 1, 3, 5 });
        CATCH_REQUIRE(gen.get() == 1);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 3);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 5);
        CATCH_REQUIRE_FALSE(gen.next());
    }
    CATCH_SECTION("Generator combinator") {
        auto gen = makeGenerators(1, 5, values({ 2, 4 }), 0);
        CATCH_REQUIRE(gen.get() == 1);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 5);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 2);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 4);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 0);
        CATCH_REQUIRE_FALSE(gen.next());
    }
    CATCH_SECTION("Explicitly typed generator sequence") {
        auto gen = makeGenerators(as<std::string>{}, "aa", "bb", "cc");
        // This just checks that the type is std::string:
        CATCH_REQUIRE(gen.get().size() == 2);
        // Iterate over the generator
        CATCH_REQUIRE(gen.get() == "aa");
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == "bb");
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == "cc");
        CATCH_REQUIRE_FALSE(gen.next());
    }
    CATCH_SECTION("Filter generator") {
        // Normal usage
        auto gen = filter([] (int i) { return i != 2; }, values({ 2, 1, 2, 3, 2, 2 }));
        CATCH_REQUIRE(gen.get() == 1);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 3);
        CATCH_REQUIRE_FALSE(gen.next());

        // Completely filtered-out generator should throw on construction
        CATCH_REQUIRE_THROWS_AS(filter([] (int) { return false; }, value(1)), Catch::GeneratorException);
    }
    CATCH_SECTION("Take generator") {
        CATCH_SECTION("Take less") {
            auto gen = take(2, values({ 1, 2, 3 }));
            CATCH_REQUIRE(gen.get() == 1);
            CATCH_REQUIRE(gen.next());
            CATCH_REQUIRE(gen.get() == 2);
            CATCH_REQUIRE_FALSE(gen.next());
        }
        CATCH_SECTION("Take more") {
            auto gen = take(2, value(1));
            CATCH_REQUIRE(gen.get() == 1);
            CATCH_REQUIRE_FALSE(gen.next());
        }
    }
    CATCH_SECTION("Map with explicit return type") {
        auto gen = map<double>([] (int i) {return 2.0 * i; }, values({ 1, 2, 3 }));
        CATCH_REQUIRE(gen.get() == 2.0);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 4.0);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 6.0);
        CATCH_REQUIRE_FALSE(gen.next());
    }
    CATCH_SECTION("Map with deduced return type") {
        auto gen = map([] (int i) {return 2.0 * i; }, values({ 1, 2, 3 }));
        CATCH_REQUIRE(gen.get() == 2.0);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 4.0);
        CATCH_REQUIRE(gen.next());
        CATCH_REQUIRE(gen.get() == 6.0);
        CATCH_REQUIRE_FALSE(gen.next());
    }
    CATCH_SECTION("Repeat") {
        CATCH_SECTION("Singular repeat") {
            auto gen = repeat(1, value(3));
            CATCH_REQUIRE(gen.get() == 3);
            CATCH_REQUIRE_FALSE(gen.next());
        }
        CATCH_SECTION("Actual repeat") {
            auto gen = repeat(2, values({ 1, 2, 3 }));
            CATCH_REQUIRE(gen.get() == 1);
            CATCH_REQUIRE(gen.next());
            CATCH_REQUIRE(gen.get() == 2);
            CATCH_REQUIRE(gen.next());
            CATCH_REQUIRE(gen.get() == 3);
            CATCH_REQUIRE(gen.next());
            CATCH_REQUIRE(gen.get() == 1);
            CATCH_REQUIRE(gen.next());
            CATCH_REQUIRE(gen.get() == 2);
            CATCH_REQUIRE(gen.next());
            CATCH_REQUIRE(gen.get() == 3);
            CATCH_REQUIRE_FALSE(gen.next());
        }
    }
    CATCH_SECTION("Range") {
        CATCH_SECTION("Positive auto step") {
            CATCH_SECTION("Integer") {
                auto gen = range(-2, 2);
                CATCH_REQUIRE(gen.get() == -2);
                CATCH_REQUIRE(gen.next());
                CATCH_REQUIRE(gen.get() == -1);
                CATCH_REQUIRE(gen.next());
                CATCH_REQUIRE(gen.get() == 0);
                CATCH_REQUIRE(gen.next());
                CATCH_REQUIRE(gen.get() == 1);
                CATCH_REQUIRE_FALSE(gen.next());
            }
        }
        CATCH_SECTION("Negative auto step") {
            CATCH_SECTION("Integer") {
                auto gen = range(2, -2);
                CATCH_REQUIRE(gen.get() == 2);
                CATCH_REQUIRE(gen.next());
                CATCH_REQUIRE(gen.get() == 1);
                CATCH_REQUIRE(gen.next());
                CATCH_REQUIRE(gen.get() == 0);
                CATCH_REQUIRE(gen.next());
                CATCH_REQUIRE(gen.get() == -1);
                CATCH_REQUIRE_FALSE(gen.next());
            }
        }
        CATCH_SECTION("Positive manual step") {
            CATCH_SECTION("Integer") {
                CATCH_SECTION("Exact") {
                    auto gen = range(-7, 5, 3);
                    CATCH_REQUIRE(gen.get() == -7);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -4);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -1);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 2);
                    CATCH_REQUIRE_FALSE(gen.next());
                }
                CATCH_SECTION("Slightly over end") {
                    auto gen = range(-7, 4, 3);
                    CATCH_REQUIRE(gen.get() == -7);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -4);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -1);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 2);
                    CATCH_REQUIRE_FALSE(gen.next());
                }
                CATCH_SECTION("Slightly under end") {
                    auto gen = range(-7, 6, 3);
                    CATCH_REQUIRE(gen.get() == -7);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -4);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -1);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 2);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 5);
                    CATCH_REQUIRE_FALSE(gen.next());
                }
            }

            CATCH_SECTION("Floating Point") {
                CATCH_SECTION("Exact") {
                    const auto rangeStart = -1.;
                    const auto rangeEnd = 1.;
                    const auto step = .1;

                    auto gen = range(rangeStart, rangeEnd, step);
                    auto expected = rangeStart;
                    while( (rangeEnd - expected) > step ) {
                        CATCH_INFO( "Current expected value is " << expected )
                        CATCH_REQUIRE(gen.get() == Approx(expected));
                        CATCH_REQUIRE(gen.next());

                        expected += step;
                    }
                    CATCH_REQUIRE(gen.get() == Approx( rangeEnd ) );
                    CATCH_REQUIRE_FALSE(gen.next());
                }
                CATCH_SECTION("Slightly over end") {
                    const auto rangeStart = -1.;
                    const auto rangeEnd = 1.;
                    const auto step = .3;

                    auto gen = range(rangeStart, rangeEnd, step);
                    auto expected = rangeStart;
                    while( (rangeEnd - expected) > step ) {
                       CATCH_INFO( "Current expected value is " << expected )
                       CATCH_REQUIRE(gen.get() == Approx(expected));
                       CATCH_REQUIRE(gen.next());

                       expected += step;
                    }
                    CATCH_REQUIRE_FALSE(gen.next());
                }
                CATCH_SECTION("Slightly under end") {
                    const auto rangeStart = -1.;
                    const auto rangeEnd = .9;
                    const auto step = .3;

                    auto gen = range(rangeStart, rangeEnd, step);
                    auto expected = rangeStart;
                    while( (rangeEnd - expected) > step ) {
                       CATCH_INFO( "Current expected value is " << expected )
                       CATCH_REQUIRE(gen.get() == Approx(expected));
                       CATCH_REQUIRE(gen.next());

                       expected += step;
                    }
                    CATCH_REQUIRE_FALSE(gen.next());
                }
            }
        }
        CATCH_SECTION("Negative manual step") {
            CATCH_SECTION("Integer") {
                CATCH_SECTION("Exact") {
                    auto gen = range(5, -7, -3);
                    CATCH_REQUIRE(gen.get() == 5);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 2);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -1);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -4);
                    CATCH_REQUIRE_FALSE(gen.next());
                }
                CATCH_SECTION("Slightly over end") {
                    auto gen = range(5, -6, -3);
                    CATCH_REQUIRE(gen.get() == 5);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 2);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -1);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -4);
                    CATCH_REQUIRE_FALSE(gen.next());
                }
                CATCH_SECTION("Slightly under end") {
                    auto gen = range(5, -8, -3);
                    CATCH_REQUIRE(gen.get() == 5);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == 2);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -1);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -4);
                    CATCH_REQUIRE(gen.next());
                    CATCH_REQUIRE(gen.get() == -7);
                    CATCH_REQUIRE_FALSE(gen.next());
                }
            }
        }
    }

}


// todo: uncopyable type used in a generator
//  idea: uncopyable tag type for a stupid generator

namespace {
struct non_copyable {
    non_copyable() = default;
    non_copyable(non_copyable const&) = delete;
    non_copyable& operator=(non_copyable const&) = delete;
    int value = -1;
};

// This class shows how to implement a simple generator for Catch tests
class TestGen : public Catch::Generators::IGenerator<int> {
    int current_number;
public:

    TestGen(non_copyable const& nc):
        current_number(nc.value) {}

    int const& get() const override;
    bool next() override {
        return false;
    }
};

// Avoids -Wweak-vtables
int const& TestGen::get() const {
    return current_number;
}

}

CATCH_TEST_CASE("GENERATE capture macros", "[generators][internals][approvals]") {
    auto value = GENERATE(take(10, random(0, 10)));

    non_copyable nc; nc.value = value;
    // neither `GENERATE_COPY` nor plain `GENERATE` would compile here
    auto value2 = GENERATE_REF(Catch::Generators::GeneratorWrapper<int>(std::unique_ptr<Catch::Generators::IGenerator<int>>(new TestGen(nc))));
    CATCH_REQUIRE(value == value2);
}

CATCH_TEST_CASE("#1809 - GENERATE_COPY and SingleValueGenerator does not compile", "[generators][compilation][approvals]") {
    // Verify Issue #1809 fix, only needs to compile.
    auto a = GENERATE_COPY(1, 2);
    (void)a;
    auto b = GENERATE_COPY(as<long>{}, 1, 2);
    (void)b;
    int i = 1;
    int j = 2;
    auto c = GENERATE_COPY(i, j);
    (void)c;
    auto d = GENERATE_COPY(as<long>{}, i, j);
    (void)d;
    CATCH_SUCCEED();
}

CATCH_TEST_CASE("Multiple random generators in one test case output different values", "[generators][internals][approvals]") {
    CATCH_SECTION("Integer") {
        auto random1 = Catch::Generators::random(0, 1000);
        auto random2 = Catch::Generators::random(0, 1000);
        size_t same = 0;
        for (size_t i = 0; i < 1000; ++i) {
            same += random1.get() == random2.get();
            random1.next(); random2.next();
        }
        // 0.5% seems like a sane bound for random identical elements within 1000 runs
        CATCH_REQUIRE(same < 5);
    }
    CATCH_SECTION("Float") {
        auto random1 = Catch::Generators::random(0., 1000.);
        auto random2 = Catch::Generators::random(0., 1000.);
        size_t same = 0;
        for (size_t i = 0; i < 1000; ++i) {
            same += random1.get() == random2.get();
            random1.next(); random2.next();
        }
        // 0.5% seems like a sane bound for random identical elements within 1000 runs
        CATCH_REQUIRE(same < 5);
    }
}
