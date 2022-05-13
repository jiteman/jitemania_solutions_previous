#pragma once


#define CULE_CREATE_TEST_CLASS_NAME( suite_name, test_name ) \
	suite_name##_##test_name##_test

#define CULE_CREATE_TEST_CLASS_NAME_string( suite_name, test_name ) \
	#suite_name"_"#test_name"_test"

#define CULE_CREATE_TEST_CLASS_INSTANCE_NAME( suite_name, test_name ) \
	suite_name##_##test_name##_test_instance

#define CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) \
	suite_name##_test_fixture
