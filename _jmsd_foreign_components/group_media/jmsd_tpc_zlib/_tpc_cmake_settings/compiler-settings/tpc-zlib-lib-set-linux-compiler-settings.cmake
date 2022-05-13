JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )

if ( UNIX )
	# C
	set( ${PROJECT_NAME}_C_FLAGS ${CMAKE_C_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_C_FLAGS "-W" ) #
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-cast-qual" ) # cast from type '' to type '' casts away qualifiers
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-conversion" ) # conversion from '' to '' may change value
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-implicit-function-declaration" ) # implicit declaration of function ''; did you mean ''?
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-implicit-fallthrough" ) # this statement may fall through
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-suggest-attribute=format" ) # function '' might be a candidate for '' format attribute

	string( REPLACE ";" " " ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) #

	set( CMAKE_C_FLAGS ${${PROJECT_NAME}_C_FLAGS_STR} )

	# C++
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-W" ) #

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )
