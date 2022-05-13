cmake_minimum_required( VERSION 3.7.1 )

project( jitemania_solutions )

if ( NOT DEFINED JMSD_CMAKE_SETTINGS_PATH )
	set( JMSD_CMAKE_SETTINGS_PATH ${CMAKE_SOURCE_DIR}/_jmsd_cmake_settings/cmake )
endif()

if ( NOT DEFINED JMSD_PLATFORM_SOURCES )
	set( JMSD_PLATFORM_SOURCES ${CMAKE_SOURCE_DIR}/_jmsd_platform_support/sources )
endif()

if ( NOT DEFINED JMSD_EXTERNAL_PREBUILT_DEPENDENCIES_PATH )
	set( JMSD_EXTERNAL_PREBUILT_DEPENDENCIES_PATH ${CMAKE_SOURCE_DIR}/../_external_prebuilt_dependencies )
endif()

include( ${JMSD_CMAKE_SETTINGS_PATH}/set-all-settings.cmake )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( library_subproject_template )
add_subdirectory( executable_template )

# foreign components
add_subdirectory( _jmsd_foreign_components )
add_subdirectory( _jmsd_tpa_components )
#~foreign components

# old jitemania components
add_subdirectory( _jmsd_old_components )
#~jitemania components

# pre jitemania components
add_subdirectory( _jmsd_migration_components )
#~pre jitemania components

# jitemania components
add_subdirectory( _jmsd_layer_low_components )
##add_subdirectory( _jmsd_layer_middle_components )
##add_subdirectory( _jmsd_layer_high_components )

add_subdirectory( _jmsd_experimental )
#~jitemania components


JMSD_SHOW_PROJECT_GROUP_FOOTER()
