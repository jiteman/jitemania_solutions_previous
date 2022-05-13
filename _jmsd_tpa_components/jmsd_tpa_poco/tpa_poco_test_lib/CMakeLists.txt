cmake_minimum_required( VERSION 3.7.1 )

project( tpa_poco_test C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpa-poco-test-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/tpa_poco_test )


## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${tpa_poco_cppunit_adapter_DEPENDENCY_DIRS}
	${tpc_poco_json_DEPENDENCY_DIRS}
	${tpc_poco_xml_DEPENDENCY_DIRS}
	${tpc_poco_util_DEPENDENCY_DIRS}
	${tpc_poco_zip_DEPENDENCY_DIRS}
	${tpc_poco_foundation_TEST_SOURCE_DIRS}
	${tpc_poco_json_TEST_SOURCE_DIRS}
	${tpc_poco_xml_TEST_SOURCE_DIRS}
	${tpc_poco_util_TEST_SOURCE_DIRS}
	${tpc_poco_zip_TEST_SOURCE_DIRS}
	${JMSD_THIS_PROJECT_SOURCE_ROOT} )
#	${JMSD_COMPONENT_SOURCE_ROOT_PATH} )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
foreach( directory ${tpc_poco_foundation_TEST_SOURCE_DIRS} )
	list( APPEND test_header_and_source_files ${directory}/*.h* )
	list( APPEND test_header_and_source_files ${directory}/*.c* )
endforeach()

foreach( directory ${tpc_poco_json_TEST_SOURCE_DIRS} )
	list( APPEND test_header_and_source_files ${directory}/*.h* )
	list( APPEND test_header_and_source_files ${directory}/*.c* )
endforeach()

foreach( directory ${tpc_poco_xml_TEST_SOURCE_DIRS} )
	list( APPEND test_header_and_source_files ${directory}/*.h* )
	list( APPEND test_header_and_source_files ${directory}/*.c* )
endforeach()

foreach( directory ${tpc_poco_util_TEST_SOURCE_DIRS} )
	list( APPEND test_header_and_source_files ${directory}/*.h* )
	list( APPEND test_header_and_source_files ${directory}/*.c* )
endforeach()

foreach( directory ${tpc_poco_zip_TEST_SOURCE_DIRS} )
	list( APPEND test_header_and_source_files ${directory}/*.h* )
	list( APPEND test_header_and_source_files ${directory}/*.c* )
endforeach()

file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/*.c*
	${test_header_and_source_files} )

set( JMSD_THIS_PROJECT_FILES_TO_REMOVE
	"TestApp"
	"Driver"
	"CppUnitTestPlugIn" )

if( UNIX )
	list( APPEND JMSD_THIS_PROJECT_FILES_TO_REMOVE
		"WindowsTestSuite"
		"WinConfigurationTest"
		"WinRegistryTest"
		"WinServiceTest" )
elseif( WIN32 )
	list( APPEND JMSD_THIS_PROJECT_FILES_TO_REMOVE
		"NamedTuplesTest"
		"TuplesTest" )
endif()

JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files JMSD_THIS_PROJECT_FILES_TO_REMOVE )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	${tpa_poco_cppunit_adapter_LINK_DEFINITIONS}
	${tpc_poco_json_LINK_DEFINITIONS}
	${tpc_poco_xml_LINK_DEFINITIONS}
	${tpc_poco_util_LINK_DEFINITIONS}
	${tpc_poco_zip_LINK_DEFINITIONS}
	-DJMSD_TPA_POCO_TEST_TEMPLATE_SHARED_INTERFACE_INTERNAL )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${tpa_poco_cppunit_adapter_LINK_DEFINITIONS}
	${tpc_poco_json_LINK_DEFINITIONS}
	${tpc_poco_xml_LINK_DEFINITIONS}
	${tpc_poco_util_LINK_DEFINITIONS}
	${tpc_poco_zip_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${tpa_poco_cppunit_adapter_DEPENDENCY_LIBS}
	${tpc_poco_json_DEPENDENCY_LIBS}
	${tpc_poco_xml_DEPENDENCY_LIBS}
	${tpc_poco_util_DEPENDENCY_LIBS}
	${tpc_poco_zip_DEPENDENCY_LIBS}
	tpa_poco_cppunit_adapter
	tpc_poco_json
	tpc_poco_xml
	tpc_poco_util
	tpc_poco_zip )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
