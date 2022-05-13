if ( NOT DEFINED JMSD_VERBOSE_CONFIGURATION_FILE_WAS_INCLUDED )
	message( STATUS "[JMSD] VERBOSE configuration file is INCLUDED" )
	set( JMSD_VERBOSE_CONFIGURATION_FILE_WAS_INCLUDED true )

	if ( EXISTS "${CMAKE_SOURCE_DIR}/CMake-verbosity-configuration.cmake" ) # JMSD way to deal with configurations
		include( ${CMAKE_SOURCE_DIR}/CMake-verbosity-configuration.cmake )
	else()
		set( JMSD_CMAKE_VERBOSE_OUTPUT is_off ) # [ is_on | is_off ]
		set( JMSD_CMAKE_DEPENDENCY_OUTPUT is_off ) # [ is_on | is_off ]
		set( JMSD_CMAKE_PROJECT_NAME_OUTPUT is_off ) # [ is_on | is_off ]
		set( JMSD_CMAKE_BUILD_OUTPUT is_off ) # [ is_on | is_off ]		
	endif()
	
	if( ${JMSD_CMAKE_VERBOSE_OUTPUT} STREQUAL "is_on" )
		set( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON true )		
		message( STATUS "[JMSD] Verbose output is on" )
	elseif( ${JMSD_CMAKE_VERBOSE_OUTPUT} STREQUAL "is_off" )
		set( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON false )		
		message( STATUS "[JMSD] Verbose output is off" )
	else()
		message( SEND_ERROR "[JMSD] [ERROR] JMSD_CMAKE_VERBOSE_OUTPUT = ${JMSD_CMAKE_VERBOSE_OUTPUT}" )
	endif()

	if ( ${JMSD_CMAKE_DEPENDENCY_OUTPUT} STREQUAL "is_on" )
		set( JMSD_CMAKE_DEPENDENCY_OUTPUT_IS_ON true )
		message( STATUS "[JMSD] Dependency output is on" )
	elseif ( ${JMSD_CMAKE_DEPENDENCY_OUTPUT} STREQUAL "is_off" )
		set( JMSD_CMAKE_DEPENDENCY_OUTPUT_IS_ON false )
		message( STATUS "[JMSD] Dependency output is off" )
	else()
		message( SEND_ERROR "[JMSD] [ERROR] JMSD_CMAKE_DEPENDENCY_OUTPUT = ${JMSD_CMAKE_DEPENDENCY_OUTPUT}" )
	endif()

	if ( ${JMSD_CMAKE_PROJECT_NAME_OUTPUT} STREQUAL "is_on" )
		set( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON true )
		message( STATUS "[JMSD] Project name output is on" )
	elseif ( ${JMSD_CMAKE_PROJECT_NAME_OUTPUT} STREQUAL "is_off" )
		set( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON false )
		message( STATUS "[JMSD] Project name output is off" )
	else()
		message( SEND_ERROR "[JMSD] [ERROR] JMSD_CMAKE_PROJECT_NAME_OUTPUT = ${JMSD_CMAKE_PROJECT_NAME_OUTPUT}" )
	endif()
	
	if( ${JMSD_CMAKE_BUILD_OUTPUT} STREQUAL "is_on" )
		set( JMSD_CMAKE_BUILD_OUTPUT_IS_ON true )		
		message( STATUS "[JMSD] Build output is on" )
	elseif( ${JMSD_CMAKE_BUILD_OUTPUT} STREQUAL "is_off" )
		set( JMSD_CMAKE_BUILD_OUTPUT_IS_ON false )		
		message( STATUS "[JMSD] Build output is off" )
	else()
		message( SEND_ERROR "[JMSD] [ERROR] JMSD_CMAKE_BUILD_OUTPUT = ${JMSD_CMAKE_BUILD_OUTPUT}" )
	endif()
	
	if( ${JMSD_CMAKE_CMAKE_OUTPUT} STREQUAL "is_on" )
		set( JMSD_CMAKE_CMAKE_OUTPUT_IS_ON true )		
		message( STATUS "[JMSD] CMake output is on" )
	elseif( ${JMSD_CMAKE_BUILD_OUTPUT} STREQUAL "is_off" )
		set( JMSD_CMAKE_CMAKE_OUTPUT_IS_ON false )		
		message( STATUS "[JMSD] CMake output is off" )
	else()
		message( SEND_ERROR "[JMSD] [ERROR] JMSD_CMAKE_CMAKE_OUTPUT = ${JMSD_CMAKE_CMAKE_OUTPUT}" )
	endif()

endif()
