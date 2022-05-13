include( ${JMSD_CMAKE_SETTINGS_PATH}/set-verbosity-configuration.cmake )

JMSD_CMAKE_CURRENT_FILE_IN( "set-windows-linker-settings.cmake" )

if ( WIN32 )
	set( JMSD_CMAKE_CXX_FLAGS "" )
	set( JMSD_CMAKE_CXX_FLAGS_DEBUG "" )
	set( JMSD_CMAKE_CXX_FLAGS_RELEASE "" )

	set( JMSD_CMAKE_SHARED_LINKER_FLAGS "" )
	set( JMSD_CMAKE_EXE_LINKER_FLAGS "" )

	# optimization settings
	#	common
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "" )
	#	debug
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_DEBUG "/DEBUG" ) # Generate debug info: optimize for debugging
	#	release
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "/OPT:REF" ) # References (optimization)
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "/SAFESEH" ) # Image has safe exception handlers: (yes)
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "/OPT:ICF" ) # Enable COMDAT folding (optimization)

	if ( JMSD_ROOT_RELEASE_LINK_TIME_CODE_GENERATION )
		if ( ${JMSD_ROOT_RELEASE_LINK_TIME_CODE_GENERATION} STREQUAL "is_on" )
			list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "/LTCG" ) # link time code generation
		endif()
	endif()

	# run-time libraries
	#	common
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "legacy_stdio_definitions.lib" )
	#	debug
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_DEBUG "ucrtd.lib" ) # C runtime support
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_DEBUG "vcruntimed.lib" ) # C++ runtime support
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_DEBUG "msvcrtd.lib" ) # C standard library
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_DEBUG "msvcprtd.lib" ) # C++ standard library
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_DEBUG "msvcmrtd.lib" )
	#	release
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "ucrt.lib" ) # C runtime support
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "vcruntime.lib" ) # C++ runtime support
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "msvcrt.lib" ) # C standard library
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "msvcprt.lib" ) # C++ standard library
	list( APPEND JMSD_CMAKE_LINKER_FLAGS_RELEASE "msvcmrt.lib" )

	# windows libraries
	#	common
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "kernel32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "user32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "gdi32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "winspool.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "comdlg32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "advapi32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "shell32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "ole32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "oleaut32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "uuid.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "odbc32.lib" )
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "odbccp32.lib" )

	# additional stuff
	#	common
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/MACHINE:X64" ) # Target machine [ X86 | X64 ]
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/NXCOMPAT" ) # Data execution prevention: (yes)
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/DYNAMICBASE" ) # Randomized base address: (yes)
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/INCREMENTAL:NO" ) # Enable incremental linking: (no)
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/SUBSYSTEM:CONSOLE" ) # Subsystem: windows // [ CONSOLE | POSIX | WINDOWS ]
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/ERRORREPORT:NONE" ) # Internal linker error reporting: do not prompt
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/NOLOGO" ) # Suppress startup banner: (yes) // Suppresses the display of the copyright banner when the linker starts up and display of informational messages during linking.
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/IGNOREIDL" ) # Ignore embedded IDL
#	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/TLBID:1" ) # TypeLib resource ID
	list( APPEND JMSD_CMAKE_LINKER_FLAGS "/MANIFEST:NO" ) # no manifest
	list( APPEND JMSD_CMAKE_SHARED_LINKER_FLAGS "/DLL" )


	string( REPLACE ";" " " JMSD_CMAKE_LINKER_FLAGS_STR "${JMSD_CMAKE_LINKER_FLAGS}" )
	string( REPLACE ";" " " JMSD_CMAKE_LINKER_FLAGS_DEBUG_STR "${JMSD_CMAKE_LINKER_FLAGS_DEBUG}" )
	string( REPLACE ";" " " JMSD_CMAKE_LINKER_FLAGS_RELEASE_STR "${JMSD_CMAKE_LINKER_FLAGS_RELEASE}" )
	string( REPLACE ";" " " JMSD_CMAKE_SHARED_LINKER_FLAGS_STR "${JMSD_CMAKE_SHARED_LINKER_FLAGS}" )
	string( REPLACE ";" " " JMSD_CMAKE_EXE_LINKER_FLAGS_STR "${JMSD_CMAKE_EXE_LINKER_FLAGS}" )

	set( CMAKE_SHARED_LINKER_FLAGS "" )
	set( CMAKE_SHARED_LINKER_FLAGS_DEBUG "" )
	set( CMAKE_SHARED_LINKER_FLAGS_RELEASE "" )
	set( CMAKE_EXE_LINKER_FLAGS "" )
	set( CMAKE_EXE_LINKER_FLAGS_DEBUG "" )
	set( CMAKE_EXE_LINKER_FLAGS_RELEASE "" )

	# use CMAKE variables for release/debug instead of this branch (above)
	if ( JMSD_CMAKE_DEBUG )
		set( CMAKE_SHARED_LINKER_FLAGS "${JMSD_CMAKE_LINKER_FLAGS_STR} ${JMSD_CMAKE_LINKER_FLAGS_DEBUG_STR} ${JMSD_CMAKE_SHARED_LINKER_FLAGS_STR}" )
		set( CMAKE_EXE_LINKER_FLAGS "${JMSD_CMAKE_LINKER_FLAGS_STR} ${JMSD_CMAKE_LINKER_FLAGS_DEBUG_STR} ${JMSD_CMAKE_EXE_LINKER_FLAGS_STR}" )

	elseif ( JMSD_CMAKE_RELEASE )
		set( CMAKE_SHARED_LINKER_FLAGS "${JMSD_CMAKE_LINKER_FLAGS_STR} ${JMSD_CMAKE_LINKER_FLAGS_RELEASE_STR} ${JMSD_CMAKE_SHARED_LINKER_FLAGS_STR}" )
		set( CMAKE_EXE_LINKER_FLAGS "${JMSD_CMAKE_LINKER_FLAGS_STR} ${JMSD_CMAKE_LINKER_FLAGS_RELEASE_STR} ${JMSD_CMAKE_EXE_LINKER_FLAGS_STR}" )

	else()
		message( SEND_ERROR "[JMSD] LINKER SETTINGS: set windows-linker-settings.cmake: neither Release nor Debug" )

	endif()


else()
	message( SEND_ERROR "[JMSD] LINKER SETTINGS: set windows-linker-settings.cmake is included while not on windows" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "set-windows-linker-settings.cmake" )


# CMAKE_STATIC_LINKER_FLAGS
# CMAKE_MODULE_LINKER_FLAGS

# CMAKE_EXE_LINKER_FLAGS
# CMAKE_EXE_LINKER_FLAGS_DEBUG
# CMAKE_EXE_LINKER_FLAGS_RELEASE

# CMAKE_SHARED_LINKER_FLAGS
# CMAKE_SHARED_LINKER_FLAGS_DEBUG
# CMAKE_SHARED_LINKER_FLAGS_RELEASE

# JMSD_CMAKE_LINKER_FLAGS
# JMSD_CMAKE_LINKER_FLAGS_DEBUG
# JMSD_CMAKE_LINKER_FLAGS_RELEASE

# JMSD_CMAKE_EXE_LINKER_FLAGS
# JMSD_CMAKE_SHARED_LINKER_FLAGS


# C run-time and standard library
# ucrt.lib	ucrtbase.dll	DLL import library for the UCRT.	/MD
# ucrtd.lib	ucrtbased.dll	DLL import library for the Debug version of the UCRT. Not redistributable.	/MDd

# C++ run-time (exception handling, type information, debugging support, runtime checks, implementation details, certain extended library functions)
# vcruntime.lib	vcruntime<version>.dll	DLL import library for the vcruntime.	/MD
# vcruntimed.lib	vcruntime<version>d.dll	DLL import library for the Debug vcruntime. Not redistributable.	/MDd

# Init
# msvcrt.lib	Static library for the native CRT startup for use with DLL UCRT and vcruntime.	/MD
# msvcrtd.lib	Static library for the Debug version of the native CRT startup for use with DLL UCRT and vcruntime. Not redistributable.	/MDd

# C++ standard library
# msvcprt.lib	Multithreaded, dynamic link (import library for MSVCP<version>.dll)	/MD
# msvcprtd.lib	Multithreaded, dynamic link (import library for MSVCP<version>D.DLL)	/MDd
