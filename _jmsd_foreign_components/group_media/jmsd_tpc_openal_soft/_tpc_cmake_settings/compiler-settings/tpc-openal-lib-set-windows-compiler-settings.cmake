JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4065" ) # switch statement contains 'default' but no 'case' labels
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4324" ) # '': structure was padded due to alignment specifier
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4355" ) # 'this': used in base member initializer list
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from '' to '', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4582" ) # '': constructor is not implicitly called
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4583" ) # '': destructor is not implicitly called
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4668" ) # '' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4702" ) # unreachable code

	# MSVC 2019
	# note: to simplify migration, consider the temporary use of /Wv:18 flag with the version of the compiler with which you used to build without warnings
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4834" ) # discarding return value of function with 'nodiscard' attribute

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
