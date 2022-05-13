cmake_minimum_required( VERSION 3.7.1 )

project( exp_ssg_lib C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/exp-ssg-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/exp_ssg_lib )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${tpc_alut_DEPENDENCY_DIRS}
	${tpc_glew_DEPENDENCY_DIRS}
	${tpc_sfml_DEPENDENCY_DIRS}
	${JMSD_THIS_PROJECT_SOURCE_ROOT} )

if( UNIX )
	include_directories( ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/platform/linux )
elseif( WIN32 )
	include_directories( ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/platform/windows )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/*.c* )

if( UNIX )
	file( GLOB_RECURSE platform_header_and_source_files
		${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/platform/linux/*.h*
		${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/platform/linux/*.c* )
elseif( WIN32 )
	file( GLOB_RECURSE platform_header_and_source_files
		${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/platform/windows/*.h*
		${JMSD_COMPONENT_SOURCE_ROOT_PATH}/jmsd_adhocs/platform/windows/*.c* )
endif()

list( APPEND header_and_source_files ${platform_header_and_source_files} )

set( platform_to_remove_header_and_source_files
	"Dialog_message_box_Linux_implementation"
	"Dialog_message_box_Osx_implementation"
	"Dialog_message_box_Windows_implementation" )

if( UNIX )
	JMSD_REMOVE_FILE_FROM_THE_LIST( platform_to_remove_header_and_source_files "Dialog_message_box_Linux_implementation" )
elseif( WIN32 )
	JMSD_REMOVE_FILE_FROM_THE_LIST( platform_to_remove_header_and_source_files "Dialog_message_box_Windows_implementation" )
endif()

JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files platform_to_remove_header_and_source_files )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DJMSD_EXP_SSG_LIBRARY_SHARED_INTERFACE_INTERNAL
	${tpc_alut_LINK_DEFINITIONS}
	${tpc_sfml_LINK_DEFINITIONS}
	${tpc_glew_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${tpc_alut_LINK_DEFINITIONS}
	${tpc_sfml_LINK_DEFINITIONS}
	${tpc_glew_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${tpc_alut_LINK_DEFINITIONS}
	tpc_alut
	${tpc_sfml_DEPENDENCY_LIBS}
	tpc_sfml
	${tpc_glew_DEPENDENCY_LIBS}
	tpc_glew )

if ( WIN32 )
	list( APPEND ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR Glu32.lib )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
