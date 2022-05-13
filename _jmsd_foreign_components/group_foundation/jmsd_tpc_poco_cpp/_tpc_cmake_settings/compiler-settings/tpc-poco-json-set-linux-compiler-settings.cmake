JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )

if ( UNIX )
	# C
	set( ${PROJECT_NAME}_C_FLAGS ${CMAKE_C_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_C_FLAGS "-W" ) #
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-sign-conversion" ) # conversion to '' from '' may change the sign of the result
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-conversion" ) # conversion from '' to '' may change value
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-cast-qual" ) # cast from type '' to type '' casts away qualifiers
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-implicit-fallthrough" ) # this statement may fall through
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-format-truncation" ) # '' directive output may be truncated writing up to A bytes into a region of size between B and C

	string( REPLACE ";" " " ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) #

	set( CMAKE_C_FLAGS ${${PROJECT_NAME}_C_FLAGS_STR} )

	# C++
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-W" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-conversion" ) # conversion from '' to '' may change value
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-float-equal" ) # comparing floating point with == or != is unsafe
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-sign-compare" ) # comparison of integer expressions of different signedness: '' and '' {aka ''}
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-unused-parameter" ) # unused parameter ''
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-shadow" ) # declaration of '' shadows a previous local
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-Wno-inline" ) # inlining failed in call to '' call is unlikely and code size would grow

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )

else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )
