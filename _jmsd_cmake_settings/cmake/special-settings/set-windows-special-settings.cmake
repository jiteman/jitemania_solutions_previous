include( ${JMSD_CMAKE_SETTINGS_PATH}/set-verbosity-configuration.cmake )

JMSD_CMAKE_CURRENT_FILE_IN( "set-windows-special-settings.cmake" )

if ( WIN32 )	
	set( CMAKE_SHARED_LIBRARY_PREFIX "" ) # Remove 'lib' prefix for shared libraries on Windows

else()
	message( SEND_ERROR "[JMSF] setwindows-special-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "set-windows-special-settings.cmake" )
