JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	# C
	set( ${PROJECT_NAME}_C_FLAGS ${CMAKE_C_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4127" ) # conditional expression is constant
#	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4242" ) # '': conversion from '' to '', possible loss of data
#	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4244" ) # '': conversion from '' to '', possible loss of data
#	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4245" ) # '': conversion from '' to '', signed/unsigned mismatch

	string( REPLACE ";" " " ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) #

	set( CMAKE_C_FLAGS ${${PROJECT_NAME}_C_FLAGS_STR} )

	# C++
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4100" ) # '': unreferenced formal parameter
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4127" ) # conditional expression is constant
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from 'unsigned __int64' to 'const __int64', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4456" ) # declaration of '' hides previous local declaration
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4457" ) # declaration of '' hides function parameter
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4505" ) # '': unreferenced local function has been removed
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4551" ) # function call missing argument list
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4574" ) # '' is defined to be '0': did you mean to use '#if '?
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4619" ) # #pragma warning: there is no warning number ''

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
