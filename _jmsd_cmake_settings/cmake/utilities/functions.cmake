function(
	JMSD_REMOVE_FILE_FROM_THE_LIST
	out_in_file_list
	file_name_to_remove
)
	set( found_file_indicies "" )
	set( filename_index 0 )

	set( out_in_list ${${out_in_file_list}} )

	foreach( file_path ${out_in_list} )
		string( FIND ${file_path} ${file_name_to_remove} found_index )

		if( NOT found_index EQUAL -1 )
			list( APPEND found_file_indicies ${filename_index} )
		endif()

		math( EXPR filename_index "${filename_index} + 1" )
	endforeach()

	list( LENGTH found_file_indicies index_quantity )

	if( ${index_quantity} GREATER 0 )
		if( ${index_quantity} GREATER 1 )
			list( REVERSE found_file_indicies )
		endif()

		foreach( file_index ${found_file_indicies} )
			list( REMOVE_AT out_in_list ${file_index} )
		endforeach()
	endif()

	set( ${out_in_file_list} ${out_in_list} PARENT_SCOPE )

endfunction()


function(
	JMSD_REMOVE_FILES_FROM_THE_LIST
	out_in_file_list
	file_name_to_remove_list
)
	set( out_in_list ${${out_in_file_list}} )


	foreach( filename ${${file_name_to_remove_list}} )
		JMSD_REMOVE_FILE_FROM_THE_LIST( out_in_list ${filename} )
	endforeach()

	set( ${out_in_file_list} ${out_in_list} PARENT_SCOPE )

endfunction()


function(
	JMSD_KEEP_FILES_IN_THE_LIST
	out_in_file_list
	file_name_to_keep_list
)
	set( out_list "" )

	foreach( filename_to_keep ${${file_name_to_keep_list}} )
		foreach( filename_path ${${out_in_file_list}} )
			string( FIND ${filename_path} ${filename_to_keep} found_index )

			if( NOT found_index EQUAL -1 )
				list( APPEND out_list ${filename_path} )
			endif()
		endforeach()
	endforeach()

	set( ${out_in_file_list} ${out_list} PARENT_SCOPE )

endfunction()
