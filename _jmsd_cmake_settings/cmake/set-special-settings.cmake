JMSD_CMAKE_CURRENT_FILE_IN( "set-special-settings.cmake" )

if ( UNIX )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/special-settings/set-linux-special-settings.cmake )
elseif ( WIN32 )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/special-settings/set-windows-special-settings.cmake )

else()
	message( STATUS "[JMSD] set-special-settings.cmake: Unsupported platform. Default special settings are used." )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "set-special-settings.cmake" )
