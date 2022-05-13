include( ${JMSD_CMAKE_SETTINGS_PATH}/set-verbosity-configuration.cmake )

JMSD_CMAKE_CURRENT_FILE_IN( "set-linux-special-settings.cmake" )

if ( UNIX )

else()
	message( SEND_ERROR "[JMSD] set-linux-special-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "set-linux-special-settings.cmake" )
