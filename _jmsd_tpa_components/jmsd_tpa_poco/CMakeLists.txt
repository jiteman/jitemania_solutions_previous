cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_tpa_poco )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_SOURCE_ROOT_PATH ${PROJECT_SOURCE_DIR}/sources )
set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_cmake_settings )


# tests
add_subdirectory( tpa_poco_cppunit_adapter )
add_subdirectory( tpa_poco_test_lib )
add_subdirectory( tpa_poco_tests )
#~tests


JMSD_SHOW_PROJECT_GROUP_FOOTER()
