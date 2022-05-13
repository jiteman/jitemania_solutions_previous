/*
 *  Created by Martin on 07/11/2017.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_MATCHERS_FLOATING_H_INCLUDED
#define TWOBLUECUBES_CATCH_MATCHERS_FLOATING_H_INCLUDED

#include "catch_matchers.h"

#include "catch_lib.h"


namespace Catch {
namespace Matchers {

    namespace Floating {

        enum class FloatingPointKind : uint8_t;

        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE WithinAbsMatcher : MatcherBase<double> {
            WithinAbsMatcher(double target, double margin);
            bool match(double const& matchee) const override;
            std::string describe() const override;
        private:
            double m_target;
            double m_margin;
        };

        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE WithinUlpsMatcher : MatcherBase<double> {
            WithinUlpsMatcher(double target, uint64_t ulps, FloatingPointKind baseType);
            bool match(double const& matchee) const override;
            std::string describe() const override;
        private:
            double m_target;
            uint64_t m_ulps;
            FloatingPointKind m_type;
        };

        // Given IEEE-754 format for floats and doubles, we can assume
        // that float -> double promotion is lossless. Given this, we can
        // assume that if we do the standard relative comparison of
        // |lhs - rhs| <= epsilon * max(fabs(lhs), fabs(rhs)), then we get
        // the same result if we do this for floats, as if we do this for
        // doubles that were promoted from floats.
        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE WithinRelMatcher : MatcherBase<double> {
            WithinRelMatcher(double target, double epsilon);
            bool match(double const& matchee) const override;
            std::string describe() const override;
        private:
            double m_target;
            double m_epsilon;
        };

    } // namespace Floating

    // The following functions create the actual matcher objects.
    // This allows the types to be inferred
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinUlpsMatcher WithinULP(double target, uint64_t maxUlpDiff);
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinUlpsMatcher WithinULP(float target, uint64_t maxUlpDiff);
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinAbsMatcher WithinAbs(double target, double margin);
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinRelMatcher WithinRel(double target, double eps);
    // defaults epsilon to 100*numeric_limits<double>::epsilon()
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinRelMatcher WithinRel(double target);
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinRelMatcher WithinRel(float target, float eps);
    // defaults epsilon to 100*numeric_limits<float>::epsilon()
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE Floating::WithinRelMatcher WithinRel(float target);

} // namespace Matchers
} // namespace Catch

#endif // TWOBLUECUBES_CATCH_MATCHERS_FLOATING_H_INCLUDED
