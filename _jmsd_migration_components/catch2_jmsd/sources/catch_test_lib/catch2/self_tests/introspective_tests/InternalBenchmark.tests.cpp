/*
 *  Created by Joachim on 16/04/2019.
 *  Adapted from donated nonius code.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch2/catch.hpp"
#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)
namespace {
    struct manual_clock {
    public:
        using duration = std::chrono::nanoseconds;
        using time_point = std::chrono::time_point<manual_clock, duration>;
        using rep = duration::rep;
        using period = duration::period;
        enum { is_steady = true };

        static time_point now() {
            return time_point(duration(tick()));
        }

        static void advance(int ticks = 1) {
            tick() += ticks;
        }

    private:
        static rep& tick() {
            static rep the_tick = 0;
            return the_tick;
        }
    };

    struct counting_clock {
    public:
        using duration = std::chrono::nanoseconds;
        using time_point = std::chrono::time_point<counting_clock, duration>;
        using rep = duration::rep;
        using period = duration::period;
        enum { is_steady = true };

        static time_point now() {
            static rep ticks = 0;
            return time_point(duration(ticks += rate()));
        }

        static void set_rate(rep new_rate) { rate() = new_rate; }

    private:
        static rep& rate() {
            static rep the_rate = 1;
            return the_rate;
        }
    };

    struct TestChronometerModel : Catch::Benchmark::Detail::ChronometerConcept {
        int started = 0;
        int finished = 0;

        void start() override { ++started; }
        void finish() override { ++finished; }
    };
} // namespace

CATCH_TEST_CASE("warmup", "[benchmark]") {
    auto rate = 1000;
    counting_clock::set_rate(rate);

    auto start = counting_clock::now();
    auto iterations = Catch::Benchmark::Detail::warmup<counting_clock>();
    auto end = counting_clock::now();

    CATCH_REQUIRE((iterations * rate) > Catch::Benchmark::Detail::warmup_time.count());
    CATCH_REQUIRE((end - start) > Catch::Benchmark::Detail::warmup_time);
}

CATCH_TEST_CASE("resolution", "[benchmark]") {
    auto rate = 1000;
    counting_clock::set_rate(rate);

    size_t count = 10;
    auto res = Catch::Benchmark::Detail::resolution<counting_clock>(static_cast<int>(count));

    CATCH_REQUIRE(res.size() == count);

    for (size_t i = 1; i < count; ++i) {
        CATCH_REQUIRE(res[i] == rate);
    }
}

CATCH_TEST_CASE("estimate_clock_resolution", "[benchmark]") {
    auto rate = 1000;
    counting_clock::set_rate(rate);

    int iters = 160000;
    auto res = Catch::Benchmark::Detail::estimate_clock_resolution<counting_clock>(iters);

    CATCH_REQUIRE(res.mean.count() == rate);
    CATCH_REQUIRE(res.outliers.total() == 0);
}

CATCH_TEST_CASE("benchmark function call", "[benchmark]") {
    CATCH_SECTION("without chronometer") {
        auto called = 0;
        auto model = TestChronometerModel{};
        auto meter = Catch::Benchmark::Chronometer{ model, 1 };
        auto fn = Catch::Benchmark::Detail::BenchmarkFunction{ [&] {
                CATCH_CHECK(model.started == 1);
                CATCH_CHECK(model.finished == 0);
                ++called;
            } };

        fn(meter);

        CATCH_CHECK(model.started == 1);
        CATCH_CHECK(model.finished == 1);
        CATCH_CHECK(called == 1);
    }

    CATCH_SECTION("with chronometer") {
        auto called = 0;
        auto model = TestChronometerModel{};
        auto meter = Catch::Benchmark::Chronometer{ model, 1 };
        auto fn = Catch::Benchmark::Detail::BenchmarkFunction{ [&](Catch::Benchmark::Chronometer) {
                CATCH_CHECK(model.started == 0);
                CATCH_CHECK(model.finished == 0);
                ++called;
            } };

        fn(meter);

        CATCH_CHECK(model.started == 0);
        CATCH_CHECK(model.finished == 0);
        CATCH_CHECK(called == 1);
    }
}

CATCH_TEST_CASE("uniform samples", "[benchmark]") {
    std::vector<double> samples(100);
    std::fill(samples.begin(), samples.end(), 23);

    using it = std::vector<double>::iterator;
    auto e = Catch::Benchmark::Detail::bootstrap(0.95, samples.begin(), samples.end(), samples, [](it a, it b) {
        auto sum = std::accumulate(a, b, 0.);
        return sum / (b - a);
    });
    CATCH_CHECK(e.point == 23);
    CATCH_CHECK(e.upper_bound == 23);
    CATCH_CHECK(e.lower_bound == 23);
    CATCH_CHECK(e.confidence_interval == 0.95);
}


CATCH_TEST_CASE("normal_cdf", "[benchmark]") {
    using Catch::Benchmark::Detail::normal_cdf;
    CATCH_CHECK(normal_cdf(0.000000) == Approx(0.50000000000000000));
    CATCH_CHECK(normal_cdf(1.000000) == Approx(0.84134474606854293));
    CATCH_CHECK(normal_cdf(-1.000000) == Approx(0.15865525393145705));
    CATCH_CHECK(normal_cdf(2.809729) == Approx(0.99752083845315409));
    CATCH_CHECK(normal_cdf(-1.352570) == Approx(0.08809652095066035));
}

CATCH_TEST_CASE("erfc_inv", "[benchmark]") {
    using Catch::Benchmark::Detail::erfc_inv;
    CATCH_CHECK(erfc_inv(1.103560) == Approx(-0.09203687623843015));
    CATCH_CHECK(erfc_inv(1.067400) == Approx(-0.05980291115763361));
    CATCH_CHECK(erfc_inv(0.050000) == Approx(1.38590382434967796));
}

CATCH_TEST_CASE("normal_quantile", "[benchmark]") {
    using Catch::Benchmark::Detail::normal_quantile;
    CATCH_CHECK(normal_quantile(0.551780) == Approx(0.13015979861484198));
    CATCH_CHECK(normal_quantile(0.533700) == Approx(0.08457408802851875));
    CATCH_CHECK(normal_quantile(0.025000) == Approx(-1.95996398454005449));
}


CATCH_TEST_CASE("mean", "[benchmark]") {
    std::vector<double> x{ 10., 20., 14., 16., 30., 24. };

    auto m = Catch::Benchmark::Detail::mean(x.begin(), x.end());

    CATCH_REQUIRE(m == 19.);
}

CATCH_TEST_CASE("weighted_average_quantile", "[benchmark]") {
    std::vector<double> x{ 10., 20., 14., 16., 30., 24. };

    auto q1 = Catch::Benchmark::Detail::weighted_average_quantile(1, 4, x.begin(), x.end());
    auto med = Catch::Benchmark::Detail::weighted_average_quantile(1, 2, x.begin(), x.end());
    auto q3 = Catch::Benchmark::Detail::weighted_average_quantile(3, 4, x.begin(), x.end());

    CATCH_REQUIRE(q1 == 14.5);
    CATCH_REQUIRE(med == 18.);
    CATCH_REQUIRE(q3 == 23.);
}

CATCH_TEST_CASE("classify_outliers", "[benchmark]") {
    auto require_outliers = [](Catch::Benchmark::OutlierClassification o, int los, int lom, int him, int his) {
        CATCH_REQUIRE(o.low_severe == los);
        CATCH_REQUIRE(o.low_mild == lom);
        CATCH_REQUIRE(o.high_mild == him);
        CATCH_REQUIRE(o.high_severe == his);
        CATCH_REQUIRE(o.total() == los + lom + him + his);
    };

    CATCH_SECTION("none") {
        std::vector<double> x{ 10., 20., 14., 16., 30., 24. };

        auto o = Catch::Benchmark::Detail::classify_outliers(x.begin(), x.end());

        CATCH_REQUIRE(o.samples_seen == static_cast<int>(x.size()));
        require_outliers(o, 0, 0, 0, 0);
    }
    CATCH_SECTION("low severe") {
        std::vector<double> x{ -12., 20., 14., 16., 30., 24. };

        auto o = Catch::Benchmark::Detail::classify_outliers(x.begin(), x.end());

        CATCH_REQUIRE(o.samples_seen == static_cast<int>(x.size()));
        require_outliers(o, 1, 0, 0, 0);
    }
    CATCH_SECTION("low mild") {
        std::vector<double> x{ 1., 20., 14., 16., 30., 24. };

        auto o = Catch::Benchmark::Detail::classify_outliers(x.begin(), x.end());

        CATCH_REQUIRE(o.samples_seen == static_cast<int>(x.size()));
        require_outliers(o, 0, 1, 0, 0);
    }
    CATCH_SECTION("high mild") {
        std::vector<double> x{ 10., 20., 14., 16., 36., 24. };

        auto o = Catch::Benchmark::Detail::classify_outliers(x.begin(), x.end());

        CATCH_REQUIRE(o.samples_seen == static_cast<int>(x.size()));
        require_outliers(o, 0, 0, 1, 0);
    }
    CATCH_SECTION("high severe") {
        std::vector<double> x{ 10., 20., 14., 16., 49., 24. };

        auto o = Catch::Benchmark::Detail::classify_outliers(x.begin(), x.end());

        CATCH_REQUIRE(o.samples_seen == static_cast<int>(x.size()));
        require_outliers(o, 0, 0, 0, 1);
    }
    CATCH_SECTION("mixed") {
        std::vector<double> x{ -20., 20., 14., 16., 39., 24. };

        auto o = Catch::Benchmark::Detail::classify_outliers(x.begin(), x.end());

        CATCH_REQUIRE(o.samples_seen == static_cast<int>(x.size()));
        require_outliers(o, 1, 0, 1, 0);
    }
}

CATCH_TEST_CASE("analyse", "[benchmark]") {
    Catch::ConfigData data{};
    data.benchmarkConfidenceInterval = 0.95;
    data.benchmarkNoAnalysis = false;
    data.benchmarkResamples = 1000;
    data.benchmarkSamples = 99;
    Catch::Config config{data};

    using Duration = Catch::Benchmark::FloatDuration<Catch::Benchmark::default_clock>;

    Catch::Benchmark::Environment<Duration> env;
    std::vector<Duration> samples(99);
    for (size_t i = 0; i < samples.size(); ++i) {
        samples[i] = Duration(23 + (i % 3 - 1));
    }

    auto analysis = Catch::Benchmark::Detail::analyse(config, env, samples.begin(), samples.end());
    CATCH_CHECK(analysis.mean.point.count() == 23);
    CATCH_CHECK(analysis.mean.lower_bound.count() < 23);
    CATCH_CHECK(analysis.mean.lower_bound.count() > 22);
    CATCH_CHECK(analysis.mean.upper_bound.count() > 23);
    CATCH_CHECK(analysis.mean.upper_bound.count() < 24);

    CATCH_CHECK(analysis.standard_deviation.point.count() > 0.5);
    CATCH_CHECK(analysis.standard_deviation.point.count() < 1);
    CATCH_CHECK(analysis.standard_deviation.lower_bound.count() > 0.5);
    CATCH_CHECK(analysis.standard_deviation.lower_bound.count() < 1);
    CATCH_CHECK(analysis.standard_deviation.upper_bound.count() > 0.5);
    CATCH_CHECK(analysis.standard_deviation.upper_bound.count() < 1);

    CATCH_CHECK(analysis.outliers.total() == 0);
    CATCH_CHECK(analysis.outliers.low_mild == 0);
    CATCH_CHECK(analysis.outliers.low_severe == 0);
    CATCH_CHECK(analysis.outliers.high_mild == 0);
    CATCH_CHECK(analysis.outliers.high_severe == 0);
    CATCH_CHECK(analysis.outliers.samples_seen == samples.size());

    CATCH_CHECK(analysis.outlier_variance < 0.5);
    CATCH_CHECK(analysis.outlier_variance > 0);
}

CATCH_TEST_CASE("analyse no analysis", "[benchmark]") {
    Catch::ConfigData data{};
    data.benchmarkConfidenceInterval = 0.95;
    data.benchmarkNoAnalysis = true;
    data.benchmarkResamples = 1000;
    data.benchmarkSamples = 99;
    Catch::Config config{ data };

    using Duration = Catch::Benchmark::FloatDuration<Catch::Benchmark::default_clock>;

    Catch::Benchmark::Environment<Duration> env;
    std::vector<Duration> samples(99);
    for (size_t i = 0; i < samples.size(); ++i) {
        samples[i] = Duration(23 + (i % 3 - 1));
    }

    auto analysis = Catch::Benchmark::Detail::analyse(config, env, samples.begin(), samples.end());
    CATCH_CHECK(analysis.mean.point.count() == 23);
    CATCH_CHECK(analysis.mean.lower_bound.count() == 23);
    CATCH_CHECK(analysis.mean.upper_bound.count() == 23);

    CATCH_CHECK(analysis.standard_deviation.point.count() == 0);
    CATCH_CHECK(analysis.standard_deviation.lower_bound.count() == 0);
    CATCH_CHECK(analysis.standard_deviation.upper_bound.count() == 0);

    CATCH_CHECK(analysis.outliers.total() == 0);
    CATCH_CHECK(analysis.outliers.low_mild == 0);
    CATCH_CHECK(analysis.outliers.low_severe == 0);
    CATCH_CHECK(analysis.outliers.high_mild == 0);
    CATCH_CHECK(analysis.outliers.high_severe == 0);
    CATCH_CHECK(analysis.outliers.samples_seen == 0);

    CATCH_CHECK(analysis.outlier_variance == 0);
}

CATCH_TEST_CASE("run_for_at_least, int", "[benchmark]") {
    manual_clock::duration time(100);

    int old_x = 1;
    auto Timing = Catch::Benchmark::Detail::run_for_at_least<manual_clock>(time, 1, [&old_x](int x) -> int {
        CATCH_CHECK(x >= old_x);
        manual_clock::advance(x);
        old_x = x;
        return x + 17;
    });

    CATCH_REQUIRE(Timing.elapsed >= time);
    CATCH_REQUIRE(Timing.result == Timing.iterations + 17);
    CATCH_REQUIRE(Timing.iterations >= time.count());
}

CATCH_TEST_CASE("run_for_at_least, chronometer", "[benchmark]") {
    manual_clock::duration time(100);

    int old_runs = 1;
    auto Timing = Catch::Benchmark::Detail::run_for_at_least<manual_clock>(time, 1, [&old_runs](Catch::Benchmark::Chronometer meter) -> int {
        CATCH_CHECK(meter.runs() >= old_runs);
        manual_clock::advance(100);
        meter.measure([] {
            manual_clock::advance(1);
        });
        old_runs = meter.runs();
        return meter.runs() + 17;
    });

    CATCH_REQUIRE(Timing.elapsed >= time);
    CATCH_REQUIRE(Timing.result == Timing.iterations + 17);
    CATCH_REQUIRE(Timing.iterations >= time.count());
}


CATCH_TEST_CASE("measure", "[benchmark]") {
    auto r = Catch::Benchmark::Detail::measure<manual_clock>([](int x) -> int {
        CATCH_CHECK(x == 17);
        manual_clock::advance(42);
        return 23;
    }, 17);
    auto s = Catch::Benchmark::Detail::measure<manual_clock>([](int x) -> int {
        CATCH_CHECK(x == 23);
        manual_clock::advance(69);
        return 17;
    }, 23);

    CATCH_CHECK(r.elapsed.count() == 42);
    CATCH_CHECK(r.result == 23);
    CATCH_CHECK(r.iterations == 1);

    CATCH_CHECK(s.elapsed.count() == 69);
    CATCH_CHECK(s.result == 17);
    CATCH_CHECK(s.iterations == 1);
}

CATCH_TEST_CASE("run benchmark", "[benchmark]") {
    counting_clock::set_rate(1000);
    auto start = counting_clock::now();

    Catch::Benchmark::Benchmark bench{ "Test Benchmark", [](Catch::Benchmark::Chronometer meter) {
        counting_clock::set_rate(100000);
        meter.measure([] { return counting_clock::now(); });
    } };

    bench.run<counting_clock>();
    auto end = counting_clock::now();

    CATCH_CHECK((end - start).count() == 2867251000);
}
#endif // CATCH_CONFIG_ENABLE_BENCHMARKING
