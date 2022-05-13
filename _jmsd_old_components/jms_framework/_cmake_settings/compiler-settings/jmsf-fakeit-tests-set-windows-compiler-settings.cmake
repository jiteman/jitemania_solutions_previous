JMSD_CMAKE_CURRENT_FILE_IN( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )

if ( WIN32 )
	set( ${PROJECT_NAME}_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

	## list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd" ) #
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4191" ) # 'reinterpret_cast': unsafe conversion from '' to ''
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4365" ) # '': conversion from '' to '', signed/unsigned mismatch
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4668" ) # '' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	list( APPEND ${PROJECT_NAME}_CXX_FLAGS "/wd4946" ) # reinterpret_cast used between related classes: 'tpunit::TestFixture' and 'VirtualOffsetSelectorTest'

	string( REPLACE ";" " " ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS}" )

	## string( REPLACE "X" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) #
	string( REPLACE "/Za" "" ${PROJECT_NAME}_CXX_FLAGS_STR "${${PROJECT_NAME}_CXX_FLAGS_STR}" ) # disable language extensions: (no)

	set( CMAKE_CXX_FLAGS ${${PROJECT_NAME}_CXX_FLAGS_STR} )
else()
	message( SEND_ERROR "[JMSD] ${JMSD_FOREIGN_COMPONENT_FULL_NAME} COMPILER SETTINGS: ${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "${JMSD_FOREIGN_COMPONENT_FULL_NAME}-windows-compiler-settings.cmake" )
