#pragma once
// User-facing chronometer


#include "catch_clock.hpp"
#include "catch_optimizer.hpp"
#include "detail/catch_complete_invoke.hpp"
#include "../catch_meta.hpp"

#include "catch_lib.h"


namespace Catch {
    namespace Benchmark {
        namespace Detail {
            struct ChronometerConcept {
                virtual void start() = 0;
                virtual void finish() = 0;
                virtual ~ChronometerConcept() = default;
            };
            template <typename Clock>
            struct ChronometerModel final : public ChronometerConcept {
                void start() override { started = Clock::now(); }
                void finish() override { finished = Clock::now(); }

                ClockDuration<Clock> elapsed() const { return finished - started; }

                TimePoint<Clock> started;
                TimePoint<Clock> finished;
            };
        } // namespace Detail

        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE Chronometer {
        public:
            template <typename Fun>
            void measure(Fun&& fun) { measure(std::forward<Fun>(fun), is_callable<Fun(int)>()); }

            int runs() const;

            Chronometer(Detail::ChronometerConcept& meter, int k);

        private:
            template <typename Fun>
            void measure(Fun&& fun, std::false_type) {
                measure([&fun](int) { return fun(); }, std::true_type());
            }

            template <typename Fun>
            void measure(Fun&& fun, std::true_type) {
                Detail::optimizer_barrier();
                impl->start();
                for (int i = 0; i < k; ++i) invoke_deoptimized(fun, i);
                impl->finish();
                Detail::optimizer_barrier();
            }

            Detail::ChronometerConcept* impl;
            int k;
        };
    } // namespace Benchmark
} // namespace Catch
