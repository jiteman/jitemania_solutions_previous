JMSD_CMAKE_CURRENT_FILE_IN( "set-compiler-settings.cmake" )

if ( UNIX )
	JMSD_SHOW_BUILD_MESSAGE( "[JMSD] COMPILER SETTINGS: Linux" )	
	include( ${JMSD_CMAKE_SETTINGS_PATH}/compiler-settings/set-linux-C-compiler-settings.cmake )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/compiler-settings/set-linux-C++-compiler-settings.cmake )

elseif( WIN32 )
	JMSD_SHOW_BUILD_MESSAGE( "[JMSD] COMPILER SETTINGS: Windows" )	
	include( ${JMSD_CMAKE_SETTINGS_PATH}/compiler-settings/set-windows-C-compiler-settings.cmake )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/compiler-settings/set-windows-C++-compiler-settings.cmake )

else()
	message( STATUS "[JMSD] COMPILER SETTINGS: Unsupported platform. Default settings are used." )

endif()


#CONFIG += c++1z
#CONFIG += exceptions
#CONFIG += depend_includepath
#CONFIG += incremental

JMSD_CMAKE_CURRENT_FILE_OUT( "set-compiler-settings.cmake" )
