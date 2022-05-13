#pragma once


#include "jmsf/cule/testing/Test_exception.hin"
#include "jmsf/cule/testing/Test_with_fixture.hin"
#include "jmsf/cule/testing/Test_fixture.h"

#include "macroses_Test_disabled.h"
#include "macroses_Test_name.h"


//==============================================================================================================================
#define CULE_DISABLED_TEST_EF( suite_name, test_name, exception_name ) \
	CULE_DISABLED_TEST_F_MACROS( suite_name, test_name )

//==============================================================================================================================
#define CULE_TEST_EF( suite_name, test_name, exception_name ) \
	class CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name ) : \
		public ::jmsf::cule::testing::Test_with_fixture< CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) >, \
		public ::jmsf::cule::testing::Test_exception< exception_name > \
	{ \
	public: \
		CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )() \
			: \
				Test( \
					JMSF_SL( \
						CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) ), \
					JMSF_FILE_AND_LINE ), \
				Test_with_fixture( \
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
		void test_exception_to_run_with() const override { \
			test_fixture_to_run_with( *get_test_fixture() ); \
		} \
		\
		void test_fixture_to_run_with( CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) &fixture ) const; \
		\
	} CULE_CREATE_TEST_CLASS_INSTANCE_NAME( suite_name, test_name ); \
	\
	void CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )::test_fixture_to_run_with( CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) &fx_ ) const
