#pragma once


#include "cppunit/TestCaller.h"

#include <string>


//#define CppUnit_addTest( suite, cls, mth )
//	suite->addTest( new CppUnit::TestCaller< cls >( #mth, &cls::mth ) )

#define CppUnit_addQualifiedTest( suite, cls, mth ) \
	suite->addTest( new CppUnit::TestCaller< cls >( #cls"::"#mth, &cls::mth ) )


#define CppUnit_addTest( suite, cls, mth ) \
	do { \
		class Local_adapter : public cls { \
		public: \
			Local_adapter() : \
				cls( ::std::string() ) \
			{} \
		\
		}; \
		\
		suite->addTest( new CppUnit::TestCaller< Local_adapter >( #mth, &cls::mth ) ); \
	} while ( false )
