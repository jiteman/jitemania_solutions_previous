cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_component )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_SOURCE_ROOT_PATH ${PROJECT_SOURCE_DIR}/sources )
set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_cmake_settings )


add_subdirectory( c_base_lib )
add_subdirectory( c_derived_lib )
add_subdirectory( c_executabe )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
