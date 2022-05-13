#pragma once


#include "cppunit/TestAssert.h"


#include <sstream>
#include <string>


#define assertTrue( condition ) \
	CPPUNIT_ASSERT( ( condition ) )

#define assertFalse( condition ) \
	CPPUNIT_ASSERT( !( condition ) )

#define failmsg( message ) \
	CPPUNIT_FAIL( ( message ) )

#define warnmsg( message ) \
	CPPUNIT_FAIL( ( message ) )

#define assertNullPtr( pointer ) \
	CPPUNIT_ASSERT( ( pointer ) == nullptr )

#define assertNotNullPtr( pointer ) \
	CPPUNIT_ASSERT( ( pointer ) != nullptr )

#define assertEqualDelta( expected, actual, delta ) \
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ( expected ), ( actual ), ( delta ) )

#define loop_1_assert( data1line, condition ) \
	{ \
		::std::stringstream the_stream; \
		the_stream << ( data1line ); \
		CPPUNIT_ASSERT_MESSAGE( the_stream.str(), ( condition ) ); \
	}

#define loop_2_assert( data1line, data2line, condition ) \
	{ \
		::std::stringstream the_stream; \
		the_stream << ( data1line ); \
		the_stream << " : "; \
		the_stream << ( data2line ); \
		CPPUNIT_ASSERT_MESSAGE( the_stream.str(), ( condition ) ); \
	}

#define assertEqual( expected, actual ) \
	CPPUNIT_ASSERT_EQUAL( ( expected ), ( actual ) )

#define assertEqualTyped( type, expected, actual ) \
	CPPUNIT_ASSERT_EQUAL( type( ( expected ) ), type( ( actual ) ) )

#undef assert
