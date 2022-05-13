cmake_minimum_required( VERSION 3.7.1 )

project( tpc_freetype C CXX )


JMSD_SHOW_PROJECT_HEADER()


include( ${JMSD_COMPONENT_CMAKE_SETTINGS_PATH}/tpc-freetype-lib-set-compiler-settings.cmake )
set( JMSD_THIS_PROJECT_SOURCE_ROOT ${JMSD_COMPONENT_SOURCE_ROOT_PATH} )

## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JMSD_PLATFORM_SOURCES}
	${tpc_zlib_DEPENDENCY_DIRS}
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

#include_directories( ${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/freetype/config )

## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files
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

file( GLOB nonrecursive_header_and_source_files
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/freetype/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/freetype/*.c*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/freetype/config/*.h*
	${JMSD_THIS_PROJECT_SOURCE_ROOT}/include/freetype/config/*.c* )

list( APPEND header_and_source_files ${nonrecursive_header_and_source_files} )

set( FILES_TO_REMOVE_HEADER_AND_SOURCE
	"autofit.c"
	"src/bdf/bdf.c"
	"cff.c"
	"ftbase.c"
	"ftcache.c"
	"gxvalid"
	"otvalid.c"
	"pcf.c"
	"pfr.c"
	"psaux.c"
	"pshinter.c"
	"psnames.c"
	"src/raster/raster.c"
	"sfnt.c"
	"src/smooth/smooth.c"
	"truetype.c"
	"type1.c"
	"type1cid.c"
	"type42.c" )

# build-in zlib
list( APPEND FILES_TO_REMOVE_HEADER_AND_SOURCE
	"src/gzip/adler32.c"
	"src/gzip/ftgzip.c"
	"src/gzip/ftzconf.h"
	"src/gzip/infblock.c"
	"src/gzip/infblock.h"
	"src/gzip/infcodes.c"
	"src/gzip/infcodes.h"
	"src/gzip/inffixed.h"
	"src/gzip/inflate.c"
	"src/gzip/inftrees.c"
	"src/gzip/inftrees.h"
	"src/gzip/infutil.c"
	"src/gzip/infutil.h"
	"src/gzip/zlib.h"
	"src/gzip/zutil.c"
	"src/gzip/zutil.h"
	"tools/ftrandom/ftrandom.c"
	"tools/apinames.c"
	"tools/test_afm.c"
	"tools/test_bbox.c"
	"tools/test_trig.c" )

if( UNIX )
	list( APPEND FILES_TO_REMOVE_HEADER_AND_SOURCE
		"src/base/ftsystem.c" )
	list( APPEND header_and_source_files
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/builds/unix/ftsystem.c )
elseif( WIN32 )
	list( APPEND FILES_TO_REMOVE_HEADER_AND_SOURCE
		"src/base/ftdebug.c" )
	list( APPEND header_and_source_files
		${JMSD_THIS_PROJECT_SOURCE_ROOT}/builds/windows/ftdebug.c )
endif()

JMSD_REMOVE_FILES_FROM_THE_LIST( header_and_source_files FILES_TO_REMOVE_HEADER_AND_SOURCE )

add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	-DJMSD_TPC_FREETYPE_SHARED_INTERFACE_INTERNAL
	-DFT2_BUILD_LIBRARY
	-DFT2_DLL_EXPORT
	${tpc_zlib_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	-DFT2_DLL_IMPORT
	${tpc_zlib_LINK_DEFINITIONS} )
JMSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JMSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${tpc_zlib_DEPENDENCY_LIBS}
	tpc_zlib )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JMSD_CMAKE_SETTINGS_PATH}/set-expose-dependencies.cmake )
JMSD_SHOW_PROJECT_FOOTER()
