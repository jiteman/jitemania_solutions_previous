JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )

if ( UNIX )
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )
	set( ${PROJECT_NAME}_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} )
	set( ${PROJECT_NAME}_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-W" ) #
	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS_DEBUG "-W" ) #
	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS_RELEASE "-W" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-missing-declarations" ) # no previous declaration for ''
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-float-equal" ) # comparing floating point with == or != is unsafe
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-conversion" ) # conversion from '' to '' may change value
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-cast-qual" ) # cast from type '' to type '' casts away qualifiers
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-shadow" ) # declaration of '' shadows a previous local

	list( APPEND ${PROJECT_NAME}_CXX_FLAGS_RELEASE "-Wno-inline" ) # inlining failed in call to '' call is unlikely and code size would grow

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )
	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_DEBUG_STR "${${PROJECT_NAME}_CXX_FLAGS_DEBUG}" )
	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_RELEASE_STR "${${PROJECT_NAME}_CXX_FLAGS_RELEASE}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_DEBUG_STR "${${PROJECT_NAME}_CXX_FLAGS_DEBUG_STR}" ) #
	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_RELEASE_STR "${${PROJECT_NAME}_CXX_FLAGS_RELEASE_STR}" ) #

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
	set( CMAKE_CXX_FLAGS_DEBUG ${${PROJECT_NAME}_CXX_FLAGS_DEBUG_STR} )
	set( CMAKE_CXX_FLAGS_RELEASE ${${PROJECT_NAME}_CXX_FLAGS_RELEASE_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )
