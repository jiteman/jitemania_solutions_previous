/*
 *  Created by Martin on 25/07/2017.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_STRING_MANIP_H_INCLUDED
#define TWOBLUECUBES_CATCH_STRING_MANIP_H_INCLUDED

#include "catch_stringref.h"

#include <string>
#include <iosfwd>
#include <vector>

#include "catch_lib.h"


namespace Catch {

    JMSD_CATCH_LIBRARY_SHARED_INTERFACE bool startsWith( std::string const& s, std::string const& prefix );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE bool startsWith( std::string const& s, char prefix );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE bool endsWith( std::string const& s, std::string const& suffix );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE bool endsWith( std::string const& s, char suffix );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE bool contains( std::string const& s, std::string const& infix );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE void toLowerInPlace( std::string& s );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE std::string toLower( std::string const& s );
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE std::string trim( std::string const& str ); // Returns a new string without whitespace at the start/end
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE StringRef trim(StringRef ref); // Returns a substring of the original ref without whitespace. Beware lifetimes!

    JMSD_CATCH_LIBRARY_SHARED_INTERFACE std::vector<StringRef> splitStringRef( StringRef str, char delimiter ); // Be aware, returns refs into original string - make sure original string outlives them
    JMSD_CATCH_LIBRARY_SHARED_INTERFACE bool replaceInPlace( std::string& str, std::string const& replaceThis, std::string const& withThis );

    struct JMSD_CATCH_LIBRARY_SHARED_INTERFACE  pluralise {
        pluralise( std::size_t count, std::string const& label );

        friend std::ostream& operator << ( std::ostream& os, pluralise const& pluraliser );

        std::size_t m_count;
        std::string m_label;
    };
}

#endif // TWOBLUECUBES_CATCH_STRING_MANIP_H_INCLUDED

