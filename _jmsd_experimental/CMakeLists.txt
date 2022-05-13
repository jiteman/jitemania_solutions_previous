cmake_minimum_required( VERSION 3.7.1 )

project( _jmsd_experimental )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( jmsd_exp_component )
##add_subdirectory( jmsd_exp_boost_example )

if( UNIX )

elseif( WIN32 )
	add_subdirectory( jmsd_exp_sfml )
	add_subdirectory( jmsd_exp_ssg )
endif()


JMSD_SHOW_PROJECT_GROUP_FOOTER()
