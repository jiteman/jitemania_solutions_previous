/*
 *  Created by Phil Nash on 08/02/2017.
 *  Copyright (c) 2017 Two Blue Cubes Ltd. All rights reserved.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_MATCHERS_STRING_H_INCLUDED
#define TWOBLUECUBES_CATCH_MATCHERS_STRING_H_INCLUDED

#include "catch_matchers.h"

#include <string>

#include "catch_lib.h"


namespace Catch {
namespace Matchers {

    namespace StdString {

        struct CasedString
        {
            CasedString( std::string const& str, CaseSensitive::Choice caseSensitivity );
            std::string adjustString( std::string const& str ) const;
            std::string caseSensitivitySuffix() const;

            CaseSensitive::Choice m_caseSensitivity;
            std::string m_str;
        };

        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE StringMatcherBase : MatcherBase<std::string> {
            StringMatcherBase( std::string const& operation, CasedString const& comparator );
            std::string describe() const override;

            CasedString m_comparator;
            std::string m_operation;
        };

        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE EqualsMatcher : StringMatcherBase {
            EqualsMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };
        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE ContainsMatcher : StringMatcherBase {
            ContainsMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };
        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE StartsWithMatcher : StringMatcherBase {
            StartsWithMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };
        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE EndsWithMatcher : StringMatcherBase {
            EndsWithMatcher( CasedString const& comparator );
            bool match( std::string const& source ) const override;
        };

        struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE RegexMatcher : MatcherBase<std::string> {
            RegexMatcher( std::string regex, CaseSensitive::Choice caseSensitivity );
            bool match( std::string const& matchee ) const override;
            std::string describe() const override;

        private:
            std::string m_regex;
            CaseSensitive::Choice m_caseSensitivity;
        };

    } // namespace StdString


    // The following functions create the actual matcher objects.
    // This allows the types to be inferred

    JMSD_CATCH_LIBRARY_SHARED_INTERFACE StdString::EqualsMatcher Equals( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE StdString::ContainsMatcher Contains( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE StdString::EndsWithMatcher EndsWith( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE StdString::StartsWithMatcher StartsWith( std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE StdString::RegexMatcher Matches( std::string const& regex, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes );

} // namespace Matchers
} // namespace Catch

#endif // TWOBLUECUBES_CATCH_MATCHERS_STRING_H_INCLUDED
