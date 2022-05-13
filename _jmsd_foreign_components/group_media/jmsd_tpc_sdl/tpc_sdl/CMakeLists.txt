cmake_minimum_required( VERSION 3.7.1 )

project( tpc_sdl C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-sdl-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH} )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/jmsd_adhocs/include ) # SDL2/SDL.h
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
##file( GLOB_RECURSE header_and_source_files
file( GLOB header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/atomic/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/atomic/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/disk/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/disk/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/dummy/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/dummy/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/directsound/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/directsound/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/wasapi/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/wasapi/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/winmm/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/audio/winmm/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/core/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/core/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/core/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/core/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/cpuinfo/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/cpuinfo/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/dynapi/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/dynapi/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/events/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/events/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/file/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/file/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/filesystem/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/filesystem/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/filesystem/dummy/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/filesystem/dummy/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/filesystem/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/filesystem/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/haptic/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/haptic/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/haptic/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/haptic/windows/*.c*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/hidapi/*.h*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/hidapi/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/hidapi/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/hidapi/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/joystick/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/joystick/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/joystick/hidapi/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/joystick/hidapi/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/joystick/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/joystick/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/libm/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/libm/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/loadso/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/loadso/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/loadso/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/loadso/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/direct3d/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/direct3d/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/direct3d11/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/direct3d11/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/opengl/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/opengl/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/opengles/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/opengles/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/opengles2/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/opengles2/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/psp/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/psp/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/software/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/render/software/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/stdlib/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/stdlib/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/power/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/power/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/power/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/power/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/sensor/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/sensor/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/sensor/dummy/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/sensor/dummy/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/*.c*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/generic/*.h*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/generic/*.c*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/stdcpp/*.h*
#	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/stdcpp/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/windows/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/windows/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/dummy/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/dummy/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/yuv2rgb/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/yuv2rgb/*.c* )

list( APPEND header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/thread/generic/SDL_syscond.c )

if( UNIX )
	file( GLOB header_and_source_files_UNIX
		)

	list( APPEND header_and_source_files ${header_and_source_files_UNIX} )
elseif( WIN32 )
	file( GLOB header_and_source_files_Windows
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/windows/*.h*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/timer/windows/*.c*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/windows/*.h*
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/src/video/windows/*.c*
		)
	list( APPEND header_and_source_files ${header_and_source_files_Windows} )
endif()

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DJMSD_TPC_SDL_SHARED_INTERFACE_INTERNAL
	-DBUILD_SDL )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	"" )
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
		"Imm32.lib"
		"Setupapi.lib"
		"Version.lib"
		"Winmm.lib" )
endif()

list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
