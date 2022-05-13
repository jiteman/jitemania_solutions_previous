JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	# C
	set( ${PROJECT_NAME}_C_FLAGS ${CMAKE_C_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4019" ) # empty statement at global scope
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4100" ) # '': unreferenced formal parameter
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4127" ) # conditional expression is constant
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4131" ) # '': uses old-style declarator
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4189" ) # '': local variable is initialized but not referenced
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4242" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4244" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4245" ) # '': conversion from '' to '', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4255" ) # '': no function prototype given: converting '()' to '(void)'
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4267" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4311" ) # '': pointer truncation from '' to ''
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4324" ) # '': structure was padded due to alignment specifier
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4334" ) # '': result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4456" ) # declaration of '' hides previous local declaration
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4477" ) # '' : format string '' requires an argument of type '', but variadic argument has type ''
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4668" ) # '' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4701" ) # potentially uninitialized local variable '' used
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4703" ) # potentially uninitialized local pointer variable '' used

	string( REPLACE ";" " " ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_C_FLAGS ${${PROJECT_NAME}_C_FLAGS_STR} )

	# C++
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4100" ) # '': unreferenced formal parameter
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4242" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4244" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from '' to '', signed/unsigned mismatch

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
