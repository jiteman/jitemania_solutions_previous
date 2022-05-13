JMSD_CMAKE_CURRENT_FILE_IN( "select-build-configuration.cmake" )

#	if configuration is explicitly specified
#		check it
#			use it if valid
##			use default if not valid
#	if configuration is specified by CMake-configuration.cmake
#		use it
#	use default configuration (release-optimized) if no configuration specified by file nor explicitly

set( JMSD_DEFAULT_CONFIGURATION release )
set( JMSD_CURRENT_CONFIGURATION is_not_specified )

# detect specification override
if ( CMAKE_BUILD_TYPE )
	if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug_override" )
		set( JMSD_CURRENT_CONFIGURATION "Debug" )
	elseif ( ${CMAKE_BUILD_TYPE} STREQUAL "Release_override" )
		set( JMSD_CURRENT_CONFIGURATION "Release" )
	else()
		message( STATUS "[JMSD] BUILD-CONFIGURATION: Configuration override is not specified: ${CMAKE_BUILD_TYPE}" )
	endif()

endif()

# detect configuration from configuration file, or standard
if ( ${JMSD_CURRENT_CONFIGURATION} STREQUAL "is_not_specified" )
	if ( EXISTS "${CMAKE_SOURCE_DIR}/CMake-build-configuration.cmake" ) # JMSF way to deal with configurations
		message( STATUS "[JMSD] BUILD-CONFIGURATION: Using configuration file: ${CMAKE_SOURCE_DIR}/CMake-build-configuration.cmake" )
		include( ${CMAKE_SOURCE_DIR}/CMake-build-configuration.cmake )

		if ( ${JMSD_ROOT_BUILD_CONFIGURATION} STREQUAL "set_to_debug" )
			set( JMSD_CURRENT_CONFIGURATION "Debug" )
		elseif( ${JMSD_ROOT_BUILD_CONFIGURATION} STREQUAL "set_to_release" )
			set( JMSD_CURRENT_CONFIGURATION "Release" )
		else()
			message( SEND_ERROR "[JMSD] BUILD-CONFIGURATION: JMSD_ROOT_DEBUG_BUILD_CONFIGURATION is not set [ set_to_debug | set_to_release ]: ${JMSD_ROOT_BUILD_CONFIGURATION}"  )
		endif()

	elseif ( CMAKE_BUILD_TYPE ) # way to deal with standard configurations
		message( STATUS "[JMSD] BUILD-CONFIGURATION: Using CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}" )

		if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
		elseif ( ${CMAKE_BUILD_TYPE} STREQUAL "Release" )
		else()
			message( SEND_ERROR "[JMSD] BUILD-CONFIGURATION: Unsupported build type: ${CMAKE_BUILD_TYPE}" )
		endif()

		set( JMSD_CURRENT_CONFIGURATION ${CMAKE_BUILD_TYPE} )

	else()
		message( STATUS "[JMSD] BUILD-CONFIGURATION: Using default configuration: ${JMSD_DEFAULT_CONFIGURATION}" )
		set( JMSD_CURRENT_CONFIGURATION ${JMSD_DEFAULT_CONFIGURATION} )

	endif()

endif() # if ( ${JMSF_CURRENT_CONFIGURATION} STREQUAL "is_not_specified" )


# set JMSD configuration flags
if ( JMSD_CURRENT_CONFIGURATION )
	if ( ${JMSD_CURRENT_CONFIGURATION} STREQUAL "Debug" )
		message( STATUS "[JMSD] BUILD-CONFIGURATION: Selecting debug build type" )
		set( JMSD_CMAKE_DEBUG true )
		set( JMSD_CMAKE_RELEASE false )
#		set( CMAKE_BUILD_TYPE Debug CACHE STRING "[JMSD] Defaulting to ${JMSD_CURRENT_CONFIGURATION} build configuration" FORCE )

	elseif ( ${JMSD_CURRENT_CONFIGURATION} STREQUAL "Release" )

		message( STATUS "[JMSD] BUILD-CONFIGURATION: Selecting release build type" )
		set( JMSD_CMAKE_DEBUG false )
		set( JMSD_CMAKE_RELEASE true )
#		set( CMAKE_BUILD_TYPE Release CACHE STRING "[JMSD] Defaulting to ${JMSD_CURRENT_CONFIGURATION} build configuration" FORCE )

	else()
		message( SEND_ERROR "[JMSD] BUILD-CONFIGURATION: Unsupported JMSD build configuration type: ${JMSD_CURRENT_CONFIGURATION}" )

	endif()

else()
	message( SEND_ERROR "[JMSD] BUILD-CONFIGURATION: No supported build configuration found" )

endif()

# set cached CMAKE_BUILD_TYPE to lowercased build name [debug|release]
if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
	if ( JMSD_CMAKE_BUILD_OUTPUT_IS_ON )
		message( STATUS "[JMSD] BUILD-CONFIGURATION: Caching ${JMSD_CURRENT_CONFIGURATION} build configuration: CMAKE_BUILD_TYPE to ${JMSD_CURRENT_CONFIGURATION}" )
	endif()
endif()
set( CMAKE_BUILD_TYPE ${JMSD_CURRENT_CONFIGURATION} CACHE STRING "[JMSD] Selecting ${JMSD_CURRENT_CONFIGURATION} build configuration" FORCE )

JMSD_CMAKE_CURRENT_FILE_OUT( "select-build-configuration.cmake" )
