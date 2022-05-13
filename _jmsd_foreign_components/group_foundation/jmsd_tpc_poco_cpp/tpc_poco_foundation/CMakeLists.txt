cmake_minimum_required( VERSION 3.7.1 )

project( tpc_poco_foundation C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-poco-foundation-set-compiler-settings.cmake )
include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/macroses/tpc-poco-functions-and-macroses.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH}/Foundation )

list( APPEND ${PROJECT_NAME}_TEST_SOURCE_DIRS_VAR ${JMSD_THIS_PROJECT_SOURCE_ROOT}/testsuite/src )


## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.c* )

set( JMSD_POCO_FOUNDATION_FILES_TO_REMOVE
	"DirectoryIterator"
	"Environment"
	"Event"
	"File"
	"FileStream"
	"FPEnvironment"
	"LogFile"
	"Mutex"
	"NamedEvent"
	"NamedMutex"
	"Path"
	"PipeImpl"
	"Platform"
	"Process"
	"RWLock"
	"Thread"
	"Semaphore"
	"SharedLibrary"
	"SharedMemory"
	"Timezone" )
JMSD_REMOVE_PLATFORM_FILES_FOR_POCO( header_and_source_files JMSD_POCO_FOUNDATION_FILES_TO_REMOVE )

set( PLATFORM_SPECIC_FILES_TO_REMOVE_HEADER_AND_SOURCE
	"AndroidLogChannel"
	"EventLogChannel"
	"SyslogChannel"
	"WindowsConsoleChannel" )
list( APPEND PLATFORM_SPECIC_FILES_TO_REMOVE_HEADER_AND_SOURCE "NamedTuple" )

if ( UNIX )
	list( REMOVE_ITEM PLATFORM_SPECIC_FILES_TO_REMOVE_HEADER_AND_SOURCE "SyslogChannel" )
elseif( WIN32 )
	list( REMOVE_ITEM PLATFORM_SPECIC_FILES_TO_REMOVE_HEADER_AND_SOURCE "EventLogChannel" )
	list( REMOVE_ITEM PLATFORM_SPECIC_FILES_TO_REMOVE_HEADER_AND_SOURCE "WindowsConsoleChannel" )
endif()

JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files PLATFORM_SPECIC_FILES_TO_REMOVE_HEADER_AND_SOURCE )

if( WIN32 )
	JMSD_MICROSOFT_MESSAGE_COMPILER( header_and_source_files ${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/pocomsg.mc )
endif()

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DFoundation_EXPORTS -DPOCO_ENABLE_CPP11 -DPOCO_DLL )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	-DPOCO_NO_AUTOMATIC_LIBS -DPOCO_ENABLE_CPP11 -DPOCO_DLL )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
if( UNIX )
	set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		"pthread"
		"dl"
		"rt" )
elseif ( WIN32 )
	set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		"Iphlpapi.lib" )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-test-source-directories.cmake )
JMSD_SHOW_PROJECT_FOOTER()
