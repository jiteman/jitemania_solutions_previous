JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )

if ( UNIX )
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-W" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-unused-parameter" ) # unused parameter ''
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-sign-compare" ) # comparison of integer expressions of different signedness: '' and ' {aka ''}
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-float-equal" ) # comparing floating point with == or != is unsafe
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-conversion" ) # conversion from ‘’ to ‘’ may change value
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-shadow" ) # declaration of ‘’ shadows a previous local
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-missing-declarations" ) # no previous declaration for ''
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-implicit-fallthrough" ) # this statement may fall through
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-cast-qual" ) # cast from type '' to type '' casts away qualifier
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-unused-but-set-variable" ) # variable ‘’ set but not used
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-deprecated-copy" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-inline" ) # inlining failed in call to '' call is unlikely and code size would grow

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )
