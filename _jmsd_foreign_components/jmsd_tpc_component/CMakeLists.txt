cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_tp_component )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_SOURCE_ROOT_PATH ${PROJECT_SOURCE_DIR}/_tpc_sources )
set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_tpc_cmake_settings )


add_subdirectory( tpc_base_lib )
add_subdirectory( tpc_derived_lib )
add_subdirectory( tpc_executabe )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
