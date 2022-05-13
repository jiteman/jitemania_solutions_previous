cmake_minimum_required( VERSION 3.7.1 )

project( tpc_sfml C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-sfml-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH} )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${tpc_openal_DEPENDENCY_DIRS}
	${tpc_vorbis_DEPENDENCY_DIRS}
	${tpc_flac_DEPENDENCY_DIRS}
	${tpc_freetype_DEPENDENCY_DIRS}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/glad/include )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )

include_directories(
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/stb_image
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/vulkan/include )


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/glad/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/glad/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/stb_image/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/stb_image/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/vulkan/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/extlibs/headers/vulkan/include/*.c* )

set( FILES_TO_REMOVE_HEADER_AND_SOURCE
	"MainAndroid.cpp"
	"MainWin32.cpp"
	"SFMLActivity.cpp"
#	"Vulkan"
	)

set( PLATFORM_FILES_TO_REMOVE_HEADER_AND_SOURCE
	"Android"
	"FreeBSD"
	"iOS"
	"OpenBSD"
	"OSX" )

if( UNIX )
	list( APPEND PLATFORM_FILES_TO_REMOVE_HEADER_AND_SOURCE
		"Win32" )
elseif( WIN32 )
	list( APPEND PLATFORM_FILES_TO_REMOVE_HEADER_AND_SOURCE
		"Unix" )
endif()

list( APPEND FILES_TO_REMOVE_HEADER_AND_SOURCE ${PLATFORM_FILES_TO_REMOVE_HEADER_AND_SOURCE} )

JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files FILES_TO_REMOVE_HEADER_AND_SOURCE )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DJMSD_SFML_SHARED_INTERFACE_INTERNAL
	-DSFML_AUDIO_EXPORTS
	-DSFML_GRAPHICS_EXPORTS
	-DSFML_NETWORK_EXPORTS
	-DSFML_SYSTEM_EXPORTS
	-DSFML_WINDOW_EXPORTS
	-DJMSD_VULKAN_IMPLEMENTATION_NOT_AVAILABLE_FOR_SMFL
	${tpc_openal_LINK_DEFINITIONS}
	${tpc_vorbis_LINK_DEFINITIONS}
	${tpc_flac_LINK_DEFINITIONS}
	${tpc_freetype_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${tpc_openal_LINK_DEFINITIONS}
	${tpc_vorbis_LINK_DEFINITIONS}
	${tpc_flac_LINK_DEFINITIONS}
	${tpc_freetype_LINK_DEFINITIONS} )
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
		"" )
elseif( WIN32 )
	set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
		${tpc_openal_DEPENDENCY_LIBS}
		${tpc_vorbis_DEPENDENCY_LIBS}
		${tpc_flac_DEPENDENCY_LIBS}
		${tpc_freetype_DEPENDENCY_LIBS}
		tpc_openal
		tpc_vorbis
		tpc_flac
		tpc_freetype
		opengl32
		Ws2_32 )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
