cmake_minimum_required( VERSION 3.7.1 )

project( exp_boost_example C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/exp-boost-example-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/exp_boost_example )

if ( CMAKE_VERSION VERSION_GREATER_EQUAL 3.12 )
	cmake_policy( SET CMP0074 NEW ) # In CMake 3.12 and above the find_package(<PackageName>) command now searches prefixes specified by the <PackageName>_ROOT CMake variable and the <PackageName>_ROOT environment variable.
endif()	

## external dependencies
# set( Boost_USE_DEBUG_LIBS OFF )
# set( Boost_USE_RELEASE_LIBS ON )
set( Boost_USE_STATIC_LIBS OFF )
set( Boost_USE_STATIC_RUNTIME OFF)
set( Boost_USE_MULTITHREADED ON )
set( Boost_NO_SYSTEM_PATHS ON )

if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
	set( Boost_USE_DEBUG_RUNTIME OFF )
endif()

# set( BOOST_INCLUDEDIR $ENV{BOOST_INCLUDEDIR} )
# set( BOOST_LIBRARYDIR $ENV{BOOST_LIBRARYDIR} )

find_package( Boost COMPONENTS system filesystem program_options REQUIRED )


## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${JMSD_THIS_PROJECT_SOURCE_ROOT} )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )

include_directories( ${Boost_INCLUDE_DIRS} )


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}_main/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}_main/*.c* )
add_executable( ${PROJECT_NAME} ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DBOOST_ALL_NO_LIB
	-DBOOST_ALL_DYN_LINK )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	-DBOOST_ALL_NO_LIB
	-DBOOST_ALL_DYN_LINK )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


# Required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )

link_directories( ${Boost_LIBRARY_DIRS} )

## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	"" )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} ${Boost_LIBRARIES} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
