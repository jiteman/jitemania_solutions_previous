cmake_minimum_required( VERSION 3.7.1 )

project( tpc_cppunit_lib C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-cppunit-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH} )

list( APPEND ${PROJECT_NAME}_TEST_SOURCE_DIRS_VAR ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/examples/cppunittest )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/cppunit/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/cppunit/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/cppunit/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/cppunit/*.c* )

set( JMSD_THIS_PROJECT_FILES_TO_REMOVE
	"CommandLineParser"
	"DllMain"
	"DllPlugInTester"
	"TestPlugInInterface" )
JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files JMSD_THIS_PROJECT_FILES_TO_REMOVE )

#if ( UNIX )
#	JMSD_REMOVE_FILE_FROM_THE_LIST( header_and_source_files "DllMain" )
#endif()

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DCPPUNIT_BUILD_DLL )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	-DCPPUNIT_DLL )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
if( WIN32 )
	set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		"" )
elseif( UNIX )
	set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		"dl" )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-test-source-directories.cmake )
JMSD_SHOW_PROJECT_FOOTER()
