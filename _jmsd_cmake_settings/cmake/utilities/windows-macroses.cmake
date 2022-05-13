macro(
	JMSD_MICROSOFT_MESSAGE_COMPILER
	out
)
    if ( WIN32 )
		set( CMAKE_MC_COMPILER mc.exe )
		set( needs_appending false )
	
        foreach(msg ${ARGN})
            get_filename_component(msg_name ${msg} NAME)
            get_filename_component(msg_path ${msg} ABSOLUTE)
            string(REPLACE ".mc" ".h" hdr ${msg_name})
			#set_source_files_properties(${hdr} PROPERTIES GENERATED TRUE)
            add_custom_command(
                OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${hdr}
                DEPENDS ${msg}
                COMMAND ${CMAKE_MC_COMPILER}
                ARGS
                    -h ${CMAKE_CURRENT_BINARY_DIR}
                    -r ${CMAKE_CURRENT_BINARY_DIR}
                    ${msg_path}
                VERBATIM # recommended: p260
            )

            # Add the generated file to the include directory
            #include_directories(${CMAKE_CURRENT_BINARY_DIR})

            # Add the generated headers to POCO_HEADERS of the component
            #POCO_HEADERS( ${out} ${name} ${CMAKE_CURRENT_BINARY_DIR}/${hdr})
			
			list( APPEND ${out} ${CMAKE_CURRENT_BINARY_DIR}/${hdr} )
			
			set( needs_appending true )

        endforeach()

		if ( needs_appending )			
			include_directories(${CMAKE_CURRENT_BINARY_DIR})			
		endif()

    endif()
	
endmacro()
