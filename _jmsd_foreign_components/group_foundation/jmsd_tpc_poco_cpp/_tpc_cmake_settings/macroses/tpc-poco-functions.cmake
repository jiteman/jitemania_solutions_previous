function(
	JMSD_REMOVE_PLATFORM_FILES_FOR_POCO
	out_in_file_list
	file_name_to_remove_list
)
	set( JMSD_POCO_PLATFORM_LIST "Android;C99;DEC;DUMMY;HPUX;POSIX;QNX;STD;STD_POSIX;STD_VX;STD_WIN32;SUN;UNIX;VMS;VX;WIN32;WIN32_OSVER;WIN32U;WINCE" )
	set( out_in_list ${${out_in_file_list}} )
	
	foreach( platform_name ${JMSD_POCO_PLATFORM_LIST} )
		foreach( filename ${${file_name_to_remove_list}} )
			JMSD_REMOVE_FILE_FROM_THE_LIST( out_in_list "${filename}_${platform_name}" )
		endforeach()
	endforeach()
	
	set( ${out_in_file_list} ${out_in_list} PARENT_SCOPE )

endfunction()
