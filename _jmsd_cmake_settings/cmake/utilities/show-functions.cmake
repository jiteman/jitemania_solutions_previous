function(
	JMSD_SHOW_PROJECT_HEADER
	)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON )
			message( STATUS "[JMSD] BUILDING PROJECT: ${PROJECT_NAME}..." )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_PROJECT_FOOTER
	)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON )
			message( STATUS "[JMSD] BUILDING PROJECT: ${PROJECT_NAME} is completed" )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_PROJECT_GROUP_HEADER
	)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON )
			message( STATUS "[JMSD] BUILDING PROJECT GROUP: ${PROJECT_NAME}..." )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_PROJECT_GROUP_FOOTER
	)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON )
			message( STATUS "[JMSD] BUILDING PROJECT GROUP: ${PROJECT_NAME} is completed" )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_PROJECT_DEPENDENCY
	)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_DEPENDENCY_OUTPUT_IS_ON )
			message( STATUS "[JMSD] Directory dependency: ${PROJECT_NAME}_DEPENDENCY_DIRS: " )
			JMSD_ECHO_DIRECTORY_LIST( ${PROJECT_NAME}_DEPENDENCY_DIRS )
			message( STATUS "[JMSD] Library dependency: ${PROJECT_NAME}_DEPENDENCY_LIBS: ${${PROJECT_NAME}_DEPENDENCY_LIBS}" )
			message( STATUS "[JMSD] Build dependency: ${PROJECT_NAME}_BUILD_DEFINITIONS: ${${PROJECT_NAME}_BUILD_DEFINITIONS}" )
			message( STATUS "[JMSD] Link dependency: ${PROJECT_NAME}_LINK_DEFINITIONS: ${${PROJECT_NAME}_LINK_DEFINITIONS}" )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_TEST_SOURCE_DIRS
	)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_DEPENDENCY_OUTPUT_IS_ON )
			message( STATUS "[JMSD] Directory dependency: ${PROJECT_NAME}_TEST_SOURCE_DIRS: " )
			JMSD_ECHO_DIRECTORY_LIST( ${PROJECT_NAME}_TEST_SOURCE_DIRS )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_MESSAGE
	message_text
)
	message( STATUS "[JMSD] ${message_text}" )
endfunction()


function(
	JMSD_SHOW_VERBOSE_MESSAGE
	message_text
)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		message( STATUS "[JMSD] ${message_text}" )
	endif()
endfunction()


function(
	JMSD_SHOW_DEPENDENCY_MESSAGE
	message_text
)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_DEPENDENCY_OUTPUT_IS_ON )
			message( STATUS "[JMSD] ${message_text}" )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_PROJECT_NAME_MESSAGE
	message_text
)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_PROJECT_NAME_OUTPUT_IS_ON )
			message( STATUS "[JMSD] ${message_text}" )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_BUILD_MESSAGE
	message_text
)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_BUILD_OUTPUT_IS_ON )
			message( STATUS "[JMSD] ${message_text}" )
		endif()
	endif()
endfunction()


function(
	JMSD_SHOW_CMAKE_MESSAGE
	message_text
)
	if ( JMSD_CMAKE_VERBOSE_OUTPUT_IS_ON )
		if ( JMSD_CMAKE_CMAKE_OUTPUT_IS_ON )
			message( STATUS "[JMSD] ${message_text}" )
		endif()
	endif()
endfunction()


function(
	JMSD_ECHO_DIRECTORY_LIST
	directory_list
)
	foreach( directory ${${directory_list}} )
		message( STATUS "  " ${directory} )
	endforeach()
endfunction()


function(
	JMSD_ECHO_DIRECTORY_LIST_IF
	is_on
	directory_list
)
	if ( ${is_on} )
		foreach( directory ${${directory_list}} )
			message( STATUS "  " ${directory} )
		endforeach()
	endif()
endfunction()
