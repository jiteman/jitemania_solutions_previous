JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	# C
	set( ${PROJECT_NAME}_C_FLAGS ${CMAKE_C_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4057" ) # '': '' differs in indirection to slightly different base types from ''
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4127" ) # conditional expression is constant
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4131" ) # '': uses old-style declarator
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4204" ) # nonstandard extension used: non-constant aggregate initializer
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4242" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4244" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4255" ) # '': no function prototype given: converting '()' to '(void)'
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4267" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4334" ) # '': result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
#	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4365" ) # '': conversion from '' to '', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4388" ) # '': signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4668" ) # '' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4701" ) # potentially uninitialized local variable '' used
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4702" ) # unreachable code
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4703" ) # potentially uninitialized local pointer variable '' used
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4706" ) # assignment within conditional expression
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4996" ) # '': The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: . See online help for details.
#	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4996" ) # '': This function or variable may be unsafe. Consider using '' instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.

	string( REPLACE ";" " " ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_C_FLAGS_STR "${${PROJECT_NAME}_C_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_C_FLAGS ${${PROJECT_NAME}_C_FLAGS_STR} )

	# C++
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4267" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from '' to '', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4668" ) # '' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	list( APPEND ${PROJECT_NAME}_C_FLAGS "/wd4996" ) # '': The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: . See online help for details.

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )

else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
