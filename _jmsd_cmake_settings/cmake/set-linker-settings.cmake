JMSD_CMAKE_CURRENT_FILE_IN( "set-linker-settings.cmake" )

if ( UNIX )
	JMSD_SHOW_BUILD_MESSAGE( "[JMSD] LINKER SETTINGS: Linux" )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/linker-settings/set-linux-linker-settings.cmake )

elseif( WIN32 )
	JMSD_SHOW_BUILD_MESSAGE( "[JMSD] LINKER SETTINGS: Windows")
	include( ${JMSD_CMAKE_SETTINGS_PATH}/linker-settings/set-windows-linker-settings.cmake )

else()
	message( STATUS "[JMSD] LINKER SETTINGS: Unsupported platform. Default settings are used." )

endif()

JMSD_CMAKE_CURRENT_FILE_IN( "set-linker-settings.cmake" )
