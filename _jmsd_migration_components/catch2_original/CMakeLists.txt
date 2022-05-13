cmake_minimum_required( VERSION 3.7.1 )

project( catch_with_tests_original )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_SOURCE_ROOT_PATH ${PROJECT_SOURCE_DIR}/sources )
set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_cmake_settings )


add_subdirectory( catch_lib )
add_subdirectory( catch_test_lib )
add_subdirectory( catch_tests )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
