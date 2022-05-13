JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )

if ( UNIX )
	# C
	set( ${PROJECT_NAME}_C_FLAGS ${CMAKE_C_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-" ) #
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-undef" ) # "" is not defined, evaluates to 0
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-sign-conversion" ) # conversion to '' from '' may change the sign of the result
	list( APPEND ${PROJECT_NAME}_C_FLAGS "-Wno-float-equal" ) # comparing floating-point with '' or '' is unsafe

	string( REPLACE ";" " " ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) #

	set( CMAKE_C_FLAGS ${${PROJECT_NAME}_C_FLAGS_STR} )

	# C++
	## set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "-W" ) #

	## string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "-W" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #

	## set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-linux-compiler-settings.cmake" )
