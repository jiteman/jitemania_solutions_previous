#pragma once


#include "jmsf/cule/testing/Test_exception.hin"

#include "macroses_Test_disabled.h"
#include "macroses_Test_name.h"


//==============================================================================================================================
#define CULE_DISABLED_TEST_E( suite_name, test_name, exception_name ) \
	CULE_DISABLED_TEST_MACROS( suite_name, test_name )

//==============================================================================================================================
#define CULE_TEST_E( suite_name, test_name, exception_name ) \
	class CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name ) : \
		public ::jmsf::cule::testing::Test_exception< exception_name > \
	{ \
	public: \
		CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )() \
			: \
				Test( \
					JMSF_SL( \
						CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) ), \
					JMSF_FILE_AND_LINE ), \
				Test_exception( \
					JMSF_SL( \
						CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) ), \
					JMSF_FILE_AND_LINE ) \
		{} \
		\
	protected: \
		void test_exception_to_run_with() const override; \
		\
	} CULE_CREATE_TEST_CLASS_INSTANCE_NAME( suite_name, test_name ); \
	\
	void CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )::test_exception_to_run_with() const
