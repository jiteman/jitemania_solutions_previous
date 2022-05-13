cmake_minimum_required( VERSION 3.7.1 )

project( tpc_alut C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-alut-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH} )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${tpc_openal_DEPENDENCY_DIRS}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include )

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )

include_directories(
	${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR}
	${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/common )

if( UNIX )
	include_directories( ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/linux )
elseif ( WIN32 )
	include_directories( ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/windows )
endif()


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/common/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/common/*.c* )

if( UNIX )
	file( GLOB_RECURSE platform_header_and_source_files
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/linux/*.h*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/linux/*.c* )
elseif ( WIN32 )
	file( GLOB_RECURSE platform_header_and_source_files
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/windows/*.h*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/windows/*.c* )
endif()

list( APPEND header_and_source_files ${platform_header_and_source_files} )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DJMSD_TPC_ALUT_LIBRARY_SHARED_INTERFACE_INTERNAL
	-DALUT_BUILD_LIBRARY
	-DHAVE_CONFIG_H
	${tpc_openal_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${tpc_openal_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${tpc_openal_DEPENDENCY_LIBS}
	tpc_openal )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
