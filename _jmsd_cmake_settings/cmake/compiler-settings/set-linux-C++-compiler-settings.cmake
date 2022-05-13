include( ${JMSD_CMAKE_SETTINGS_PATH}/set-verbosity-configuration.cmake )

JMSD_CMAKE_CURRENT_FILE_IN( "set-linux-compiler-settings.cmake" )

if ( UNIX )
	set( JMSD_CMAKE_CXX_FLAGS "" )
	set( JMSD_CMAKE_CXX_FLAGS_DEBUG "" )
	set( JMSD_CMAKE_CXX_FLAGS_RELEASE "" )

	# C language

	# C++ language


	# warning settings
	#	common
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wall" ) # enable all warnings
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wextra" ) # enable extra warnings
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Werror" ) # treat warnings as errors
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wpedantic" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-pedantic-errors" ) #
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wformat=2" ) #
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-W" ) #
	#	debug
	#	release

	# special warning settings
	#	common
	# same as for C
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wundef" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wshadow" ) # declaration of '' shadows a member of ''
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wcast-qual" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wcast-align" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wwrite-strings" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wpointer-arith" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wconversion" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wsign-compare" ) # [-Wextra]
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wmissing-declarations" ) # no previous declaration for ''
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Waggregate-return" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Winline" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "--param inline-unit-growth=30" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wredundant-decls" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Winline" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-long-long" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wmissing-noreturn" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-missing-field-initializers" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-missing-braces" )
	#~same as for C
	# C++ specific
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wfloat-equal" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wmissing-format-attribute" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wunreachable-code" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-format-nonliteral" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-format-security" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wdisabled-optimization" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wpacked" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-reorder" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wno-parentheses" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wpadded" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "--param large-stack-frame-growth=5000" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wshift-negative-value" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-Wshift-overflow=2" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "-fno-delete-null-pointer-checks" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS "" )

	#	debug
	#	release

	# special warning settings (google [test] sucks)
	#	common
	#	debug
	#	release

	# optimization settings
	#	common
	#	debug
	list( APPEND JMSD_CMAKE_CXX_FLAGS_DEBUG "-g" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS_DEBUG "-ggdb3" )
	#	list( APPEND JMSD_CMAKE_CXX_FLAGS_DEBUG "-Og" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS_DEBUG "-D_GLIBCXX_DEBUG" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS_DEBUG "-D_GLIBCXX_ASSERTIONS" )
	#	release
	list( APPEND JMSD_CMAKE_CXX_FLAGS_RELEASE "-O3" )

	# analysis settings
	#	common
	#	debug
	#	release

	# language settings
	#	common
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-std=c++17" )
	list( APPEND JMSD_CMAKE_CXX_FLAGS "-fconcepts" ) # C++ Concepts are now supported
	#	debug
	#	release

	# security settings
	#	common
	#	debug
	#	release

	# additional stuff
	#	common
	#	debug
	#	release

	string( REPLACE ";" " " JMSD_CMAKE_CXX_FLAGS_STR "${JMSD_CMAKE_CXX_FLAGS}" )
	string( REPLACE ";" " " JMSD_CMAKE_CXX_FLAGS_DEBUG_STR "${JMSD_CMAKE_CXX_FLAGS_DEBUG}" )
	string( REPLACE ";" " " JMSD_CMAKE_CXX_FLAGS_RELEASE_STR "${JMSD_CMAKE_CXX_FLAGS_RELEASE}" )

	set( CMAKE_CXX_FLAGS "" )
	set( CMAKE_CXX_FLAGS_DEBUG "" )
	set( CMAKE_CXX_FLAGS_RELEASE "" )

	set( CMAKE_CXX_FLAGS ${JMSD_CMAKE_CXX_FLAGS_STR} )
	set( CMAKE_CXX_FLAGS_DEBUG ${JMSD_CMAKE_CXX_FLAGS_DEBUG_STR} )
	set( CMAKE_CXX_FLAGS_RELEASE ${JMSD_CMAKE_CXX_FLAGS_RELEASE_STR} )

else()
	message( SEND_ERROR "[JMSD] COMPILER SETTINGS: set-linux-compiler-settings.cmake is included while not on linux" )

endif()

JMSD_CMAKE_CURRENT_FILE_OUT( "set-linux-compiler-settings.cmake" )
