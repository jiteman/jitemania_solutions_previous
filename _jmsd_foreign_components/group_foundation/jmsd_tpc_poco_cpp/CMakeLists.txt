cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_tpc_poco_cpp )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_SOURCE_ROOT_PATH ${PROJECT_SOURCE_DIR}/_tpc_sources )
set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_tpc_cmake_settings )


add_subdirectory( tpc_poco_foundation )
add_subdirectory( tpc_poco_json )
add_subdirectory( tpc_poco_xml )
add_subdirectory( tpc_poco_util )
add_subdirectory( tpc_poco_seven_zip )
add_subdirectory( tpc_poco_zip )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
