JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4100" ) # '': unreferenced formal parameter
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4127" ) # conditional expression is constant
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4244" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4266" ) # '': no override available for virtual member function from base ''; function is hidden
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4267" ) # '': conversion from '' to '', possible loss of data
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4191" ) # '': unsafe conversion from '' to ''
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from 'unsigned __int64' to 'const __int64', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4388" ) # '': signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4456" ) # declaration of '' hides previous local declaration
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4457" ) # declaration of '' hides hides function parameter
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4619" ) # #pragma warning: there is no warning number ''

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable language extensions: (no)
	string( REPLACE "/Zc:strictStrings" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable string-literal to [char|wchar_t]* conversion (off by default)

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
