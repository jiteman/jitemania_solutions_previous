#pragma once


#include "jmsf/cule/testing/Test_fixture.h"

#include "macroses_Test_name.h"


//==============================================================================================================================
#define CULE_TEST_FIXTURE( suite_name ) \
	class CULE_CREATE_TEST_FIXTURE_NAME( suite_name ) : public ::jmsf::cule::testing::Test_fixture
