macro(
	JMSD_LIST_TO_STRING
	in_list_out_string
)
	string( REPLACE ";" " " ${in_list_out_string} "${${in_list_out_string}}" )

endmacro()


macro(
	JMSD_STRING_REMOVE_DUPLICATES
	in_out_string
)
	string( REPLACE " " ";" intermediate_string "${${in_out_string}}" )

	list( LENGTH intermediate_string nb_elem )
	if ( nb_elem GREATER 1 )
		list( REMOVE_DUPLICATES intermediate_string )
		string( REPLACE ";" " " ${in_out_string} "${intermediate_string}" )
	endif()

endmacro()


if ( UNIX )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/utilities/linux-macroses.cmake )
elseif( WIN32 )
	include( ${JMSD_CMAKE_SETTINGS_PATH}/utilities/windows-macroses.cmake )
endif()
