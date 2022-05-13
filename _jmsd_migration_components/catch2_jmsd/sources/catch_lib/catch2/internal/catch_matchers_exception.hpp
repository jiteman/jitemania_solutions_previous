/*
 *  Created by Martin Hořeňovský on 13/10/2019.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_MATCHERS_EXCEPTION_HPP_INCLUDED
#define TWOBLUECUBES_CATCH_MATCHERS_EXCEPTION_HPP_INCLUDED

#include "catch_matchers.h"

#include "catch_lib.h"


namespace Catch {
namespace Matchers {
namespace Exception {

class JMSD_CATCH_LIBRARY_SHARED_INTERFACE ExceptionMessageMatcher : public MatcherBase<std::exception> {
    std::string m_message;
public:

    ExceptionMessageMatcher(std::string const& message):
        m_message(message)
    {}

    bool match(std::exception const& ex) const override;

    std::string describe() const override;
};

} // namespace Exception

JMSD_CATCH_LIBRARY_SHARED_INTERFACE Exception::ExceptionMessageMatcher Message(std::string const& message);

} // namespace Matchers
} // namespace Catch

#endif // TWOBLUECUBES_CATCH_MATCHERS_EXCEPTION_HPP_INCLUDED
