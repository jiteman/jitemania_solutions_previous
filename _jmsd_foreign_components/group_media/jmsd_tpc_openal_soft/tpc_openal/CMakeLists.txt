cmake_minimum_required( VERSION 3.7.1 )

project( tpc_openal C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-openal-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH} )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${tpc_sdl_DEPENDENCY_DIRS}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include )

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )

include_directories(
	${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/al
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/common
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/common )

if( UNIX )
	include_directories( ${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/linux )
elseif ( WIN32 )
	include_directories( ${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/windows )
endif()


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/al/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/al/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/common/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/common/*.c*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/router/*.h*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/router/*.c*
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

file( GLOB nonrecursive_header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/effects/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/effects/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/filters/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/filters/*.c* )

if( UNIX )
	file( GLOB nonrecursive_platform_header_and_source_files
		"" )
elseif ( WIN32 )
	file( GLOB nonrecursive_platform_header_and_source_files
		"" )
endif()

file( GLOB single_header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/base.*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/loopback.*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/null.*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/sdl2.* )

if( UNIX )
	file( GLOB_RECURSE single_platform_header_and_source_files
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/*.h*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/*.c*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/*.h*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/*.c* )
elseif ( WIN32 )
	file( GLOB single_platform_header_and_source_files
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/dsound.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/mixer_sse.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/mixer_sse2.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/mixer_sse3.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/mixer_sse4.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/wasapi.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/wave.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/backends/winmm.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/defs.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/hrtfbase.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/mixer_c.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/mixer_sse.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/mixer_sse2.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/mixer_sse3.*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/alc/mixer/mixer_sse41.* )
endif()

list( APPEND header_and_source_files
	${nonrecursive_header_and_source_files}
	${platform_header_and_source_files}
	${nonrecursive_platform_header_and_source_files}
	${single_header_and_source_files}
	${single_platform_header_and_source_files} )

set( FILES_TO_REMOVE_HEADER_AND_SOURCE
	"" )

JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files FILES_TO_REMOVE_HEADER_AND_SOURCE )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DJMSD_OPENAL_SHARED_INTERFACE_INTERNAL
	-DAL_ALEXT_PROTOTYPES
	${tpc_sdl_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${tpc_sdl_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${tpc_sdl_DEPENDENCY_LIBS}
	tpc_sdl )

## project target section
if ( UNIX )
	list( APPEND  ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		 )
elseif( WIN32 )
	list( APPEND ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		"Winmm.lib" )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
