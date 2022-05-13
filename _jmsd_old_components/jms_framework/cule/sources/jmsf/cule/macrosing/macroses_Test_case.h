#pragma once


#include "jmsf/cule/testing/Test.h"
#include "jmsf/cule/registering/Test_registry.h"

#include "macroses_Test_disabled.h"
#include "macroses_Test_name.h"


//==============================================================================================================================
#define CULE_DISABLED_TEST( suite_name, test_name ) \
	CULE_DISABLED_TEST_MACROS( suite_name, test_name )


//==============================================================================================================================
#define CULE_TEST( suite_name, test_name ) \
	class CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name ) : \
		public ::jmsf::cule::testing::Test \
	{ \
	public: \
		CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )() \
			: \
				Test( \
					JMSF_SL( CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) ), \
					JMSF_FILE_AND_LINE ) \
		{} \
		\
	protected: \
		void run() const; \
		\
	} CULE_CREATE_TEST_CLASS_INSTANCE_NAME( suite_name,test_name ); \
	\
	void CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )::run() const
