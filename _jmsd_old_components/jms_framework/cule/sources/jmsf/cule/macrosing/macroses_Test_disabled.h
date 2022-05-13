#pragma once


#include "jmsf/cule/testing/Test_disabled.h"

#include "macroses_Test_name.h"


//==============================================================================================================================
#define CULE_DISABLED_TEST_MACROS( suite_name, test_name ) \
	class CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name ) : \
		public ::jmsf::cule::testing::Test_disabled \
	{ \
	public: \
		CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )() \
			: \
				Test_disabled( \
					JMSF_SL( CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) ), \
					JMSF_FILE_AND_LINE ) \
		{} \
		\
	private: \
		void dummy_run_method() const; \
		\
	} CULE_CREATE_TEST_CLASS_INSTANCE_NAME( suite_name,test_name ); \
	\
	void CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )::dummy_run_method() const


//==============================================================================================================================
#define CULE_DISABLED_TEST_F_MACROS( suite_name, test_name ) \
	class CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name ) : \
		public ::jmsf::cule::testing::Test_disabled \
	{ \
	public: \
		CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )() \
			: \
				Test_disabled( \
					JMSF_SL( CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) ), \
					JMSF_FILE_AND_LINE ) \
		{} \
		\
	private: \
		void dummy_run_method( CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) &fixture ) const; \
		\
	private: \
		mutable CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) *_the_fake_fixture; \
	} CULE_CREATE_TEST_CLASS_INSTANCE_NAME( suite_name,test_name ); \
	\
	void CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name )::dummy_run_method( CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) &fx_ ) const
