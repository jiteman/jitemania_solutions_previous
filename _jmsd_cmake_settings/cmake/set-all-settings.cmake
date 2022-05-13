include( ${JMSD_CMAKE_SETTINGS_PATH}/set-verbosity-configuration.cmake )

JMSD_CMAKE_CURRENT_FILE_IN( "set-all-settings.cmake" )

include( ${JMSD_CMAKE_SETTINGS_PATH}/utilities/functions-and-macroses.cmake )

include( ${JMSD_CMAKE_SETTINGS_PATH}/disable-in-source-build.cmake )

include( ${JMSD_CMAKE_SETTINGS_PATH}/select-build-configuration.cmake )

include( ${JMSD_CMAKE_SETTINGS_PATH}/reset-all-settings.cmake )

JMSD_CMAKE_CURRENT_FILE_OUT( "set-all-settings.cmake" )
