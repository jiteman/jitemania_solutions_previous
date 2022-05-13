JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4165" ) # 'HRESULT' is being converted to 'bool'; are you sure this is what you want?
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from '' to '', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4456" ) # declaration of '' hides previous local declaration
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4668" ) # '' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4701" ) # potentially uninitialized local variable '' used
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4703" ) # potentially uninitialized local pointer variable '' used
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4800" ) # Implicit conversion from '' to bool. Possible information loss
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4996" ) # '': was declared deprecated
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd5031" ) # #pragma warning(pop): likely mismatch, popping warning state pushed in different file
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd5032" ) # detected #pragma warning(push) with no corresponding #pragma warning(pop)

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
