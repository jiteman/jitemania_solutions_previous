cmake_minimum_required( VERSION 3.7.1 )
##include_directories( ${gtf_customization_lib_DEPENDENCY_DIRS} )
##include_directories( ${poco_foundation_lib_DEPENDENCY_DIRS} )
##include_directories( ${cpp_unit_lib_DEPENDENCY_DIRS} )

project( jmsf_tests C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/jmsf-tests-set-compiler-settings.cmake )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${jmsf_DEPENDENCY_DIRS}
	${jmsf_researching_DEPENDENCY_DIRS}
	${tdd_learning_DEPENDENCY_DIRS}
	${cule_DEPENDENCY_DIRS}
	${tpa_gtm_lib_DEPENDENCY_DIRS}
	${PROJECT_SOURCE_DIR}/sources )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
file ( GLOB_RECURSE header_and_source_files ${PROJECT_SOURCE_DIR}/sources/*.h* ${PROJECT_SOURCE_DIR}/sources/*.c* )
add_executable( ${PROJECT_NAME} ${header_and_source_files} )

## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	${jmsf_LINK_DEFINITIONS}
	${jmsf_researching_LINK_DEFINITIONS}
	${tdd_learning_LINK_DEFINITIONS}
	${cule_LINK_DEFINITIONS}
	${tpa_gtm_lib_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	"" )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


# Required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${jmsf_DEPENDENCY_LIBS}
	${jmsf_researching_DEPENDENCY_LIBS}
	${tdd_learning_DEPENDENCY_LIBS}
	${cule_DEPENDENCY_LIBS}
	${tpa_gtm_lib_DEPENDENCY_LIBS}
	jmsf
	jmsf_researching
	tdd_learning
	cule
	tpa_gtm_lib )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
