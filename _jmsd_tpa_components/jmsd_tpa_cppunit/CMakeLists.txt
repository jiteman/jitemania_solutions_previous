cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_tpa_cppunit )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_SOURCE_ROOT_PATH ${PROJECT_SOURCE_DIR}/sources )
set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_cmake_settings )


add_subdirectory( tpa_cppunit_clocker )
add_subdirectory( tpa_cppunit_lib )

# tests
#add_subdirectory( tpa_cppunit_test_lib )
#add_subdirectory( tpa_cppunit_tests )
#~tests


JMSD_SHOW_PROJECT_GROUP_FOOTER()
