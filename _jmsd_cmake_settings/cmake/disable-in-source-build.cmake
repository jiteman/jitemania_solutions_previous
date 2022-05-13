JMSD_CMAKE_CURRENT_FILE_IN( "disable-in-source-build.cmake" )

if ( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" )
	message( SEND_ERROR "[JMSD] IN-SOURCE BUILD IS DISABLED - In-source build is disabled." )
endif()

string( FIND "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}" JMSD_IS_IN_SOURCE_BUILD )

if ( NOT ${JMSD_IS_IN_SOURCE_BUILD} EQUAL -1 )
	message( SEND_ERROR "[JMSD] IN-SOURCE BUILD IS DISABLED - In-source build is disabled." )
endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "disable-in-source-build.cmake" )
